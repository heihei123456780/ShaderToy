#ifndef SHADER_INPUT_H
#define SHADER_INPUT_H

#include "vector3.h"
#include "vector4.h"

class ShaderInput
{
public:
    Vector3     iResolution;
    float       iTime;
    float       iGlobalTime;
    Vector4     iMouse;
    Vector4     iDate;
    float       iSampleRate;
    Vector3     iChannelResolution[4];
    float       iChannelTime[4];

    int         iFrame;
    float       iTimeDelta;
    float       iFrameRate;
};

#endif // SHADERINPUT_H
