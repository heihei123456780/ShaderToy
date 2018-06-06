#include "vector3.h"
#include "vector4.h"

#include "termios.h"

#include "shaders.h"
#include "texture.h"
#include "framerate.h"
#include "shadertoy.h"
#include "shaderinput.h"
#include "bufferobject.h"
#include "shaderprogram.h"
#include "vertexarrayobject.h"

#include <time.h>
#include <sys/time.h>
#include <iostream>

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

void ShaderToy::initilizeUniformValue()
{
    mInput.iResolutionPosition = mProgram->uniformLocation("iResolution");
    mInput.iTimePosition = mProgram->uniformLocation("iTime");
    mInput.iGlobalTimePosition = mProgram->uniformLocation("iGlobalTime");
    mInput.iTimePosition = mProgram->uniformLocation("iTime");
    mInput.iChannelTimePosition = mProgram->uniformLocation("iChannelTime");
    mInput.iMousePosition = mProgram->uniformLocation("iMouse");
    mInput.iDatePosition = mProgram->uniformLocation("iDate");
    mInput.iSampleRatePosition = mProgram->uniformLocation("iSampleRate");
    mInput.iChannelResolutionPosition = mProgram->uniformLocation("iChannelResolution");
    mInput.iFramePosition = mProgram->uniformLocation("iFrame");
    mInput.iTimeDeltaPosition = mProgram->uniformLocation("iTimeDelta");
    mInput.iFrameRatePosition = mProgram->uniformLocation("iFrameRate");

    mInput.iResolution = Vector3((float)width(), (float)height(), 1.0f);
    mInput.iTime = 0.0f;
    mInput.iGlobalTime = 0.0f;
    mInput.iMouse = Vector4(0.0f, 0.0f, 0.0f, 0.0f);
    mInput.iDate = Vector4(0.0f, 0.0f, 0.0f, 0.0f);
    mInput.iSampleRate = 44100 * 1.0f;

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

    mInput.iFrame = 0;
    mInput.iTimeDelta = 0.0f;
    mInput.iFrameRate = 0.0f;


}

void ShaderToy::bindUniform()
{
    if (mProgram != nullptr)
    {
        mProgram->setUniformValue(mInput.iResolutionPosition, mInput.iResolution);
        mProgram->setUniformValue(mInput.iTimePosition, mInput.iTime);
        mProgram->setUniformValue(mInput.iGlobalTimePosition, mInput.iGlobalTime);
        mProgram->setUniformValue(mInput.iMousePosition, mInput.iMouse);
        mProgram->setUniformValue(mInput.iDatePosition, mInput.iDatePosition);
        mProgram->setUniformValue(mInput.iSampleRatePosition, mInput.iSampleRate);
        mProgram->setUniformValueArray(mInput.iChannelResolutionPosition, mInput.iChannelResolution, 4);
        mProgram->setUniformValueArray(mInput.iChannelTimePosition, mInput.iChannelTime, 4, 1);
        mProgram->setUniformValue(mInput.iTimeDeltaPosition, mInput.iTimeDelta);
        mProgram->setUniformValue(mInput.iFramePosition, mInput.iFrame);
        mProgram->setUniformValue(mInput.iFrameRatePosition, mInput.iFrameRate);

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

    mInput.iResolution.setX((float)w / 100.0f);
    mInput.iResolution.setY((float)h / 100.0f);
}

void ShaderToy::renderGL()
{
    time_t t = time(nullptr);
    struct tm *date = localtime(&t);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    mProgram->bind();
    mInput.iTime = mFPS.globalTime() * 1.0f;
    mInput.iGlobalTime = mInput.iTime;

    mInput.iDate.setX(date->tm_year + 1900.0f);
    mInput.iDate.setY((float)date->tm_mon);
    mInput.iDate.setZ((float)date->tm_mday);
    mInput.iDate.setW(date->tm_hour * 60.0f * 60.0f +
                      date->tm_min * 60.0f + (float)date->tm_sec);

    mInput.iFrame += mFPS.frameCount();
    mInput.iTimeDelta =  mFPS.frameRateDelay() * 1.0f;
    mInput.iFrameRate = 1.0f / mInput.iTimeDelta;

    bindUniform();

    mVAO->bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    mVAO->release();

    Window::renderGL();
}

void ShaderToy::keydownEvent(SDL_KeyboardEvent *event)
{
}

void ShaderToy::mouseButtonEvent(SDL_MouseButtonEvent *event)
{

}

void ShaderToy::mouseMotionEvent(SDL_MouseMotionEvent *event)
{
    mInput.iMouse.setX(float(event->x) / width());
    mInput.iMouse.setY(float(event->y) / height());
}
