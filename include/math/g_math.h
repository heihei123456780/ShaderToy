#ifndef MATH_H
#define MATH_H

#include "math_util.h"

#include <math.h>
#include <limits>

class Math
{
public:
    inline static float acos(float radian) { return __builtin_acosf(radian); }
    inline static float asin(float radian) { return __builtin_asinf(radian); }
    inline static float atan(float radian) { return __builtin_atanf(radian); }
    inline static float atan2(float r1, float r2) { return __builtin_atan2f(r1, r2); }
    inline static float cos(float radian) { return __builtin_cosf(radian); }
    inline static float sin(float radian) { return __builtin_sinf(radian); }
    inline static float tan(float radian) { return __builtin_tanf(radian); }
    inline static float cot(float radian) { return 1.0f / __builtin_tanf(radian); }
    
    inline static int max(int a, int b) {  return a > b ? a : b; }
    inline static float max(float a, float b) { return a > b ? a : b; }
    inline static double max(double a, double b) { return a > b ? a : b; }
    
    inline static int min(int a, int b) { return a < b ? a : b; }
    inline static float min(float a, float b) { return a < b ? a : b; }
    inline static double min(double a, double b) { return a < b ? a : b; }
    
    inline static float log(float n) { return __builtin_log(n); }
    inline static float log10(float n) { return __builtin_log10(n); }

    inline static float abs(float f) { return __builtin_fabsf(f); }
    inline static float fabs(float f) { return __builtin_fabsf(f); }
    inline static float exp(float f) { return __builtin_expf(f); }
    inline static float fmod(float f1, float f2) { return __builtin_fmodf(f1, f2); }
    inline static float ceil(float f) { return __builtin_ceilf(f); } 
    inline static float floor(float f) { return __builtin_floor(f); }
    inline static float pow(float n, float i) { return __builtin_powf(n, i); }
    inline static float round(float f) { return __builtin_roundf(f); }
    inline static float sqr(float f) { return f * f; }
    inline static float sqrt(float f) { return 1.0f / MathUtil::fast_sqrt_inverse(f); }

    inline static float radToDeg(float radian) { return radian * (180.0 / PI); }
    inline static float degToRad(float degree) { return degree * (PI * 180.0); }
    
    inline static int clamp(int value, int _min, int _max) { return max(min(value, _max), _min); }
    inline static float clamp(float value, float _min, float _max) { return max(min(value, _max), _min); }

    static constexpr float E            = 2.71828182845904523536f;
    static constexpr float Epsilon      = 0.000001f;
    static constexpr float LargeEpsilon = 0.00005f;
    static constexpr float Infinity     = std::numeric_limits<float>::infinity();
    static constexpr float NegInfinity  = -std::numeric_limits<float>::infinity();
    static constexpr float Log2E        = 1.442695040888963387f;
    static constexpr float Log10E       = 0.4342944819032518f;
    static constexpr float PI           = 3.14159265358979323846f;
    static constexpr float PI_2         = 6.28318530717958647693f;
    static constexpr float Half_Pi      = 1.57079632679489661923f;
    static constexpr float Tolerance    = 2e-37f;  
};

#endif // MATH
