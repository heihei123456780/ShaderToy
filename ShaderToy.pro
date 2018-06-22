TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += ./include \
               ./include/3d \
               ./include/gl \
               ./include/math \
               ./include/utils

LIBS += -lSDL2 -lGL -lGLEW

SOURCES += \
    src/bufferobject.cpp \
    src/camera.cpp \
    src/eulerangles.cpp \
    src/filesystem.cpp \
    src/framebuffer.cpp \
    src/framerate.cpp \
    src/main.cpp \
    src/matrix2x2.cpp \
    src/matrix2x3.cpp \
    src/matrix2x4.cpp \
    src/matrix3x2.cpp \
    src/matrix3x3.cpp \
    src/matrix3x4.cpp \
    src/matrix4x2.cpp \
    src/matrix4x3.cpp \
    src/matrix4x4.cpp \
    src/point.cpp \
    src/pointF.cpp \
    src/quaternion.cpp \
    src/rectangle.cpp \
    src/rectangleF.cpp \
    src/renderer.cpp \
    src/shader.cpp \
    src/shaderprogram.cpp \
    src/shaders.cpp \
    src/shadertoy.cpp \
    src/size.cpp \
    src/sizeF.cpp \
    src/texture.cpp \
    src/transform.cpp \
    src/vector2.cpp \
    src/vector3.cpp \
    src/vector4.cpp \
    src/vertexarrayobject.cpp \
    src/window.cpp \
    test/readfile.cpp \
    src/resource.cpp

HEADERS += \
    include/common.h \
    include/stb_image_write.h \
    include/stb_image.h \
    include/3d/camera.h \
    include/gl/bufferobject.h \
    include/gl/framebuffer.h \
    include/gl/renderer.h \
    include/gl/shader.h \
    include/gl/shaderinput.h \
    include/gl/shaderprogram.h \
    include/gl/shaders.h \
    include/gl/shadertoy.h \
    include/gl/texture.h \
    include/gl/vertexarrayobject.h \
    include/gl/window.h \
    include/math/eulerangles.h \
    include/math/g_math.h \
    include/math/math_util.h \
    include/math/matrix2x2.h \
    include/math/matrix2x3.h \
    include/math/matrix2x4.h \
    include/math/matrix3x2.h \
    include/math/matrix3x3.h \
    include/math/matrix3x4.h \
    include/math/matrix4x2.h \
    include/math/matrix4x3.h \
    include/math/matrix4x4.h \
    include/math/point.h \
    include/math/pointF.h \
    include/math/quaternion.h \
    include/math/rectangle.h \
    include/math/rectangleF.h \
    include/math/size.h \
    include/math/sizeF.h \
    include/math/transform.h \
    include/math/vector2.h \
    include/math/vector3.h \
    include/math/vector4.h \
    include/utils/filesystem.h \
    include/utils/framerate.h \
    include/common.h \
    include/stb_image.h \
    include/stb_image_write.h \
    include/resource.h

SUBDIRS += \
    ShaderToy.pro

DISTFILES += \
    ShaderToy.pro.use \
    ShaderToy.pro.user \
    README.md
