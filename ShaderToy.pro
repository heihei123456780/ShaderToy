TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += ./include

LIBS += -lSDL2 -lGL -lGLEW

SOURCES += \
    bufferobject.cpp \
    camera.cpp \
    filesystem.cpp \
    framebuffer.cpp \
    framerate.cpp \
    main.cpp \
    point.cpp \
    pointF.cpp \
    rectangle.cpp \
    rectangleF.cpp \
    renderer.cpp \
    shader.cpp \
    shaderprogram.cpp \
    shaders.cpp \
    shadertoy.cpp \
    size.cpp \
    sizeF.cpp \
    texture.cpp \
    vertexarrayobject.cpp \
    window.cpp \
    matrix2x2.cpp \
    matrix2x3.cpp \
    matrix2x4.cpp \
    matrix3x2.cpp \
    matrix3x3.cpp \
    matrix3x4.cpp \
    matrix4x2.cpp \
    matrix4x3.cpp \
    matrix4x4.cpp \
    vector4.cpp \
    vector3.cpp \
    vector2.cpp \
    transform.cpp \
    quaternion.cpp \
    eulerangles.cpp

HEADERS += \
    include/bufferobject.h \
    include/camera.h \
    include/common.h \
    include/eulerangles.h \
    include/filesystem.h \
    include/framebuffer.h \
    include/framerate.h \
    include/g_math.h \
    include/math_util.h \
    include/matrix2x2.h \
    include/matrix2x3.h \
    include/matrix2x4.h \
    include/matrix3x2.h \
    include/matrix3x3.h \
    include/matrix3x4.h \
    include/matrix4x2.h \
    include/matrix4x3.h \
    include/matrix4x4.h \
    include/point.h \
    include/pointF.h \
    include/quaternion.h \
    include/rectangle.h \
    include/rectangleF.h \
    include/renderer.h \
    include/shader.h \
    include/shaderinput.h \
    include/shaderprogram.h \
    include/shaders.h \
    include/shadertoy.h \
    include/size.h \
    include/sizeF.h \
    include/stb_image_write.h \
    include/stb_image.h \
    include/texture.h \
    include/transform.h \
    include/vector2.h \
    include/vector3.h \
    include/vector4.h \
    include/vertexarrayobject.h \
    include/window.h \
    include/rectangle.h \


SUBDIRS += \
    ShaderToy.pro \
    ShaderToy.pro

DISTFILES += \
    ShaderToy.pro.use \
    README.md \
    ShaderToy.pro.use \
    ShaderToy.pro.user \
    README.md
