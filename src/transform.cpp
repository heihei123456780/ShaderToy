#include "vector2.h"
#include "vector3.h"
#include "transform.h"
#include "matrix3x3.h"
#include "matrix4x4.h"
#include "rectangle.h"
#include "rectangleF.h"

void Transform::rotate(Matrix3x3 &result, float angle)
{
    float s = Math::sin(angle);
    float c = Math::cos(angle);

    result.setToIdentity();
    result.m_mat[0][0] =  c;
    result.m_mat[0][1] = -s;
    result.m_mat[1][0] =  s;
    result.m_mat[1][1] =  c;
}

void Transform::scale(Matrix3x3 &result, float sx, float sy)
{
    result.setToIdentity();
    result.m_mat[0][0] = sx;
    result.m_mat[0][1] = sy;
}

void Transform::shear(Matrix3x3 &result, float x, float y)
{
    result.setToIdentity();
    result.m_mat[1][0] = x;
    result.m_mat[0][1] = y;
}

void Transform::translate(Matrix3x3 &result, float dx, float dy)
{
    result.setToIdentity();
    result.m_mat[2][0] = dx;
    result.m_mat[2][1] = dy;
}

Matrix3x3 Transform::rotate(float angle)
{
    Matrix3x3 mat3;
    rotate(mat3, angle);
    return angle;
}

Matrix3x3 Transform::scale(float sx, float sy)
{
    Matrix3x3 mat3;
    scale(mat3, sx, sy);
    return mat3;
}

Matrix3x3 Transform::shearX(float x)
{
    Matrix3x3 mat3;
    shear(mat3, x, 0.0f);
    return mat3;
}

Matrix3x3 Transform::shearY(float y)
{
    Matrix3x3 mat3;
    shear(mat3, 0.0f, y);
    return mat3;
}

Matrix3x3 Transform::translate(float dx, float dy)
{
    Matrix3x3 mat3;
    translate(mat3, dx, dy);
    return mat3;
}
    
void Transform::fromAxisAngle(Matrix4x4 &result, float angle, float x, float y, float z)
{
    float s = Math::sin(angle);
    float c = Math::cos(angle);
    float _c = 1.0f - c;

    result.m_mat[0][0] = x * x * _c + c; 
    result.m_mat[1][0] = x * y * _c - z * s;
    result.m_mat[2][0] = x * z * _c + y * s;
    result.m_mat[3][0] = 0.0f;
    result.m_mat[0][1] = y * x * _c + z * s; 
    result.m_mat[1][1] = y * y * _c + c;
    result.m_mat[2][1] = y * z * _c - x * s;
    result.m_mat[3][1] = 0.0f;
    result.m_mat[0][2] = x * z * _c - y * s;
    result.m_mat[1][2] = y * z * _c + x * s;
    result.m_mat[2][2] = z * z * _c + c;
    result.m_mat[3][2] = 0.0f;
    result.m_mat[0][3] = 0.0f;
    result.m_mat[1][3] = 0.0f;
    result.m_mat[2][3] = 0.0f;
    result.m_mat[3][3] = 1.0f;
}

void Transform::fromAxisAngle(Matrix4x4 &result, float angle, const Vector3 &axis)
{
    fromAxisAngle(result, angle, axis.x(), axis.y(), axis.z());
}

void Transform::rotateX(Matrix4x4 &result, float angle)
{
    float s = Math::sin(angle);
    float c = Math::cos(angle);

    result.setToIdentity();
    result.m_mat[1][1] =  c;
    result.m_mat[1][2] =  s;
    result.m_mat[2][1] = -s;
    result.m_mat[2][2] =  c;
}

void Transform::rotateY(Matrix4x4 &result, float angle)
{
    float s = Math::sin(angle);
    float c = Math::cos(angle);

    result.setToIdentity();
    result.m_mat[0][0] =  c;
    result.m_mat[0][2] = -s;
    result.m_mat[2][0] =  s;
    result.m_mat[2][2] =  c;
}

void Transform::rotateZ(Matrix4x4 &result, float angle)
{
    float s = Math::sin(angle);
    float c = Math::cos(angle);

    result.setToIdentity();
    result.m_mat[0][0] =  c;
    result.m_mat[0][1] =  s;
    result.m_mat[1][0] = -s;
    result.m_mat[1][1] =  c;
}

void Transform::scale(Matrix4x4 &result, float sx, float sy, float sz)
{
    result.setToIdentity();
    result.m_mat[0][0] = sx;
    result.m_mat[1][1] = sy;
    result.m_mat[2][2] = sz;
}

void Transform::translate( Matrix4x4 &result, float dx, float dy, float dz)
{
    result.setToIdentity();
    result.m_mat[3][0] = dx;
    result.m_mat[3][1] = dy;
    result.m_mat[3][2] = dz;
}

void Transform::ortho(Matrix4x4 &result, const Rectangle &rect)
{
    ortho(result, rect.left(), rect.right(), rect.bottom(), rect.top(), -1.0f, 1.0f);
}

void Transform::ortho(Matrix4x4 &result, const RectangleF &rect)
{
    ortho(result, rect.left(), rect.right(), rect.bottom(), rect.top(), -1.0f, 1.0f);
}

void Transform::ortho(Matrix4x4 &result, float left, float right, float bottom, float top, float zNear, float zFar)
{
    if (left == right || bottom == top || zNear == zFar)
        return;

    float width = right - left;
    float invheight = top - bottom;
    float clip = zFar - zNear;
    
    result.m_mat[0][0] = 2.0f / width;
    result.m_mat[1][0] = 0.0f;
    result.m_mat[2][0] = 0.0f;
    result.m_mat[3][0] = -(left + right) / width;
    result.m_mat[0][1] = 0.0f;
    result.m_mat[1][1] = 2.0f / invheight;
    result.m_mat[2][1] = 0.0f;
    result.m_mat[3][1] = -(top + bottom) / invheight;
    result.m_mat[0][2] = 0.0f;
    result.m_mat[1][2] = 0.0f;
    result.m_mat[2][2] = -2.0f / clip;
    result.m_mat[3][2] = -(zNear + zFar) / clip;
    result.m_mat[0][3] = 0.0f;
    result.m_mat[1][3] = 0.0f;
    result.m_mat[2][3] = 0.0f;
    result.m_mat[3][3] = 1.0f;
}

void Transform::frustum(Matrix4x4 &result, float left, float right, float bottom, float top, float zNear, float zFar)
{
    if (left == right || bottom == top || zNear == zFar)
        return;

    float width = right - left;
    float invheight = top - bottom;
    float clip = zFar - zNear;

    result.m_mat[0][0] = 2.0f * zNear / width;
    result.m_mat[1][0] = 0.0f;
    result.m_mat[2][0] = (left + right) / width;
    result.m_mat[3][0] = 0.0f;
    result.m_mat[0][1] = 0.0f;
    result.m_mat[1][1] = 2.0f * zNear / invheight;
    result.m_mat[2][1] = (top + bottom) / invheight;
    result.m_mat[3][1] = 0.0f;
    result.m_mat[0][2] = 0.0f;
    result.m_mat[1][2] = 0.0f;
    result.m_mat[2][2] = -(zNear + zFar) / clip;
    result.m_mat[3][2] = (-2.0f * zNear * zFar) / clip;
    result.m_mat[0][3] = 0.0f;
    result.m_mat[1][3] = 0.0f;
    result.m_mat[2][3] = -1.0f;
    result.m_mat[3][3] = 0.0f;
}

void Transform::perspective(Matrix4x4 &result, float fov, float ratio, float zNear, float zFar)
{
    if (zNear == zFar || ratio == 0.0f)
        return;
    
    float radian = Math::degToRad(fov);
    float s = Math::sin(radian);

    if (s == 0.0f)
        return;
    
    float cotan = Math::cot(radian);
    float clip = zFar - zNear;

    result.m_mat[0][0] = cotan / ratio;
    result.m_mat[1][0] = 0.0f;
    result.m_mat[2][0] = 0.0f;
    result.m_mat[3][0] = 0.0f;
    result.m_mat[0][1] = 0.0f;
    result.m_mat[1][1] = cotan;
    result.m_mat[2][1] = 0.0f;
    result.m_mat[3][1] = 0.0f;
    result.m_mat[0][2] = 0.0f;
    result.m_mat[1][2] = 0.0f;
    result.m_mat[2][2] = -(zNear + zFar) / clip;
    result.m_mat[3][2] = -(2.0f * zNear * zFar) / clip;
    result.m_mat[0][3] = 0.0f;
    result.m_mat[1][3] = 0.0f;
    result.m_mat[2][3] = -1.0f;
    result.m_mat[3][3] = 0.0f;    
}

void Transform::lookAt(Matrix4x4 &result, const Vector3 &eye, const Vector3 &center, const Vector3 &up)
{
    Vector3 forward = center - eye;

    forward.normalize();
    Vector3 side = forward.crossProduct(up).normalized();
    Vector3 upVector = side.crossProduct(forward);

    result.m_mat[0][0] = side.x();
    result.m_mat[1][0] = side.y();
    result.m_mat[2][0] = side.z();
    result.m_mat[3][0] = 0.0f;
    result.m_mat[0][1] = upVector.x();
    result.m_mat[1][1] = upVector.y();
    result.m_mat[2][1] = upVector.z();
    result.m_mat[3][1] = 0.0f;
    result.m_mat[0][2] = -forward.x();
    result.m_mat[1][2] = -forward.y();
    result.m_mat[2][2] = -forward.z();
    result.m_mat[3][2] = 0.0f;
    result.m_mat[0][3] = 0.0f;
    result.m_mat[1][3] = 0.0f;
    result.m_mat[2][3] = 0.0f;
    result.m_mat[3][3] = 1.0f;    
}

void Transform::lookAt(Matrix4x4 &result, float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ,
                       float upX, float upY, float upZ)
{
    lookAt(result, Vector3(eyeX, eyeY, eyeZ),  
                   Vector3(centerX, centerY, centerZ), 
                   Vector3(upX, upY, upZ));
}

void Transform::viewport(Matrix4x4 &result, const RectangleF &rect)
{
    viewport(result, rect.left(), rect.bottom(), rect.width(), rect.height(), 1.0f, -1.0f);
}

void Transform::viewport(Matrix4x4 &result, float left, float bottom, float width, float height, float zNear, float zFar)
{
    const float w2 = width / 2.0f;
    const float h2 = height / 2.0f;

    result.m_mat[0][0] = w2;
    result.m_mat[1][0] = 0.0f;
    result.m_mat[2][0] = 0.0f;
    result.m_mat[3][0] = left + w2;
    result.m_mat[0][1] = 0.0f;
    result.m_mat[1][1] = h2;
    result.m_mat[2][1] = 0.0f;
    result.m_mat[3][1] = bottom + h2;
    result.m_mat[0][2] = 0.0f;
    result.m_mat[1][2] = 0.0f;
    result.m_mat[2][2] = (zFar - zNear) / 2.0f;
    result.m_mat[3][2] = (zNear + zFar) / 2.0f;
    result.m_mat[0][3] = 0.0f;
    result.m_mat[1][3] = 0.0f;
    result.m_mat[2][3] = 0.0f;
    result.m_mat[3][3] = 1.0f;    
}

Matrix4x4 Transform::ortho(const Rectangle &rect)
{
    Matrix4x4 result;
    ortho(result, rect.left(), rect.right(), rect.bottom(), rect.top(), -1.0f, 1.0f);
    return result;
}

Matrix4x4 Transform::ortho(const RectangleF &rect)
{
    Matrix4x4 result;
    ortho(result, rect.left(), rect.right(), rect.bottom(), rect.top(), -1.0f, 1.0f);
    return result;
}

Matrix4x4 Transform::ortho(float left, float right, float bottom, float top, float zNear, float zFar)
{
    Matrix4x4 result;
    ortho(result, left, right, bottom, top ,zNear, zFar);
    return result;
}

Matrix4x4 Transform::frustum(float left, float right, float bottom, float top, float zNear, float zFar)
{
    Matrix4x4 result;
    frustum(result, left, right, bottom, top ,zNear, zFar);
    return result;
}

Matrix4x4 Transform::perspective(float fov, float ratio, float zNear, float zFar)
{
    Matrix4x4 result;
    perspective(result, fov, ratio, zNear, zFar);
    return result;
}

Matrix4x4 Transform::lookAt(const Vector3 &eye, const Vector3 &center, const Vector3 &up)
{
    Matrix4x4 result;
    lookAt(result, eye, center, up);
    return result;
}

Matrix4x4 Transform::lookAt(float eyeX, float eyeY, float eyeZ,
                            float centerX, float centerY, float centerZ, 
                            float upX, float upY, float upZ)
{
    Matrix4x4 result;
    lookAt(result, Vector3(eyeX, eyeY, eyeZ),  
                   Vector3(centerX, centerY, centerZ), 
                   Vector3(upX, upY, upZ));
    return result;
}

Matrix4x4 Transform::viewport(const RectangleF &rect)
{
    Matrix4x4 result;
    viewport(result, rect);
    return result;
}

Matrix4x4 Transform::viewport(float left, float bottom, float width, float height, float zNear, float zFar)
{
    Matrix4x4 result;
    viewport(result, left, bottom, width, height ,zNear, zFar);
    return result;
}

Matrix4x4 Transform::fromAxisAngle(float angle, float x, float y, float z)
{
    Matrix4x4 result;
    fromAxisAngle(result, angle, x, y, z);
    return result;
}

Matrix4x4 Transform::fromAxisAngle(float angle, const Vector3 &axis)
{
    Matrix4x4 result;
    fromAxisAngle(result, angle, axis.x(), axis.y(), axis.z());
    return result;
}

Matrix4x4 Transform::rotateX(float angle)
{
    Matrix4x4 result;
    rotateX(result, angle);
    return result;
}

Matrix4x4 Transform::rotateY(float angle)
{
    Matrix4x4 result;
    rotateY(result, angle);
    return result;
}

Matrix4x4 Transform::rotateZ(float angle)
{
    Matrix4x4 result;
    rotateZ(result, angle);
    return result;
}

Matrix4x4 Transform::scale(float sx, float sy, float sz)
{
    Matrix4x4 result;
    scale(result, sx, sy, sz);
    return result;
}

Matrix4x4 Transform::translate(float dx, float dy, float dz)
{
    Matrix4x4 result;
    translate(result, dx, dy, dz);
    return result;
}
