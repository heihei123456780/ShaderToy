#ifndef MATRIX4X3_H
#define MATRIX4X3_H

class Vector3;
class Vector4;
class Matrix2x3;
class Matrix3x2;
class Matrix3x3;
class Matrix3x4;
class Matrix4x2;
class Matrix4x4;

class Matrix4x3
{
public:
    Matrix4x3();
    Matrix4x3(float value);
    explicit Matrix4x3(float arr[4][3]);
    Matrix4x3(float f00, float f01, float f02,
              float f10, float f11, float f12,
              float f20, float f21, float f22,
              float f30, float f31, float f32);
    Matrix4x3(const Matrix4x3 &mat43);

    ~Matrix4x3()
    {
    }

    Vector3 row(int index) const;
    Vector4 column(int index) const;
    
    inline float cellValue(int r, int c) const { return m_mat[r][c]; }
    inline void setCellValue(int r, int c, float value) { m_mat[r][c] = value; }
    inline const float *constData() const { return *m_mat; }

    void setRow(int index, const Vector3 &vec3);
    void setColumn(int index, const Vector4 &vec4);
    void fill(float value);

    inline void setToZero() { *this = Matrix4x3::ZERO; }
    inline void inverse() { *this = Matrix4x3::inverse(*this); }
    
    float determinant() const;
    
public:    
    static void inverse(const Matrix4x3 &mat43, Matrix4x3 &result);
    static void transpose(const Matrix4x3 &mat43, Matrix3x4 &result);
    
    static void add(const Matrix4x3 &left, const Matrix4x3 &right, Matrix4x3 &result);
    static void subtract(const Matrix4x3 &left, const Matrix4x3 &right, Matrix4x3 &result);
    static void multiply(const Matrix4x3 &left, float right, Matrix4x3 &result);
    static void multiply(float left, const Matrix4x3 &right, Matrix4x3 &result);
    
    static void multiply(const Matrix4x3 &left, const Matrix3x2 &right, Matrix4x2 &result);
    static void multiply(const Matrix4x3 &left, const Matrix3x3 &right, Matrix4x3 &result);
    static void multiply(const Matrix4x3 &left, const Matrix3x4 &right, Matrix4x4 &result);
    
    static void multiply(const Matrix4x3 &left, const Vector3 &right, Vector4 &result);
    static void multiply(const Vector4 &left, const Matrix4x3 &right, Vector3 &result);

    static Matrix4x3 inverse(const Matrix4x3 &mat43);
    static Matrix3x4 transpose(const Matrix4x3 &mat43);

    static Matrix4x3 add(const Matrix4x3 &left, const Matrix4x3 &right);
    static Matrix4x3 subtract(const Matrix4x3 &left, const Matrix4x3 &right);
    static Matrix4x3 multiply(const Matrix4x3 &left, float right);
    static Matrix4x3 multiply(float left, const Matrix4x3 &right);

    static Matrix4x2 multiply(const Matrix4x3 &left, const Matrix3x2 &right);
    static Matrix4x3 multiply(const Matrix4x3 &left, const Matrix3x3 &right);
    static Matrix4x4 multiply(const Matrix4x3 &left, const Matrix3x4 &right);
    
    static Vector4 multiply(const Matrix4x3 &left, const Vector3 &right);
    static Vector3 multiply(const Vector4 &left, const Matrix4x3 &right);

public:
    inline float *operator[](int row) { return m_mat[row]; }
    
    Matrix4x3 &operator=(const Matrix4x3 &mat3);
    
    friend bool operator==(const Matrix4x3 &m1, const Matrix4x3 &m2);
    friend bool operator!=(const Matrix4x3 &m1, const Matrix4x3 &m2);

    inline friend Matrix4x3 operator+(const Matrix4x3 &m1, const Matrix4x3 &m2) { return Matrix4x3::add(m1, m2); }
    inline friend Matrix4x3 operator-(const Matrix4x3 &m1, const Matrix4x3 &m2) { return Matrix4x3::subtract(m1, m2); }
    inline friend Matrix4x3 operator*(float factor, const Matrix4x3 &mat43) { return Matrix4x3::multiply(factor, mat43); }
    inline friend Matrix4x3 operator*(const Matrix4x3 &mat43, float factor) { return Matrix4x3::multiply(mat43, factor); }
    
    friend Matrix4x2 operator*(const Matrix4x3 &m43, const Matrix3x2 &m32);
    friend Matrix4x3 operator*(const Matrix4x3 &m43, const Matrix3x3 &m33);
    friend Matrix4x4 operator*(const Matrix4x3 &m43, const Matrix3x4 &m34);
    
    friend Vector4 operator*(const Matrix4x3 &mat43, const Vector3 &vec3);
    friend Vector3 operator*(const Vector4 &vec4, const Matrix4x3 &mat43);

    static const float EPSILON;
    static const Matrix4x3 ZERO;

    friend class Matrix2x4;
    friend class Matrix3x4;
    friend class Matrix4x2;
    friend class Matrix4x4;

private:
    float m_mat[4][3];
}; // class Matrix4x3

#endif // _MATRIX4X3_H_
