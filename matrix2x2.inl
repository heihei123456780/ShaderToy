#include "vector2.h"
#include "matrix2x3.h"
#include "matrix2x4.h"

const Matrix2x2 Matrix2x2::ZERO     (0.0f, 0.0f,
                                     0.0f, 0.0f);
                                     
const Matrix2x2 Matrix2x2::IDENTITY (1.0f, 0.0f,
                                     0.0f, 1.0f);

inline Matrix2x2::Matrix2x2()
{
    m_mat[0][0] = 0.0f;
    m_mat[0][1] = 0.0f;
    m_mat[1][0] = 0.0f;
    m_mat[1][1] = 0.0f;
}

inline Matrix2x2::Matrix2x2(float value)
{
    m_mat[0][0] = value;
    m_mat[0][1] = value;
    m_mat[1][0] = value;
    m_mat[1][1] = value;
}

inline Matrix2x2::Matrix2x2(float arr[2][2])
{
    m_mat[0][0] = arr[0][0];
    m_mat[0][1] = arr[0][1];
    m_mat[1][0] = arr[1][0];
    m_mat[1][1] = arr[1][1];
}

inline Matrix2x2::Matrix2x2(float f00, float f01,
                            float f10, float f11)
{
    m_mat[0][0] = f00;
    m_mat[0][1] = f01;
    m_mat[1][0] = f10;
    m_mat[1][1] = f11;
}

inline Matrix2x2::Matrix2x2(const Matrix2x2 &mat2)
{
    m_mat[0][0] = mat2.m_mat[0][0];
    m_mat[0][1] = mat2.m_mat[0][1];
    m_mat[1][0] = mat2.m_mat[1][0];
    m_mat[1][1] = mat2.m_mat[1][1];
}

inline Vector2 Matrix2x2::row(int index) const
{
    return Vector2(m_mat[0][index],
                   m_mat[1][index]);
}

inline Vector2 Matrix2x2::column(int index) const
{
    return Vector2(m_mat[index][0],
                   m_mat[index][1]);
}

inline void Matrix2x2::setColumn(int index, const Vector2 &vec3)
{
    m_mat[0][index] = vec3.x();
    m_mat[1][index] = vec3.y();
}

inline void Matrix2x2::setRow(int index, const Vector2 &vec3)
{
    m_mat[index][0] = vec3.x();
    m_mat[index][1] = vec3.y();
}

inline void Matrix2x2::fill(float value)
{
    m_mat[0][0] = value;
    m_mat[0][1] = value;
    m_mat[1][0] = value;
    m_mat[1][1] = value;
}

inline bool Matrix2x2::isAffine() const
{
    return (m_mat[0][0] == 1.0f &&
            m_mat[1][1] == 1.0f);
}

inline void Matrix2x2::fromAxes(const Vector2 &xAxis, const Vector2 &yAxis)
{
    setColumn(0, xAxis);
    setColumn(1, yAxis);
}

inline float Matrix2x2::determinant() const
{
    return (m_mat[0][0] * m_mat[1][1] - 
            m_mat[0][1] * m_mat[1][0]);
}

inline void Matrix2x2::inverse(const Matrix2x2 &mat2, Matrix2x2 &result)
{
    double det = mat2.determinant();

    if (det == 0.0f)
        return;
    
    double invDet = 1.0f / det;
    result.m_mat[0][0] = mat2.m_mat[0][0] * invDet;
    result.m_mat[0][1] = mat2.m_mat[0][1] * invDet;
    result.m_mat[1][0] = mat2.m_mat[1][0] * invDet;
    result.m_mat[1][1] = mat2.m_mat[1][1] * invDet;
}

inline void Matrix2x2::transpose(const Matrix2x2 &mat2, Matrix2x2 &result)
{
    result.m_mat[0][0] = mat2.m_mat[0][0];
    result.m_mat[0][1] = mat2.m_mat[1][0];
    result.m_mat[1][0] = mat2.m_mat[0][1];
    result.m_mat[1][1] = mat2.m_mat[1][1];
}

inline void Matrix2x2::add(const Matrix2x2 &left, const Matrix2x2 &right, Matrix2x2 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] + right.m_mat[0][0];
    result.m_mat[0][1] = left.m_mat[0][1] + right.m_mat[0][1];
    result.m_mat[1][0] = left.m_mat[1][0] + right.m_mat[1][0];
    result.m_mat[0][1] = left.m_mat[1][1] + right.m_mat[1][1];
}

inline void Matrix2x2::subtract(const Matrix2x2 &left, const Matrix2x2 &right, Matrix2x2 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] - right.m_mat[0][0];
    result.m_mat[0][1] = left.m_mat[0][1] - right.m_mat[0][1];
    result.m_mat[1][0] = left.m_mat[1][0] - right.m_mat[1][0];
    result.m_mat[0][1] = left.m_mat[1][1] - right.m_mat[1][1];
}

inline void Matrix2x2::multiply(const Matrix2x2 &left, float right, Matrix2x2 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] * right;
    result.m_mat[0][1] = left.m_mat[0][1] * right;
    result.m_mat[1][0] = left.m_mat[1][0] * right;
    result.m_mat[0][1] = left.m_mat[1][1] * right;
}

inline void Matrix2x2::multiply(float left, const Matrix2x2 &right, Matrix2x2 &result)
{
    result.m_mat[0][0] = left * right.m_mat[0][0];
    result.m_mat[0][1] = left * right.m_mat[0][1];
    result.m_mat[1][0] = left * right.m_mat[1][0];
    result.m_mat[0][1] = left * right.m_mat[1][1];
}

inline void Matrix2x2::multiply(const Matrix2x2 &left, const Matrix2x2 &right, Matrix2x2 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] * right.m_mat[0][0] + left.m_mat[0][1] * right.m_mat[1][0];
    result.m_mat[0][1] = left.m_mat[0][0] * right.m_mat[0][1] + left.m_mat[0][1] * right.m_mat[1][1];
    result.m_mat[1][0] = left.m_mat[1][0] * right.m_mat[0][0] + left.m_mat[1][1] * right.m_mat[1][0];
    result.m_mat[0][1] = left.m_mat[1][0] * right.m_mat[0][1] + left.m_mat[1][1] * right.m_mat[1][1];
}

inline void Matrix2x2::multiply(const Matrix2x2 &left, const Matrix2x3 &right, Matrix2x3 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] * right.m_mat[0][0] + left.m_mat[0][1] * right.m_mat[1][0];
    result.m_mat[0][1] = left.m_mat[0][0] * right.m_mat[0][1] + left.m_mat[0][1] * right.m_mat[1][1];
    result.m_mat[0][2] = left.m_mat[0][0] * right.m_mat[0][2] + left.m_mat[0][1] * right.m_mat[1][2];
    result.m_mat[1][0] = left.m_mat[1][0] * right.m_mat[0][0] + left.m_mat[1][1] * right.m_mat[1][0];
    result.m_mat[1][1] = left.m_mat[1][0] * right.m_mat[0][1] + left.m_mat[1][1] * right.m_mat[1][1];
    result.m_mat[1][2] = left.m_mat[1][0] * right.m_mat[0][2] + left.m_mat[1][1] * right.m_mat[1][2];
}

inline void Matrix2x2::multiply(const Matrix2x2 &left, const Matrix2x4 &right, Matrix2x4 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] * right.m_mat[0][0] + left.m_mat[0][1] * right.m_mat[1][0];
    result.m_mat[0][1] = left.m_mat[0][0] * right.m_mat[0][1] + left.m_mat[0][1] * right.m_mat[1][1];
    result.m_mat[0][2] = left.m_mat[0][0] * right.m_mat[0][2] + left.m_mat[0][1] * right.m_mat[1][2];
    result.m_mat[0][3] = left.m_mat[0][0] * right.m_mat[0][3] + left.m_mat[0][1] * right.m_mat[1][3];
    result.m_mat[1][0] = left.m_mat[1][0] * right.m_mat[0][0] + left.m_mat[1][1] * right.m_mat[1][0];
    result.m_mat[1][1] = left.m_mat[1][0] * right.m_mat[0][1] + left.m_mat[1][1] * right.m_mat[1][1];
    result.m_mat[1][2] = left.m_mat[1][0] * right.m_mat[0][2] + left.m_mat[1][1] * right.m_mat[1][2];
    result.m_mat[1][3] = left.m_mat[1][0] * right.m_mat[0][3] + left.m_mat[1][1] * right.m_mat[1][3];
}

inline void Matrix2x2::multiply(const Matrix2x2 &left, const Vector2 &right, Vector2 &result)
{
    float x = left.m_mat[0][0] * right.x() + left.m_mat[0][1] * right.y();
    float y = left.m_mat[1][0] * right.x() + left.m_mat[1][1] * right.y();
    
    result.setX(x);
    result.setY(y);
}

inline void Matrix2x2::multiply(const Vector2 &left, const Matrix2x2 &right, Vector2 &result)
{
    float x = left.x() * right.m_mat[0][0] + left.y() * right.m_mat[1][0];
    float y = left.x() * right.m_mat[0][1] + left.y() * right.m_mat[1][1];
    
    result.setX(x);
    result.setY(y);
}

inline Matrix2x2 Matrix2x2::inverse(const Matrix2x2 &mat2)
{
    Matrix2x2 result;
    inverse(mat2, result);
    return result;
}

inline Matrix2x2 Matrix2x2::transpose(const Matrix2x2 &mat2)
{
    Matrix2x2 result;
    transpose(mat2, result);
    return result;
}

inline Matrix2x2 Matrix2x2::add(const Matrix2x2 &left, const Matrix2x2 &right)
{
    Matrix2x2 result;
    add(left, right, result);
    return result;
}

inline Matrix2x2 Matrix2x2::subtract(const Matrix2x2 &left, const Matrix2x2 &right)
{
    Matrix2x2 result;
    subtract(left, right, result);
    return result;
}

inline Matrix2x2 Matrix2x2::multiply(const Matrix2x2 &left, float right)
{
    Matrix2x2 result;
    multiply(left, right, result);
    return result;
}

inline Matrix2x2 Matrix2x2::multiply(float left, const Matrix2x2 &right)
{
    Matrix2x2 result;
    multiply(left, right, result);
    return result;
}

inline Matrix2x2 Matrix2x2::multiply(const Matrix2x2 &left, const Matrix2x2 &right)
{
    Matrix2x2 result;
    multiply(left, right, result);
    return result;
}

inline Matrix2x3 Matrix2x2::multiply(const Matrix2x2 &left, const Matrix2x3 &right)
{
    Matrix2x3 result;
    multiply(left, right, result);
    return result;
}

inline Matrix2x4 Matrix2x2::multiply(const Matrix2x2 &left, const Matrix2x4 &right)
{
    Matrix2x4 result;
    multiply(left, right, result);
    return result;
}

inline Vector2 Matrix2x2::multiply(const Matrix2x2 &left, const Vector2 &right)
{
    Vector2 result;
    multiply(left, right, result);
    return result;
}

inline Vector2 Matrix2x2::multiply(const Vector2 &left, const Matrix2x2 &right)
{
    Vector2 result;
    multiply(left, right, result);
    return result;
}

inline Matrix2x2 &Matrix2x2::operator=(const Matrix2x2 &mat2)
{
    m_mat[0][0] = mat2.m_mat[0][0];
    m_mat[0][1] = mat2.m_mat[0][1];
    m_mat[1][0] = mat2.m_mat[1][0];
    m_mat[1][1] = mat2.m_mat[1][1];
    return *this;
}

inline bool operator==(const Matrix2x2 &m1, const Matrix2x2 &m2)
{
    for (int r = 0; r < 2; r++)
    {
        for (int c = 0; c < 2; c++)
        {
            if (m1.m_mat[r][c] != m2.m_mat[r][c])
                return false;
        }
    }

    return true;
}

inline bool operator!=(const Matrix2x2 &m1, const Matrix2x2 &m2)
{
    for (int r = 0; r < 2; r++)
    {
        for (int c = 0; c < 2; r++)
        {
            if (m1.m_mat[r][c] != m2.m_mat[r][c])
                return true;
        }
    }

    return false;
}

inline Matrix2x3 operator*(const Matrix2x2 &m22, const Matrix2x3 &m23)
{
    return Matrix2x2::multiply(m22, m23);
}

inline Matrix2x4 operator*(const Matrix2x2 &m22, const Matrix2x4 &m24)
{
    return Matrix2x2::multiply(m22, m24);
}

inline Vector2 operator*(const Matrix2x2 &mat2, const Vector2 &vec2)
{
    return Matrix2x2::multiply(mat2, vec2);
}

Vector2 operator*(const Vector2 &vec2, const Matrix2x2 &mat2)
{
    return Matrix2x2::multiply(vec2, mat2);
}
