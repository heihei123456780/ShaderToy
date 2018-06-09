TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += ./include

LIBS += -lSDL2 -lGL -lGLEW

SOURCES += \

HEADERS += \

SUBDIRS += \
    ShaderToy.pro

DISTFILES += \
    ShaderToy.pro.use \
    ShaderToy.pro.user \
    README.md
