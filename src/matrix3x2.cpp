#include "vector2.h"
#include "vector3.h"
#include "matrix2x2.h"
#include "matrix2x3.h"
#include "matrix2x4.h"
#include "matrix3x2.h"
#include "matrix3x3.h"
#include "matrix3x4.h"

const Matrix3x2 Matrix3x2::ZERO(0.0f, 0.0f,
                                0.0f, 0.0f,
                                0.0f, 0.0f);

Matrix3x2::Matrix3x2()
{
    m_mat[0][0] = 0.0f;
    m_mat[0][1] = 0.0f;
    m_mat[1][0] = 0.0f;
    m_mat[1][1] = 0.0f;
    m_mat[2][0] = 0.0f;
    m_mat[2][1] = 0.0f;
}

Matrix3x2::Matrix3x2(float arr[3][2])
{
    m_mat[0][0] = arr[0][0];
    m_mat[0][1] = arr[0][1];
    m_mat[1][0] = arr[1][0];
    m_mat[1][1] = arr[1][1];
    m_mat[2][0] = arr[2][0];
    m_mat[2][1] = arr[2][1];
}

Matrix3x2::Matrix3x2(float f00, float f01,
                     float f10, float f11,
                     float f20, float f21)
{
    m_mat[0][0] = f00;
    m_mat[0][1] = f01;
    m_mat[1][0] = f10;
    m_mat[1][1] = f11;
    m_mat[2][0] = f20;
    m_mat[2][1] = f21;
}

Matrix3x2::Matrix3x2(const Matrix3x2 &mat32)
{
    m_mat[0][0] = mat32.m_mat[0][0];
    m_mat[0][1] = mat32.m_mat[0][1];
    m_mat[1][0] = mat32.m_mat[1][0];
    m_mat[1][1] = mat32.m_mat[1][1];
    m_mat[2][0] = mat32.m_mat[2][0];
    m_mat[2][1] = mat32.m_mat[2][1];
}

Vector2 Matrix3x2::row(int index) const
{
    return Vector2(m_mat[index][0],
                   m_mat[index][1]);
}

Vector3 Matrix3x2::column(int index) const
{
    return Vector3(m_mat[0][index],
                   m_mat[1][index],
                   m_mat[2][index]);
}

void Matrix3x2::setRow(int index, const Vector2 &vec2)
{
    m_mat[index][0] = vec2.x();
    m_mat[index][1] = vec2.y();
}

void Matrix3x2::setColumn(int index, const Vector3 &vec3)
{
    m_mat[0][index] = vec3.x();
    m_mat[1][index] = vec3.y();
    m_mat[2][index] = vec3.z();
}

void Matrix3x2::fill(float value)
{
    m_mat[0][0] = value;
    m_mat[0][1] = value;
    m_mat[1][0] = value;
    m_mat[1][1] = value;
    m_mat[2][0] = value;
    m_mat[2][1] = value;
}

void Matrix3x2::inverse(const Matrix3x2 &mat32, Matrix3x2 &result)
{
}

void Matrix3x2::transpose(const Matrix3x2 &mat32, Matrix2x3 &result)
{
    result.m_mat[0][0] = mat32.m_mat[0][0];
    result.m_mat[1][0] = mat32.m_mat[0][1];
    result.m_mat[0][1] = mat32.m_mat[1][0];
    result.m_mat[1][1] = mat32.m_mat[1][1];
    result.m_mat[0][2] = mat32.m_mat[2][0];
    result.m_mat[1][2] = mat32.m_mat[2][1];
}

void Matrix3x2::add(const Matrix3x2 &left, const Matrix3x2 &right, Matrix3x2 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] + right.m_mat[0][0];
    result.m_mat[0][1] = left.m_mat[0][1] + right.m_mat[0][1];
    result.m_mat[1][0] = left.m_mat[1][0] + right.m_mat[1][0];
    result.m_mat[1][1] = left.m_mat[1][1] + right.m_mat[1][1];
    result.m_mat[2][0] = left.m_mat[2][0] + right.m_mat[2][0];
    result.m_mat[2][1] = left.m_mat[2][1] + right.m_mat[2][1];
}

void Matrix3x2::subtract(const Matrix3x2 &left, const Matrix3x2 &right, Matrix3x2 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] - right.m_mat[0][0];
    result.m_mat[0][1] = left.m_mat[0][1] - right.m_mat[0][1];
    result.m_mat[1][0] = left.m_mat[1][0] - right.m_mat[1][0];
    result.m_mat[1][1] = left.m_mat[1][1] - right.m_mat[1][1];
    result.m_mat[2][0] = left.m_mat[2][0] - right.m_mat[2][0];
    result.m_mat[2][1] = left.m_mat[2][1] - right.m_mat[2][1];
}

void Matrix3x2::multiply(const Matrix3x2 &left, float right, Matrix3x2 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] * right;
    result.m_mat[0][1] = left.m_mat[0][1] * right;
    result.m_mat[1][0] = left.m_mat[1][0] * right;
    result.m_mat[1][0] = left.m_mat[1][1] * right;
    result.m_mat[2][0] = left.m_mat[2][0] * right;
    result.m_mat[2][1] = left.m_mat[2][1] * right;
}

void Matrix3x2::multiply(float left, const Matrix3x2 &right, Matrix3x2 &result)
{
    result.m_mat[0][0] = left * right.m_mat[0][0];
    result.m_mat[0][1] = left * right.m_mat[0][1];
    result.m_mat[1][0] = left * right.m_mat[1][0];
    result.m_mat[1][1] = left * right.m_mat[1][1];
    result.m_mat[2][0] = left * right.m_mat[2][0];
    result.m_mat[2][1] = left * right.m_mat[2][1];
}

void Matrix3x2::multiply(const Matrix3x2 &left, const Matrix2x2 &right, Matrix3x2 &result)
{
    result.m_mat[0][0] = left.m_mat[0][0] * right.m_mat[0][0] + left.m_mat[0][1] * right.m_mat[1][0];
    result.m_mat[0][1] = left.m_mat[0][0] * right.m_mat[0][1] + left.m_mat[0][1] * right.m_mat[1][1];
    result.m_mat[1][0] = left.m_mat[1][0] * right.m_mat[0][0] + left.m_mat[1][1] * right.m_mat[1][0];
    result.m_mat[1][1] = left.m_mat[1][0] * right.m_mat[0][1] + left.m_mat[1][1] * right.m_mat[1][1];
    result.m_mat[2][0] = left.m_mat[2][0] * right.m_mat[0][0] + left.m_mat[2][1] * right.m_mat[1][0];
    result.m_mat[2][1] = left.m_mat[2][0] * right.m_mat[0][1] + left.m_mat[2][1] * right.m_mat[1][1];
}

void Matrix3x2::multiply(const Matrix3x2 &left, const Matrix2x3 &right, Matrix3x3 &result)
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
}

void Matrix3x2::multiply(const Matrix3x2 &left, const Matrix2x4 &right, Matrix3x4 &result)
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
}

void Matrix3x2::multiply(const Matrix3x2 &left, const Vector2 &right, Vector3 &result)
{
    float x = left.m_mat[0][0] * right.x() + left.m_mat[0][1] * right.y();
    float y = left.m_mat[1][0] * right.x() + left.m_mat[1][1] * right.y();
    float z = left.m_mat[2][0] * right.x() + left.m_mat[2][1] * right.y();
    
    result.setX(x);
    result.setY(y);
    result.setZ(z);
}

void Matrix3x2::multiply(const Vector3 &left, const Matrix3x2 &right, Vector2 &result)
{
    float x = left.x() * right.m_mat[0][0] + left.y() * right.m_mat[1][0] +
              left.z() * right.m_mat[2][0];
    float y = left.x() * right.m_mat[0][1] + left.y() * right.m_mat[1][1] + 
              left.z() * right.m_mat[2][1];

    result.setX(x);
    result.setY(y);
}

Matrix3x2 Matrix3x2::inverse(const Matrix3x2 &mat32)
{
    Matrix3x2 result;
    inverse(mat32, result);
    return result;
}

Matrix2x3 Matrix3x2::transpose(const Matrix3x2 &mat32)
{
    Matrix2x3 result;
    transpose(mat32, result);
    return result;
}

Matrix3x2 Matrix3x2::add(const Matrix3x2 &left, const Matrix3x2 &right)
{
    Matrix3x2 result;
    add(left, right, result);
    return result;
}

Matrix3x2 Matrix3x2::subtract(const Matrix3x2 &left, const Matrix3x2 &right)
{
    Matrix3x2 result;
    subtract(left, right, result);
    return result;
}

Matrix3x2 Matrix3x2::multiply(const Matrix3x2 &left, float right)
{
    Matrix3x2 result;
    multiply(left, right, result);
    return result;
}

Matrix3x2 Matrix3x2::multiply(float left, const Matrix3x2 &right)
{
    Matrix3x2 result;
    multiply(left, right, result);
    return result;
}

Matrix3x2 Matrix3x2::multiply(const Matrix3x2 &left, const Matrix2x2 &right)
{
    Matrix3x2 result;
    multiply(left, right, result);
    return result;
}

Matrix3x3 Matrix3x2::multiply(const Matrix3x2 &left, const Matrix2x3 &right)
{
    Matrix3x3 result;
    multiply(left, right, result);
    return result;
}

Matrix3x4 Matrix3x2::multiply(const Matrix3x2 &left, const Matrix2x4 &right)
{
    Matrix3x4 result;
    multiply(left, right, result);
    return result;
}

Vector3 Matrix3x2::multiply(const Matrix3x2 &left, const Vector2 &right)
{
    Vector3 result;
    multiply(left, right, result);
    return result;
}

Vector2 Matrix3x2::multiply(const Vector3 &left, const Matrix3x2 &right)
{
    Vector2 result;
    multiply(left, right, result);
    return result;
}

Matrix3x2 &Matrix3x2::operator=(const Matrix3x2 &mat32)
{
    m_mat[0][0] = mat32.m_mat[0][0];
    m_mat[0][1] = mat32.m_mat[0][1];
    m_mat[1][0] = mat32.m_mat[1][0];
    m_mat[1][1] = mat32.m_mat[1][1];
    m_mat[2][0] = mat32.m_mat[2][0];
    m_mat[2][1] = mat32.m_mat[2][1];
    return *this;
}

bool operator==(const Matrix3x2 &m1, const Matrix3x2 &m2)
{
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 2; c++)
        {
            if (m1.m_mat[r][c] != m2.m_mat[r][c])
                return false;
        }
    }

    return true;
}

bool operator!=(const Matrix3x2 &m1, const Matrix3x2 &m2)
{
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 2; r++)
        {
            if (m1.m_mat[r][c] != m2.m_mat[r][c])
                return true;
        }
    }

    return false;
}

Matrix3x2 operator*(const Matrix3x2 &m32, const Matrix2x2 &m22)
{
    return Matrix3x2::multiply(m32, m22);
}

Matrix3x3 operator*(const Matrix3x2 &m32, const Matrix2x3 &m23)
{
    return Matrix3x2::multiply(m32, m23);
}

Matrix3x4 operator*(const Matrix3x2 &m32, const Matrix2x4 &m24)
{
    return Matrix3x2::multiply(m32, m24);
}

Vector3 operator*(const Matrix3x2 &mat32, const Vector2 &vec2)
{
    return Matrix3x2::multiply(mat32, vec2);
}

Vector2 operator*(const Vector3 &vec3, const Matrix3x2 &mat32)
{
    return Matrix3x2::multiply(vec3, mat32);
}
