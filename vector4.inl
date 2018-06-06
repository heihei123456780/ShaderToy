#include "vector2.h"
#include "vector3.h"

inline void Vector4::inverse()
{
    m_x = 1.0f / m_x;
    m_y = 1.0f / m_y;
    m_z = 1.0f / m_z;
    m_w = 1.0f / m_w;
}

inline void Vector4::normalize()
{
    float len = m_x * m_x +
                m_y * m_y +
                m_z * m_z +
                m_w * m_w;

    len = Math::sqrt(len);
    if (len > 0.0f)
    {
        float inverse = 1.0f / len;
        m_x *= inverse;
        m_y *= inverse;
        m_z *= inverse;
        m_w *= inverse;
    }
}

inline Vector4 Vector4::inversed() const
{
    Vector4 v = *this;
    v.inverse();
    return v;
}

inline Vector4 Vector4::normalized() const
{
    Vector4 v = *this;
    v.normalize();
    return v;
}

inline float Vector4::dot(const Vector4 &v1, const Vector4 &v2)
{
    return (v1.m_x * v2.m_x +
            v1.m_y * v2.m_y +
            v1.m_z * v2.m_z +
            v1.m_w * v2.m_w);
}

inline Vector4 Vector4::add(const Vector4 &left, const Vector4 &right)
{
    Vector4 result;
    result.m_x = left.m_x + right.m_x;
    result.m_y = left.m_y + right.m_y;
    result.m_z = left.m_z + right.m_z;
    result.m_w = left.m_w + right.m_w;
    return result;
}

inline Vector4 Vector4::subtract(const Vector4 &left, const Vector4 &right)
{
    Vector4 result;
    result.m_x = left.m_x - right.m_x;
    result.m_y = left.m_y - right.m_y;
    result.m_z = left.m_z - right.m_z;
    result.m_w = left.m_w + right.m_w;
    return result;
}

inline Vector4 Vector4::multiply(float left, const Vector4 &right)
{
    Vector4 result;
    result.m_x = left * right.m_x;
    result.m_y = left * right.m_y;
    result.m_z = left * right.m_z;
    result.m_w = left * right.m_w;
    return result;
}

inline Vector4 Vector4::multiply(const Vector4 &left, float right)
{
    Vector4 result;
    result.m_x = left.m_x * right;
    result.m_y = left.m_y * right;
    result.m_z = left.m_z * right;
    result.m_w = left.m_w * right;
    return result;
}

inline Vector4 Vector4::multiply(const Vector4 &left, const Vector4 &right)
{
    Vector4 result;
    result.m_x = left.m_x * right.m_y;
    result.m_y = left.m_y * right.m_y;
    result.m_z = left.m_z * right.m_z;
    result.m_w = left.m_w * right.m_w;
    return result;
}

inline Vector4 &Vector4::operator=(const Vector4 &vec4)
{
    m_x = vec4.m_x;
    m_y = vec4.m_y;
    m_z = vec4.m_z;
    m_w = vec4.m_w;
    return *this;
}

inline Vector4 &Vector4::operator+=(const Vector4 &vec4)
{
    m_x += vec4.m_x;
    m_y += vec4.m_y;
    m_z += vec4.m_z;
    m_w += vec4.m_w;
    return *this; 
}

inline Vector4 &Vector4::operator-=(const Vector4 &vec4)
{
    m_x -= vec4.m_x;
    m_y -= vec4.m_y;
    m_z -= vec4.m_z;
    m_w -= vec4.m_w;
    return *this; 
}

inline Vector4 &Vector4::operator*=(float factor) 
{
    m_x *= factor;
    m_y *= factor;
    m_z *= factor;
    m_w *= factor;
    return *this; 
}

inline Vector4 &Vector4::operator*=(const Vector4 &vec4)
{
    m_x *= vec4.m_x;
    m_y *= vec4.m_y;
    m_z *= vec4.m_z;
    m_w *= vec4.m_w;
    return *this; 
}

inline Vector4 &Vector4::operator/=(float divisor)
{
    float inverse = 1.0f / divisor;
    m_x *= inverse;
    m_y *= inverse;
    m_z *= inverse;
    m_w *= inverse;
    return *this;
}

inline Vector4 &Vector4::operator/=(const Vector4 &vec4)
{
    m_x /= vec4.m_x;
    m_y /= vec4.m_y;
    m_z /= vec4.m_z;
    m_w /= vec4.m_w;
    return *this;
}

inline bool operator==(const Vector4 &v1, const Vector4 &v2)
{
    return (v1.m_x == v2.m_x &&
            v1.m_y == v2.m_y &&
            v1.m_z == v2.m_z &&
            v1.m_w == v2.m_w);
}

inline bool operator!=(const Vector4 &v1, const Vector4 &v2)
{
    return (v1.m_x != v2.m_x ||
            v1.m_y != v2.m_y ||
            v1.m_z != v2.m_z ||
            v1.m_w != v2.m_w);
}

inline Vector2 Vector4::toVector2() const
{
    return Vector2(m_x, m_y);
}

inline Vector3 Vector4::toVector3() const
{
    return Vector3(m_x, m_y, m_z);
}
