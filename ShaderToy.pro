TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lSDL2 -lGL -lGLEW

SOURCES += \
    texture.cpp \
    vector2.inl \
    vector3.inl \
    vector4.inl \
    window.cpp \
    framebuffer.cpp \
    framerate.cpp \
    main.cpp \
    matrix2x2.inl \
    matrix2x3.inl \
    matrix2x4.inl \
    matrix3x2.inl \
    matrix3x3.inl \
    matrix3x4.inl \
    matrix4x2.inl \
    matrix4x3.inl \
    matrix4x4.inl \
    shader.cpp \
    shaderprogram.cpp \
    shaders.cpp \
    shadertoy.cpp \
    camera.cpp \
    vertexarrayobject.cpp \
    bufferobject.cpp \
    renderer.cpp \
    filesystem.cpp

HEADERS += \
    matrix3x2.h \
    texture.h \
    vector2.h \
    vector3.h \
    vector4.h \
    window.h \
    common.h \
    framerate.h \
    math_util.h \
    matrix2x2.h \
    matrix2x3.h \
    matrix2x4.h \
    matrix3x2.h \
    matrix3x3.h \
    matrix3x4.h \
    matrix4x2.h \
    matrix4x3.h \
    matrix4x4.h \
    shader.h \
    shaderprogram.h \
    shaders.h \
    shadertoy.h \
    g_math.h \
    camera.h \
    vertexarrayobject.h \
    framebuffer.h \
    shaderinput.h \
    bufferobject.h \
    renderer.h \
    stb_image.h \
    stb_image_write.h \
    filesystem.h


SUBDIRS += \
    ShaderToy.pro

DISTFILES += \
    ShaderToy.pro.use
