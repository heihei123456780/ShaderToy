#ifndef MATRIX4X4_H
#define MATRIX4X4_H

class Vector4;
class Matrix4x2;
class Matrix4x3;

class Matrix4x4
{
public:
    Matrix4x4();
    Matrix4x4(float value);
    explicit Matrix4x4(float arr[4][4]);
    Matrix4x4(float f00, float f01, float f02, float f03,
              float f10, float f11, float f12, float f13,
              float f20, float f21, float f22, float f23,
              float f30, float f31, float f32, float f33);
    Matrix4x4(const Matrix4x4 &mat4);

    ~Matrix4x4()
    {
    }

    Vector4 row(int index) const;
    Vector4 column(int index) const;
    
    inline float cellValue(int r, int c) const { return m_mat[r][c]; }
    inline void setCellValue(int r, int c, float value) { m_mat[r][c] = value; }
    inline const float *constData() const { return *m_mat; }

    void setRow(int index, const Vector4 &vec4);
    void setColumn(int index, const Vector4 &vec4);

    inline bool isAffine() const;
    inline void fromAxes(const Vector4 &xAxis, const Vector4 &yAxis,
                         const Vector4 &zAxis, const Vector4 &wAxis);

    inline bool isZero() const { return *this == Matrix4x4::ZERO; }
    inline bool isIdentity() const { return *this == Matrix4x4::IDENTITY; }
    
    inline void setToZero() { *this = Matrix4x4::ZERO; }
    inline void setToIdentity() { *this = Matrix4x4::IDENTITY; }
    void fill(float value);

    inline void inverse() { *this = Matrix4x4::inverse(*this); }
    inline void transpose() { *this = Matrix4x4::transpose(*this); }
    
    float determinant() const;
    
public:    
    static void inverse(const Matrix4x4 &mat2, Matrix4x4 &result);
    static void transpose(const Matrix4x4 &mat2, Matrix4x4 &result);
    
    static void add(const Matrix4x4 &left, const Matrix4x4 &right, Matrix4x4 &result);
    static void subtract(const Matrix4x4 &left, const Matrix4x4 &right, Matrix4x4 &result);
    static void multiply(const Matrix4x4 &left, float right, Matrix4x4 &result);
    static void multiply(float left, const Matrix4x4 &right, Matrix4x4 &result);
    
    static void multiply(const Matrix4x4 &left, const Matrix4x2 &right, Matrix4x2 &result);
    static void multiply(const Matrix4x4 &left, const Matrix4x3 &right, Matrix4x3 &result);
    static void multiply(const Matrix4x4 &left, const Matrix4x4 &right, Matrix4x4 &result);

    static void multiply(const Matrix4x4 &left, const Vector4 &right, Vector4 &result);
    static void multiply(const Vector4 &left, const Matrix4x4 &right, Vector4 &result);

    static Matrix4x4 inverse(const Matrix4x4 &mat2);
    static Matrix4x4 transpose(const Matrix4x4 &mat2);

    static Matrix4x4 add(const Matrix4x4 &left, const Matrix4x4 &right);
    static Matrix4x4 subtract(const Matrix4x4 &left, const Matrix4x4 &right);
    static Matrix4x4 multiply(const Matrix4x4 &left, float right);
    static Matrix4x4 multiply(float left, const Matrix4x4 &right);
    
    static Matrix4x2 multiply(const Matrix4x4 &left, const Matrix4x2 &right);
    static Matrix4x3 multiply(const Matrix4x4 &left, const Matrix4x3 &right);
    static Matrix4x4 multiply(const Matrix4x4 &left, const Matrix4x4 &right);
    
    static Vector4 multiply(const Matrix4x4 &left, const Vector4 &right);
    static Vector4 multiply(const Vector4 &left, const Matrix4x4 &right);

public:
    inline float *operator[](int row) { return m_mat[row]; }
    
    Matrix4x4 &operator=(const Matrix4x4 &mat3);
    
    friend bool operator==(const Matrix4x4 &m1, const Matrix4x4 &m2);
    friend bool operator!=(const Matrix4x4 &m1, const Matrix4x4 &m2);

    inline friend Matrix4x4 operator+(const Matrix4x4 &m1, const Matrix4x4 &m2) { return Matrix4x4::add(m1, m2); }
    inline friend Matrix4x4 operator-(const Matrix4x4 &m1, const Matrix4x4 &m2) { return Matrix4x4::subtract(m1, m2); }
    inline friend Matrix4x4 operator*(float factor, const Matrix4x4 &mat2) { return Matrix4x4::multiply(factor, mat2); }
    inline friend Matrix4x4 operator*(const Matrix4x4 &mat2, float factor) { return Matrix4x4::multiply(mat2, factor); }
    inline friend Matrix4x4 operator*(const Matrix4x4 &m1, const Matrix4x4 &m2) { return Matrix4x4::multiply(m1, m2); }

    friend Matrix4x2 operator*(const Matrix4x4 &m44, const Matrix4x2 &m42);
    friend Matrix4x3 operator*(const Matrix4x4 &m44, const Matrix4x3 &m43);
    
    friend Vector4 operator*(const Matrix4x4 &mat4, const Vector4 &vec4);
    friend Vector4 operator*(const Vector4 &vec4, const Matrix4x4 &mat4);

    static const float EPSILON;
    static const Matrix4x4 ZERO;
    static const Matrix4x4 IDENTITY;

    friend class Matrix2x4;
    friend class Matrix3x4;
    friend class Matrix4x2;
    friend class Matrix4x3;
    friend class Transform;

private:
    float m_mat[4][4];
}; // class Matrix4x4

#endif // _MATRIX4X4_H_
