#ifndef VECTOR2_H
#define VECTOR2_H

#include "g_math.h"

class Vector3;
class Vector4;

class Vector2
{
public:
    Vector2() 
        : m_x(0.0f), m_y(0.0f) 
    {
    }

    Vector2(float x, float y) 
        : m_x(x), m_y(y) 
    {
    }
    
    Vector2(const Vector2 &vec2) 
        : Vector2(vec2.m_x, vec2.m_y) 
    {
    }
    
    explicit Vector2(float arr[2]) 
        : m_x(arr[0]), m_y(arr[1]) 
    {
    }

    ~Vector2()
    {
    }
    
    inline float x() const { return m_x; }
    inline float y() const { return m_y; } 
    
    inline void setX(float x) { m_x = x; }
    inline void setY(float y) { m_y = y; }
    
    void inverse();
    void normalize();

    Vector2 inversed() const;
    Vector2 normalized() const;

    float angleBetween(const Vector2 &vec2) const;
    
    inline float length() const { return (float)Math::sqrt(m_x * m_x + m_y * m_y); }
    inline float lengthSquared() const { return (m_x * m_x + m_y * m_y); }
    
    inline float distance(const Vector2 &vec2) const { return (*this - vec2).length(); }
    inline float distancesquared(const Vector2 &vec2) const { return (*this - vec2).lengthSquared(); }

    static float cross(const Vector2 &v1, const Vector2 &v2);
    inline float crossProduct(const Vector2 &vec2) const { return cross(*this, vec2); }

    static float dot(const Vector2 &v1, const Vector2 &v2);
    inline float dotProduct(const Vector2 &vec2) const { return dot(*this, vec2); }

    Vector2 midPoint(const Vector2 &vec2) const;
    Vector2 perpendicular(void) const;
    Vector2 reflect(const Vector2 &vec2) const;

public:    
    static Vector2 add(const Vector2 &left, const Vector2 &right);
    static Vector2 subtract(const Vector2 &left, const Vector2 &right);
    static Vector2 multiply(float left, const Vector2 &right);
    static Vector2 multiply(const Vector2 &left, float right);
    static Vector2 multiply(const Vector2 &left, const Vector2 &right);
    
public:    
    inline float &operator[](size_t i) { return *(&m_x + i); }

    Vector2 &operator=(const Vector2 &vec2);
    Vector2 &operator+=(const Vector2 &vec2);
    Vector2 &operator-=(const Vector2 &vec2);
    Vector2 &operator*=(float factor);
    Vector2 &operator*=(const Vector2 &vec2);
    Vector2 &operator/=(float divisor);
    Vector2 &operator/=(const Vector2 &vec2);

    friend bool operator==(const Vector2 &v1, const Vector2 &v2);
    friend bool operator!=(const Vector2 &v1, const Vector2 &v2);

    inline friend Vector2 operator+(const Vector2 &v1, const Vector2 &v2) { return Vector2::add(v1, v2); }
    inline friend Vector2 operator-(const Vector2 &v1, const Vector2 &v2) { return Vector2::subtract(v1, v2); }
    inline friend Vector2 operator*(float factor, const Vector2 &vec2) { return Vector2::multiply(factor, vec2); }
    inline friend Vector2 operator*(const Vector2 &vec2, float factor) { return Vector2::multiply(vec2, factor); }
    inline friend Vector2 operator*(const Vector2 &v1, const Vector2 &v2) { return Vector2::multiply(v1, v2); }
    inline friend Vector2 operator/(const Vector2 &vec2, float divisor) { return Vector2::multiply(vec2, 1.0f / divisor); }

    Vector3 toVector3() const;
    Vector4 toVector4() const;

    friend class Transform;

private:
    float m_x, m_y;
};  // class Vector2

#include "vector2.h"

#endif // VECTOR2_H
