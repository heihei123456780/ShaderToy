#ifndef VECTOR4_H
#define VECTOR4_H

#include "g_math.h"

class Vector2;
class Vector3;

class Vector4
{
public:
    Vector4() 
        : m_x(0.0f), m_y(0.0f), m_z(0.0f), m_w(0.0f) 
    {
    }
    
    Vector4(float x, float y, float z, float w) 
        : m_x(x), m_y(y), m_z(z), m_w(w) 
    {
    }
    
    Vector4(const Vector4 &vec4) 
        : m_x(vec4.m_x), m_y(vec4.m_y), m_z(vec4.m_z), m_w(vec4.m_w) 
    {
    }
    
    explicit Vector4(float arr[4]) 
        : m_x(arr[0]), m_y(arr[1]), m_z(arr[2]), m_w(arr[3]) 
    {
    }

    ~Vector4()
    {
    }

    inline float x() const { return m_x; }
    inline float y() const { return m_y; }
    inline float z() const { return m_z; }
    inline float w() const { return m_w; } 

    inline void setX(float x) { m_x = x; }
    inline void setY(float y) { m_y = y; }
    inline void setZ(float z) { m_z = z; }
    inline void setW(float w) { m_w = w; }

    void inverse();
    void normalize();

    Vector4 inversed() const;
    Vector4 normalized() const;
    
    float length() const { return (float)Math::sqrt(m_x * m_x +  m_y * m_y + m_z * m_z + m_w * m_w); }
    float lengthSquared() const { return (m_x * m_x + m_y * m_y + m_z * m_z + m_w * m_w); }
    
    static float dot(const Vector4 &v1, const Vector4 &v2);
    inline float dotProduct(const Vector4 &vec4) const { return dot(*this, vec4); }

public:
    static Vector4 add(const Vector4 &left, const Vector4 &right);
    static Vector4 subtract(const Vector4 &left, const Vector4 &right);
    static Vector4 multiply(float left, const Vector4 &right);
    static Vector4 multiply(const Vector4 &left, float right);
    static Vector4 multiply(const Vector4 &left, const Vector4 &right);

public:
    inline float &operator[](size_t i) { return *(&m_x + i); }

    Vector4 &operator=(const Vector4 &vec4);
    Vector4 &operator+=(const Vector4 &vec4); 
    Vector4 &operator-=(const Vector4 &vec4); 
    Vector4 &operator*=(float factor);
    Vector4 &operator*=(const Vector4 &vec4); 
    Vector4 &operator/=(float divisor);
    Vector4 &operator/=(const Vector4 &vec4);

    friend bool operator==(const Vector4 &v1, const Vector4 &v2);
    friend bool operator!=(const Vector4 &v1, const Vector4 &v2);

    inline friend Vector4 operator+(const Vector4 &v1, const Vector4 &v2) { return Vector4::add(v1, v2); }
    inline friend Vector4 operator-(const Vector4 &v1, const Vector4 &v2) { return Vector4::subtract(v1, v2); }
    inline friend Vector4 operator*(float factor, const Vector4 &vec4) { return Vector4::multiply(factor, vec4); }
    inline friend Vector4 operator*(const Vector4 &vec4, float factor) { return Vector4::multiply(vec4, factor); }
    inline friend Vector4 operator*(const Vector4 &v1, const Vector4 &v2) { return Vector4::multiply(v1, v2); }
    inline friend Vector4 operator/(const Vector4 &vec4, float divisor) { float inv = 1.0f / divisor; return Vector4::multiply(vec4, inv); }

    Vector2 toVector2() const;
    Vector3 toVector3() const;

    friend class Transform;

private:
    float m_x, m_y, m_z, m_w;
}; // class Vector4

#endif // VECTOR4_H
