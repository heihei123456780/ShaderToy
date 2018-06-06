#include "vector3.h"
#include "vector4.h"
#include "matrix3x2.h"
#include "matrix3x3.h"
#include "matrix4x2.h"
#include "matrix4x3.h"
#include "matrix4x4.h"

const Matrix3x4 Matrix3x4::ZERO(0.0f, 0.0f, 0.0f, 0.0f,
                                0.0f, 0.0f, 0.0f, 0.0f,
                                0.0f, 0.0f, 0.0f, 0.0f);

inline Matrix3x4::Matrix3x4()
{
    m_mat[0][0] = 0.0f;
    m_mat[0][1] = 0.0f;
    m_mat[0][2] = 0.0f;
    m_mat[0][3] = 0.0f;
    m_mat[1][0] = 0.0f;
    m_mat[1][1] = 0.0f;
    m_mat[1][2] = 0.0f;
    m_mat[1][3] = 0.0f;
    m_mat[2][0] = 0.0f;
    m_mat[2][1] = 0.0f;
    m_mat[2][2] = 0.0f;
    m_mat[2][3] = 0.0f;
}

inline Matrix3x4::Matrix3x4(float value)
{
    m_mat[0][0] = value;
    m_mat[0][1] = value;
    m_mat[0][2] = value;
    m_mat[0][3] = value;
    m_mat[1][0] = value;
    m_mat[1][1] = value;
    m_mat[1][2] = value;
    m_mat[1][3] = value;
    m_mat[2][0] = value;
    m_mat[2][1] = value;
    m_mat[2][2] = value;
    m_mat[2][3] = value;
}

inline Matrix3x4::Matrix3x4(float arr[3][4])
{
    m_mat[0][0] = arr[0][0];
    m_mat[0][1] = arr[0][1];
    m_mat[0][2] = arr[0][2];
    m_mat[0][3] = arr[0][3];
    m_mat[1][0] = arr[1][0];
    m_mat[1][1] = arr[1][1];
    m_mat[1][2] = arr[1][2];
    m_mat[1][3] = arr[1][3];
    m_mat[2][0] = arr[2][0];
    m_mat[2][1] = arr[2][1];
    m_mat[2][2] = arr[2][2];
    m_mat[2][3] = arr[2][3];
}

inline Matrix3x4::Matrix3x4(float f00, float f01, float f02, float f03,
                            float f10, float f11, float f12, float f13,
                            float f20, float f21, float f22, float f23)
{
    m_mat[0][0] = f00;
    m_mat[0][1] = f01;
    m_mat[0][2] = f02;
    m_mat[0][3] = f03;
    m_mat[1][0] = f10;
    m_mat[1][1] = f11;
    m_mat[1][2] = f12;
    m_mat[1][3] = f13;
    m_mat[2][0] = f20;
    m_mat[2][1] = f21;
    m_mat[2][2] = f22;
    m_mat[2][3] = f23;
}

inline Matrix3x4::Matrix3x4(const Matrix3x4 &mat34)
{
    m_mat[0][0] = mat34.m_mat[0][0];
    m_mat[0][1] = mat34.m_mat[0][1];
    m_mat[0][2] = mat34.m_mat[0][2];
    m_mat[0][3] = mat34.m_mat[0][3];
    m_mat[1][0] = mat34.m_mat[1][0];
    m_mat[1][1] = mat34.m_mat[1][1];
    m_mat[1][2] = mat34.m_mat[1][2];
    m_mat[1][3] = mat34.m_mat[1][3];
    m_mat[2][0] = mat34.m_mat[2][0];
    m_mat[2][1] = mat34.m_mat[2][1];
    m_mat[2][2] = mat34.m_mat[2][2];
    m_mat[2][3] = mat34.m_mat[2][3];
}

inline Vector3 Matrix3x4::row(int index) const
{
    return Vector3(m_mat[index][0],
                   m_mat[index][1],
                   m_mat[index][2]);
}

inline Vector3 Matrix3x4::column(int index) const
{    
    return Vector3(m_mat[0][index],
                   m_mat[1][index],
                   m_mat[2][index]);
}

inline void Matrix3x4::setRow(int index, const Vector4 &vec4)
{
    m_mat[index][0] = vec4.x();
    m_mat[index][1] = vec4.y();
    m_mat[index][2] = vec4.z();
    m_mat[index][3] = vec4.w();
}

inline void Matrix3x4::setColumn(int index, const Vector3 &vec3)
{
    m_mat[0][index] = vec3.x();
    m_mat[1][index] = vec3.y();
    m_mat[2][index] = vec3.z();
}

inline void Matrix3x4::fill(float value)
{
    m_mat[0][0] = value;
    m_mat[0][1] = value;
    m_mat[0][2] = value;
    m_mat[0][3] = value;
    m_mat[1][0] = value;
    m_mat[1][1] = value;
    m_mat[1][2] = value;
    m_mat[1][3] = value;
    m_mat[2][0] = value;
    m_mat[2][1] = value;
    m_mat[2][2] = value;
    m_mat[2][3] = value;
}

inline float Matrix3x4::determinant() const
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

inline void Matrix3x4::inverse(const Matrix3x4 &mat34, Matrix3x4 &result)
{
}

inline void Matrix3x4::transpose(const Matrix3x4 &mat34, Matrix4x3 &result)
{
    result.m_mat[0][0] = mat34.m_mat[0][0];
    result.m_mat[1][0] = mat34.m_mat[0][1];
    result.m_mat[2][0] = mat34.m_mat[0][2];
    result.m_mat[3][0] = mat34.m_mat[0][3];
    result.m_mat[0][1] = mat34.m_mat[1][0];
    result.m_mat[1][2] = mat34.m_mat[1][1];
    result.m_mat[2][1] = mat34.m_mat[1][2];
    result.m_mat[3][1] = mat34.m_mat[1][3];
    result.m_mat[0][2] = mat34.m_mat[2][0];
    result.m_mat[1][2] = mat34.m_mat[2][1];
    result.m_mat[2][2] = mat34.m_mat[2][2];
    result.m_mat[3][2] = mat34.m_mat[2][3];
}

inline void Matrix3x4::add(const Matrix3x4 &left, const Matrix3x4 &right, Matrix3x4 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] + right.m_mat[0][0];
    result.m_mat[0][1] = left.m_mat[0][1] + right.m_mat[0][1];
    result.m_mat[0][2] = left.m_mat[0][2] + right.m_mat[0][2];
    result.m_mat[0][3] = left.m_mat[0][3] + right.m_mat[0][3];
    result.m_mat[1][0] = left.m_mat[1][0] + right.m_mat[1][0];
    result.m_mat[1][1] = left.m_mat[1][1] + right.m_mat[1][1];
    result.m_mat[1][2] = left.m_mat[1][2] + right.m_mat[1][2];
    result.m_mat[1][3] = left.m_mat[1][3] + right.m_mat[1][3];
    result.m_mat[2][0] = left.m_mat[2][0] + right.m_mat[2][0];
    result.m_mat[2][1] = left.m_mat[2][1] + right.m_mat[2][1];
    result.m_mat[2][2] = left.m_mat[2][2] + right.m_mat[2][2];
    result.m_mat[2][3] = left.m_mat[2][3] + right.m_mat[2][3];
}

inline void Matrix3x4::subtract(const Matrix3x4 &left, const Matrix3x4 &right, Matrix3x4 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] - right.m_mat[0][0];
    result.m_mat[0][1] = left.m_mat[0][1] - right.m_mat[0][1];
    result.m_mat[0][2] = left.m_mat[0][2] - right.m_mat[0][2];
    result.m_mat[0][3] = left.m_mat[0][3] - right.m_mat[0][3];
    result.m_mat[1][0] = left.m_mat[1][0] - right.m_mat[1][0];
    result.m_mat[1][1] = left.m_mat[1][1] - right.m_mat[1][1];
    result.m_mat[1][2] = left.m_mat[1][2] - right.m_mat[1][2];
    result.m_mat[1][3] = left.m_mat[1][3] - right.m_mat[1][3];
    result.m_mat[2][0] = left.m_mat[2][0] - right.m_mat[2][0];
    result.m_mat[2][1] = left.m_mat[2][1] - right.m_mat[2][1];
    result.m_mat[2][2] = left.m_mat[2][2] - right.m_mat[2][2];
    result.m_mat[2][3] = left.m_mat[2][3] - right.m_mat[2][3];
}

inline void Matrix3x4::multiply(const Matrix3x4 &left, float right, Matrix3x4 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] * right;
    result.m_mat[0][1] = left.m_mat[0][1] * right;
    result.m_mat[0][2] = left.m_mat[0][2] * right;
    result.m_mat[0][3] = left.m_mat[0][3] * right;
    result.m_mat[1][0] = left.m_mat[1][0] * right;
    result.m_mat[1][1] = left.m_mat[1][1] * right;
    result.m_mat[1][2] = left.m_mat[1][2] * right;
    result.m_mat[1][3] = left.m_mat[1][3] * right;
    result.m_mat[2][0] = left.m_mat[2][0] * right;
    result.m_mat[2][1] = left.m_mat[2][1] * right;
    result.m_mat[2][2] = left.m_mat[2][2] * right;
    result.m_mat[2][3] = left.m_mat[2][3] * right;
}

inline void Matrix3x4::multiply(float left, const Matrix3x4 &right, Matrix3x4 &result)
{
    result.m_mat[0][0] = left * right.m_mat[0][0];
    result.m_mat[0][1] = left * right.m_mat[0][1];
    result.m_mat[0][2] = left * right.m_mat[0][2];
    result.m_mat[0][3] = left * right.m_mat[0][3];
    result.m_mat[1][0] = left * right.m_mat[1][0];
    result.m_mat[1][1] = left * right.m_mat[1][1];
    result.m_mat[1][2] = left * right.m_mat[1][2];
    result.m_mat[1][3] = left * right.m_mat[1][3];
    result.m_mat[2][0] = left * right.m_mat[2][0];
    result.m_mat[2][1] = left * right.m_mat[2][1];
    result.m_mat[2][2] = left * right.m_mat[2][2];
    result.m_mat[2][3] = left * right.m_mat[2][3];
}

inline void Matrix3x4::multiply(const Matrix3x4 &left, const Matrix4x2 &right, Matrix3x2 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] * right.m_mat[0][0] + left.m_mat[0][1] * right.m_mat[1][0] + 
                         left.m_mat[0][2] * right.m_mat[2][0] + left.m_mat[0][3] * right.m_mat[3][0];
    result.m_mat[0][1] = left.m_mat[0][0] * right.m_mat[0][1] + left.m_mat[0][1] * right.m_mat[1][1] + 
                         left.m_mat[0][2] * right.m_mat[2][1] + left.m_mat[0][3] * right.m_mat[3][1];
    result.m_mat[1][0] = left.m_mat[1][0] * right.m_mat[0][0] + left.m_mat[1][1] * right.m_mat[1][0] + 
                         left.m_mat[1][2] * right.m_mat[2][0] + left.m_mat[1][3] * right.m_mat[3][0];
    result.m_mat[1][1] = left.m_mat[1][0] * right.m_mat[0][1] + left.m_mat[1][1] * right.m_mat[1][1] + 
                         left.m_mat[1][2] * right.m_mat[2][1] + left.m_mat[1][3] * right.m_mat[3][1];
    result.m_mat[2][0] = left.m_mat[2][0] * right.m_mat[0][0] + left.m_mat[2][1] * right.m_mat[1][0] + 
                         left.m_mat[2][2] * right.m_mat[2][0] + left.m_mat[2][3] * right.m_mat[3][0];
    result.m_mat[2][1] = left.m_mat[2][0] * right.m_mat[0][0] + left.m_mat[2][1] * right.m_mat[1][1] + 
                         left.m_mat[2][2] * right.m_mat[2][1] + left.m_mat[2][3] * right.m_mat[3][1];
}

inline void Matrix3x4::multiply(const Matrix3x4 &left, const Matrix4x3 &right, Matrix3x3 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] * right.m_mat[0][0] + left.m_mat[0][1] * right.m_mat[1][0] + 
                         left.m_mat[0][2] * right.m_mat[2][0] + left.m_mat[0][3] * right.m_mat[3][0];
    result.m_mat[0][1] = left.m_mat[0][0] * right.m_mat[0][1] + left.m_mat[0][1] * right.m_mat[1][1] + 
                         left.m_mat[0][2] * right.m_mat[2][1] + left.m_mat[0][3] * right.m_mat[3][1];
    result.m_mat[0][2] = left.m_mat[0][0] * right.m_mat[0][2] + left.m_mat[0][1] * right.m_mat[1][2] + 
                         left.m_mat[0][2] * right.m_mat[2][2] + left.m_mat[0][3] * right.m_mat[3][2];
    result.m_mat[1][0] = left.m_mat[1][0] * right.m_mat[0][0] + left.m_mat[1][1] * right.m_mat[1][0] + 
                         left.m_mat[1][2] * right.m_mat[2][0] + left.m_mat[1][3] * right.m_mat[3][0];
    result.m_mat[1][1] = left.m_mat[1][0] * right.m_mat[0][1] + left.m_mat[1][1] * right.m_mat[1][1] + 
                         left.m_mat[1][2] * right.m_mat[2][1] + left.m_mat[1][3] * right.m_mat[3][1];
    result.m_mat[1][2] = left.m_mat[1][0] * right.m_mat[0][2] + left.m_mat[1][1] * right.m_mat[1][2] + 
                         left.m_mat[1][2] * right.m_mat[2][2] + left.m_mat[1][3] * right.m_mat[3][2];
    result.m_mat[2][0] = left.m_mat[2][0] * right.m_mat[0][0] + left.m_mat[2][1] * right.m_mat[1][0] + 
                         left.m_mat[2][2] * right.m_mat[2][0] + left.m_mat[2][3] * right.m_mat[3][0];
    result.m_mat[2][1] = left.m_mat[2][0] * right.m_mat[0][1] + left.m_mat[2][1] * right.m_mat[1][1] + 
                         left.m_mat[2][2] * right.m_mat[2][1] + left.m_mat[2][3] * right.m_mat[3][1];
    result.m_mat[2][2] = left.m_mat[2][0] * right.m_mat[0][2] + left.m_mat[2][1] * right.m_mat[1][2] + 
                         left.m_mat[2][2] * right.m_mat[2][2] + left.m_mat[2][3] * right.m_mat[3][2];
}

inline void Matrix3x4::multiply(const Matrix3x4 &left, const Matrix4x4 &right, Matrix3x4 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] * right.m_mat[0][0] + left.m_mat[0][1] * right.m_mat[1][0] + 
                         left.m_mat[0][2] * right.m_mat[2][0] + left.m_mat[0][3] * right.m_mat[3][0];
    result.m_mat[0][1] = left.m_mat[0][0] * right.m_mat[0][1] + left.m_mat[0][1] * right.m_mat[1][1] + 
                         left.m_mat[0][2] * right.m_mat[2][1] + left.m_mat[0][3] * right.m_mat[3][1];
    result.m_mat[0][2] = left.m_mat[0][0] * right.m_mat[0][2] + left.m_mat[0][1] * right.m_mat[1][2] + 
                         left.m_mat[0][2] * right.m_mat[2][2] + left.m_mat[0][3] * right.m_mat[3][2];
    result.m_mat[0][3] = left.m_mat[0][0] * right.m_mat[0][3] + left.m_mat[0][1] * right.m_mat[1][3] + 
                         left.m_mat[0][2] * right.m_mat[2][3] + left.m_mat[0][3] * right.m_mat[3][3];
    result.m_mat[1][0] = left.m_mat[1][0] * right.m_mat[0][0] + left.m_mat[1][1] * right.m_mat[1][0] + 
                         left.m_mat[1][2] * right.m_mat[2][0] + left.m_mat[1][3] * right.m_mat[3][0];
    result.m_mat[1][1] = left.m_mat[1][0] * right.m_mat[0][1] + left.m_mat[1][1] * right.m_mat[1][1] + 
                         left.m_mat[1][2] * right.m_mat[2][1] + left.m_mat[1][3] * right.m_mat[3][1];
    result.m_mat[1][2] = left.m_mat[1][0] * right.m_mat[0][2] + left.m_mat[1][1] * right.m_mat[1][2] + 
                         left.m_mat[1][2] * right.m_mat[2][2] + left.m_mat[1][3] * right.m_mat[3][2];
    result.m_mat[1][3] = left.m_mat[1][0] * right.m_mat[0][3] + left.m_mat[1][1] * right.m_mat[1][3] + 
                         left.m_mat[1][2] * right.m_mat[2][3] + left.m_mat[1][3] * right.m_mat[3][3];
    result.m_mat[2][0] = left.m_mat[2][0] * right.m_mat[0][0] + left.m_mat[2][1] * right.m_mat[1][0] + 
                         left.m_mat[2][2] * right.m_mat[2][0] + left.m_mat[2][3] * right.m_mat[3][0];
    result.m_mat[2][1] = left.m_mat[2][0] * right.m_mat[0][1] + left.m_mat[2][1] * right.m_mat[1][1] + 
                         left.m_mat[2][2] * right.m_mat[2][1] + left.m_mat[2][3] * right.m_mat[3][1];
    result.m_mat[2][2] = left.m_mat[2][0] * right.m_mat[0][2] + left.m_mat[2][1] * right.m_mat[1][2] + 
                         left.m_mat[2][2] * right.m_mat[2][2] + left.m_mat[2][3] * right.m_mat[3][2];
    result.m_mat[2][2] = left.m_mat[2][0] * right.m_mat[0][3] + left.m_mat[2][1] * right.m_mat[1][3] + 
                         left.m_mat[2][2] * right.m_mat[2][3] + left.m_mat[2][3] * right.m_mat[3][3];
}

inline void Matrix3x4::multiply(const Matrix3x4 &left, const Vector4 &right, Vector3 &result)
{
    float x = left.m_mat[0][0] * right.x() + left.m_mat[0][1] * right.y() + 
              left.m_mat[0][2] * right.z() + left.m_mat[0][3] * right.w();
    float y = left.m_mat[1][0] * right.x() + left.m_mat[1][1] * right.y() +
              left.m_mat[1][2] * right.z() + left.m_mat[1][3] * right.w();
    float z = left.m_mat[2][0] * right.x() + left.m_mat[2][1] * right.y() +
              left.m_mat[2][2] * right.z() + left.m_mat[2][3] * right.w();

    result.setX(x);
    result.setY(y);
    result.setZ(z);
}

inline void Matrix3x4::multiply(const Vector3 &left, const Matrix3x4 &right, Vector4 &result)
{
    float x = left.x() * right.m_mat[0][0] + left.y() * right.m_mat[1][0] + 
              left.z() * right.m_mat[2][0];
    float y = left.x() * right.m_mat[0][1] + left.y() * right.m_mat[1][1] +
              left.z() * right.m_mat[2][1];
    float z = left.x() * right.m_mat[0][2] + left.y() * right.m_mat[1][2] +
              left.z() * right.m_mat[2][2];
    float w = left.x() * right.m_mat[0][3] + left.y() * right.m_mat[1][3] + 
              left.z() * right.m_mat[2][3];

    result.setX(x);
    result.setY(y);
    result.setZ(z);
    result.setW(w);
}

inline Matrix3x4 Matrix3x4::inverse(const Matrix3x4 &mat34)
{
    Matrix3x4 result;
    inverse(mat34, result);
    return result;
}

inline Matrix4x3 Matrix3x4::transpose(const Matrix3x4 &mat34)
{
    Matrix4x3 result;
    transpose(mat34, result);
    return result;
}

inline Matrix3x4 Matrix3x4::add(const Matrix3x4 &left, const Matrix3x4 &right)
{
    Matrix3x4 result;
    add(left, right, result);
    return result;
}

inline Matrix3x4 Matrix3x4::subtract(const Matrix3x4 &left, const Matrix3x4 &right)
{
    Matrix3x4 result;
    subtract(left, right, result);
    return result;
}

inline Matrix3x4 Matrix3x4::multiply(const Matrix3x4 &left, float right)
{
    Matrix3x4 result;
    multiply(left, right, result);
    return result;
}

inline Matrix3x4 Matrix3x4::multiply(float left, const Matrix3x4 &right)
{
    Matrix3x4 result;
    multiply(left, right, result);
    return result;
}

inline Matrix3x2 Matrix3x4::multiply(const Matrix3x4 &left, const Matrix4x2 &right)
{
    Matrix3x2 result;
    multiply(left, right, result);
    return result;
}

inline Matrix3x3 Matrix3x4::multiply(const Matrix3x4 &left, const Matrix4x3 &right)
{
    Matrix3x3 result;
    multiply(left, right, result);
    return result;
}

inline Matrix3x4 Matrix3x4::multiply(const Matrix3x4 &left, const Matrix4x4 &right)
{
    Matrix3x4 result;
    multiply(left, right, result);
    return result;
}

inline Vector3 Matrix3x4::multiply(const Matrix3x4 &left, const Vector4 &right)
{
    Vector3 result;
    multiply(left, right, result);
    return result;
}

inline Vector4 Matrix3x4::multiply(const Vector3 &left, const Matrix3x4 &right)
{
    Vector4 result;
    multiply(left, right, result);
    return result;
}

inline Matrix3x4 &Matrix3x4::operator=(const Matrix3x4 &mat34)
{
    m_mat[0][0] = mat34.m_mat[0][0];
    m_mat[0][1] = mat34.m_mat[0][1];
    m_mat[0][2] = mat34.m_mat[0][2];
    m_mat[0][3] = mat34.m_mat[0][3];
    m_mat[1][0] = mat34.m_mat[1][0];
    m_mat[1][1] = mat34.m_mat[1][1];
    m_mat[1][2] = mat34.m_mat[1][2];
    m_mat[1][3] = mat34.m_mat[1][3];
    m_mat[2][0] = mat34.m_mat[2][0];
    m_mat[2][1] = mat34.m_mat[2][1];
    m_mat[2][2] = mat34.m_mat[2][2];
    m_mat[2][3] = mat34.m_mat[2][3];
    return *this;
}

inline bool operator==(const Matrix3x4 &m1, const Matrix3x4 &m2)
{
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 4; c++)
        {
            if (m1.m_mat[r][c] != m2.m_mat[r][c])
                return false;
        }
    }

    return true;
}

inline bool operator!=(const Matrix3x4 &m1, const Matrix3x4 &m2)
{
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 4; r++)
        {
            if (m1.m_mat[r][c] != m2.m_mat[r][c])
                return true;
        }
    }

    return false;
}

inline Matrix3x2 operator*(const Matrix3x4 &m34, const Matrix4x2 &m42)
{
    return Matrix3x4::multiply(m34, m42);
}

inline Matrix3x3 operator*(const Matrix3x4 &m34, const Matrix4x3 &m43)
{
    return Matrix3x4::multiply(m34, m43);
}

inline Matrix3x4 operator*(const Matrix3x4 &m34, const Matrix4x4 &m44)
{
    return Matrix3x4::multiply(m34, m44);
}

inline Vector3 operator*(const Matrix3x4 &mat34, const Vector4 &vec4)
{
    return Matrix3x4::multiply(mat34, vec4);
}

inline Vector4 operator*(const Vector3 &vec3, const Matrix3x4 &mat34)
{
    return Matrix3x4::multiply(vec3, mat34);
}
