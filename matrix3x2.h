#ifndef MATRIx3x2_H
#define MATRIx3x2_H

class Vector2;
class Vector3;
class Matrix2x2;
class Matrix2x3;
class Matrix2x4;
class Matrix3x3;
class Matrix3x4;

class Matrix3x2
{
public:
    Matrix3x2();
    Matrix3x2(float value);
    explicit Matrix3x2(float arr[3][2]);
    Matrix3x2(float f00, float f01,
              float f10, float f11,
              float f20, float f21);
    Matrix3x2(const Matrix3x2 &mat32);

    ~Matrix3x2()
    {
    }

    Vector2 row(int index) const;
    Vector3 column(int index) const;

    inline float cellValue(int r, int c) const { return m_mat[r][c]; }
    inline void setCellValue(int r, int c, float value) { m_mat[r][c] = value; }
    
    inline const float *constData() const { return *m_mat; }

    void setRow(int index, const Vector2 &vec2);
    void setColumn(int index, const Vector3 &vec3);
    void fill(float value);

    inline void setToZero() { *this = Matrix3x2::ZERO; }
    inline void inverse() { *this = Matrix3x2::inverse(*this); }

public:    
    static void inverse(const Matrix3x2 &mat32, Matrix3x2 &result);
    static void transpose(const Matrix3x2 &mat32, Matrix2x3 &result);
    
    static void add(const Matrix3x2 &left, const Matrix3x2 &right, Matrix3x2 &result);
    static void subtract(const Matrix3x2 &left, const Matrix3x2 &right, Matrix3x2 &result);
    static void multiply(const Matrix3x2 &left, float right, Matrix3x2 &result);
    static void multiply(float left, const Matrix3x2 &right, Matrix3x2 &result);
    
    static void multiply(const Matrix3x2 &left, const Matrix2x2 &right, Matrix3x2 &result);
    static void multiply(const Matrix3x2 &left, const Matrix2x3 &right, Matrix3x3 &result);
    static void multiply(const Matrix3x2 &left, const Matrix2x4 &right, Matrix3x4 &result);
    
    static void multiply(const Matrix3x2 &left, const Vector2 &right, Vector3 &result);
    static void multiply(const Vector3 &left, const Matrix3x2 &right, Vector2 &result);
    
    static Matrix3x2 inverse(const Matrix3x2 &mat32);
    static Matrix2x3 transpose(const Matrix3x2 &mat32);

    static Matrix3x2 add(const Matrix3x2 &left, const Matrix3x2 &right);
    static Matrix3x2 subtract(const Matrix3x2 &left, const Matrix3x2 &right);
    static Matrix3x2 multiply(const Matrix3x2 &left, float right);
    static Matrix3x2 multiply(float left, const Matrix3x2 &right);
    
    static Matrix3x2 multiply(const Matrix3x2 &left, const Matrix2x2 &right);
    static Matrix3x3 multiply(const Matrix3x2 &left, const Matrix2x3 &right);
    static Matrix3x4 multiply(const Matrix3x2 &left, const Matrix2x4 &right);
    
    static Vector3 multiply(const Matrix3x2 &left, const Vector2 &right);
    static Vector2 multiply(const Vector3 &left, const Matrix3x2 &right);

public:
    inline float *operator[](int row) { return m_mat[row]; }

    Matrix3x2 &operator=(const Matrix3x2 &mat3);

    friend bool operator==(const Matrix3x2 &m1, const Matrix3x2 &m2);
    friend bool operator!=(const Matrix3x2 &m1, const Matrix3x2 &m2);

    inline friend Matrix3x2 operator+(const Matrix3x2 &m1, const Matrix3x2 &m2) { return Matrix3x2::add(m1, m2);}
    inline friend Matrix3x2 operator-(const Matrix3x2 &m1, const Matrix3x2 &m2) { return Matrix3x2::subtract(m1, m2); }
    inline friend Matrix3x2 operator*(float factor, const Matrix3x2 &mat32) { return Matrix3x2::multiply(factor, mat32); }
    inline friend Matrix3x2 operator*(const Matrix3x2 &mat32, float factor) { return Matrix3x2::multiply(mat32, factor); }
    
    friend Matrix3x2 operator*(const Matrix3x2 &m32, const Matrix2x2 &m22);
    friend Matrix3x3 operator*(const Matrix3x2 &m32, const Matrix2x3 &m23);
    friend Matrix3x4 operator*(const Matrix3x2 &m32, const Matrix2x4 &m24); 
    
    friend Vector2 operator*(const Matrix3x2 &mat32, const Vector3 &vec3);
    friend Vector3 operator*(const Vector2 &vec2, const Matrix3x2 &mat32);

    static const float EPSILON;
    static const Matrix3x2 ZERO;

    friend class Matrix2x3;
    friend class Matrix3x3;
    friend class Matrix3x4;
    friend class Matrix4x3;
    
private:
    float m_mat[3][2];
}; // class Matrix3x2

#include "matrix3x2.inl"

#endif // MATRIx3x3_H
