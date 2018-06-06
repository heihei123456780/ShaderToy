#include "vector2.h"
#include "vector2.h"
#include "vector3.h"
#include "vector3.h"
#include "matrix2x2.h"
#include "matrix2x2.h"
#include "matrix3x2.h"
#include "matrix3x2.h"
#include "matrix3x3.h"
#include "matrix3x3.h"
#include "matrix3x4.h"
#include "matrix3x4.h"

const Matrix2x3 Matrix2x3::ZERO(0.0f, 0.0f, 0.0f,
                                0.0f, 0.0f, 0.0f);

inline Matrix2x3::Matrix2x3()
{
    m_mat[0][0] = 0.0f;
    m_mat[0][1] = 0.0f;
    m_mat[0][2] = 0.0f;
    m_mat[1][0] = 0.0f;
    m_mat[1][1] = 0.0f;
    m_mat[1][2] = 0.0f;
}

inline Matrix2x3::Matrix2x3(float value)
{
    m_mat[0][0] = value;
    m_mat[0][1] = value;
    m_mat[0][2] = value;
    m_mat[1][0] = value;
    m_mat[1][1] = value;
    m_mat[1][2] = value;
}

inline Matrix2x3::Matrix2x3(float arr[2][3])
{
    m_mat[0][0] = arr[0][0];
    m_mat[0][1] = arr[0][1];
    m_mat[0][2] = arr[0][2];
    m_mat[1][0] = arr[1][0];
    m_mat[1][1] = arr[1][1];
    m_mat[1][2] = arr[1][2];
}

inline Matrix2x3::Matrix2x3(float f00, float f01, float f02,
                            float f10, float f11, float f12)
{
    m_mat[0][0] = f00;
    m_mat[0][1] = f01;
    m_mat[0][2] = f02;
    m_mat[1][0] = f10;
    m_mat[1][1] = f11;
    m_mat[1][2] = f12;
}

inline Matrix2x3::Matrix2x3(const Matrix2x3 &mat23)
{
    m_mat[0][0] = mat23.m_mat[0][0];
    m_mat[0][1] = mat23.m_mat[0][1];
    m_mat[0][2] = mat23.m_mat[0][2];
    m_mat[1][0] = mat23.m_mat[1][0];
    m_mat[1][1] = mat23.m_mat[1][1];
    m_mat[1][2] = mat23.m_mat[1][2];
}

inline Vector2 Matrix2x3::column(int index) const
{
    return Vector2(m_mat[0][index],
                   m_mat[1][index]);
}

inline Vector3 Matrix2x3::row(int index) const
{
    return Vector3(m_mat[index][0],
                   m_mat[index][1],
                   m_mat[index][2]);
}

inline void Matrix2x3::setRow(int index, const Vector3 &vec3)
{
    m_mat[index][0] = vec3.x();
    m_mat[index][1] = vec3.y();
    m_mat[index][2] = vec3.z();
}

inline void Matrix2x3::setColumn(int index, const Vector2 &vec2)
{
    m_mat[0][index] = vec2.x();
    m_mat[1][index] = vec2.y();
}

inline void Matrix2x3::fill(float value)
{
    m_mat[0][0] = value;
    m_mat[0][1] = value;
    m_mat[0][2] = value;
    m_mat[1][0] = value;
    m_mat[1][1] = value;
    m_mat[1][2] = value;
}

inline void Matrix2x3::inverse(const Matrix2x3 &mat23, Matrix2x3 &result)
{
}

inline void Matrix2x3::transpose(const Matrix2x3 &mat23, Matrix3x2 &result)
{
    result.m_mat[0][0] = mat23.m_mat[0][0];
    result.m_mat[1][0] = mat23.m_mat[0][1];
    result.m_mat[2][0] = mat23.m_mat[0][2];
    result.m_mat[1][0] = mat23.m_mat[0][1];
    result.m_mat[1][1] = mat23.m_mat[1][1];
    result.m_mat[2][1] = mat23.m_mat[1][2];
}

inline void Matrix2x3::add(const Matrix2x3 &left, const Matrix2x3 &right, Matrix2x3 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] + right.m_mat[0][0];
    result.m_mat[0][1] = left.m_mat[0][1] + right.m_mat[0][1];
    result.m_mat[0][2] = left.m_mat[0][2] + right.m_mat[0][2];
    result.m_mat[1][0] = left.m_mat[1][0] + right.m_mat[1][0];
    result.m_mat[1][1] = left.m_mat[1][1] + right.m_mat[1][1];
    result.m_mat[1][2] = left.m_mat[1][2] + right.m_mat[1][2];
}

inline void Matrix2x3::subtract(const Matrix2x3 &left, const Matrix2x3 &right, Matrix2x3 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] - right.m_mat[0][0];
    result.m_mat[0][1] = left.m_mat[0][1] - right.m_mat[0][1];
    result.m_mat[0][2] = left.m_mat[0][2] - right.m_mat[0][2];
    result.m_mat[1][0] = left.m_mat[1][0] - right.m_mat[1][0];
    result.m_mat[0][1] = left.m_mat[1][1] - right.m_mat[1][1];
    result.m_mat[0][2] = left.m_mat[1][2] - right.m_mat[1][2];
}

inline void Matrix2x3::multiply(const Matrix2x3 &left, const Matrix3x2 &right, Matrix2x2 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] * right.m_mat[0][0] + left.m_mat[0][1] * right.m_mat[1][0] + 
                         left.m_mat[0][2] * right.m_mat[2][0];
    result.m_mat[0][1] = left.m_mat[0][0] * right.m_mat[0][1] + left.m_mat[0][1] * right.m_mat[1][1] + 
                         left.m_mat[0][2] * right.m_mat[2][1];
    result.m_mat[1][0] = left.m_mat[1][0] * right.m_mat[0][0] + left.m_mat[1][1] * right.m_mat[1][0] + 
                         left.m_mat[1][2] * right.m_mat[2][0];
    result.m_mat[1][1] = left.m_mat[1][0] * right.m_mat[0][1] + left.m_mat[1][1] * right.m_mat[1][1] + 
                         left.m_mat[1][2] * right.m_mat[2][1];
}

inline void Matrix2x3::multiply(const Matrix2x3 &left, const Matrix3x3 &right, Matrix2x3 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] * right.m_mat[0][0] + left.m_mat[0][1] * right.m_mat[1][0] + 
                         left.m_mat[0][2] * right.m_mat[2][0];
    result.m_mat[0][1] = left.m_mat[0][0] * right.m_mat[0][1] + left.m_mat[0][1] * right.m_mat[1][1] + 
                         left.m_mat[0][2] * right.m_mat[2][1];
    result.m_mat[0][2] = left.m_mat[0][0] * right.m_mat[0][2] + left.m_mat[0][1] * right.m_mat[1][2] + 
                         left.m_mat[0][2] * right.m_mat[2][2];
    result.m_mat[1][0] = left.m_mat[1][0] * right.m_mat[0][0] + left.m_mat[1][1] * right.m_mat[1][0] + 
                         left.m_mat[1][2] * right.m_mat[2][0];
    result.m_mat[1][1] = left.m_mat[1][0] * right.m_mat[0][1] + left.m_mat[1][1] * right.m_mat[1][1] + 
                         left.m_mat[1][2] * right.m_mat[2][1];
    result.m_mat[1][2] = left.m_mat[1][0] * right.m_mat[0][2] + left.m_mat[1][1] * right.m_mat[1][2] + 
                         left.m_mat[2][2] * right.m_mat[2][2];
}

inline void Matrix2x3::multiply(const Matrix2x3 &left, const Matrix3x4 &right, Matrix2x4 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] * right.m_mat[0][0] + left.m_mat[0][1] * right.m_mat[1][0] + 
                         left.m_mat[0][2] * right.m_mat[2][0];
    result.m_mat[0][1] = left.m_mat[0][0] * right.m_mat[0][1] + left.m_mat[0][1] * right.m_mat[1][1] + 
                         left.m_mat[0][2] * right.m_mat[2][1];
    result.m_mat[0][2] = left.m_mat[0][0] * right.m_mat[0][2] + left.m_mat[0][1] * right.m_mat[1][2] + 
                         left.m_mat[0][2] * right.m_mat[2][2];
    result.m_mat[0][3] = left.m_mat[0][0] * right.m_mat[0][3] + left.m_mat[0][1] * right.m_mat[1][3] + 
                         left.m_mat[0][2] * right.m_mat[2][3];
    result.m_mat[1][0] = left.m_mat[1][0] * right.m_mat[0][0] + left.m_mat[1][1] * right.m_mat[1][0] + 
                         left.m_mat[1][2] * right.m_mat[2][0];
    result.m_mat[1][1] = left.m_mat[1][0] * right.m_mat[0][1] + left.m_mat[1][1] * right.m_mat[1][1] + 
                         left.m_mat[1][2] * right.m_mat[2][1];
    result.m_mat[1][2] = left.m_mat[1][0] * right.m_mat[0][2] + left.m_mat[1][1] * right.m_mat[1][2] + 
                         left.m_mat[2][2] * right.m_mat[2][2];
    result.m_mat[1][3] = left.m_mat[1][0] * right.m_mat[0][3] + left.m_mat[1][1] * right.m_mat[1][3] + 
                         left.m_mat[2][2] * right.m_mat[2][3];
}

inline void Matrix2x3::multiply(const Matrix2x3 &left, float right, Matrix2x3 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] * right;
    result.m_mat[0][1] = left.m_mat[0][1] * right;
    result.m_mat[0][2] = left.m_mat[0][2] * right;
    result.m_mat[1][0] = left.m_mat[1][0] * right;
    result.m_mat[1][1] = left.m_mat[1][1] * right;
    result.m_mat[1][2] = left.m_mat[1][2] * right;
}

inline void Matrix2x3::multiply(float left, const Matrix2x3 &right, Matrix2x3 &result)
{
    result.m_mat[0][0] = left * right.m_mat[0][0];
    result.m_mat[0][1] = left * right.m_mat[0][1];
    result.m_mat[0][2] = left * right.m_mat[0][2];
    result.m_mat[1][0] = left * right.m_mat[1][0];
    result.m_mat[1][1] = left * right.m_mat[1][1];
    result.m_mat[1][2] = left * right.m_mat[1][2];
}

inline void Matrix2x3::multiply(const Matrix2x3 &left, const Vector3 &right, Vector2 &result)
{
    float x = left.m_mat[0][0] * right.x() + left.m_mat[0][1] * right.y() + 
              left.m_mat[0][2] * right.z();
    float y = left.m_mat[1][0] * right.x() + left.m_mat[1][1] * right.y() + 
              left.m_mat[1][2] * right.z();
    
    result.setX(x);
    result.setY(y);
}

inline void Matrix2x3::multiply(const Vector2 &left, const Matrix2x3 &right, Vector3 &result)
{
    float x = left.x() * right.m_mat[0][0] + left.y() * right.m_mat[1][0];
    float y = left.x() * right.m_mat[0][1] + left.y() * right.m_mat[1][1];
    float z = left.x() * right.m_mat[0][2] + left.y() * right.m_mat[1][2];

    result.setX(x);
    result.setY(y);
    result.setZ(z);
}

inline Matrix2x3 Matrix2x3::inverse(const Matrix2x3 &mat23)
{
    Matrix2x3 result;
    inverse(mat23, result);
    return result;
}

inline Matrix3x2 Matrix2x3::transpose(const Matrix2x3 &mat23)
{
    Matrix3x2 result;
    transpose(mat23, result);
    return result;
}

inline Matrix2x3 Matrix2x3::add(const Matrix2x3 &left, const Matrix2x3 &right)
{
    Matrix2x3 result;
    add(left, right, result);
    return result;
}

inline Matrix2x3 Matrix2x3::subtract(const Matrix2x3 &left, const Matrix2x3 &right)
{
    Matrix2x3 result;
    subtract(left, right, result);
    return result;
}

inline Matrix2x3 Matrix2x3::multiply(const Matrix2x3 &left, float right)
{
    Matrix2x3 result;
    multiply(left, right, result);
    return result;
}

inline Matrix2x3 Matrix2x3::multiply(float left, const Matrix2x3 &right)
{
    Matrix2x3 result;
    multiply(left, right, result);
    return result;
}

inline Matrix2x2 Matrix2x3::multiply(const Matrix2x3 &left, const Matrix3x2 &right)
{
    Matrix2x2 result;
    multiply(left, right, result);
    return result;
}

inline Matrix2x3 Matrix2x3::multiply(const Matrix2x3 &left, const Matrix3x3 &right)
{
    Matrix2x3 result;
    multiply(left, right, result);
    return result;
}

inline Matrix2x4 Matrix2x3::multiply(const Matrix2x3 &left, const Matrix3x4 &right)
{
    Matrix2x4 result;
    multiply(left, right, result);
    return result;
}

inline Vector2 Matrix2x3::multiply(const Matrix2x3 &left, const Vector3 &right)
{
    Vector2 result;
    multiply(left, right, result);
    return result;
}

inline Vector3 Matrix2x3::multiply(const Vector2 &left, const Matrix2x3 &right)
{
    Vector3 result;
    multiply(left, right, result);
    return result;
}

inline Matrix2x3 &Matrix2x3::operator=(const Matrix2x3 &mat23)
{
    m_mat[0][0] = mat23.m_mat[0][0];
    m_mat[0][1] = mat23.m_mat[0][1];
    m_mat[0][2] = mat23.m_mat[0][2];
    m_mat[1][0] = mat23.m_mat[1][0];
    m_mat[1][1] = mat23.m_mat[1][1];
    m_mat[1][2] = mat23.m_mat[1][2];
    return *this;
}

inline bool operator==(const Matrix2x3 &m1, const Matrix2x3 &m2)
{
    for (int r = 0; r < 2; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (m1.m_mat[r][c] != m2.m_mat[r][c])
                return false;
        }
    }

    return true;
}

inline bool operator!=(const Matrix2x3 &m1, const Matrix2x3 &m2)
{
    for (int r = 0; r < 2; r++)
    {
        for (int c = 0; c < 3; r++)
        {
            if (m1.m_mat[r][c] != m2.m_mat[r][c])
                return true;
        }
    }

    return false;
}

inline Matrix2x2 operator*(const Matrix2x3 &m23, const Matrix3x2 &m32)
{
    return Matrix2x3::multiply(m23, m32);
}

inline Matrix2x3 operator*(const Matrix2x3 &m23, const Matrix3x3 &m33)
{
    return Matrix2x3::multiply(m23, m33);
}

inline Matrix2x4 operator*(const Matrix2x3 &m23, const Matrix3x4 &m34)
{
    return Matrix2x3::multiply(m23, m34);
}

inline Vector2 operator*(const Matrix2x3 &mat23, const Vector3 &vec3)
{
    return Matrix2x3::multiply(mat23, vec3);
}

inline Vector3 operator*(const Vector2 &vec2, const Matrix2x3 &mat23)
{
    return Matrix2x3::multiply(vec2, mat23);
}
