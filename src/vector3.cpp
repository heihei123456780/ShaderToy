#include "vector2.h"
#include "vector3.h"
#include "vector4.h"

void Vector3::inverse()
{
    m_x = 1.0f / m_x;
    m_y = 1.0f / m_y;
    m_z = 1.0f / m_z;
}

void Vector3::normalize()
{
    float len = m_x * m_x +
                m_y * m_y +
                m_z * m_z;

    len = Math::sqrt(len);
    if (len > 0.0f)
    {
        float inverse = 1.0f / len;
        m_x *= inverse;
        m_y *= inverse;
        m_z *= inverse;
    }
}

Vector3 Vector3::inversed() const
{
    Vector3 v = *this;
    v.inverse();
    return v;
}

Vector3 Vector3::normalized() const
{
    Vector3 v = *this;
    v.normalize();
    return v;
}

float Vector3::angleBetween(const Vector3 &vec3) const
{
    float len_product = this->length() * vec3.length();
    
    if (len_product < 1e-6f)
        len_product = 1e-6f;

    float f = this->dotProduct(vec3) / len_product;
    
    return Math::acos(f);
}

Vector3 Vector3::cross(const Vector3 &v1, const Vector3 &v2)
{
    return Vector3((v1.m_y * v2.m_z) - (v1.m_z * v2.m_y),
                   (v1.m_x * v2.m_z) - (v1.m_z * v2.m_x),
                   (v1.m_x * v2.m_y) - (v1.m_y * v2.m_x));
}

float Vector3::dot(const Vector3 &v1, const Vector3 &v2)
{
    return (v1.m_x * v2.m_x +
            v1.m_y * v2.m_y +
            v1.m_z * v2.m_z);
}

Vector3 Vector3::midPoint(const Vector3 &vec3) const
{
    return Vector3((m_x + vec3.m_x) * 0.5f,
                   (m_y + vec3.m_y) * 0.5f,
                   (m_z + vec3.m_z) * 0.5f);
}

Vector3 Vector3::perpendicular(void) const
{
    const float square_zero = (float)(1e-06 * 1e-6);
    Vector3 perp = crossProduct(Vector3(1.0f, 0.0f, 0.0f));
    
    if (perp.lengthSquared() < square_zero)
    {
        perp = crossProduct(Vector3(0.0f, 1.0f, 0.0f));
    }

    perp.normalize();
    return perp;
}

Vector3 Vector3::reflect(const Vector3 &vec3) const
{
    return Vector3(*this - (2.0f * dotProduct(vec3) * vec3));
}

Vector3 Vector3::add(const Vector3 &left, const Vector3 &right)
{
    Vector3 result;
    result.m_x = left.m_x + right.m_x;
    result.m_y = left.m_y + right.m_y;
    result.m_z = left.m_z + right.m_z;
    return result;
}

Vector3 Vector3::subtract(const Vector3 &left, const Vector3 &right)
{
    Vector3 result;
    result.m_x = left.m_x - right.m_x;
    result.m_y = left.m_y - right.m_y;
    result.m_z = left.m_z - right.m_z;
    return result;
}

Vector3 Vector3::multiply(float left, const Vector3 &right)
{
    Vector3 result;
    result.m_x = left * right.m_x;
    result.m_y = left * right.m_y;
    result.m_z = left * right.m_z;
    return result;
}

Vector3 Vector3::multiply(const Vector3 &left, float right)
{
    Vector3 result;
    result.m_x = left.m_x * right;
    result.m_y = left.m_y * right;
    result.m_z = left.m_z * right;
    return result;
}

Vector3 Vector3::multiply(const Vector3 &left, const Vector3 &right)
{
    Vector3 result;
    result.m_x = left.m_x * right.m_x;
    result.m_y = left.m_y * right.m_y;
    result.m_z = left.m_z * right.m_z;
    return result;
}

Vector3 &Vector3::operator=(const Vector3 &vec3)
{
    m_x = vec3.m_x;
    m_y = vec3.m_y;
    m_z = vec3.m_z;
    return *this;
}

Vector3 &Vector3::operator+=(const Vector3 &vec3)
{
    m_x += vec3.m_x;
    m_y += vec3.m_y;
    m_z += vec3.m_z;
    return *this; 
}

Vector3 &Vector3::operator-=(const Vector3 &vec3)
{
    m_x -= vec3.m_x;
    m_y -= vec3.m_y;
    m_z -= vec3.m_z;
    return *this; 
}

Vector3 &Vector3::operator*=(float factor)
{
    m_x *= factor;
    m_y *= factor;
    m_z *= factor;
    return *this; 
}

Vector3 &Vector3::operator*=(const Vector3 &vec3)
{
    m_x *= vec3.m_x;
    m_y *= vec3.m_y;
    m_z *= vec3.m_z;
    return *this; 
}

Vector3 &Vector3::operator/=(float divisor)
{
    float inverse = 1.0f / divisor;
    m_x *= inverse;
    m_y *= inverse;
    m_z *= inverse;
    return *this;
}

Vector3 &Vector3::operator/=(const Vector3 &vec3)
{
    m_x /= vec3.m_x;
    m_y /= vec3.m_y;
    m_z /= vec3.m_z;
    return *this;
}

bool operator==(const Vector3 &v1, const Vector3 &v2)
{
    return (v1.m_x == v2.m_x &&
            v1.m_y == v2.m_y &&
            v1.m_z == v2.m_z);
}

bool operator!=(const Vector3 &v1, const Vector3 &v2)
{
    return (v1.m_x != v2.m_x ||
            v1.m_y != v2.m_y ||
            v1.m_z != v2.m_z);
}

Vector2 Vector3::toVector2() const
{
    return Vector2(m_x, m_y);
}

Vector4 Vector3::toVector4() const
{
    return Vector4(m_x, m_y, m_z, 1.0f);
}
