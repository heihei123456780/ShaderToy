#define AA 3

//
// Cheap 2D Humanoid SDF for dropping into scenes to add a sense of scale.
// Hazel Quantock 2018
//
// Based on: https://www.shadertoy.com/view/4scBWN
//
float RoundMax( float a, float b, float r ) {
    a += r; b += r;    
    float f = ( a > 0. && b > 0. ) ? sqrt(a*a+b*b) : max(a,b);    
    return f - r;
}

float RoundMin( float a, float b, float r ) {
    return -RoundMax(-a,-b,r);
}

float Humanoid( in vec2 uv, in float phase ) {
    float n3 = sin((uv.y-uv.x*.7)*11.+phase)*.014; // "pose"
    float n0 = sin((uv.y+uv.x*1.1)*23.+phase*2.)*.007;
    float n1 = sin((uv.y-uv.x*.8)*37.+phase*4.)*.004;
    float n2 = sin((uv.y+uv.x*.9)*71.+phase*8.)*.002;

    
    float head = length((uv-vec2(0,1.65))/vec2(1,1.2))-.15/1.2;
    float neck = length(uv-vec2(0,1.5))-.05;
    float torso = abs(uv.x)-.25 - uv.x*.3;

    torso = RoundMax( torso, uv.y-1.5, .2 );
    torso = RoundMax( torso, -(uv.y-.6), .0 );

    float f = RoundMin(head,neck,.04);
    f = RoundMin(f,torso,.02);
    
    float leg = abs(abs(uv.x+(uv.y-.9)*.1*cos(phase*3.))-.15+.075*uv.y)-.07-.07*uv.y; 
    leg = max( leg, uv.y-1. );
    
    f = RoundMin(f,leg,.1);

    float stick = max(abs(uv.x+.4-uv.y*.04)-0.025, uv.y-1.15);
    float arm = max(max(abs(uv.y-1.-uv.x*.3) - .06, uv.x), -uv.x-.4);
    
    f = RoundMin(f, stick, 0.0);
    f = RoundMin(f, arm, 0.05);
    
    f += (-n0+n1+n2+n3)*(.1+.9*uv.y/1.6);
    
    return max( f, -uv.y );
}

//
// Lens flare, original based on:
// musk's lens flare by mu6k  
//
// https://www.shadertoy.com/view/4sX3Rs
//
float lensflare(vec2 fragCoord) {
    vec3 ro, ta;
    mat3 cam = getCamera( iTime, iMouse/iResolution.xyxy, ro, ta );
    vec3 cpos = SUN_DIR*cam; 
    vec2 pos = CAMERA_FL * cpos.xy / cpos.z;
    vec2 uv = (-iResolution.xy + 2.0*fragCoord)/iResolution.y;
    
	vec2 uvd = uv*(length(uv));
	float f = 0.1/(length(uv-pos)*16.0+1.0);
	f += max(1.0/(1.0+32.0*pow(length(uvd+0.8*pos),2.0)),.0)*0.25;
	vec2 uvx = mix(uv,uvd,-0.5);
	f += max(0.01-pow(length(uvx+0.4*pos),2.4),.0)*6.0;
	f += max(0.01-pow(length(uvx-0.3*pos),1.6),.0)*6.0;
	uvx = mix(uv,uvd,-0.4);
	f += max(0.01-pow(length(uvx+0.2*pos),5.5),.0)*2.0;
    
	return f;
}

bool intersectSphere ( in vec3 ro, in vec3 rd, in vec4 sph ) {
    vec3  ds = ro - sph.xyz;
    float bs = dot(rd, ds);
    float cs = dot(ds, ds) - sph.w*sph.w;
    float ts = bs*bs - cs;
	
    if( ts > 0.0 ) {
        ts = -bs - sqrt( ts );
		if( ts>0. ) {
			return true;
		}
    }
    return false;
}

bool intersectPlane (in vec3 ro, in vec3 rd, in vec3 n, in vec3 p0, inout float dist) {   
    dist = dot(p0 - ro, n)/dot(rd,n);
    return dist > 0.;
}

void mainImage( out vec4 fragColor, in vec2 fragCoord ) {  
    if( letterBox(fragCoord, iResolution.xy, 2.35) ) {
        fragColor = vec4( 0., 0., 0., 1. );
    } else {
        vec4 col = texelFetch(iChannel0, ivec2(fragCoord), 0);
        vec4 clouds = texelFetch(iChannel1, ivec2(fragCoord), 0);
    	
        col.rgb = clouds.rgb + col.rgb * clouds.a;
       
        vec3 ro, rd, ta;
		mat3 cam = getCamera( iTime, iMouse/iResolution.xyxy, ro, ta );
        float dist;
        vec4 tcol = vec4(0.);
        vec2 p = (-iResolution.xy + 2.0*(fragCoord))/iResolution.y;
        rd = cam * normalize(vec3(p,CAMERA_FL)); 
        
        if (intersectSphere(ro,rd,vec4(FLAG_POSITION,HUMANOID_SCALE*INV_SCENE_SCALE*2.))) {
            for(int x=0; x<AA; x++) {
                for(int y=0; y<AA; y++) {
                    vec2 p = (-iResolution.xy + 2.0*(fragCoord + vec2(x,y)/float(AA) - .5))/iResolution.y;
                    rd = cam * normalize(vec3(p,CAMERA_FL)); 

                    if (intersectPlane(ro, rd, vec3(0,0,1), FLAG_POSITION, dist) && dist < col.w) {
                        vec3 pos = ro + rd * dist;
                        vec2 uv = (pos.xy - FLAG_POSITION.xy)*(SCENE_SCALE/HUMANOID_SCALE);
                        uv.x = -uv.x + uv.y*0.05;
                        float sdf = Humanoid( uv, 3. );
                        float a = smoothstep(.4,.6,.5-.5*sdf/(abs(sdf)+.002));
                        float sdf2 = Humanoid( uv+vec2(.025,0.05), 3. );
                        float a2 = smoothstep(.4,.6,.5-.5*sdf2/(abs(sdf2)+.002));
                        float c = (a-a2)*2.;
                        c = clamp(c+uv.x*.2+.6,0.,1.); c*=c; c*=c;
                        tcol += vec4(mix(vec3(.04,0.05,0.06),SUN_COLOR,c),a);
                    }
                }
            }
            tcol /= float(AA*AA);
        }
        
        col.rgb = mix(col.rgb, tcol.rgb, tcol.w);    
            
        // lens flare
        col.rgb += SUN_COLOR*lensflare(fragCoord)*smoothstep(-.3,.5,dot(rd,SUN_DIR));       
        col.rgb = clamp(col.rgb, vec3(0), vec3(1));
        
        // gamma and contrast
        col.rgb = mix(col.rgb, pow(col.rgb, vec3(1./2.2)), .85);
        col.rgb = mix( col.rgb, col.bbb, 0.2 ); 
     
        // vignette
        vec2 uv = fragCoord / iResolution.xy;
        col.rgb = mix(col.rgb*col.rgb, col.rgb, pow( 16.0*uv.x*uv.y*(1.0-uv.x)*(1.0-uv.y), 0.1 ));
        
        // noise
        col.rgb -= hash12(fragCoord)*.025;
        
        fragColor = vec4( col.rgb, 1. );
    }
}
