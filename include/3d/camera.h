#ifndef CAMERA_H
#define CAMERA_H

#include "matrix4x4.h"

class Camera
{
public:
    enum CameraType {
        Perspective  = 1 << 0,
        Orthographic = 1 << 1
    };

    Camera();

    float fieldOfView() const;

    float zoomX() const;
    float zoomY() const;

    float aspectRatio() const { return mAspectRatio; }
    float nearPlane() const { return mNearPlane; }
    float farPlane() const { return mFarPlane; }

    void setFieldOfView(float fov);

    void setZoomX(float x);
    void setZoomY(float y);

    void setAspectRatio(float ratio);
    void setNearPlane(float nearPlane);
    void setFarPlane(float farPlane);

private:
    CameraType mType;
    float mFieldOfView;
    float mZoom[2];
    float mAspectRatio;

    float mNearPlane;
    float mFarPlane;

    mutable Matrix4x4 mView;
    mutable Matrix4x4 mProjection;
    mutable Matrix4x4 mViewProjection;
    mutable Matrix4x4 mInverseView;
    mutable Matrix4x4 mInverseViewProjection;
    mutable int mBits;
};

#endif // CAMERA_H
