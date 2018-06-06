#include "vector4.h"
#include "matrix4x2.h"
#include "matrix4x3.h"

const float Matrix4x4::EPSILON = 1e-06;

const Matrix4x4 Matrix4x4::ZERO     (0.0f, 0.0f, 0.0f, 0.0f,
                                     0.0f, 0.0f, 0.0f, 0.0f,
                                     0.0f, 0.0f, 0.0f, 0.0f,
                                     0.0f, 0.0f, 0.0f, 0.0f);

const Matrix4x4 Matrix4x4::IDENTITY (1.0f, 0.0f, 0.0f, 0.0f,
                                     0.0f, 1.0f, 0.0f, 0.0f,
                                     0.0f, 0.0f, 1.0f, 0.0f,
                                     0.0f, 0.0f, 0.0f, 1.0f);
inline Matrix4x4::Matrix4x4()
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
    m_mat[3][0] = 0.0f;
    m_mat[3][1] = 0.0f;
    m_mat[3][2] = 0.0f;
    m_mat[3][3] = 0.0f;
}

inline Matrix4x4::Matrix4x4(float value)
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
    m_mat[3][0] = value;
    m_mat[3][1] = value;
    m_mat[3][2] = value;
    m_mat[3][3] = value;
}

inline Matrix4x4::Matrix4x4(float arr[4][4])
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
    m_mat[3][0] = arr[3][0];
    m_mat[3][1] = arr[3][1];
    m_mat[3][2] = arr[3][2];
    m_mat[3][3] = arr[3][3];
}

inline Matrix4x4::Matrix4x4(float f00, float f01, float f02, float f03,
                             float f10, float f11, float f12, float f13,
                             float f20, float f21, float f22, float f23,
                             float f30, float f31, float f32, float f33)
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
    m_mat[3][0] = f30;
    m_mat[3][1] = f31;
    m_mat[3][2] = f32;
    m_mat[3][3] = f33;
}

Matrix4x4::Matrix4x4(const Matrix4x4 &mat4)
{
    m_mat[0][0] = mat4.m_mat[0][0];
    m_mat[0][1] = mat4.m_mat[0][1];
    m_mat[0][2] = mat4.m_mat[0][2];
    m_mat[0][3] = mat4.m_mat[0][3];
    m_mat[1][0] = mat4.m_mat[1][0];
    m_mat[1][1] = mat4.m_mat[1][1];
    m_mat[1][2] = mat4.m_mat[1][2];
    m_mat[1][3] = mat4.m_mat[1][3];
    m_mat[2][0] = mat4.m_mat[2][0];
    m_mat[2][1] = mat4.m_mat[2][1];
    m_mat[2][2] = mat4.m_mat[2][2];
    m_mat[2][3] = mat4.m_mat[2][3];
    m_mat[3][0] = mat4.m_mat[3][0];
    m_mat[3][1] = mat4.m_mat[3][1];
    m_mat[3][2] = mat4.m_mat[3][2];
    m_mat[3][3] = mat4.m_mat[3][3];
}

inline Vector4 Matrix4x4::row(int index) const
{
    return Vector4(m_mat[index][0],
                   m_mat[index][1],
                   m_mat[index][2],
                   m_mat[index][3]);
}

inline Vector4 Matrix4x4::column(int index) const
{
    return Vector4(m_mat[0][index],
                   m_mat[1][index],
                   m_mat[2][index],
                   m_mat[3][index]);
}

inline void Matrix4x4::setRow(int index, const Vector4 &vec4)
{
    m_mat[index][0] = vec4.x();
    m_mat[index][1] = vec4.y();
    m_mat[index][2] = vec4.z();
    m_mat[index][3] = vec4.w();
}

inline void Matrix4x4::setColumn(int index, const Vector4 &vec4)
{
    m_mat[0][index] = vec4.x();
    m_mat[1][index] = vec4.y();
    m_mat[2][index] = vec4.z();
    m_mat[3][index] = vec4.w();
}

inline void Matrix4x4::fill(float value)
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
    m_mat[3][0] = value;
    m_mat[3][1] = value;
    m_mat[3][2] = value;
    m_mat[3][3] = value;
}

inline bool Matrix4x4::isAffine() const
{
    return (m_mat[0][2] == 0.0f &&
            m_mat[1][2] == 0.0f &&
            m_mat[2][2] == 0.0f &&
            m_mat[3][3] == 1.0f);
}

inline void Matrix4x4::fromAxes(const Vector4 &xAxis, const Vector4 &yAxis,
                     const Vector4 &zAxis, const Vector4 &wAxis)
{
    setColumn(0, xAxis);
    setColumn(1, yAxis);
    setColumn(2, zAxis);
    setColumn(4, wAxis);
}

inline float Matrix4x4::determinant() const
{
	return 0.0f;
}

inline void Matrix4x4::inverse(const Matrix4x4 &mat4, Matrix4x4 &result)
{
    
}

inline void Matrix4x4::transpose(const Matrix4x4 &mat4, Matrix4x4 &result)
{
    result.m_mat[0][0] = mat4.m_mat[0][0];
    result.m_mat[0][1] = mat4.m_mat[1][0];
    result.m_mat[0][2] = mat4.m_mat[2][0];
    result.m_mat[0][3] = mat4.m_mat[3][0];
    result.m_mat[1][0] = mat4.m_mat[0][1];
    result.m_mat[1][1] = mat4.m_mat[1][1];
    result.m_mat[1][2] = mat4.m_mat[2][1];
    result.m_mat[1][3] = mat4.m_mat[3][1];
    result.m_mat[2][0] = mat4.m_mat[0][2];
    result.m_mat[2][1] = mat4.m_mat[1][2];
    result.m_mat[2][2] = mat4.m_mat[2][2];
    result.m_mat[2][3] = mat4.m_mat[3][2];
    result.m_mat[3][0] = mat4.m_mat[0][3];
    result.m_mat[3][1] = mat4.m_mat[1][3];
    result.m_mat[3][2] = mat4.m_mat[2][3];
    result.m_mat[3][3] = mat4.m_mat[3][3];
}

inline void Matrix4x4::add(const Matrix4x4 &left, const Matrix4x4 &right, Matrix4x4 &result)
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
    result.m_mat[3][0] = left.m_mat[3][0] + right.m_mat[3][0];
    result.m_mat[3][1] = left.m_mat[3][1] + right.m_mat[3][1];
    result.m_mat[3][2] = left.m_mat[3][2] + right.m_mat[3][2];
    result.m_mat[3][3] = left.m_mat[3][3] + right.m_mat[3][3];
}

inline void Matrix4x4::subtract(const Matrix4x4 &left, const Matrix4x4 &right, Matrix4x4 &result)
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
    result.m_mat[3][0] = left.m_mat[3][0] - right.m_mat[3][0];
    result.m_mat[3][1] = left.m_mat[3][1] - right.m_mat[3][1];
    result.m_mat[3][2] = left.m_mat[3][2] - right.m_mat[3][2];
    result.m_mat[3][3] = left.m_mat[3][3] - right.m_mat[3][3];
}

inline void Matrix4x4::multiply(const Matrix4x4 &left, const Matrix4x2 &right, Matrix4x2 &result)
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
    result.m_mat[2][1] = left.m_mat[2][0] * right.m_mat[0][1] + left.m_mat[2][1] * right.m_mat[1][1] + 
                         left.m_mat[2][2] * right.m_mat[2][1] + left.m_mat[2][3] * right.m_mat[3][1];
    result.m_mat[3][0] = left.m_mat[3][0] * right.m_mat[0][0] + left.m_mat[3][1] * right.m_mat[1][0] +
                         left.m_mat[3][2] * right.m_mat[2][0] + left.m_mat[3][3] * right.m_mat[3][0];
    result.m_mat[3][1] = left.m_mat[3][0] * right.m_mat[0][1] + left.m_mat[3][1] * right.m_mat[1][1] +
                         left.m_mat[3][2] * right.m_mat[2][1] + left.m_mat[3][3] * right.m_mat[3][1];
}

inline void Matrix4x4::multiply(const Matrix4x4 &left, const Matrix4x3 &right, Matrix4x3 &result)
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
                         left.m_mat[2][2] * right.m_mat[2][1] + left.m_mat[2][3] * right.m_mat[3][2];
    result.m_mat[3][0] = left.m_mat[3][0] * right.m_mat[0][0] + left.m_mat[3][1] * right.m_mat[1][0] +
                         left.m_mat[3][2] * right.m_mat[2][0] + left.m_mat[3][3] * right.m_mat[3][0];
    result.m_mat[3][1] = left.m_mat[3][0] * right.m_mat[0][1] + left.m_mat[3][1] * right.m_mat[1][1] +
                         left.m_mat[3][2] * right.m_mat[2][1] + left.m_mat[3][3] * right.m_mat[3][1];
    result.m_mat[3][2] = left.m_mat[3][0] * right.m_mat[0][2] + left.m_mat[3][1] * right.m_mat[1][2] +
                         left.m_mat[3][2] * right.m_mat[2][2] + left.m_mat[3][3] * right.m_mat[3][2];
}

inline void Matrix4x4::multiply(const Matrix4x4 &left, const Matrix4x4 &right, Matrix4x4 &result)
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
    result.m_mat[2][3] = left.m_mat[2][0] * right.m_mat[0][3] + left.m_mat[2][1] * right.m_mat[1][3] + 
                         left.m_mat[2][2] * right.m_mat[2][3] + left.m_mat[2][3] * right.m_mat[3][3];
    result.m_mat[3][0] = left.m_mat[3][0] * right.m_mat[0][0] + left.m_mat[3][1] * right.m_mat[1][0] +
                         left.m_mat[3][2] * right.m_mat[2][0] + left.m_mat[3][3] * right.m_mat[3][0];
    result.m_mat[3][1] = left.m_mat[3][0] * right.m_mat[0][1] + left.m_mat[3][1] * right.m_mat[1][1] +
                         left.m_mat[3][2] * right.m_mat[2][1] + left.m_mat[3][3] * right.m_mat[3][1];
    result.m_mat[3][2] = left.m_mat[3][0] * right.m_mat[0][2] + left.m_mat[3][1] * right.m_mat[1][2] +
                         left.m_mat[3][2] * right.m_mat[2][2] + left.m_mat[3][3] * right.m_mat[3][2];
    result.m_mat[3][3] = left.m_mat[3][0] * right.m_mat[0][3] + left.m_mat[3][1] * right.m_mat[1][3] +
                         left.m_mat[3][2] * right.m_mat[2][3] + left.m_mat[3][3] * right.m_mat[3][3];
}   

inline void Matrix4x4::multiply(const Matrix4x4 &left, float right, Matrix4x4 &result)
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
    result.m_mat[3][0] = left.m_mat[3][0] * right;
    result.m_mat[3][1] = left.m_mat[3][1] * right;
    result.m_mat[3][2] = left.m_mat[3][2] * right;
    result.m_mat[3][3] = left.m_mat[3][3] * right;
}

inline void Matrix4x4::multiply(float left, const Matrix4x4 &right, Matrix4x4 &result)
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
    result.m_mat[3][0] = left * right.m_mat[3][0];
    result.m_mat[3][1] = left * right.m_mat[3][1];
    result.m_mat[3][2] = left * right.m_mat[3][2];
    result.m_mat[3][3] = left * right.m_mat[3][3];
}

inline void Matrix4x4::multiply(const Matrix4x4 &left, const Vector4 &right, Vector4 &result)
{
    float x = left.m_mat[0][0] * right.x() + left.m_mat[0][1] * right.y() + 
              left.m_mat[0][2] * right.z() + left.m_mat[0][3] * right.w();
    float y = left.m_mat[1][0] * right.x() + left.m_mat[1][1] * right.y() +
              left.m_mat[1][2] * right.z() + left.m_mat[1][3] * right.w();
    float z = left.m_mat[2][0] * right.x() + left.m_mat[2][1] * right.y() +
              left.m_mat[2][2] * right.z() + left.m_mat[2][3] * right.w();
    float w = left.m_mat[3][0] * right.x() + left.m_mat[3][1] * right.y() +
              left.m_mat[3][2] * right.z() + left.m_mat[3][3] * right.w();

    result.setX(x);
    result.setY(y);
    result.setZ(z);
    result.setW(w);
}

inline void Matrix4x4::multiply(const Vector4 &left, const Matrix4x4 &right, Vector4 &result)
{
    float x = left.x() * right.m_mat[0][0] + left.y() * right.m_mat[1][0] + 
              left.z() * right.m_mat[2][0] + left.w() * right.m_mat[3][0];
    float y = left.x() * right.m_mat[0][1] + left.y() * right.m_mat[1][1] + 
              left.z() * right.m_mat[2][1] + left.w() * right.m_mat[3][1]; 
    float z = left.x() * right.m_mat[0][2] + left.y() * right.m_mat[1][2] + 
              left.z() * right.m_mat[2][2] + left.w() * right.m_mat[3][2];
    float w = left.x() * right.m_mat[0][3] + left.y() * right.m_mat[1][3] + 
              left.z() * right.m_mat[2][3] + left.w() * right.m_mat[3][3];

    result.setX(x);
    result.setY(y);
    result.setZ(z);
    result.setW(w);
}

inline Matrix4x4 Matrix4x4::inverse(const Matrix4x4 &mat4)
{
    Matrix4x4 result;
    inverse(mat4, result);
    return result;
}

inline Matrix4x4 Matrix4x4::transpose(const Matrix4x4 &mat4)
{
    Matrix4x4 result;
    transpose(mat4, result);
    return result;
}

inline Matrix4x4 Matrix4x4::add(const Matrix4x4 &left, const Matrix4x4 &right)
{
    Matrix4x4 result;
    add(left, right, result);
    return result;
}

inline Matrix4x4 Matrix4x4::subtract(const Matrix4x4 &left, const Matrix4x4 &right)
{
    Matrix4x4 result;
    subtract(left, right, result);
    return result;
}

inline Matrix4x4 Matrix4x4::multiply(const Matrix4x4 &left, float right)
{
    Matrix4x4 result;
    multiply(left, right, result);
    return result;
}

inline Matrix4x4 Matrix4x4::multiply(float left, const Matrix4x4 &right)
{
    Matrix4x4 result;
    multiply(left, right, result);
    return result;
}

inline Matrix4x2 Matrix4x4::multiply(const Matrix4x4 &left, const Matrix4x2 &right)
{
    Matrix4x2 result;
    multiply(left, right, result);
    return result;
}

inline Matrix4x3 Matrix4x4::multiply(const Matrix4x4 &left, const Matrix4x3 &right)
{
    Matrix4x3 result;
    multiply(left, right, result);
    return result;
}

inline Matrix4x4 Matrix4x4::multiply(const Matrix4x4 &left, const Matrix4x4 &right)
{
    Matrix4x4 result;
    multiply(left, right, result);
    return result;
}

inline Vector4 Matrix4x4::multiply(const Matrix4x4 &left, const Vector4 &right)
{
    Vector4 result;
    multiply(left, right, result);
    return result;
}

inline Vector4 Matrix4x4::multiply(const Vector4 &left, const Matrix4x4 &right)
{
    Vector4 result;
    multiply(left, right, result);
    return result;
}

inline Matrix4x4 &Matrix4x4::operator=(const Matrix4x4 &mat4)
{
    m_mat[0][0] = mat4.m_mat[0][0];
    m_mat[0][1] = mat4.m_mat[0][1];
    m_mat[0][2] = mat4.m_mat[0][2];
    m_mat[0][3] = mat4.m_mat[0][3];
    m_mat[1][0] = mat4.m_mat[1][0];
    m_mat[1][1] = mat4.m_mat[1][1];
    m_mat[1][2] = mat4.m_mat[1][2];
    m_mat[1][3] = mat4.m_mat[1][3];
    m_mat[2][0] = mat4.m_mat[2][0];
    m_mat[2][1] = mat4.m_mat[2][1];
    m_mat[2][2] = mat4.m_mat[2][2];
    m_mat[2][3] = mat4.m_mat[2][3];
    m_mat[3][0] = mat4.m_mat[3][0];
    m_mat[3][1] = mat4.m_mat[3][1];
    m_mat[3][3] = mat4.m_mat[3][3];
    m_mat[3][3] = mat4.m_mat[3][3];
    return *this;
}

inline bool operator==(const Matrix4x4 &m1, const Matrix4x4 &m2)
{
    for (int r = 0; r < 4; r++)
    {
        for (int c = 0; c < 4; c++)
        {
            if (m1.m_mat[r][c] != m2.m_mat[r][c])
                return false;
        }
    }

    return true;
}

inline bool operator!=(const Matrix4x4 &m1, const Matrix4x4 &m2)
{
    for (int r = 0; r < 4; r++)
    {
        for (int c = 0; c < 4; r++)
        {
            if (m1.m_mat[r][c] != m2.m_mat[r][c])
                return true;
        }
    }

    return false;
}

inline Matrix4x2 operator*(const Matrix4x4 &m44, const Matrix4x2 &m42)
{
    return Matrix4x4::multiply(m44, m42);
}

inline Matrix4x3 operator*(const Matrix4x4 &m44, const Matrix4x3 &m43)
{
    return Matrix4x4::multiply(m44, m43);
}

inline Vector4 operator*(const Matrix4x4 &mat4, const Vector4 &vec4)
{
    return Matrix4x4::multiply(mat4, vec4);
}

inline Vector4 operator*(const Vector4 &vec4, const Matrix4x4 &mat4)
{
    return Matrix4x4::multiply(vec4, mat4);
}
