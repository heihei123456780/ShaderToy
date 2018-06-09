#include "vector2.h"
#include "vector3.h"
#include "vector4.h"

void Vector2::inverse()
{
    m_x = 1.0f / m_x;
    m_y = 1.0f / m_y;
}

void Vector2::normalize()
{
    float len = m_x * m_x + m_y * m_y;

    len = Math::sqrt(len);
    if (len > 0.0f)
    {
        float inverse = 1.0f / len;
        m_x *= inverse;
        m_y *= inverse;
    }
}

Vector2 Vector2::inversed() const
{
    Vector2 v = *this;
    v.inverse();
    return v;
}

Vector2 Vector2::normalized() const
{
    Vector2 v = *this;
    v.normalize();
    return v;
}

float Vector2::angleBetween(const Vector2 &vec2) const
{
    float len_product = this->length() * vec2.length();
    
    if (len_product < 1e-6f)
        len_product = 1e-6f;

    float f = this->dotProduct(vec2) / len_product;
    
    return Math::abs(f);
}

float Vector2::cross(const Vector2 &v1, const Vector2 &v2)
{
    return (v1.m_x * v2.m_y - 
            v1.m_y * v2.m_x);
}

float Vector2::dot(const Vector2 &v1, const Vector2 &v2)
{
    return (v1.m_x * v2.m_x + 
            v1.m_y * v2.m_y);
}

Vector2 Vector2::midPoint(const Vector2 &vec2) const
{
    return Vector2((m_x + vec2.m_x) * 0.5f,
                   (m_y + vec2.m_y) * 0.5f);
}

Vector2 Vector2::perpendicular(void) const
{
    return Vector2(-m_y, m_x);
}

Vector2 Vector2::add(const Vector2 &left, const Vector2 &right)
{
    Vector2 result;
    result.m_x = left.m_x + right.m_x;
    result.m_y = left.m_y + right.m_y;
    return result;
}

Vector2 Vector2::subtract(const Vector2 &left, const Vector2 &right)
{
    Vector2 result;
    result.m_x = left.m_x - right.m_x;
    result.m_y = left.m_y - right.m_y;
    return result;
}

Vector2 Vector2::multiply(float left, const Vector2 &right)
{
    Vector2 result;
    result.m_x = left * right.m_x;
    result.m_y = left * right.m_y;
    return result;
}

Vector2 Vector2::multiply(const Vector2 &left, float right)
{
    Vector2 result;
    result.m_x = left.m_x * right;
    result.m_y = left.m_y * right;
    return result;
}

Vector2 Vector2::multiply(const Vector2 &left, const Vector2 &right)
{
    Vector2 result;
    result.m_x = left.m_x * right.m_y;
    result.m_y = left.m_y * right.m_y;
    return result;
}

Vector2 &Vector2::operator=(const Vector2 &vec2)
{
    m_x = vec2.m_x;
    m_y = vec2.m_y;
    return *this;
}

Vector2 &Vector2::operator+=(const Vector2 &vec2)
{
    m_x += vec2.m_x;
    m_y += vec2.m_y;
    return *this; 
}

Vector2 &Vector2::operator-=(const Vector2 &vec2)
{
    m_x -= vec2.m_x;
    m_y -= vec2.m_y;
    return *this; 
}

Vector2 &Vector2::operator*=(float factor)
{
    m_x *= factor;
    m_y *= factor;
    return *this; 
}

Vector2 &Vector2::operator*=(const Vector2 &vec2)
{
    m_x *= vec2.m_x;
    m_y *= vec2.m_y;
    return *this; 
}

Vector2 &Vector2::operator/=(float divisor)
{
    float inverse = 1.0f / divisor;
    m_x *= inverse;
    m_y *= inverse;
    return *this;
}

Vector2 &Vector2::operator/=(const Vector2 &vec2)
{
    m_x /= vec2.m_x;
    m_y /= vec2.m_y;
    return *this;
}

bool operator==(const Vector2 &v1, const Vector2 &v2)
{
    return (v1.m_x == v2.m_x &&
            v1.m_y == v2.m_y);
}

bool operator!=(const Vector2 &v1, const Vector2 &v2)
{
    return (v1.m_x != v2.m_x ||
            v1.m_y != v2.m_y);
}

Vector3 Vector2::toVector3() const
{
    return Vector3(m_x, m_y, 1.0f);
}

Vector4 Vector2::toVector4() const
{
    return Vector4(m_x, m_y, 1.0f, 1.0f);
}
