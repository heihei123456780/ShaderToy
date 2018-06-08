#include "vector2.h"
#include "vector4.h"
#include "matrix2x2.h"
#include "matrix2x3.h"
#include "matrix2x4.h"
#include "matrix4x2.h"
#include "matrix4x3.h"
#include "matrix4x4.h"

const Matrix2x4 Matrix2x4::ZERO(0.0f, 0.0f, 0.0f, 0.0f,
                                0.0f, 0.0f, 0.0f, 0.0f);

Matrix2x4::Matrix2x4()
{
    m_mat[0][0] = 0.0f;
    m_mat[0][1] = 0.0f;
    m_mat[0][2] = 0.0f;
    m_mat[1][0] = 0.0f;
    m_mat[1][1] = 0.0f;
    m_mat[1][2] = 0.0f;
}

Matrix2x4::Matrix2x4(float arr[2][4])
{
    m_mat[0][0] = arr[0][0];
    m_mat[0][1] = arr[0][1];
    m_mat[0][2] = arr[0][2];
    m_mat[1][0] = arr[1][0];
    m_mat[1][1] = arr[1][1];
    m_mat[1][2] = arr[1][2];
}

Matrix2x4::Matrix2x4(float f00, float f01, float f02, float f03,
                     float f10, float f11, float f12, float f13)
{
    m_mat[0][0] = f00;
    m_mat[0][1] = f01;
    m_mat[0][2] = f02;
    m_mat[0][3] = f03;
    m_mat[1][0] = f10;
    m_mat[1][1] = f11;
    m_mat[1][2] = f12;
    m_mat[1][3] = f13;
}

Matrix2x4::Matrix2x4(const Matrix2x4 &mat24)
{
    m_mat[0][0] = mat24.m_mat[0][0];
    m_mat[0][1] = mat24.m_mat[0][1];
    m_mat[0][2] = mat24.m_mat[0][2];
    m_mat[0][3] = mat24.m_mat[0][3];
    m_mat[1][0] = mat24.m_mat[1][0];
    m_mat[1][1] = mat24.m_mat[1][1];
    m_mat[1][2] = mat24.m_mat[1][2];
    m_mat[1][3] = mat24.m_mat[1][3];
}

Vector4 Matrix2x4::row(int index) const
{
    return Vector4(m_mat[index][0],
                   m_mat[index][1],
                   m_mat[index][2],
                   m_mat[index][3]);
}

Vector2 Matrix2x4::column(int index) const
{
    return Vector2(m_mat[0][index],
                   m_mat[1][index]);
}

void Matrix2x4::setRow(int index, const Vector4 &vec4)
{
    m_mat[index][0] = vec4.x();
    m_mat[index][1] = vec4.y();
    m_mat[index][2] = vec4.z();
    m_mat[index][3] = vec4.w();
}

void Matrix2x4::setColumn(int index, const Vector2 &vec2)
{
    m_mat[0][index] = vec2.x();
    m_mat[1][index] = vec2.y();
}

void Matrix2x4::fill(float value)
{
    m_mat[0][0] = value;
    m_mat[0][1] = value;
    m_mat[0][2] = value;
    m_mat[0][3] = value;
    m_mat[1][0] = value;
    m_mat[1][1] = value;
    m_mat[1][2] = value;
    m_mat[1][3] = value;
}

void Matrix2x4::inverse(const Matrix2x4 &mat24, Matrix2x4 &result)
{
}

void Matrix2x4::transpose(const Matrix2x4 &mat24, Matrix4x2 &result)
{
    result.m_mat[0][0] = mat24.m_mat[0][0];
    result.m_mat[1][0] = mat24.m_mat[0][1];
    result.m_mat[2][0] = mat24.m_mat[0][2];
    result.m_mat[3][0] = mat24.m_mat[0][3];
    result.m_mat[0][1] = mat24.m_mat[1][0];
    result.m_mat[1][1] = mat24.m_mat[1][1];
    result.m_mat[2][1] = mat24.m_mat[1][2];
    result.m_mat[3][1] = mat24.m_mat[1][3];
}

void Matrix2x4::add(const Matrix2x4 &left, const Matrix2x4 &right, Matrix2x4 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] + right.m_mat[0][0];
    result.m_mat[0][1] = left.m_mat[0][1] + right.m_mat[0][1];
    result.m_mat[0][2] = left.m_mat[0][2] + right.m_mat[0][2];
    result.m_mat[0][3] = left.m_mat[0][3] + right.m_mat[0][3];
    result.m_mat[1][0] = left.m_mat[1][0] + right.m_mat[1][0];
    result.m_mat[1][1] = left.m_mat[1][1] + right.m_mat[1][1];
    result.m_mat[1][2] = left.m_mat[1][2] + right.m_mat[1][2];
    result.m_mat[1][3] = left.m_mat[1][3] + right.m_mat[1][3];
}

void Matrix2x4::subtract(const Matrix2x4 &left, const Matrix2x4 &right, Matrix2x4 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] - right.m_mat[0][0];
    result.m_mat[0][1] = left.m_mat[0][1] - right.m_mat[0][1];
    result.m_mat[0][2] = left.m_mat[0][2] - right.m_mat[0][2];
    result.m_mat[0][3] = left.m_mat[0][3] - right.m_mat[0][3];
    result.m_mat[1][0] = left.m_mat[1][0] - right.m_mat[1][0];
    result.m_mat[1][1] = left.m_mat[1][1] - right.m_mat[1][1];
    result.m_mat[1][2] = left.m_mat[1][2] - right.m_mat[1][2];
    result.m_mat[1][3] = left.m_mat[1][3] - right.m_mat[1][3];
}

void Matrix2x4::multiply(const Matrix2x4 &left, float right, Matrix2x4 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] * right;
    result.m_mat[0][1] = left.m_mat[0][1] * right;
    result.m_mat[0][2] = left.m_mat[0][2] * right;
    result.m_mat[0][3] = left.m_mat[0][3] * right;
    result.m_mat[1][0] = left.m_mat[1][0] * right;
    result.m_mat[1][1] = left.m_mat[1][1] * right;
    result.m_mat[1][2] = left.m_mat[1][2] * right;
    result.m_mat[1][3] = left.m_mat[1][3] * right;
}

void Matrix2x4::multiply(float left, const Matrix2x4 &right, Matrix2x4 &result)
{
    result.m_mat[0][0] = left * right.m_mat[0][0];
    result.m_mat[0][1] = left * right.m_mat[0][1];
    result.m_mat[0][2] = left * right.m_mat[0][2];
    result.m_mat[0][3] = left * right.m_mat[0][3];
    result.m_mat[1][0] = left * right.m_mat[1][0];
    result.m_mat[1][1] = left * right.m_mat[1][1];
    result.m_mat[1][2] = left * right.m_mat[1][2];
    result.m_mat[1][3] = left * right.m_mat[1][3];
}

void Matrix2x4::multiply(const Matrix2x4 &left, const Matrix4x2 &right, Matrix2x2 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] * right.m_mat[0][0] + left.m_mat[0][1] * right.m_mat[1][0] + 
                         left.m_mat[0][2] * right.m_mat[2][0] + left.m_mat[0][3] * right.m_mat[3][0];
    result.m_mat[0][1] = left.m_mat[0][0] * right.m_mat[0][1] + left.m_mat[0][1] * right.m_mat[1][1] + 
                         left.m_mat[0][2] * right.m_mat[2][1] + left.m_mat[0][3] * right.m_mat[3][1];
    result.m_mat[1][0] = left.m_mat[1][0] * right.m_mat[0][0] + left.m_mat[1][1] * right.m_mat[1][0] + 
                         left.m_mat[1][2] * right.m_mat[2][0] + left.m_mat[1][3] * right.m_mat[3][0];
    result.m_mat[1][1] = left.m_mat[1][0] * right.m_mat[0][1] + left.m_mat[1][1] * right.m_mat[1][1] + 
                         left.m_mat[1][2] * right.m_mat[2][1] + left.m_mat[1][3] * right.m_mat[3][1];
}

void Matrix2x4::multiply(const Matrix2x4 &left, const Matrix4x3 &right, Matrix2x3 &result)
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
}

void Matrix2x4::multiply(const Matrix2x4 &left, const Matrix4x4 &right, Matrix2x4 &result)
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
}

void Matrix2x4::multiply(const Matrix2x4 &left, const Vector4 &right, Vector2 &result)
{
    float x = left.m_mat[0][0] * right.x() + left.m_mat[0][1] * right.y() + 
              left.m_mat[0][2] * right.z() + left.m_mat[0][3] * right.w();
    float y = left.m_mat[1][0] * right.x() + left.m_mat[1][1] * right.y() +
              left.m_mat[1][2] * right.z();

    result.setX(x);
    result.setY(y);
}

void Matrix2x4::multiply(const Vector2 &left, const Matrix2x4 &right, Vector4 &result)
{
    float x = left.x() * right.m_mat[0][0] + left.y() * right.m_mat[1][0];
    float y = left.x() * right.m_mat[0][1] + left.y() * right.m_mat[1][1];
    float z = left.x() * right.m_mat[0][2] + left.y() * right.m_mat[1][2];
    float w = left.x() * right.m_mat[0][3] + left.y() * right.m_mat[1][3];

    result.setX(x);
    result.setY(y);
    result.setZ(z);
    result.setW(w);
}

Matrix2x4 Matrix2x4::inverse(const Matrix2x4 &mat24)
{
    Matrix2x4 result;
    inverse(mat24, result);
    return result;
}

Matrix4x2 Matrix2x4::transpose(const Matrix2x4 &mat24)
{
    Matrix4x2 result;
    transpose(mat24, result);
    return result;
}

Matrix2x4 Matrix2x4::add(const Matrix2x4 &left, const Matrix2x4 &right)
{
    Matrix2x4 result;
    add(left, right, result);
    return result;
}

Matrix2x4 Matrix2x4::subtract(const Matrix2x4 &left, const Matrix2x4 &right)
{
    Matrix2x4 result;
    subtract(left, right, result);
    return result;
}

Matrix2x4 Matrix2x4::multiply(const Matrix2x4 &left, float right)
{
    Matrix2x4 result;
    multiply(left, right, result);
    return result;
}

Matrix2x4 Matrix2x4::multiply(float left, const Matrix2x4 &right)
{
    Matrix2x4 result;
    multiply(left, right, result);
    return result;
}

Matrix2x2 Matrix2x4::multiply(const Matrix2x4 &left, const Matrix4x2 &right)
{
    Matrix2x2 result;
    multiply(left, right, result);
    return result;
}

Matrix2x3 Matrix2x4::multiply(const Matrix2x4 &left, const Matrix4x3 &right)
{
    Matrix2x3 result;
    multiply(left, right, result);
    return result;
}

Matrix2x4 Matrix2x4::multiply(const Matrix2x4 &left, const Matrix4x4 &right)
{
    Matrix2x4 result;
    multiply(left, right, result);
    return result;
}

Vector2 Matrix2x4::multiply(const Matrix2x4 &left, const Vector4 &right)
{
    Vector2 result;
    multiply(left, right, result);
    return result;
}

Vector4 Matrix2x4::multiply(const Vector2 &left, const Matrix2x4 &right)
{
    Vector4 result;
    multiply(left, right, result);
    return result;
}

Matrix2x4 &Matrix2x4::operator=(const Matrix2x4 &mat24)
{
    m_mat[0][0] = mat24.m_mat[0][0];
    m_mat[0][1] = mat24.m_mat[0][1];
    m_mat[0][2] = mat24.m_mat[0][2];
    m_mat[0][3] = mat24.m_mat[0][3];
    m_mat[1][0] = mat24.m_mat[1][0];
    m_mat[1][1] = mat24.m_mat[1][1];
    m_mat[1][2] = mat24.m_mat[1][2];
    m_mat[1][3] = mat24.m_mat[1][3];
    return *this;
}

bool operator==(const Matrix2x4 &m1, const Matrix2x4 &m2)
{
    for (int r = 0; r < 2; r++)
    {
        for (int c = 0; c < 4; c++)
        {
            if (m1.m_mat[r][c] != m2.m_mat[r][c])
                return false;
        }
    }

    return true;
}

bool operator!=(const Matrix2x4 &m1, const Matrix2x4 &m2)
{
    for (int r = 0; r < 2; r++)
    {
        for (int c = 0; c < 4; r++)
        {
            if (m1.m_mat[r][c] != m2.m_mat[r][c])
                return true;
        }
    }

    return false;
}

Matrix2x2 operator*(const Matrix2x4 &m24, const Matrix4x2 &m42)
{
    return Matrix2x4::multiply(m24, m42);
}

Matrix2x3 operator*(const Matrix2x4 &m24, const Matrix4x3 &m43)
{
    return Matrix2x4::multiply(m24, m43);
}

Matrix2x4 operator*(const Matrix2x4 &m24, const Matrix4x4 &m44)
{
    return Matrix2x4::multiply(m24, m44);
}

Vector2 operator*(const Matrix2x4 &mat24, const Vector4 &vec4)
{
    return Matrix2x4::multiply(mat24, vec4);
}

Vector4 operator*(const Vector2 &vec2, const Matrix2x4 &mat24)
{
    return Matrix2x4::multiply(vec2, mat24);
}
