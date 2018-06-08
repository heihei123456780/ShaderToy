#ifndef SHADER_TOY_H
#define SHADER_TOY_H

#include "window.h"
#include "framerate.h"
#include "shaderinput.h"

class Texture;
class BufferObject;
class ShaderProgram;
class VertexArrayObject;

class ShaderToy : public Window
{
public:
    ShaderToy();
    ~ShaderToy();

    void addTexture(std::vector<const char *> texFileNames);
    void addUserFragmentMainCode(const char *fragmentMain);
    bool screenshot();

protected:
    void initilizeGL() override;
    void resizeGL(int w, int h) override;
    void renderGL() override;

    void keydownEvent(SDL_KeyboardEvent *event) override;
    void mouseButtonEvent(SDL_MouseButtonEvent *event) override;
    void mouseMotionEvent(SDL_MouseMotionEvent *event) override;

private:
    void initilizeUniformValue();
    void bindUniform();

    FrameRate  mFPS;
    ShaderInput mInput;
    BufferObject *mVBOArray;
    BufferObject *mVBOIndex;
    ShaderProgram *mProgram;
    VertexArrayObject *mVAO;
    std::vector<Texture *> mTextures;
};

#endif // SHADER_TOY_H
