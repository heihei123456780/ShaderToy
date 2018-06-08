#ifndef MATRIX2X2_H
#define MATRIX2X2_H

class Vector2;
class Matrix2x3;
class Matrix2x4;

class Matrix2x2
{
public:
    Matrix2x2();
    Matrix2x2(float value);
    explicit Matrix2x2(float arr[2][2]);
    Matrix2x2(float f00, float f01,
              float f10, float f11);
    Matrix2x2(const Matrix2x2 &mat2);

    ~Matrix2x2()
    {
    }

    Vector2 row(int index) const;
    Vector2 column(int index) const;
    
    inline float cellValue(int r, int c) const { return m_mat[r][c]; }
    inline void setCellValue(int r, int c, float value) { m_mat[r][c] = value; }
    inline const float *constData() const { return *m_mat; }

    void setRow(int index, const Vector2 &vec3);
    void setColumn(int index, const Vector2 &vec3);
    void fill(float value);

    bool isAffine() const;
    void fromAxes(const Vector2 &xAxis, const Vector2 &yAxis);

    inline bool isZero() const { return *this == Matrix2x2::ZERO; }
    inline bool isIdentity() const { return *this == Matrix2x2::IDENTITY; }
    
    inline void setToZero() { *this = Matrix2x2::ZERO; }
    inline void setToIdentity() { *this = Matrix2x2::IDENTITY; }
    
    inline void inverse() { *this = Matrix2x2::inverse(*this); }
    inline void transpose() { *this = Matrix2x2::transpose(*this); }
    
    float determinant() const;

public:    
    static void inverse(const Matrix2x2 &mat2, Matrix2x2 &result);
    static void transpose(const Matrix2x2 &mat2, Matrix2x2 &result);
    
    static void add(const Matrix2x2 &left, const Matrix2x2 &right, Matrix2x2 &result);
    static void subtract(const Matrix2x2 &left, const Matrix2x2 &right, Matrix2x2 &result);
    static void multiply(const Matrix2x2 &left, float right, Matrix2x2 &result);
    static void multiply(float left, const Matrix2x2 &right, Matrix2x2 &result);
    
    static void multiply(const Matrix2x2 &left, const Matrix2x2 &right, Matrix2x2 &result);
    static void multiply(const Matrix2x2 &left, const Matrix2x3 &right, Matrix2x3 &result);
    static void multiply(const Matrix2x2 &left, const Matrix2x4 &right, Matrix2x4 &result);
    
    static void multiply(const Matrix2x2 &left, const Vector2 &right, Vector2 &result);
    static void multiply(const Vector2 &left, const Matrix2x2 &right, Vector2 &result);
    
    static Matrix2x2 inverse(const Matrix2x2 &mat2);
    static Matrix2x2 transpose(const Matrix2x2 &mat2);

    static Matrix2x2 add(const Matrix2x2 &left, const Matrix2x2 &right);
    static Matrix2x2 subtract(const Matrix2x2 &left, const Matrix2x2 &right);
    static Matrix2x2 multiply(const Matrix2x2 &left, float right);
    static Matrix2x2 multiply(float left, const Matrix2x2 &right);

    static Matrix2x2 multiply(const Matrix2x2 &left, const Matrix2x2 &right);
    static Matrix2x3 multiply(const Matrix2x2 &left, const Matrix2x3 &right);
    static Matrix2x4 multiply(const Matrix2x2 &left, const Matrix2x4 &right);
    
    static Vector2 multiply(const Matrix2x2 &left, const Vector2 &right);
    static Vector2 multiply(const Vector2 &left, const Matrix2x2 &right);

public:
    inline float *operator[](int row) { return m_mat[row]; }

    Matrix2x2 &operator=(const Matrix2x2 &mat3);

    friend bool operator==(const Matrix2x2 &m1, const Matrix2x2 &m2);
    friend bool operator!=(const Matrix2x2 &m1, const Matrix2x2 &m2);

    inline friend Matrix2x2 operator+(const Matrix2x2 &m1, const Matrix2x2 &m2) { return Matrix2x2::add(m1, m2);}
    inline friend Matrix2x2 operator-(const Matrix2x2 &m1, const Matrix2x2 &m2) { return Matrix2x2::subtract(m1, m2); }
    inline friend Matrix2x2 operator*(float factor, const Matrix2x2 &mat2) { return Matrix2x2::multiply(factor, mat2); }
    inline friend Matrix2x2 operator*(const Matrix2x2 &mat2, float factor) { return Matrix2x2::multiply(mat2, factor); }
    inline friend Matrix2x2 operator*(const Matrix2x2 &m1, const Matrix2x2 &m2) { return Matrix2x2::multiply(m1, m2); }
    
    friend Matrix2x3 operator*(const Matrix2x2 &m22, const Matrix2x3 &m23);
    friend Matrix2x4 operator*(const Matrix2x2 &m22, const Matrix2x4 &m24);

    friend Vector2 operator*(const Matrix2x2 &mat2, const Vector2 &vec2);
    friend Vector2 operator*(const Vector2 &vec2, const Matrix2x2 &mat2);

    static const float EPSILON;
    static const Matrix2x2 ZERO;
    static const Matrix2x2 IDENTITY;

    friend class Matrix2x3;
    friend class Matrix2x4;
    friend class Matrix3x2;
    friend class Matrix4x2;
    
private:
    float m_mat[2][2];
}; // class Matrix2x2

#endif // MATRIX2X2_H
