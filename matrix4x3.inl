#include "vector3.h"
#include "vector4.h"
#include "matrix2x3.h"
#include "matrix3x3.h"
#include "matrix3x4.h"
#include "matrix4x2.h"
#include "matrix4x4.h"

const Matrix4x3 Matrix4x3::ZERO(0.0f, 0.0f, 0.0f,
                                0.0f, 0.0f, 0.0f,
                                0.0f, 0.0f, 0.0f,
                                0.0f, 0.0f, 0.0f);

inline Matrix4x3::Matrix4x3()
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
    m_mat[3][0] = 0.0f;
    m_mat[3][1] = 0.0f;
    m_mat[3][2] = 0.0f;
}

inline Matrix4x3::Matrix4x3(float value)
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
    m_mat[3][0] = value;
    m_mat[3][1] = value;
    m_mat[3][2] = value;
}

inline Matrix4x3::Matrix4x3(float arr[4][3])
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
    m_mat[3][0] = arr[3][0];
    m_mat[3][1] = arr[3][1];
    m_mat[3][2] = arr[3][2];
}

inline Matrix4x3::Matrix4x3(float f00, float f01, float f02,
                     float f10, float f11, float f12,
                     float f20, float f21, float f22,
                     float f30, float f31, float f32)
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
    m_mat[3][0] = f30;
    m_mat[3][1] = f31;
    m_mat[3][2] = f32;
}

inline Matrix4x3::Matrix4x3(const Matrix4x3 &mat43)
{
    m_mat[0][0] = mat43.m_mat[0][0];
    m_mat[0][1] = mat43.m_mat[0][1];
    m_mat[0][2] = mat43.m_mat[0][2];
    m_mat[1][0] = mat43.m_mat[1][0];
    m_mat[1][1] = mat43.m_mat[1][1];
    m_mat[1][2] = mat43.m_mat[1][2];
    m_mat[2][0] = mat43.m_mat[2][0];
    m_mat[2][1] = mat43.m_mat[2][1];
    m_mat[2][2] = mat43.m_mat[2][2];
    m_mat[3][0] = mat43.m_mat[3][0];
    m_mat[3][1] = mat43.m_mat[3][1];
    m_mat[3][2] = mat43.m_mat[3][2];
}

inline Vector3 Matrix4x3::row(int index) const
{
    return Vector3(m_mat[index][0],
                   m_mat[index][1],
                   m_mat[index][2]);
}

inline Vector4 Matrix4x3::column(int index) const
{    
    return Vector4(m_mat[0][index],
                   m_mat[1][index],
                   m_mat[2][index],
                   m_mat[3][index]);
}

inline void Matrix4x3::setRow(int index, const Vector3 &vec3)
{
    m_mat[index][0] = vec3.x();
    m_mat[index][1] = vec3.y();
    m_mat[index][2] = vec3.z();
}

inline void Matrix4x3::setColumn(int index, const Vector4 &vec4)
{
    m_mat[0][index] = vec4.x();
    m_mat[1][index] = vec4.y();
    m_mat[2][index] = vec4.z();
    m_mat[3][index] = vec4.w();
}

void Matrix4x3::fill(float value)
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
    m_mat[3][0] = value;
    m_mat[3][1] = value;
    m_mat[3][2] = value;
}

inline float Matrix4x3::determinant() const
{
    return 0.0f;
}

inline void Matrix4x3::inverse(const Matrix4x3 &mat43, Matrix4x3 &result)
{
}

inline void Matrix4x3::transpose(const Matrix4x3 &mat43, Matrix3x4 &result)
{
    result.m_mat[0][0] = mat43.m_mat[0][0];
    result.m_mat[1][0] = mat43.m_mat[0][1];
    result.m_mat[2][0] = mat43.m_mat[0][2];
    result.m_mat[0][1] = mat43.m_mat[1][0];
    result.m_mat[1][1] = mat43.m_mat[1][1];
    result.m_mat[2][1] = mat43.m_mat[1][2];
    result.m_mat[0][2] = mat43.m_mat[2][0];
    result.m_mat[1][2] = mat43.m_mat[2][1];
    result.m_mat[2][2] = mat43.m_mat[2][2];
    result.m_mat[0][3] = mat43.m_mat[3][0];
    result.m_mat[1][3] = mat43.m_mat[3][1];
    result.m_mat[2][3] = mat43.m_mat[3][2];
}

inline void Matrix4x3::add(const Matrix4x3 &left, const Matrix4x3 &right, Matrix4x3 &result)
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
    result.m_mat[3][0] = left.m_mat[3][0] + right.m_mat[3][0];
    result.m_mat[3][1] = left.m_mat[3][1] + right.m_mat[3][1];
    result.m_mat[3][2] = left.m_mat[3][2] + right.m_mat[3][2];
}

inline void Matrix4x3::subtract(const Matrix4x3 &left, const Matrix4x3 &right, Matrix4x3 &result)
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
    result.m_mat[3][0] = left.m_mat[3][0] - right.m_mat[3][0];
    result.m_mat[3][1] = left.m_mat[3][1] - right.m_mat[3][1];
    result.m_mat[3][2] = left.m_mat[3][2] - right.m_mat[3][2];
}

inline void Matrix4x3::multiply(const Matrix4x3 &left, float right, Matrix4x3 &result)
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
    result.m_mat[3][0] = left.m_mat[3][0] * right;
    result.m_mat[3][1] = left.m_mat[3][1] * right;
    result.m_mat[3][2] = left.m_mat[3][2] * right;
}

inline void Matrix4x3::multiply(float left, const Matrix4x3 &right, Matrix4x3 &result)
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
    result.m_mat[3][0] = left * right.m_mat[3][0];
    result.m_mat[3][1] = left * right.m_mat[3][1];
    result.m_mat[3][2] = left * right.m_mat[3][2];
}

inline void Matrix4x3::multiply(const Matrix4x3 &left, const Matrix3x2 &right, Matrix4x2 &result)
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
    result.m_mat[3][0] = left.m_mat[3][0] * right.m_mat[0][0] + left.m_mat[3][1] * right.m_mat[1][0] +
                         left.m_mat[3][2] * right.m_mat[2][0];
    result.m_mat[3][1] = left.m_mat[3][0] * right.m_mat[0][1] + left.m_mat[3][1] * right.m_mat[1][1] +
                         left.m_mat[3][2] * right.m_mat[2][1];
}

inline void Matrix4x3::multiply(const Matrix4x3 &left, const Matrix3x3 &right, Matrix4x3 &result)
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
    result.m_mat[3][0] = left.m_mat[3][0] * right.m_mat[0][0] + left.m_mat[3][1] * right.m_mat[1][0] +
                         left.m_mat[3][2] * right.m_mat[2][0];
    result.m_mat[3][1] = left.m_mat[3][0] * right.m_mat[0][1] + left.m_mat[3][1] * right.m_mat[1][1] +
                         left.m_mat[3][2] * right.m_mat[2][1];
    result.m_mat[3][2] = left.m_mat[3][0] * right.m_mat[0][2] + left.m_mat[3][1] * right.m_mat[1][2] +
                         left.m_mat[3][2] * right.m_mat[2][2];
}

inline void Matrix4x3::multiply(const Matrix4x3 &left, const Matrix3x4 &right, Matrix4x4 &result)
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
    result.m_mat[1][3] = left.m_mat[1][0] * right.m_mat[0][3] + left.m_mat[1][1] * right.m_mat[1][3] +
                         left.m_mat[1][2] * right.m_mat[2][3];
    result.m_mat[2][0] = left.m_mat[2][0] * right.m_mat[0][0] + left.m_mat[2][1] * right.m_mat[1][0] +
                         left.m_mat[2][2] * right.m_mat[2][0];
    result.m_mat[2][1] = left.m_mat[2][0] * right.m_mat[0][1] + left.m_mat[2][1] * right.m_mat[1][1] +
                         left.m_mat[2][2] * right.m_mat[2][1];
    result.m_mat[2][2] = left.m_mat[2][0] * right.m_mat[0][2] + left.m_mat[2][1] * right.m_mat[1][2] +
                         left.m_mat[2][2] * right.m_mat[2][2];
    result.m_mat[2][3] = left.m_mat[2][0] * right.m_mat[0][3] + left.m_mat[2][1] * right.m_mat[1][3] +
                         left.m_mat[2][2] * right.m_mat[2][3];
    result.m_mat[3][0] = left.m_mat[3][0] * right.m_mat[0][0] + left.m_mat[3][1] * right.m_mat[1][0] +
                         left.m_mat[3][2] * right.m_mat[2][0];
    result.m_mat[3][1] = left.m_mat[3][0] * right.m_mat[0][1] + left.m_mat[3][1] * right.m_mat[1][1] +
                         left.m_mat[3][2] * right.m_mat[2][1];
    result.m_mat[3][2] = left.m_mat[3][0] * right.m_mat[0][2] + left.m_mat[3][1] * right.m_mat[1][2] +
                         left.m_mat[3][2] * right.m_mat[2][2];
    result.m_mat[3][3] = left.m_mat[3][0] * right.m_mat[0][3] + left.m_mat[3][1] * right.m_mat[1][3] +
                         left.m_mat[3][2] * right.m_mat[2][3];
}

inline void Matrix4x3::multiply(const Matrix4x3 &left, const Vector3 &right, Vector4 &result)
{
    float x = left.m_mat[0][0] * right.x() + left.m_mat[0][1] * right.y() + 
              left.m_mat[0][2] * right.z();
    float y = left.m_mat[1][0] * right.x() + left.m_mat[1][1] * right.y() +
              left.m_mat[1][2] * right.z();
    float z = left.m_mat[2][0] * right.x() + left.m_mat[2][1] * right.y() +
              left.m_mat[2][2] * right.z();
    float w = left.m_mat[3][0] * right.x() + left.m_mat[3][1] * right.y() +
              left.m_mat[3][2] * right.z();

    result.setX(x);
    result.setY(y);
    result.setZ(z);
    result.setW(w);
}

inline void Matrix4x3::multiply(const Vector4 &left, const Matrix4x3 &right, Vector3 &result)
{
    float x = left.x() * right.m_mat[0][0] + left.y() * right.m_mat[1][0] + 
              left.z() * right.m_mat[2][0] + left.w() * right.m_mat[3][0];
    float y = left.x() * right.m_mat[0][1] + left.y() * right.m_mat[1][1] +
              left.z() * right.m_mat[2][1] + left.w() * right.m_mat[3][1];
    float z = left.x() * right.m_mat[0][2] + left.y() * right.m_mat[1][2] +
              left.z() * right.m_mat[2][2] + left.w() * right.m_mat[3][2];

    result.setX(x);
    result.setY(y);
    result.setZ(z);
}

inline Matrix4x3 Matrix4x3::inverse(const Matrix4x3 &mat43)
{
    Matrix4x3 result;
    inverse(mat43, result);
    return result;
}

inline Matrix3x4 Matrix4x3::transpose(const Matrix4x3 &mat43)
{
    Matrix3x4 result;
    transpose(mat43, result);
    return result;
}

inline Matrix4x3 Matrix4x3::add(const Matrix4x3 &left, const Matrix4x3 &right)
{
    Matrix4x3 result;
    add(left, right, result);
    return result;
}

inline Matrix4x3 Matrix4x3::subtract(const Matrix4x3 &left, const Matrix4x3 &right)
{
    Matrix4x3 result;
    subtract(left, right, result);
    return result;
}

inline Matrix4x3 Matrix4x3::multiply(const Matrix4x3 &left, float right)
{
    Matrix4x3 result;
    multiply(left, right, result);
    return result;
}

inline Matrix4x3 Matrix4x3::multiply(float left, const Matrix4x3 &right)
{
    Matrix4x3 result;
    multiply(left, right, result);
    return result;
}

inline Matrix4x2 Matrix4x3::multiply(const Matrix4x3 &left, const Matrix3x2 &right)
{
    Matrix4x2 result;
    multiply(left, right, result);
    return result;
}

inline Matrix4x3 Matrix4x3::multiply(const Matrix4x3 &left, const Matrix3x3 &right)
{
    Matrix4x3 result;
    multiply(left, right, result);
    return result;
}

inline Matrix4x4 Matrix4x3::multiply(const Matrix4x3 &left, const Matrix3x4 &right)
{
    Matrix4x4 result;
    multiply(left, right, result);
    return result;
}

inline Vector4 Matrix4x3::multiply(const Matrix4x3 &left, const Vector3 &right)
{
    Vector4 result;
    multiply(left, right, result);
    return result;
}

inline Vector3 Matrix4x3::multiply(const Vector4 &left, const Matrix4x3 &right)
{
    Vector3 result;
    multiply(left, right, result);
    return result;
}

inline Matrix4x3 &Matrix4x3::operator=(const Matrix4x3 &mat43)
{
    m_mat[0][0] = mat43.m_mat[0][0];
    m_mat[0][1] = mat43.m_mat[0][1];
    m_mat[0][2] = mat43.m_mat[0][2];
    m_mat[1][0] = mat43.m_mat[1][0];
    m_mat[1][1] = mat43.m_mat[1][1];
    m_mat[1][2] = mat43.m_mat[1][2];
    m_mat[2][0] = mat43.m_mat[2][0];
    m_mat[2][1] = mat43.m_mat[2][1];
    m_mat[2][2] = mat43.m_mat[2][2];
    m_mat[3][0] = mat43.m_mat[3][0];
    m_mat[3][1] = mat43.m_mat[2][1];
    m_mat[3][2] = mat43.m_mat[3][2];
    return *this;
}

inline bool operator==(const Matrix4x3 &m1, const Matrix4x3 &m2)
{
    for (int r = 0; r < 4; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (m1.m_mat[r][c] != m2.m_mat[r][c])
                return false;
        }
    }

    return true;
}

inline bool operator!=(const Matrix4x3 &m1, const Matrix4x3 &m2)
{
    for (int r = 0; r < 4; r++)
    {
        for (int c = 0; c < 3; r++)
        {
            if (m1.m_mat[r][c] != m2.m_mat[r][c])
                return true;
        }
    }

    return false;
}

inline Matrix4x2 operator*(const Matrix4x3 &m43, const Matrix3x2 &m32)
{
    return Matrix4x3::multiply(m43, m32);
}

inline Matrix4x3 operator*(const Matrix4x3 &m43, const Matrix3x3 &m33)
{
    return Matrix4x3::multiply(m43, m33);
}

inline Matrix4x4 operator*(const Matrix4x3 &m43, const Matrix3x4 &m34)
{
    return Matrix4x3::multiply(m43, m34);
}

inline Vector4 operator*(const Matrix4x3 &mat43, const Vector3 &vec4)
{
    return Matrix4x3::multiply(mat43, vec4);
}

inline Vector3 operator*(const Vector4 &vec3, const Matrix4x3 &mat43)
{
    return Matrix4x3::multiply(vec3, mat43);
}
