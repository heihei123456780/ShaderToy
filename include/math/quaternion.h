#ifndef QUATERNION_H
#define QUATERNION_H

class Vector3;
class Vector4;
class Matrix3x3;
class EulerAngles;

class Quaternion
{
public:
    Quaternion() 
        : m_w(1.0f), m_x(0.0f), m_y(0.0f), m_z(0.0f) 
    {
    }

    Quaternion(float w, float x, float y, float z) 
        : m_w(w), m_x(x), m_y(y), m_z(z) 
    {
    }
    
    Quaternion(float w, const Vector3 &vec3); 
    
    explicit Quaternion(float arr[4]) 
        : m_w(arr[0]), m_x(arr[1]), m_y(arr[2]), m_z(arr[3]) 
    {
    }
    
    explicit Quaternion(const Vector4 &vec4);
        
    Quaternion(const Quaternion &q) 
        : m_w(q.m_w), m_x(q.m_x), m_y(q.m_y), m_z(q.m_z) 
    {
    }

	~Quaternion()
    {
    }

    inline bool isNull() const 
    {
        return m_w == 0.0f && m_x == 0.0f && 
               m_y == 0.0f && m_z == 0.0f;
    }

    inline bool isIdentity() const 
    {
        return m_w == 1.0f && m_x == 0.0f &&
               m_y == 0.0f && m_z == 0.0f;
    }

    inline float x() const { return m_x; }
    inline float y() const { return m_y; }
    inline float z() const { return m_z; }
    inline float scalar() const { return m_w; }

    inline void setX(float x) { m_x = x; }
    inline void setY(float y) { m_y = y; }
    inline void setZ(float z) { m_z = z; }
    inline void setScalar(float scalar) { m_w = scalar; }

    void conjugate();
    void inverse();
    void normalize();
    
    Quaternion inversed() const;
    Quaternion normalized() const;

    inline Quaternion conjugated() const { return Quaternion(m_w, -m_x, -m_y, -m_z); }
    
    static float dot(const Quaternion &q1, const Quaternion &q2);
    inline float dotProduct(const Quaternion &quad) const { return dot(*this, quad); }
    
    Matrix3x3 toRotationMatrix() const;
    EulerAngles toEulerAngles() const;

    static Quaternion fromAxes(const Vector3 &xAxis, const Vector3 &yAxis, const Vector3 &zAxis);
    static Quaternion fromRotationMatrix(const Matrix3x3 &mat3);
    static Quaternion fromAxisAngle(const Vector3 &axis, float angle);
    static Quaternion fromEulerAngles(const EulerAngles &angles);
    static Quaternion fromDirection(const Vector3 &direction, const Vector3 &up);
    static Quaternion rotationTo(const Vector3 &from, const Vector3 &to);

    static Quaternion nlerp(const Quaternion &q1, const Quaternion &q2, float t);
    static Quaternion slerp(const Quaternion &q1, const Quaternion &q2, float t);
    static Quaternion squad(const Quaternion &q1, const Quaternion &q2, float t);

public:
    static Quaternion add(const Quaternion &left, const Quaternion &right);
    static Quaternion subtract(const Quaternion &left, const Quaternion &right);
    static Quaternion multiply(float left, const Quaternion &right);
    static Quaternion multiply(const Quaternion &left, float right);
    static Quaternion multiply(const Quaternion &left, const Quaternion &right);
    
public:
    Quaternion &operator=(const Quaternion &quad);
    Quaternion &operator+=(const Quaternion &quad);
    Quaternion &operator-=(const Quaternion &quad);
    Quaternion &operator*=(float factor);
    Quaternion &operator*=(const Quaternion &quad);
    Quaternion &operator/=(float divisor);


    friend bool operator==(const Quaternion &q1, const Quaternion &q2);
    friend bool operator!=(const Quaternion &q1, const Quaternion &q2);

    friend Quaternion operator+(const Quaternion &q1, const Quaternion &q2) { return add(q1, q2); }
    friend Quaternion operator-(const Quaternion &q1, const Quaternion &q2) { return subtract(q1, q2); }
    friend Quaternion &operator-(Quaternion &quad);
    friend Quaternion operator*(float factor, const Quaternion &quad) { return multiply(factor, quad); }
    friend Quaternion operator*(const Quaternion &quad, float factor) { return multiply(quad, factor); }
    friend Quaternion operator*(const Quaternion &q1, const Quaternion &q2) { return multiply(q1, q2); }
    friend Quaternion operator/(const Quaternion &quad, float divisor) { return multiply(quad, 1.0f / divisor); }

private:
    float m_w, m_x, m_y, m_z;
}; // class of Quaternion

#endif // QUATERNION_H
