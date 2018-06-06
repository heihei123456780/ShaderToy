#include "vector3.h"
#include "vector3.h"
#include "matrix3x2.h"
#include "matrix3x2.h"
#include "matrix3x4.h"
#include "matrix3x4.h"

const Matrix3x3 Matrix3x3::ZERO     (0.0f, 0.0f, 0.0f,
                                     0.0f, 0.0f, 0.0f,
                                     0.0f, 0.0f, 0.0f);

const Matrix3x3 Matrix3x3::IDENTITY (1.0f, 0.0f, 0.0f,
                                     0.0f, 1.0f, 0.0f,
                                     0.0f, 0.0f, 1.0f);

inline Matrix3x3::Matrix3x3()
{
    m_mat[0][0] = 0.0f;
    m_mat[0][1] = 0.0f;
    m_mat[0][2] = 0.0f;
    m_mat[1][0] = 0.0f;
    m_mat[1][1] = 0.0f;
    m_mat[1][2] = 0.0f;
    m_mat[2][0] = 0.0f;
    m_mat[2][1] = 0.0f;
    m_mat[2][2] = 0.0f;

}

inline Matrix3x3::Matrix3x3(float value)
{
    m_mat[0][0] = value;
    m_mat[0][1] = value;
    m_mat[0][2] = value;
    m_mat[1][0] = value;
    m_mat[1][1] = value;
    m_mat[1][2] = value;
    m_mat[2][0] = value;
    m_mat[2][1] = value;
    m_mat[2][2] = value;
}

Matrix3x3::Matrix3x3(float arr[3][3])
{
    m_mat[0][0] = arr[0][0];
    m_mat[0][1] = arr[0][1];
    m_mat[0][2] = arr[0][2];
    m_mat[1][0] = arr[1][0];
    m_mat[1][1] = arr[1][1];
    m_mat[1][2] = arr[1][2];
    m_mat[2][0] = arr[2][0];
    m_mat[2][1] = arr[2][1];
    m_mat[2][2] = arr[2][2];
}

inline Matrix3x3::Matrix3x3(float f00, float f01, float f02,
                     float f10, float f11, float f12,
                     float f20, float f21, float f22)
{
    m_mat[0][0] = f00;
    m_mat[0][1] = f01;
    m_mat[0][2] = f02;
    m_mat[1][0] = f10;
    m_mat[1][1] = f11;
    m_mat[1][2] = f12;
    m_mat[2][0] = f20;
    m_mat[2][1] = f21;
    m_mat[2][2] = f22;
}

inline Matrix3x3::Matrix3x3(const Matrix3x3 &mat3)
{
    m_mat[0][0] = mat3.m_mat[0][0];
    m_mat[0][1] = mat3.m_mat[0][1];
    m_mat[0][2] = mat3.m_mat[0][2];
    m_mat[1][0] = mat3.m_mat[1][0];
    m_mat[1][1] = mat3.m_mat[1][1];
    m_mat[1][2] = mat3.m_mat[1][2];
    m_mat[2][0] = mat3.m_mat[2][0];
    m_mat[2][1] = mat3.m_mat[2][1];
    m_mat[2][2] = mat3.m_mat[2][2];
}

inline Vector3 Matrix3x3::row(int index) const
{
    return Vector3(m_mat[index][0],
                   m_mat[index][1],
                   m_mat[index][2]);
}

inline Vector3 Matrix3x3::column(int index) const
{    
    return Vector3(m_mat[0][index],
                   m_mat[1][index],
                   m_mat[2][index]);
}

inline void Matrix3x3::setRow(int index, const Vector3 &vec3)
{
    m_mat[index][0] = vec3.x();
    m_mat[index][1] = vec3.y();
    m_mat[index][2] = vec3.z();
}

inline void Matrix3x3::setColumn(int index, const Vector3 &vec3)
{
    m_mat[0][index] = vec3.x();
    m_mat[1][index] = vec3.y();
    m_mat[2][index] = vec3.z();
}

inline void Matrix3x3::fill(float value)
{
    m_mat[0][0] = value;
    m_mat[0][1] = value;
    m_mat[0][2] = value;
    m_mat[1][0] = value;
    m_mat[1][1] = value;
    m_mat[1][2] = value;
    m_mat[2][0] = value;
    m_mat[2][1] = value;
    m_mat[2][2] = value;
}

inline bool Matrix3x3::isAffine() const
{
    return (m_mat[0][2] == 0.0f &&
            m_mat[1][2] == 0.0f &&
            m_mat[2][2] == 1.0f);
}

inline void Matrix3x3::fromAxes(const Vector3 &xAxis, const Vector3 &yAxis, const Vector3 &zAxis)
{
    setColumn(0, xAxis);
    setColumn(1, yAxis);
    setColumn(2, zAxis);
}

inline float Matrix3x3::determinant() const
{
    float factor0 = m_mat[1][1] * m_mat[2][2] -
                    m_mat[1][2] * m_mat[2][1];
    float factor1 = m_mat[1][2] * m_mat[2][0] -
                    m_mat[1][0] * m_mat[2][2];
    float factor2 = m_mat[1][0] * m_mat[2][1] -
                    m_mat[1][1] * m_mat[2][0];

    float det = m_mat[0][0] * factor0 -
                m_mat[0][1] * factor1 +
                m_mat[0][2] * factor2;
    return det;
}

inline void Matrix3x3::inverse(const Matrix3x3 &mat3, Matrix3x3 &result)
{
    result.m_mat[0][0] = mat3.m_mat[1][1] * mat3.m_mat[2][2] -
                         mat3.m_mat[1][2] * mat3.m_mat[2][1];
    result.m_mat[0][1] = mat3.m_mat[1][0] * mat3.m_mat[2][2] -
                         mat3.m_mat[1][2] * mat3.m_mat[2][0];
    result.m_mat[0][2] = mat3.m_mat[1][0] * mat3.m_mat[2][1] -
                         mat3.m_mat[2][2] * mat3.m_mat[2][0];
    result.m_mat[1][0] = mat3.m_mat[0][1] * mat3.m_mat[2][2] -
                         mat3.m_mat[0][2] * mat3.m_mat[2][1];
    result.m_mat[1][1] = mat3.m_mat[0][0] * mat3.m_mat[2][2] -
                         mat3.m_mat[0][2] * mat3.m_mat[2][0];
    result.m_mat[1][2] = mat3.m_mat[0][0] * mat3.m_mat[2][1] -
                         mat3.m_mat[0][1] * mat3.m_mat[2][0];
    result.m_mat[2][0] = mat3.m_mat[0][1] * mat3.m_mat[1][2] -
                         mat3.m_mat[0][2] * mat3.m_mat[1][1];
    result.m_mat[2][1] = mat3.m_mat[0][0] * mat3.m_mat[1][2] -
                         mat3.m_mat[0][2] * mat3.m_mat[2][0];
    result.m_mat[2][2] = mat3.m_mat[0][0] * mat3.m_mat[1][1] -
                         mat3.m_mat[0][1] * mat3.m_mat[1][0];

    float det =
        mat3.m_mat[0][0] * mat3.m_mat[0][0] +
        mat3.m_mat[0][1] * mat3.m_mat[1][0] +
        mat3.m_mat[0][2] * mat3.m_mat[2][0];

    float invDet = 1.0f / det;
    
    result.m_mat[0][0] *= invDet;
    result.m_mat[0][1] *= invDet;
    result.m_mat[0][2] *= invDet;
    result.m_mat[1][0] *= invDet;
    result.m_mat[1][1] *= invDet;
    result.m_mat[1][2] *= invDet;
    result.m_mat[2][0] *= invDet;
    result.m_mat[2][1] *= invDet;
    result.m_mat[2][2] *= invDet;
}

inline void Matrix3x3::transpose(const Matrix3x3 &mat3, Matrix3x3 &result)
{
    result.m_mat[0][0] = mat3.m_mat[0][0];
    result.m_mat[0][1] = mat3.m_mat[1][0];
    result.m_mat[0][2] = mat3.m_mat[2][0];
    result.m_mat[1][0] = mat3.m_mat[0][1];
    result.m_mat[1][1] = mat3.m_mat[1][1];
    result.m_mat[1][2] = mat3.m_mat[2][1];
    result.m_mat[2][0] = mat3.m_mat[0][2];
    result.m_mat[2][1] = mat3.m_mat[1][2];
    result.m_mat[2][2] = mat3.m_mat[2][2];
}

inline void Matrix3x3::add(const Matrix3x3 &left, const Matrix3x3 &right, Matrix3x3 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] + right.m_mat[0][0];
    result.m_mat[0][1] = left.m_mat[0][1] + right.m_mat[0][1];
    result.m_mat[0][2] = left.m_mat[0][2] + right.m_mat[0][2];
    result.m_mat[1][0] = left.m_mat[1][0] + right.m_mat[1][0];
    result.m_mat[1][1] = left.m_mat[1][1] + right.m_mat[1][1];
    result.m_mat[1][2] = left.m_mat[1][2] + right.m_mat[1][2];
    result.m_mat[2][0] = left.m_mat[2][0] + right.m_mat[2][0];
    result.m_mat[2][1] = left.m_mat[2][1] + right.m_mat[2][1];
    result.m_mat[2][2] = left.m_mat[2][2] + right.m_mat[2][2];
}

inline void Matrix3x3::subtract(const Matrix3x3 &left, const Matrix3x3 &right, Matrix3x3 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] - right.m_mat[0][0];
    result.m_mat[0][1] = left.m_mat[0][1] - right.m_mat[0][1];
    result.m_mat[0][2] = left.m_mat[0][2] - right.m_mat[0][2];
    result.m_mat[1][0] = left.m_mat[1][0] - right.m_mat[1][0];
    result.m_mat[1][1] = left.m_mat[1][1] - right.m_mat[1][1];
    result.m_mat[1][2] = left.m_mat[1][2] - right.m_mat[1][2];
    result.m_mat[2][0] = left.m_mat[2][0] - right.m_mat[2][0];
    result.m_mat[2][1] = left.m_mat[2][1] - right.m_mat[2][1];
    result.m_mat[2][2] = left.m_mat[2][2] - right.m_mat[2][2];
}

inline void Matrix3x3::multiply(const Matrix3x3 &left, float right, Matrix3x3 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] * right;
    result.m_mat[0][1] = left.m_mat[0][1] * right;
    result.m_mat[0][2] = left.m_mat[0][2] * right;
    result.m_mat[1][0] = left.m_mat[1][0] * right;
    result.m_mat[1][1] = left.m_mat[1][1] * right;
    result.m_mat[1][2] = left.m_mat[1][2] * right;
    result.m_mat[2][0] = left.m_mat[2][0] * right;
    result.m_mat[2][1] = left.m_mat[2][1] * right;
    result.m_mat[2][2] = left.m_mat[2][2] * right;
}

inline void Matrix3x3::multiply(float left, const Matrix3x3 &right, Matrix3x3 &result)
{
    result.m_mat[0][0] = left * right.m_mat[0][0];
    result.m_mat[0][1] = left * right.m_mat[0][1];
    result.m_mat[0][2] = left * right.m_mat[0][2];
    result.m_mat[1][0] = left * right.m_mat[1][0];
    result.m_mat[1][1] = left * right.m_mat[1][1];
    result.m_mat[1][2] = left * right.m_mat[1][2];
    result.m_mat[2][0] = left * right.m_mat[2][0];
    result.m_mat[2][1] = left * right.m_mat[2][1];
    result.m_mat[2][2] = left * right.m_mat[2][2];
}

inline void Matrix3x3::multiply(const Matrix3x3 &left, const Matrix3x2 &right, Matrix3x2 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] * right.m_mat[0][0] + left.m_mat[0][1] * right.m_mat[1][0] + 
                         left.m_mat[0][2] * right.m_mat[2][0];
    result.m_mat[0][1] = left.m_mat[0][0] * right.m_mat[0][1] + left.m_mat[0][1] * right.m_mat[1][1] + 
                         left.m_mat[0][2] * right.m_mat[2][1];
    result.m_mat[1][0] = left.m_mat[1][0] * right.m_mat[0][0] + left.m_mat[1][1] * right.m_mat[1][0] + 
                         left.m_mat[1][2] * right.m_mat[2][0];
    result.m_mat[1][1] = left.m_mat[1][0] * right.m_mat[0][1] + left.m_mat[1][1] * right.m_mat[1][1] + 
                         left.m_mat[1][2] * right.m_mat[2][1];
    result.m_mat[2][0] = left.m_mat[2][0] * right.m_mat[0][0] + left.m_mat[2][1] * right.m_mat[1][0] + 
                         left.m_mat[2][2] * right.m_mat[2][0];
    result.m_mat[2][1] = left.m_mat[2][0] * right.m_mat[0][1] + left.m_mat[2][1] * right.m_mat[1][1] + 
                         left.m_mat[2][2] * right.m_mat[2][1];
}

inline void Matrix3x3::multiply(const Matrix3x3 &left, const Matrix3x3 &right, Matrix3x3 &result)
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
                         left.m_mat[1][2] * right.m_mat[2][2];
    result.m_mat[2][0] = left.m_mat[2][0] * right.m_mat[0][0] + left.m_mat[2][1] * right.m_mat[1][0] + 
                         left.m_mat[2][2] * right.m_mat[2][0];
    result.m_mat[2][1] = left.m_mat[2][0] * right.m_mat[0][1] + left.m_mat[2][1] * right.m_mat[1][1] + 
                         left.m_mat[2][2] * right.m_mat[2][1];
    result.m_mat[2][2] = left.m_mat[2][0] * right.m_mat[0][2] + left.m_mat[2][1] * right.m_mat[1][2] + 
                         left.m_mat[2][2] * right.m_mat[2][2];
} 

inline void Matrix3x3::multiply(const Matrix3x3 &left, const Matrix3x4 &right, Matrix3x4 &result)
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
                         left.m_mat[1][2] * right.m_mat[2][2];
    result.m_mat[1][2] = left.m_mat[1][0] * right.m_mat[0][3] + left.m_mat[1][1] * right.m_mat[1][3] + 
                         left.m_mat[1][2] * right.m_mat[2][3];
    result.m_mat[2][0] = left.m_mat[2][0] * right.m_mat[0][0] + left.m_mat[2][1] * right.m_mat[1][0] + 
                         left.m_mat[2][2] * right.m_mat[2][0];
    result.m_mat[2][1] = left.m_mat[2][0] * right.m_mat[0][1] + left.m_mat[2][1] * right.m_mat[1][1] + 
                         left.m_mat[2][2] * right.m_mat[2][1];
    result.m_mat[2][2] = left.m_mat[2][0] * right.m_mat[0][2] + left.m_mat[2][1] * right.m_mat[1][2] + 
                         left.m_mat[2][2] * right.m_mat[2][2];
    result.m_mat[2][3] = left.m_mat[2][0] * right.m_mat[0][3] + left.m_mat[2][1] * right.m_mat[1][3] + 
                         left.m_mat[2][2] * right.m_mat[2][3];
}

inline void Matrix3x3::multiply(const Matrix3x3 &left, const Vector3 &right, Vector3 &result)
{
    float x = left.m_mat[0][0] * right.x() + left.m_mat[0][1] * right.y() + 
              left.m_mat[0][2] * right.z();
    float y = left.m_mat[1][0] * right.x() + left.m_mat[1][1] * right.y() +
              left.m_mat[1][2] * right.z();
    float z = left.m_mat[2][0] * right.x() + left.m_mat[2][1] * right.y() +
              left.m_mat[2][2] * right.z();

    result.setX(x);
    result.setY(y);
    result.setZ(z);
}

inline void Matrix3x3::multiply(const Vector3 &left, const Matrix3x3 &right, Vector3 &result)
{
    float x = left.x() * right.m_mat[0][0] + left.y() * right.m_mat[1][0] + 
              left.z() * right.m_mat[2][0];

    float y = left.x() * right.m_mat[0][1] + left.y() * right.m_mat[1][1] +
              left.z() * right.m_mat[2][1];
    
    float z = left.x() * right.m_mat[0][2] + left.y() * right.m_mat[1][2] +
              left.z() * right.m_mat[2][2];

    result.setX(x);
    result.setY(y);
    result.setZ(z);
}

inline Matrix3x3 Matrix3x3::inverse(const Matrix3x3 &mat3)
{
    Matrix3x3 result;
    inverse(mat3, result);
    return result;
}

inline Matrix3x3 Matrix3x3::transpose(const Matrix3x3 &mat3)
{
    Matrix3x3 result;
    transpose(mat3, result);
    return result;
}

inline Matrix3x3 Matrix3x3::add(const Matrix3x3 &left, const Matrix3x3 &right)
{
    Matrix3x3 result;
    add(left, right, result);
    return result;
}

inline Matrix3x3 Matrix3x3::subtract(const Matrix3x3 &left, const Matrix3x3 &right)
{
    Matrix3x3 result;
    subtract(left, right, result);
    return result;
}

inline Matrix3x3 Matrix3x3::multiply(const Matrix3x3 &left, float right)
{
    Matrix3x3 result;
    multiply(left, right, result);
    return result;
}

inline Matrix3x3 Matrix3x3::multiply(float left, const Matrix3x3 &right)
{
    Matrix3x3 result;
    multiply(left, right, result);
    return result;
}

inline Matrix3x2 Matrix3x3::multiply(const Matrix3x3 &left, const Matrix3x2 &right)
{
    Matrix3x2 result;
    multiply(left, right, result);
    return result;
}

inline Matrix3x3 Matrix3x3::multiply(const Matrix3x3 &left, const Matrix3x3 &right)
{
    Matrix3x3 result;
    multiply(left, right, result);
    return result;
}

inline Matrix3x4 Matrix3x3::multiply(const Matrix3x3 &left, const Matrix3x4 &right)
{
    Matrix3x4 result;
    multiply(left, right, result);
    return result;
}

inline Vector3 Matrix3x3::multiply(const Matrix3x3 &left, const Vector3 &right)
{
    Vector3 result;
    multiply(left, right, result);
    return result;
}

inline Vector3 Matrix3x3::multiply(const Vector3 &left, const Matrix3x3 &right)
{
    Vector3 result;
    multiply(left, right, result);
    return result;
}

inline Matrix3x3 &Matrix3x3::operator=(const Matrix3x3 &mat3)
{
    m_mat[0][0] = mat3.m_mat[0][0];
    m_mat[0][1] = mat3.m_mat[0][1];
    m_mat[0][2] = mat3.m_mat[0][2];
    m_mat[1][0] = mat3.m_mat[1][0];
    m_mat[1][1] = mat3.m_mat[1][1];
    m_mat[1][2] = mat3.m_mat[1][2];
    m_mat[2][0] = mat3.m_mat[2][0];
    m_mat[2][1] = mat3.m_mat[2][1];
    m_mat[2][2] = mat3.m_mat[2][2];
    return *this;
}

inline bool operator==(const Matrix3x3 &m1, const Matrix3x3 &m2)
{
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (m1.m_mat[r][c] != m2.m_mat[r][c])
                return false;
        }
    }

    return true;
}

inline bool operator!=(const Matrix3x3 &m1, const Matrix3x3 &m2)
{
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; r++)
        {
            if (m1.m_mat[r][c] != m2.m_mat[r][c])
                return true;
        }
    }

    return false;
}

inline Matrix3x2 operator*(const Matrix3x3 &m33, const Matrix3x2 &m32)
{
    return Matrix3x3::multiply(m33, m32);
}

inline Matrix3x4 operator*(const Matrix3x3 &m33, const Matrix3x4 &m34)
{
    return Matrix3x3::multiply(m33, m34);
}

inline Vector3 operator*(const Matrix3x3 &mat3, const Vector3 &vec3)
{
    return Matrix3x3::multiply(mat3, vec3);
}

inline Vector3 operator*(const Vector3 &vec3, const Matrix3x3 &mat3)
{
    return Matrix3x3::multiply(vec3, mat3);
}
