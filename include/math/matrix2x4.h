#ifndef MATRIX2x4_H
#define MATRIX2x4_H

class Vector2;
class Vector4;
class Matrix2x2;
class Matrix2x3;
class Matrix4x2;
class Matrix4x3;
class Matrix4x4;

class Matrix2x4
{
public:
    Matrix2x4();
    Matrix2x4(float value);
    explicit Matrix2x4(float arr[2][4]);
    Matrix2x4(float f00, float f01, float f02, float f03,
              float f10, float f11, float f12, float f13);
    Matrix2x4(const Matrix2x4 &mat24);

    Vector4 row(int index) const;
    Vector2 column(int index) const;

    inline float cellValue(int r, int c) const { return m_mat[r][c]; }
    inline void setCellValue(int r, int c, float value) { m_mat[r][c] = value; }
    inline const float *constData() const { return *m_mat; }

    void setRow(int index, const Vector4 &vec4);
    void setColumn(int index, const Vector2 &vec2);
    void fill(float value);

    inline void setToZero() { *this = Matrix2x4::ZERO; }
    inline void inverse() { *this = Matrix2x4::inverse(*this); }

public:    
    static void inverse(const Matrix2x4 &mat24, Matrix2x4 &result);
    static void transpose(const Matrix2x4 &mat24, Matrix4x2 &result);
    
    static void add(const Matrix2x4 &left, const Matrix2x4 &right, Matrix2x4 &result);
    static void subtract(const Matrix2x4 &left, const Matrix2x4 &right, Matrix2x4 &result);
    static void multiply(const Matrix2x4 &left, float right, Matrix2x4 &result);
    static void multiply(float left, const Matrix2x4 &right, Matrix2x4 &result);
    
    static void multiply(const Matrix2x4 &left, const Matrix4x2 &right, Matrix2x2 &result);
    static void multiply(const Matrix2x4 &left, const Matrix4x3 &right, Matrix2x3 &result);
    static void multiply(const Matrix2x4 &left, const Matrix4x4 &right, Matrix2x4 &result);
    
    static void multiply(const Matrix2x4 &left, const Vector4 &right, Vector2 &result);
    static void multiply(const Vector2 &left, const Matrix2x4 &right, Vector4 &result);
    
    static Matrix2x4 inverse(const Matrix2x4 &mat24);
    static Matrix4x2 transpose(const Matrix2x4 &mat24);

    static Matrix2x4 add(const Matrix2x4 &left, const Matrix2x4 &right);
    static Matrix2x4 subtract(const Matrix2x4 &left, const Matrix2x4 &right);
    static Matrix2x4 multiply(const Matrix2x4 &left, float right);
    static Matrix2x4 multiply(float left, const Matrix2x4 &right);
    
    static Matrix2x2 multiply(const Matrix2x4 &left, const Matrix4x2 &right);
    static Matrix2x3 multiply(const Matrix2x4 &left, const Matrix4x3 &right);
    static Matrix2x4 multiply(const Matrix2x4 &left, const Matrix4x4 &right);
    
    static Vector2 multiply(const Matrix2x4 &left, const Vector4 &right);
    static Vector4 multiply(const Vector2 &left, const Matrix2x4 &right);

public:
    inline float *operator[](int row) { return m_mat[row]; }

    Matrix2x4 &operator=(const Matrix2x4 &mat3);

    friend bool operator==(const Matrix2x4 &m1, const Matrix2x4 &m2);
    friend bool operator!=(const Matrix2x4 &m1, const Matrix2x4 &m2);

    inline friend Matrix2x4 operator+(const Matrix2x4 &m1, const Matrix2x4 &m2) { return Matrix2x4::add(m1, m2);}
    inline friend Matrix2x4 operator-(const Matrix2x4 &m1, const Matrix2x4 &m2) { return Matrix2x4::subtract(m1, m2); }
    inline friend Matrix2x4 operator*(float factor, const Matrix2x4 &mat24) { return Matrix2x4::multiply(factor, mat24); }
    inline friend Matrix2x4 operator*(const Matrix2x4 &mat24, float factor) { return Matrix2x4::multiply(mat24, factor); }
    
    friend Matrix2x2 operator*(const Matrix2x4 &m24, const Matrix4x2 &m42);
    friend Matrix2x3 operator*(const Matrix2x4 &m24, const Matrix4x3 &m43);
    friend Matrix2x4 operator*(const Matrix2x4 &m24, const Matrix4x4 &m44);
    
    friend Vector2 operator*(const Matrix2x4 &mat24, const Vector4 &vec4);
    friend Vector4 operator*(const Vector2 &vec2, const Matrix2x4 &mat24);

    static const float EPSILON;
    static const Matrix2x4 ZERO;

    friend class Matrix2x2;
    friend class Matrix2x3;
    friend class Matrix3x2;
    friend class Matrix4x2;

private:
    float m_mat[2][4];
}; // class Matrix2x4


#endif // _MATRIX2X4_H_
