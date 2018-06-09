#ifndef MATH_UTIL_H
#define MATH_UTIL_H

class MathUtil
{
public:
    static float fast_sqrt_inverse(float f);
    static float fast_cos(float radian);
    static float fast_sin(float radian);
};

inline float MathUtil::fast_sqrt_inverse(float f)
{
    float xhalf = 0.5f * f;
    int i = *(int *)&f;
    i = 0x5f375a86 - (i >> 1);
    f = *(float *)&i;
    f = f * (1.5f - xhalf * f * f);
    return f;
}


inline float fast_cos(float radian)
{
    return 1.0f;
}

inline float fast_sin(float radian)
{
    return 1.0f;
}

#endif // MATH_UTIL_H
