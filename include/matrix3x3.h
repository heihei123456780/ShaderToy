#ifndef MATRIX3X3_H
#define MATRIX3X3_H

class Vector3;
class Matrix3x2;
class Matrix3x4;

class Matrix3x3
{
public:
    Matrix3x3();
    Matrix3x3(float value);
    explicit Matrix3x3(float arr[3][3]);
    Matrix3x3(float f00, float f01, float f02,
              float f10, float f11, float f12,
              float f20, float f21, float f22);    
    Matrix3x3(const Matrix3x3 &mat3);

    ~Matrix3x3()
    {
    }

    Vector3 row(int index) const;
    Vector3 column(int index) const;
    
    inline float cellValue(int r, int c) const { return m_mat[r][c]; }
    inline void setCellValue(int r, int c, float value) { m_mat[r][c] = value; }

    inline const float *constData() const { return *m_mat; }

    void setRow(int index, const Vector3 &vec3);
    void setColumn(int index, const Vector3 &vec3);
    void fill(float value);

    inline bool isAffine() const;
    inline void fromAxes(const Vector3 &xAxis, const Vector3 &yAxis, const Vector3 &zAxis);

    inline bool isZero() const { return *this == Matrix3x3::ZERO; }
    inline bool isIdentity() const { return *this == Matrix3x3::IDENTITY; }

    inline void setToZero() { *this = Matrix3x3::ZERO; }
    inline void setToIdentity() { *this = Matrix3x3::IDENTITY; }
    
    inline void inverse() { *this = inverse(*this); }
    inline void transpose() { *this = transpose(*this); }

    float determinant() const;

public:    
    static void inverse(const Matrix3x3 &mat2, Matrix3x3 &result);
    static void transpose(const Matrix3x3 &mat2, Matrix3x3 &result);
    
    static void add(const Matrix3x3 &left, const Matrix3x3 &right, Matrix3x3 &result);
    static void subtract(const Matrix3x3 &left, const Matrix3x3 &right, Matrix3x3 &result);
    static void multiply(const Matrix3x3 &left, float right, Matrix3x3 &result);
    static void multiply(float left, const Matrix3x3 &right, Matrix3x3 &result);
    
    static void multiply(const Matrix3x3 &left, const Matrix3x2 &right, Matrix3x2 &result);
    static void multiply(const Matrix3x3 &left, const Matrix3x3 &right, Matrix3x3 &result);
    static void multiply(const Matrix3x3 &left, const Matrix3x4 &right, Matrix3x4 &result);
    
    static void multiply(const Matrix3x3 &left, const Vector3 &right, Vector3 &result);
    static void multiply(const Vector3 &left, const Matrix3x3 &right, Vector3 &result);
    
    static Matrix3x3 inverse(const Matrix3x3 &mat2);
    static Matrix3x3 transpose(const Matrix3x3 &mat2);

    static Matrix3x3 add(const Matrix3x3 &left, const Matrix3x3 &right);
    static Matrix3x3 subtract(const Matrix3x3 &left, const Matrix3x3 &right);
    static Matrix3x3 multiply(const Matrix3x3 &left, float right);
    static Matrix3x3 multiply(float left, const Matrix3x3 &right);
    
    static Matrix3x2 multiply(const Matrix3x3 &left, const Matrix3x2 &right);
    static Matrix3x3 multiply(const Matrix3x3 &left, const Matrix3x3 &right);
    static Matrix3x4 multiply(const Matrix3x3 &left, const Matrix3x4 &right);
    
    static Vector3 multiply(const Matrix3x3 &left, const Vector3 &right);
    static Vector3 multiply(const Vector3 &left, const Matrix3x3 &right);

public:
    inline float *operator[](int row) { return m_mat[row]; }
    
    Matrix3x3 &operator=(const Matrix3x3 &mat3);
    
    friend bool operator==(const Matrix3x3 &m1, const Matrix3x3 &m2);
    friend bool operator!=(const Matrix3x3 &m1, const Matrix3x3 &m2);

    inline friend Matrix3x3 operator+(const Matrix3x3 &m1, const Matrix3x3 &m2) { return Matrix3x3::add(m1, m2); }
    inline friend Matrix3x3 operator-(const Matrix3x3 &m1, const Matrix3x3 &m2) { return Matrix3x3::subtract(m1, m2); }
    inline friend Matrix3x3 operator*(float factor, const Matrix3x3 &mat2) { return Matrix3x3::multiply(factor, mat2); }
    inline friend Matrix3x3 operator*(const Matrix3x3 &mat2, float factor) { return Matrix3x3::multiply(mat2, factor); }
    inline friend Matrix3x3 operator*(const Matrix3x3 &m1, const Matrix3x3 &m2) { return Matrix3x3::multiply(m1, m2); }

    friend Matrix3x2 operator*(const Matrix3x3 &m33, const Matrix3x2 &m34);
    friend Matrix3x4 operator*(const Matrix3x3 &m43, const Matrix3x4 &m33);
    
    friend Vector3 operator*(const Matrix3x3 &mat3, const Vector3 &vec3);
    friend Vector3 operator*(const Vector3 &vec3, const Matrix3x3 &mat3);

    static const float EPSILON;
    static const Matrix3x3 ZERO;
    static const Matrix3x3 IDENTITY;

    friend class Matrix2x3;
    friend class Matrix3x2;
    friend class Matrix3x4;
    friend class Matrix4x3;
    friend class Transform;
    friend class Quaternion;
    
private:
    float m_mat[3][3];
}; // class Matrix3x3


#endif // MATRIX3X3_H
