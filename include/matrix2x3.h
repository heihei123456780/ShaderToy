#ifndef MATRIX2X3_H
#define MATRIX2X3_H

class Vector2;
class Vector3;
class Matrix2x2;
class Matrix2x4;
class Matrix3x2;
class Matrix3x3;
class Matrix3x4;

class Matrix2x3
{
public:
    Matrix2x3();
    Matrix2x3(float value);
    explicit Matrix2x3(float arr[2][3]);
    Matrix2x3(float f00, float f01, float f02,
              float f10, float f11, float f12);
    Matrix2x3(const Matrix2x3 &mat23);

    ~Matrix2x3()
    {
    }

    Vector3 row(int index) const;
    Vector2 column(int index) const;

    inline float cellValue(int r, int c) const { return m_mat[r][c]; }
    inline void setCellValue(int r, int c, float value) { m_mat[r][c] = value; }
    inline const float *constData() const { return *m_mat; }

    void setRow(int index, const Vector3 &vec3);
    void setColumn(int index, const Vector2 &vec2);
    void fill(float value);

    inline void setToZero() { *this = Matrix2x3::ZERO; }
    inline void inverse() { *this = Matrix2x3::inverse(*this); }

public:    
    static void inverse(const Matrix2x3 &mat23, Matrix2x3 &result);
    static void transpose(const Matrix2x3 &mat23, Matrix3x2 &result);
    
    static void add(const Matrix2x3 &left, const Matrix2x3 &right, Matrix2x3 &result);
    static void subtract(const Matrix2x3 &left, const Matrix2x3 &right, Matrix2x3 &result);
    static void multiply(const Matrix2x3 &left, float right, Matrix2x3 &result);
    static void multiply(float left, const Matrix2x3 &right, Matrix2x3 &result);
    
    static void multiply(const Matrix2x3 &left, const Matrix3x2 &right, Matrix2x2 &result);
    static void multiply(const Matrix2x3 &left, const Matrix3x3 &right, Matrix2x3 &result);
    static void multiply(const Matrix2x3 &left, const Matrix3x4 &right, Matrix2x4 &result);
    
    static void multiply(const Matrix2x3 &left, const Vector3 &right, Vector2 &result);
    static void multiply(const Vector2 &left, const Matrix2x3 &right, Vector3 &result);
    
    static Matrix2x3 inverse(const Matrix2x3 &mat23);
    static Matrix3x2 transpose(const Matrix2x3 &mat23);

    static Matrix2x3 add(const Matrix2x3 &left, const Matrix2x3 &right);
    static Matrix2x3 subtract(const Matrix2x3 &left, const Matrix2x3 &right);
    static Matrix2x3 multiply(const Matrix2x3 &left, float right);
    static Matrix2x3 multiply(float left, const Matrix2x3 &right);
    
    static Matrix2x2 multiply(const Matrix2x3 &left, const Matrix3x2 &right);
    static Matrix2x3 multiply(const Matrix2x3 &left, const Matrix3x3 &right);
    static Matrix2x4 multiply(const Matrix2x3 &left, const Matrix3x4 &right);
    
    static Vector2 multiply(const Matrix2x3 &left, const Vector3 &right);
    static Vector3 multiply(const Vector2 &left, const Matrix2x3 &right);

public:
    inline float *operator[](int row) { return m_mat[row]; }

    Matrix2x3 &operator=(const Matrix2x3 &mat3);

    friend bool operator==(const Matrix2x3 &m1, const Matrix2x3 &m2);
    friend bool operator!=(const Matrix2x3 &m1, const Matrix2x3 &m2);

    inline friend Matrix2x3 operator+(const Matrix2x3 &m1, const Matrix2x3 &m2) { return Matrix2x3::add(m1, m2);}
    inline friend Matrix2x3 operator-(const Matrix2x3 &m1, const Matrix2x3 &m2) { return Matrix2x3::subtract(m1, m2); }
    inline friend Matrix2x3 operator*(float factor, const Matrix2x3 &mat23) { return Matrix2x3::multiply(factor, mat23); }
    inline friend Matrix2x3 operator*(const Matrix2x3 &mat23, float factor) { return Matrix2x3::multiply(mat23, factor); }
    
    friend Matrix2x2 operator*(const Matrix2x3 &m23, const Matrix3x2 &m32);
    friend Matrix2x3 operator*(const Matrix2x3 &m23, const Matrix3x3 &m33);
    friend Matrix2x4 operator*(const Matrix2x3 &m23, const Matrix3x4 &m34);
    
    friend Vector2 operator*(const Matrix2x3 &mat23, const Vector3 &vec3);
    friend Vector3 operator*(const Vector2 &vec2, const Matrix2x3 &mat23);

    static const float EPSILON;
    static const Matrix2x3 ZERO;

    friend class Matrix2x2;
    friend class Matrix2x4;
    friend class Matrix3x2;
    friend class Matrix4x2;
    
private:
    float m_mat[2][3];
}; // class Matrix2x3

#endif // _MATRIX2X3_H_
