#include "vector3.h"
#include "vector4.h"

#include "shaders.h"
#include "texture.h"
#include "framerate.h"
#include "rectangle.h"
#include "shadertoy.h"
#include "shaderinput.h"
#include "bufferobject.h"
#include "shaderprogram.h"
#include "vertexarrayobject.h"

#include <GLFW/glfw3.h>
#include <time.h>
#include <sys/time.h>

#define NUMBER(n) n < 10 ? 0 : int(n / 10)

GLfloat vertices[] = {
   -1.0f,  1.0f,  0.0f,  1.0f,  0.0f,
    1.0f,  1.0f,  0.0f,  1.0f,  1.0f,
    1.0f, -1.0f,  0.0f,  0.0f,  1.0f,
   -1.0f, -1.0f,  0.0f,  0.0f,  0.0f
};

GLuint indices[] = {
    0, 1, 2,
    0, 2, 3
};

ShaderToy::ShaderToy()
    : mVAO(nullptr),
      mVBOArray(nullptr),
      mVBOIndex(nullptr),
      mProgram(nullptr)

{
}

ShaderToy::~ShaderToy()
{
    delete mVAO;
    delete mVBOArray;
    delete mVBOIndex;
    delete mProgram;
}

void ShaderToy::addTexture(std::vector<const char *> texFileNames)
{
    auto size = texFileNames.size();
    for (int i = 0; i < size; i++)
    {
        /*Texture *texture = new Texture(GL_TEXTURE_2D, texFileNames[i].c_str());
        if (texture->isLoaded())
        {
            texture->bindToChannel(i);
            mTextures.push_back(texture);
        }*/
    }
}

void ShaderToy::addUserFragmentMainCode(const char *fragmentMain)
{
    char buffer[0x20];
    std::string fragment = std::string(fragmentShaderPassHeader);

    auto size = mTextures.size();
    for (int i = 0; i < size; i++)
    {
        sprintf(buffer, "uniform sampler2D iChannel%d\n", i);
        fragment.append(buffer);
    }

    fragment.append(fragmentMain);
    fragment.append(fragmentShaderPassFooter);

    mProgram = new ShaderProgram();
    mProgram->addShaderFromSource(Shader::ShaderType::Vertex, vertexShader);
    mProgram->addShaderFromSource(Shader::ShaderType::Fragment, fragment);
    mProgram->link();

    if (!mProgram->isLinked())
        SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "Linked Error: %s", mProgram->log().c_str());

}

bool ShaderToy::screenshot()
{
    int w = width();
    int h = height();

    GLubyte *pixels = new GLubyte[w * h * 4];
    glReadPixels(0, 0, w, h, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

    time_t t = time(nullptr);
    struct tm *dt = localtime(&t);

    const char *homepath = getenv("HOME");
    if (homepath == nullptr)
    {
        delete[] pixels;
        return false;
    }

    size_t len = strlen(homepath);

    char filename[len + 20];
    sprintf(filename, "%s/%d%d%d%d%d%d%d%d%d%d%d.png", homepath, dt->tm_year + 1900, NUMBER(dt->tm_mon + 1),
            (dt->tm_mon + 1) % 10, NUMBER(dt->tm_mday), dt->tm_mday % 10, NUMBER(dt->tm_hour),
            dt->tm_hour % 10, NUMBER(dt->tm_min), dt->tm_min % 10, NUMBER(dt->tm_sec),
            dt->tm_sec % 10);

    if (Texture::savePixelsToFile(filename, pixels, w, h, 4) == false)
    {
        delete[] pixels;
        return false;
    }

    return true;
}

void ShaderToy::initilizeUniformValue()
{
    mInput.iResolution  = Vector3(width() * 1.0f, height() * 1.0f, 1.0f);
    mInput.iTime        = 0.0f;
    mInput.iGlobalTime  = 0.0f;
    mInput.iMouse       = Vector4(0.0f, 0.0f, 0.0f, 0.0f);
    mInput.iDate        = Vector4(0.0f, 0.0f, 0.0f, 0.0f);
    mInput.iSampleRate  = 44100 * 1.0f;

    auto size = mTextures.size();

    if (size <= 4)
    {
        for (int i = 0; i < size; i++)
        {
            mInput.iChannelResolution[i] = Vector3(mTextures[i]->width(),
                                                   mTextures[i]->height(),
                                                   1.0f);
            mInput.iChannelTime[i] = 0.0f;
        }
    }

    mInput.iFrame       = 0;
    mInput.iTimeDelta   = 0.0f;
    mInput.iFrameRate   = 0.0f;
}

void ShaderToy::bindUniform()
{
    if (mProgram != nullptr)
    {
        mProgram->setUniformValue("iResolution", mInput.iResolution);
        mProgram->setUniformValue("iTime", mInput.iTime);
        mProgram->setUniformValue("iGlobalTime", mInput.iGlobalTime);
        mProgram->setUniformValue("iMouse", mInput.iMouse);
        mProgram->setUniformValue("iDate", mInput.iDate);
        mProgram->setUniformValue("iSampleRate", mInput.iSampleRate);
        mProgram->setUniformValueArray("iChannelResolution", mInput.iChannelResolution, 4);
        mProgram->setUniformValueArray("iChannelTime", mInput.iChannelTime, 4, 1);
        mProgram->setUniformValue("iTimeDelta", mInput.iTimeDelta);
        mProgram->setUniformValue("iFrame", mInput.iFrame);
        mProgram->setUniformValue("iFrameRate", mInput.iFrameRate);

        mProgram->setUniformValue("iChannel0", 0);
        mProgram->setUniformValue("iChannel1", 1);
        mProgram->setUniformValue("iChannel2", 2);
        mProgram->setUniformValue("iChannel3", 3);

        mProgram->setUniformValue("iChannel[0].resolution", mInput.iChannelResolution[0]);
        mProgram->setUniformValue("iChannel[1].resolution", mInput.iChannelResolution[1]);
        mProgram->setUniformValue("iChannel[2].resolution", mInput.iChannelResolution[2]);
        mProgram->setUniformValue("iChannel[3].resolution", mInput.iChannelResolution[3]);

        mProgram->setUniformValue("iChannel[0].time", mInput.iChannelTime[0]);
        mProgram->setUniformValue("iChannel[1].time", mInput.iChannelTime[1]);
        mProgram->setUniformValue("iChannel[2].time", mInput.iChannelTime[2]);
        mProgram->setUniformValue("iChannel[3].time", mInput.iChannelTime[3]);
    }
}

void ShaderToy::initilizeGL()
{
    mFPS.initFrameRate();

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    mVAO = new VertexArrayObject();
    mVAO->create();
    mVAO->bind();

    mVBOArray = new BufferObject(GL_ARRAY_BUFFER);
    mVBOArray->create();
    mVBOArray->bind();
    mVBOArray->setUsagePattern(GL_STATIC_DRAW);
    mVBOArray->allocate(vertices, sizeof(vertices));

    initilizeUniformValue();

    mProgram->enableAttributeArray(0);
    mProgram->setAttributeBuffer(0, GL_FLOAT, 0, 3, sizeof(GLfloat) * 5);
    mProgram->enableAttributeArray(1);
    mProgram->setAttributeBuffer(1, GL_FLOAT, 3, 2, 5 * sizeof(GLfloat));

    mVBOIndex = new BufferObject(GL_ELEMENT_ARRAY_BUFFER);
    mVBOIndex->create();
    mVBOIndex->setUsagePattern(GL_STATIC_DRAW);
    mVBOIndex->bind();
    mVBOIndex->allocate(indices, sizeof(indices));

    mVAO->release();
    mProgram->release();
}

void ShaderToy::resizeGL(int w, int h)
{
    glViewport(0, 0, GLsizei(w), GLsizei(h));

    mInput.iResolution.setX(w * 1.0f);
    mInput.iResolution.setY(h * 1.0f);

    Window::resizeGL(w, h);
}

void ShaderToy::renderGL()
{
    time_t t = time(nullptr);
    struct tm *date = localtime(&t);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    mProgram->bind();
    mInput.iTime = mFPS.globalTime() / 1000.0f;
    mInput.iGlobalTime = mInput.iTime;

    mInput.iDate.setX(date->tm_year + 1900.0f);
    mInput.iDate.setY((float)date->tm_mon);
    mInput.iDate.setZ((float)date->tm_mday);
    mInput.iDate.setW(date->tm_hour * 60.0f * 60.0f +
                      date->tm_min * 60.0f + (float)date->tm_sec);

    mInput.iFrame += mFPS.frameCount();
    mInput.iTimeDelta =  mFPS.frameRateDelay() / 1000.0f;
    mInput.iFrameRate = 1.0f / mInput.iTimeDelta;

    bindUniform();

    mVAO->bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    mVAO->release();

    Window::renderGL();
}

void ShaderToy::keydownEvent(SDL_KeyboardEvent *event)
{
    if (event->keysym.sym == SDLK_x)
    {
        if (screenshot() == false)
        {
            SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "Save screenshot failed\n");
        }
    }
}

void ShaderToy::mouseButtonEvent(SDL_MouseButtonEvent *event)
{
    if (event->type == SDL_MOUSEBUTTONUP)
    {
        mInput.iMouse.setZ(-Math::abs(mInput.iMouse.z()));
        mInput.iMouse.setW(-Math::abs(mInput.iMouse.w()));
    }
    else if (event->type == SDL_MOUSEBUTTONDOWN)
    {
        const Rectangle *rect = drawableRect();
        mInput.iMouse.setZ(Math::floor(event->x - rect->left()) / rect->width() * width());
        mInput.iMouse.setW(Math::floor(height() - (event->y - rect->top()) / rect->height() * height()));
        mInput.iMouse.setX(mInput.iMouse.z());
        mInput.iMouse.setY(mInput.iMouse.w());
    }
}

void ShaderToy::mouseMotionEvent(SDL_MouseMotionEvent *event)
{
    const Rectangle *rect = drawableRect();
    mInput.iMouse.setX(Math::floor(event->x - rect->left()) / rect->width() * width());
    mInput.iMouse.setY(Math::floor(height() - (event->y - rect->top()) / rect->height() * height()));
}
