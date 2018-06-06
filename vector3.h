#ifndef VECTOR3_H
#define VECTOR3_H

#include "g_math.h"

class Vector2;
class Vector4;

class  Vector3
{
public:
    Vector3() 
        : m_x(0.0f), m_y(0.0f), m_z(0.0f) 
    {
    }
    
    Vector3(float x, float y, float z) 
        : m_x(x), m_y(y), m_z(z) 
    {
    }
    
    Vector3(const Vector3 &vec3) 
        : m_x(vec3.m_x), m_y(vec3.m_y), m_z(vec3.m_z) 
    {
    }
    
    explicit Vector3(float arr[3]) 
        : m_x(arr[0]), m_y(arr[1]), m_z(arr[2]) 
    {
    }

    ~Vector3()
    {
    }

    inline float x() const { return m_x; }
    inline float y() const { return m_y; }
    inline float z() const { return m_z; }

    inline void setX(float x) { m_x = x; }
    inline void setY(float y) { m_y = y; }
    inline void setZ(float z) { m_z = z; }

    void inverse();
    void normalize();

    Vector3 inversed() const;
    Vector3 normalized() const;

    float angleBetween(const Vector3 &vec3) const;

    inline float length() const { return (float)Math::sqrt(m_x * m_x +  m_y * m_y + m_z * m_z); }
    inline float lengthSquared() const { return (m_x * m_x + m_y * m_y + m_z * m_z); }

    inline float distance(const Vector3 &vec3) const { return (*this - vec3).length();}
    inline float distanceSquared(const Vector3 &vec3) const { return (*this - vec3).lengthSquared(); }

    static Vector3 cross(const Vector3 &v1, const Vector3 &v2);
    inline Vector3 crossProduct(const Vector3 &vec3) const { return cross(*this, vec3); }
    
    static float dot(const Vector3 &v1, const Vector3 &v2);
    inline float dotProduct(const Vector3 &vec3) const { return dot(*this, vec3); }

    Vector3 midPoint(const Vector3 &vec3) const;
    Vector3 perpendicular(void) const;
    Vector3 reflect(const Vector3 &vec3) const;

public:    
    static Vector3 add(const Vector3 &left, const Vector3 &right);
    static Vector3 subtract(const Vector3 &left, const Vector3 &right);
    static Vector3 multiply(float left, const Vector3 &right);
    static Vector3 multiply(const Vector3 &left, float right);
    static Vector3 multiply(const Vector3 &left, const Vector3 &right);

public:
    inline float &operator[](size_t i) { return *(&m_x + i); }

    Vector3 &operator=(const Vector3 &vec3);
    Vector3 &operator+=(const Vector3 &vec3); 
    Vector3 &operator-=(const Vector3 &vec3); 
    Vector3 &operator*=(float factor); 
    Vector3 &operator*=(const Vector3 &vec3); 
    Vector3 &operator/=(float divisor);
    Vector3 &operator/=(const Vector3 &vec3);
    
    friend bool operator==(const Vector3 &v1, const Vector3 &v2);
    friend bool operator!=(const Vector3 &v1, const Vector3 &v2);

    inline friend Vector3 operator+(const Vector3 &v1, const Vector3 &v2) { return Vector3::add(v1, v2); }
    inline friend Vector3 operator-(const Vector3 &v1, const Vector3 &v2) { return Vector3::subtract(v1, v2); }
    inline friend Vector3 operator*(float factor, const Vector3 &vec3) { return Vector3::multiply(factor, vec3); }
    inline friend Vector3 operator*(const Vector3 &vec3, float factor) { return Vector3::multiply(vec3, factor); }
    inline friend Vector3 operator*(const Vector3 &v1, const Vector3 &v2) { return Vector3::multiply(v1, v2); }
    inline friend Vector3 operator/(const Vector3 &vec3, float divisor) { return Vector3::multiply(vec3, 1.0f / divisor); }

    Vector2 toVector2() const;
    Vector4 toVector4() const;

    friend class Transform;
    
private:
    float m_x, m_y, m_z;
};  // class Vector3

#include "vector3.inl"

#endif // _VECTOR3_H_
