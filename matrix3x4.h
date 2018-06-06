#ifndef MATRIX3X4_H
#define MATRIX3X4_H

class Vector3;
class Vector4;
class Matrix3x2;
class Matrix3x3;
class Matrix4x2;
class Matrix4x3;
class Matrix4x4;

class Matrix3x4
{
public:
    Matrix3x4();
    Matrix3x4(float value);
    explicit Matrix3x4(float arr[3][4]);
    Matrix3x4(float f00, float f01, float f02, float f03,
              float f10, float f11, float f12, float f13,
              float f20, float f21, float f22, float f23);    
    Matrix3x4(const Matrix3x4 &mat34);

    ~Matrix3x4()
    {
    }

    Vector3 row(int index) const;
    Vector3 column(int index) const;
    
    inline float cellValue(int r, int c) const { return m_mat[r][c]; }
    inline void setCellValue(int r, int c, float value) { m_mat[r][c] = value; }

    inline const float *constData() const { return *m_mat; }

    void setRow(int index, const Vector4 &vec4);
    void setColumn(int index, const Vector3 &vec4);
    void fill(float value);

    inline void setToZero() { *this = Matrix3x4::ZERO; }
    inline void innverse() { *this = Matrix3x4::inverse(*this); }

    float determinant() const;

public:    
    static void inverse(const Matrix3x4 &mat2, Matrix3x4 &result);
    static void transpose(const Matrix3x4 &mat34, Matrix4x3 &result);
    
    static void add(const Matrix3x4 &left, const Matrix3x4 &right, Matrix3x4 &result);
    static void subtract(const Matrix3x4 &left, const Matrix3x4 &right, Matrix3x4 &result);
    static void multiply(const Matrix3x4 &left, float right, Matrix3x4 &result);
    static void multiply(float left, const Matrix3x4 &right, Matrix3x4 &result);
    
    static void multiply(const Matrix3x4 &left, const Matrix4x2 &right, Matrix3x2 &result);
    static void multiply(const Matrix3x4 &left, const Matrix4x3 &right, Matrix3x3 &result);
    static void multiply(const Matrix3x4 &left, const Matrix4x4 &right, Matrix3x4 &result);
    
    static void multiply(const Matrix3x4 &left, const Vector4 &right, Vector3 &result);
    static void multiply(const Vector3 &left, const Matrix3x4 &right, Vector4 &result);
    
    static Matrix3x4 inverse(const Matrix3x4 &mat2);
    static Matrix4x3 transpose(const Matrix3x4 &mat2);

    static Matrix3x4 add(const Matrix3x4 &left, const Matrix3x4 &right);
    static Matrix3x4 subtract(const Matrix3x4 &left, const Matrix3x4 &right);
    static Matrix3x4 multiply(const Matrix3x4 &left, float right);
    static Matrix3x4 multiply(float left, const Matrix3x4 &right);
    
    static Matrix3x2 multiply(const Matrix3x4 &left, const Matrix4x2 &right);
    static Matrix3x3 multiply(const Matrix3x4 &left, const Matrix4x3 &right);
    static Matrix3x4 multiply(const Matrix3x4 &left, const Matrix4x4 &right);
    
    static Vector3 multiply(const Matrix3x4 &left, const Vector4 &right);
    static Vector4 multiply(const Vector3 &left, const Matrix3x4 &right);

public:
    inline float *operator[](int row) { return m_mat[row]; }
    
    Matrix3x4 &operator=(const Matrix3x4 &mat34);
    
    friend bool operator==(const Matrix3x4 &m1, const Matrix3x4 &m2);
    friend bool operator!=(const Matrix3x4 &m1, const Matrix3x4 &m2);

    inline friend Matrix3x4 operator+(const Matrix3x4 &m1, const Matrix3x4 &m2) { return Matrix3x4::add(m1, m2); }
    inline friend Matrix3x4 operator-(const Matrix3x4 &m1, const Matrix3x4 &m2) { return Matrix3x4::subtract(m1, m2); }
    inline friend Matrix3x4 operator*(float factor, const Matrix3x4 &mat2) { return Matrix3x4::multiply(factor, mat2); }
    inline friend Matrix3x4 operator*(const Matrix3x4 &mat2, float factor) { return Matrix3x4::multiply(mat2, factor); }
    
    friend Matrix3x2 operator*(const Matrix3x4 &m34, const Matrix4x2 &m42);
    friend Matrix3x3 operator*(const Matrix3x4 &m34, const Matrix4x3 &m43);
    friend Matrix3x4 operator*(const Matrix3x4 &m34, const Matrix4x4 &m44);
    
    friend Vector3 operator*(const Matrix3x4 &mat34, const Vector4 &vec4);
    friend Vector4 operator*(const Vector3 &vec3, const Matrix3x4 &mat34);

    static const float EPSILON;
    static const Matrix3x4 ZERO;
    
    friend class Matrix2x3;
    friend class Matrix3x2;
    friend class Matrix3x3;
    friend class Matrix4x3;

private:
    float m_mat[3][4];
}; // class Matrix3x4

#include "matrix3x4.inl"

#endif // _MATRIX3X4_H_
