#ifndef MATRIX4X2_H
#define MATRIX4X2_H

class Vector2;
class Vector4;
class Matrix2x2;
class Matrix2x3;
class Matrix2x4;
class Matrix4x3;
class Matrix4x4;

class Matrix4x2
{
public:
    Matrix4x2();
    Matrix4x2(float value);
    explicit Matrix4x2(float arr[4][2]);
    Matrix4x2(float f00, float f01,
              float f10, float f11,
              float f20, float f21,
              float f30, float f31);    
    Matrix4x2(const Matrix4x2 &mat42);

    ~Matrix4x2()
    {
    }

    Vector2 row(int index) const;
    Vector4 column(int index) const;
    
    inline float cellValue(int r, int c) const { return m_mat[r][c]; }
    inline void setCellValue(int r, int c, float value) { m_mat[r][c] = value; }

    inline const float *constData() const { return *m_mat; }

    void setRow(int index, const Vector2 &vec2);
    void setColumn(int index, const Vector4 &vec2);
    void fill(float value);

    inline void setToZero() { *this = Matrix4x2::ZERO; }
    inline void inverse() { *this = Matrix4x2::inverse(*this); }

    float determinant() const;
    
public:    
    static void inverse(const Matrix4x2 &mat2, Matrix4x2 &result);
    static void transpose(const Matrix4x2 &mat2, Matrix2x4 &result);
    
    static void add(const Matrix4x2 &left, const Matrix4x2 &right, Matrix4x2 &result);
    static void subtract(const Matrix4x2 &left, const Matrix4x2 &right, Matrix4x2 &result);
    static void multiply(const Matrix4x2 &left, float right, Matrix4x2 &result);
    static void multiply(float left, const Matrix4x2 &right, Matrix4x2 &result);
    
    static void multiply(const Matrix4x2 &left, const Matrix2x2 &right, Matrix4x2 &result);
    static void multiply(const Matrix4x2 &left, const Matrix2x3 &right, Matrix4x3 &result);
    static void multiply(const Matrix4x2 &left, const Matrix2x4 &right, Matrix4x4 &result);
    
    static void multiply(const Matrix4x2 &left, const Vector2 &right, Vector4 &result);
    static void multiply(const Vector4 &left, const Matrix4x2 &right, Vector2 &result);
    
    static Matrix4x2 inverse(const Matrix4x2 &mat2);
    static Matrix2x4 transpose(const Matrix4x2 &mat2);

    static Matrix4x2 add(const Matrix4x2 &left, const Matrix4x2 &right);
    static Matrix4x2 subtract(const Matrix4x2 &left, const Matrix4x2 &right);
    static Matrix4x2 multiply(const Matrix4x2 &left, float right);
    static Matrix4x2 multiply(float left, const Matrix4x2 &right);
    
    static Matrix4x2 multiply(const Matrix4x2 &left, const Matrix2x2 &right);
    static Matrix4x3 multiply(const Matrix4x2 &left, const Matrix2x3 &right);
    static Matrix4x4 multiply(const Matrix4x2 &left, const Matrix2x4 &right);
    
    static Vector4 multiply(const Matrix4x2 &left, const Vector2 &right);
    static Vector2 multiply(const Vector4 &left, const Matrix4x2 &right);

public:
    inline float *operator[](int row) { return m_mat[row]; }
    
    Matrix4x2 &operator=(const Matrix4x2 &mat42);
    
    friend bool operator==(const Matrix4x2 &m1, const Matrix4x2 &m2);
    friend bool operator!=(const Matrix4x2 &m1, const Matrix4x2 &m2);

    inline friend Matrix4x2 operator+(const Matrix4x2 &m1, const Matrix4x2 &m2) { return Matrix4x2::add(m1, m2); }
    inline friend Matrix4x2 operator-(const Matrix4x2 &m1, const Matrix4x2 &m2) { return Matrix4x2::subtract(m1, m2); }
    inline friend Matrix4x2 operator*(float factor, const Matrix4x2 &mat2) { return Matrix4x2::multiply(factor, mat2); }
    inline friend Matrix4x2 operator*(const Matrix4x2 &mat2, float factor) { return Matrix4x2::multiply(mat2, factor); }

    friend Matrix4x2 operator*(const Matrix4x2 &m42, const Matrix2x2 &m22);
    friend Matrix4x3 operator*(const Matrix4x2 &m42, const Matrix2x3 &m23);
    friend Matrix4x4 operator*(const Matrix4x2 &m42, const Matrix2x4 &m24);
    
    friend Vector4 operator*(const Matrix4x2 &mat42, const Vector2 &vec2);
    friend Vector2 operator*(const Vector4 &vec4, const Matrix4x2 &mat42);

    static const float EPSILON;
    static const Matrix4x2 ZERO;
    
    friend class Matrix2x4;
    friend class Matrix3x4;
    friend class Matrix4x3;
    friend class Matrix4x4;
    
private:
    float m_mat[4][2];
}; // class Matrix4x2

#include "matrix4x2.inl"

#endif // _MATRIX4X2_H_
