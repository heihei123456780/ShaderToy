#include "vector2.h"
#include "vector4.h"
#include "matrix2x2.h"
#include "matrix2x3.h"
#include "matrix2x4.h"
#include "matrix4x2.h"
#include "matrix4x3.h"
#include "matrix4x4.h"

const Matrix4x2 Matrix4x2::ZERO(0.0f, 0.0f,
                                0.0f, 0.0f,
                                0.0f, 0.0f,
                                0.0f, 0.0f);

Matrix4x2::Matrix4x2()
{
    m_mat[0][0] = 0.0f;
    m_mat[0][1] = 0.0f;
    m_mat[1][0] = 0.0f;
    m_mat[1][1] = 0.0f;
    m_mat[2][0] = 0.0f;
    m_mat[2][1] = 0.0f;
    m_mat[3][0] = 0.0f;
    m_mat[3][1] = 0.0f;
}

Matrix4x2::Matrix4x2(float value)
{
    m_mat[0][0] = value;
    m_mat[0][1] = value;
    m_mat[1][0] = value;
    m_mat[1][1] = value;
    m_mat[2][0] = value;
    m_mat[2][1] = value;
    m_mat[3][0] = value;
    m_mat[3][1] = value;
}

Matrix4x2::Matrix4x2(float arr[4][2])
{
    m_mat[0][0] = arr[0][0];
    m_mat[0][1] = arr[0][1];
    m_mat[1][0] = arr[1][0];
    m_mat[1][1] = arr[1][1];
    m_mat[2][0] = arr[2][0];
    m_mat[2][1] = arr[2][1];
    m_mat[3][0] = arr[2][0];
    m_mat[3][1] = arr[3][1];
}

Matrix4x2::Matrix4x2(float f00, float f01,
                     float f10, float f11,
                     float f20, float f21,
                     float f30, float f31)
{
    m_mat[0][0] = f00;
    m_mat[0][1] = f01;
    m_mat[1][0] = f10;
    m_mat[1][1] = f11;
    m_mat[2][0] = f20;
    m_mat[2][1] = f21;
    m_mat[3][0] = f30;
    m_mat[3][1] = f21;
}

Matrix4x2::Matrix4x2(const Matrix4x2 &mat42)
{
    m_mat[0][0] = mat42.m_mat[0][0];
    m_mat[0][1] = mat42.m_mat[0][1];
    m_mat[1][0] = mat42.m_mat[1][0];
    m_mat[1][1] = mat42.m_mat[1][1];
    m_mat[2][0] = mat42.m_mat[2][0];
    m_mat[2][1] = mat42.m_mat[2][1];
    m_mat[3][0] = mat42.m_mat[3][0];
    m_mat[3][1] = mat42.m_mat[3][1];
}

Vector2 Matrix4x2::row(int index) const
{
    return Vector2(m_mat[index][0],
                   m_mat[index][1]);
}

Vector4 Matrix4x2::column(int index) const
{    
    return Vector4(m_mat[0][index],
                   m_mat[1][index],
                   m_mat[2][index],
                   m_mat[3][index]);
}

void Matrix4x2::setRow(int index, const Vector2 &vec2)
{
    m_mat[index][0] = vec2.x();
    m_mat[index][1] = vec2.y();
}

void Matrix4x2::setColumn(int index, const Vector4 &vec4)
{
    m_mat[0][index] = vec4.x();
    m_mat[1][index] = vec4.y();
    m_mat[2][index] = vec4.z();
    m_mat[3][index] = vec4.w();
}

void Matrix4x2::fill(float value)
{
    m_mat[0][0] = value;
    m_mat[0][1] = value;
    m_mat[1][0] = value;
    m_mat[1][1] = value;
    m_mat[2][0] = value;
    m_mat[2][1] = value;
    m_mat[3][0] = value;
    m_mat[3][1] = value;
}

float Matrix4x2::determinant() const
{
   return 0.0f;
}

void Matrix4x2::inverse(const Matrix4x2 &mat42, Matrix4x2 &result)
{
    
}

void Matrix4x2::transpose(const Matrix4x2 &mat42, Matrix2x4 &result)
{
    result.m_mat[0][0] = mat42.m_mat[0][0];
    result.m_mat[1][0] = mat42.m_mat[0][1];
    result.m_mat[0][1] = mat42.m_mat[1][0];
    result.m_mat[1][1] = mat42.m_mat[1][1];
    result.m_mat[0][2] = mat42.m_mat[2][0];
    result.m_mat[1][2] = mat42.m_mat[2][1];
    result.m_mat[0][3] = mat42.m_mat[3][0];
    result.m_mat[1][3] = mat42.m_mat[3][1];
}

void Matrix4x2::add(const Matrix4x2 &left, const Matrix4x2 &right, Matrix4x2 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] + right.m_mat[0][0];
    result.m_mat[0][1] = left.m_mat[0][1] + right.m_mat[0][1];
    result.m_mat[1][0] = left.m_mat[1][0] + right.m_mat[1][0];
    result.m_mat[1][1] = left.m_mat[1][1] + right.m_mat[1][1];
    result.m_mat[2][0] = left.m_mat[2][0] + right.m_mat[2][0];
    result.m_mat[2][1] = left.m_mat[2][1] + right.m_mat[2][1];
    result.m_mat[3][0] = left.m_mat[3][0] + right.m_mat[3][0];
    result.m_mat[3][1] = left.m_mat[3][1] + right.m_mat[3][1];
}

void Matrix4x2::subtract(const Matrix4x2 &left, const Matrix4x2 &right, Matrix4x2 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] - right.m_mat[0][0];
    result.m_mat[0][1] = left.m_mat[0][1] - right.m_mat[0][1];
    result.m_mat[1][0] = left.m_mat[1][0] - right.m_mat[1][0];
    result.m_mat[1][1] = left.m_mat[1][1] - right.m_mat[1][1];
    result.m_mat[2][0] = left.m_mat[2][0] - right.m_mat[2][0];
    result.m_mat[2][1] = left.m_mat[2][1] - right.m_mat[2][1];
    result.m_mat[3][0] = left.m_mat[3][0] - right.m_mat[3][0];
    result.m_mat[3][1] = left.m_mat[3][1] - right.m_mat[3][1];
}

void Matrix4x2::multiply(const Matrix4x2 &left, float right, Matrix4x2 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] * right;
    result.m_mat[0][1] = left.m_mat[0][1] * right;
    result.m_mat[1][0] = left.m_mat[1][0] * right;
    result.m_mat[1][1] = left.m_mat[1][1] * right;
    result.m_mat[2][0] = left.m_mat[2][0] * right;
    result.m_mat[2][1] = left.m_mat[2][1] * right;
    result.m_mat[3][0] = left.m_mat[3][0] * right;
    result.m_mat[3][1] = left.m_mat[3][1] * right;
}

void Matrix4x2::multiply(float left, const Matrix4x2 &right, Matrix4x2 &result)
{
    result.m_mat[0][0] = left * right.m_mat[0][0];
    result.m_mat[0][1] = left * right.m_mat[0][1];
    result.m_mat[1][0] = left * right.m_mat[1][0];
    result.m_mat[1][1] = left * right.m_mat[1][1];
    result.m_mat[2][0] = left * right.m_mat[2][0];
    result.m_mat[2][1] = left * right.m_mat[2][1];
    result.m_mat[3][0] = left * right.m_mat[3][0];
    result.m_mat[3][1] = left * right.m_mat[3][1];
}

void Matrix4x2::multiply(const Matrix4x2 &left, const Matrix2x2 &right, Matrix4x2 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] * right.m_mat[0][0] + left.m_mat[0][1] * right.m_mat[1][0];
    result.m_mat[0][1] = left.m_mat[0][0] * right.m_mat[0][1] + left.m_mat[0][1] * right.m_mat[1][1];
    result.m_mat[1][0] = left.m_mat[1][0] * right.m_mat[0][0] + left.m_mat[1][1] * right.m_mat[1][0];
    result.m_mat[1][1] = left.m_mat[1][0] * right.m_mat[0][1] + left.m_mat[1][1] * right.m_mat[1][1];
    result.m_mat[2][0] = left.m_mat[2][0] * right.m_mat[0][0] + left.m_mat[2][1] * right.m_mat[1][0];
    result.m_mat[2][1] = left.m_mat[2][0] * right.m_mat[0][1] + left.m_mat[2][1] * right.m_mat[1][1];
    result.m_mat[3][0] = left.m_mat[3][0] * right.m_mat[0][0] + left.m_mat[3][1] * right.m_mat[1][0];
    result.m_mat[3][1] = left.m_mat[3][0] * right.m_mat[0][1] + left.m_mat[3][1] * right.m_mat[1][1];
}

void Matrix4x2::multiply(const Matrix4x2 &left, const Matrix2x3 &right, Matrix4x3 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] * right.m_mat[0][0] + left.m_mat[0][1] * right.m_mat[1][0];
    result.m_mat[0][1] = left.m_mat[0][0] * right.m_mat[0][1] + left.m_mat[0][1] * right.m_mat[1][1];
    result.m_mat[0][2] = left.m_mat[0][0] * right.m_mat[0][2] + left.m_mat[0][1] * right.m_mat[1][2];
    result.m_mat[1][0] = left.m_mat[1][0] * right.m_mat[0][0] + left.m_mat[1][1] * right.m_mat[1][0];
    result.m_mat[1][1] = left.m_mat[1][0] * right.m_mat[0][1] + left.m_mat[1][1] * right.m_mat[1][1];
    result.m_mat[1][2] = left.m_mat[1][0] * right.m_mat[0][2] + left.m_mat[1][1] * right.m_mat[1][2];
    result.m_mat[2][0] = left.m_mat[2][0] * right.m_mat[0][0] + left.m_mat[2][1] * right.m_mat[1][0];
    result.m_mat[2][1] = left.m_mat[2][0] * right.m_mat[0][1] + left.m_mat[2][1] * right.m_mat[1][1];
    result.m_mat[2][2] = left.m_mat[2][0] * right.m_mat[0][2] + left.m_mat[2][1] * right.m_mat[1][2];
    result.m_mat[3][0] = left.m_mat[3][0] * right.m_mat[0][0] + left.m_mat[3][1] * right.m_mat[1][0];
    result.m_mat[3][1] = left.m_mat[3][0] * right.m_mat[0][1] + left.m_mat[3][1] * right.m_mat[1][1];
    result.m_mat[3][2] = left.m_mat[3][0] * right.m_mat[0][2] + left.m_mat[3][1] * right.m_mat[1][2];
}

void Matrix4x2::multiply(const Matrix4x2 &left, const Matrix2x4 &right, Matrix4x4 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] * right.m_mat[0][0] + left.m_mat[0][1] * right.m_mat[1][0];
    result.m_mat[0][1] = left.m_mat[0][0] * right.m_mat[0][1] + left.m_mat[0][1] * right.m_mat[1][1];
    result.m_mat[0][2] = left.m_mat[0][0] * right.m_mat[0][2] + left.m_mat[0][1] * right.m_mat[1][2];
    result.m_mat[0][3] = left.m_mat[0][0] * right.m_mat[0][3] + left.m_mat[0][1] * right.m_mat[1][3];
    result.m_mat[1][0] = left.m_mat[1][0] * right.m_mat[0][0] + left.m_mat[1][1] * right.m_mat[1][0];
    result.m_mat[1][1] = left.m_mat[1][0] * right.m_mat[0][1] + left.m_mat[1][1] * right.m_mat[1][1];
    result.m_mat[1][2] = left.m_mat[1][0] * right.m_mat[0][2] + left.m_mat[1][1] * right.m_mat[1][2];
    result.m_mat[1][3] = left.m_mat[1][0] * right.m_mat[0][3] + left.m_mat[1][1] * right.m_mat[1][3];
    result.m_mat[2][0] = left.m_mat[2][0] * right.m_mat[0][0] + left.m_mat[2][1] * right.m_mat[1][0];
    result.m_mat[2][1] = left.m_mat[2][0] * right.m_mat[0][1] + left.m_mat[2][1] * right.m_mat[1][1];
    result.m_mat[2][2] = left.m_mat[2][0] * right.m_mat[0][2] + left.m_mat[2][1] * right.m_mat[1][2];
    result.m_mat[2][3] = left.m_mat[2][0] * right.m_mat[0][3] + left.m_mat[2][1] * right.m_mat[1][3];
    result.m_mat[3][0] = left.m_mat[3][0] * right.m_mat[0][0] + left.m_mat[3][1] * right.m_mat[1][0];
    result.m_mat[3][1] = left.m_mat[3][0] * right.m_mat[0][1] + left.m_mat[3][1] * right.m_mat[1][1];
    result.m_mat[3][2] = left.m_mat[3][0] * right.m_mat[0][2] + left.m_mat[3][1] * right.m_mat[1][2];
    result.m_mat[3][3] = left.m_mat[3][0] * right.m_mat[0][3] + left.m_mat[3][1] * right.m_mat[1][3];
}

void Matrix4x2::multiply(const Matrix4x2 &left, const Vector2 &right, Vector4 &result)
{
    float x = left.m_mat[0][0] * right.x() + left.m_mat[0][1] * right.y();
    float y = left.m_mat[1][0] * right.x() + left.m_mat[1][1] * right.y();
    float z = left.m_mat[2][0] * right.x() + left.m_mat[2][1] * right.y();
    float w = left.m_mat[3][0] * right.x() + left.m_mat[3][1] * right.y();

    result.setX(x);
    result.setY(y);
    result.setZ(z);
    result.setW(w);
}

void Matrix4x2::multiply(const Vector4 &left, const Matrix4x2 &right, Vector2 &result)
{
    float x = left.x() * right.m_mat[0][0] + left.y() * right.m_mat[1][0] + 
              left.z() * right.m_mat[2][0] + left.w() * right.m_mat[3][0];
    float y = left.x() * right.m_mat[0][1] + left.y() * right.m_mat[1][1] +
              left.z() * right.m_mat[2][1] + left.w() * right.m_mat[3][1];

    result.setX(x);
    result.setY(y);
}

Matrix4x2 Matrix4x2::inverse(const Matrix4x2 &mat42)
{
    Matrix4x2 result;
    inverse(mat42, result);
    return result;
}

Matrix2x4 Matrix4x2::transpose(const Matrix4x2 &mat42)
{
    Matrix2x4 result;
    transpose(mat42, result);
    return result;
}

Matrix4x2 Matrix4x2::add(const Matrix4x2 &left, const Matrix4x2 &right)
{
    Matrix4x2 result;
    add(left, right, result);
    return result;
}

Matrix4x2 Matrix4x2::subtract(const Matrix4x2 &left, const Matrix4x2 &right)
{
    Matrix4x2 result;
    subtract(left, right, result);
    return result;
}

Matrix4x2 Matrix4x2::multiply(const Matrix4x2 &left, float right)
{
    Matrix4x2 result;
    multiply(left, right, result);
    return result;
}

Matrix4x2 Matrix4x2::multiply(float left, const Matrix4x2 &right)
{
    Matrix4x2 result;
    multiply(left, right, result);
    return result;
}

Matrix4x2 Matrix4x2::multiply(const Matrix4x2 &left, const Matrix2x2 &right)
{
    Matrix4x2 result;
    multiply(left, right, result);
    return result;
}

Matrix4x3 Matrix4x2::multiply(const Matrix4x2 &left, const Matrix2x3 &right)
{
    Matrix4x3 result;
    multiply(left, right, result);
    return result;
}

Matrix4x4 Matrix4x2::multiply(const Matrix4x2 &left, const Matrix2x4 &right)
{
    Matrix4x4 result;
    multiply(left, right, result);
    return result;
}

Vector4 Matrix4x2::multiply(const Matrix4x2 &left, const Vector2 &right)
{
    Vector4 result;
    multiply(left, right, result);
    return result;
}

Vector2 Matrix4x2::multiply(const Vector4 &left, const Matrix4x2 &right)
{
    Vector2 result;
    multiply(left, right, result);
    return result;
}

Matrix4x2 &Matrix4x2::operator=(const Matrix4x2 &mat42)
{
    m_mat[0][0] = mat42.m_mat[0][0];
    m_mat[0][1] = mat42.m_mat[0][1];
    m_mat[1][0] = mat42.m_mat[1][0];
    m_mat[1][1] = mat42.m_mat[1][1];
    m_mat[2][1] = mat42.m_mat[2][0];
    m_mat[2][0] = mat42.m_mat[2][1];
    m_mat[3][0] = mat42.m_mat[3][0];
    m_mat[3][1] = mat42.m_mat[3][1];
    return *this;
}

bool operator==(const Matrix4x2 &m1, const Matrix4x2 &m2)
{
    for (int r = 0; r < 4; r++)
    {
        for (int c = 0; c < 2; c++)
        {
            if (m1.m_mat[r][c] != m2.m_mat[r][c])
                return false;
        }
    }

    return true;
}

bool operator!=(const Matrix4x2 &m1, const Matrix4x2 &m2)
{
    for (int r = 0; r < 4; r++)
    {
        for (int c = 0; c < 2; r++)
        {
            if (m1.m_mat[r][c] != m2.m_mat[r][c])
                return true;
        }
    }

    return false;
}

Matrix4x2 operator*(const Matrix4x2 &m42, const Matrix2x2 &m22)
{
    return Matrix4x2::multiply(m42, m22);
}

Matrix4x3 operator*(const Matrix4x2 &m42, const Matrix2x3 &m23)
{
    return Matrix4x2::multiply(m42, m23);
}

Matrix4x4 operator*(const Matrix4x2 &m42, const Matrix2x4 &m24)
{
    return Matrix4x2::multiply(m42, m24);
}

Vector4 operator*(const Matrix4x2 &mat42, const Vector2 &vec2)
{
    return Matrix4x2::multiply(mat42, vec2);
}

Vector2 operator*(const Vector4 &vec4, const Matrix4x2 &mat42)
{
    return Matrix4x2::multiply(vec4, mat42);
}
