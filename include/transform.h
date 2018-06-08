#ifndef TRANSFORM_H
#define TRANSFORM_H

class Vector2;
class Vector3;
class Matrix3x3;
class Matrix4x4;
class Rectangle;
class RectangleF;

class Transform 
{
public:
    // 2D transform
    static void rotate(Matrix3x3 &result, float angle);
    static void scale(Matrix3x3 &result, float sx, float sy);
    static void shear(Matrix3x3 &result, float x, float y);
    static void translate(Matrix3x3 &result, float x, float y);

    static Matrix3x3 rotate(float angle);
    static Matrix3x3 scale(float sx, float sy);
    static Matrix3x3 shearX(float x);
    static Matrix3x3 shearY(float y);
    static Matrix3x3 translate(float x, float y);
    
    // 3D transform
    static void ortho(Matrix4x4 &result, const Rectangle &rect);
    static void ortho(Matrix4x4 &result, const RectangleF &rect);
    static void ortho(Matrix4x4 &result, float left, float right, float bottom, float top, float zNear, float zFar);

    static void frustum(Matrix4x4 &result, float left, float right, float bottom, float top, float zNear, float zFar);

    static void perspective(Matrix4x4 &result, float fov, float ratio, float zNear, float zFar);

    static void lookAt(Matrix4x4 &result, const Vector3 &eye, const Vector3 &center, const Vector3 &up);
    static void lookAt(Matrix4x4 &result, float eyeX, float eyeY, float eyeZ,
                       float centerX, float centerY, float centerZ, 
                       float upX, float upY, float upZ);

    static void viewport(Matrix4x4 &result, const RectangleF &rect);
    static void viewport(Matrix4x4 &result, float left, float bottom, float width, float height, float zNear, float zFar);


    static void fromAxisAngle(Matrix4x4 &mat4, float angle, float x, float y, float z);
    static void fromAxisAngle(Matrix4x4 &mat4, float angle, const Vector3 &axis);
    static void rotateX(Matrix4x4 &mat4, float angle);
    static void rotateY(Matrix4x4 &mat4, float angle);
    static void rotateZ(Matrix4x4 &mat4, float angle);
    static void scale(Matrix4x4 &mat4, float sx, float sy, float sz);
    
    static void translate( Matrix4x4 &mat4, float x, float y, float z);
    
    static Matrix4x4 ortho(const Rectangle &rect);
    static Matrix4x4 ortho(const RectangleF &rect);
    static Matrix4x4 ortho(float left, float right, float bottom, float top, float zNear, float zFar);
    static Matrix4x4 frustum(float left, float right, float bottom, float top, float zNear, float zFar);
    static Matrix4x4 perspective(float fov, float ratio, float zNear, float zFar);
    static Matrix4x4 lookAt(const Vector3 &eye, const Vector3 &center, const Vector3 &up);
    static Matrix4x4 lookAt(float eyeX, float eyeY, float eyeZ, 
                            float centerX, float centerY, float centerZ, 
                            float upX, float upY, float upZ);
    static Matrix4x4 viewport(const RectangleF &rect);
    static Matrix4x4 viewport(float left, float bottom, float width, float height, float zNear, float zFar);
    
    static Matrix4x4 fromAxisAngle(float angle, float x, float y, float z);
    static Matrix4x4 fromAxisAngle(float angle, const Vector3 &axis);
    static Matrix4x4 rotateX(float angle);
    static Matrix4x4 rotateY(float angle);
    static Matrix4x4 rotateZ(float angle);
    static Matrix4x4 scale(float sx, float sy, float sz);
    static Matrix4x4 translate(float x, float y, float z);
};

#endif
