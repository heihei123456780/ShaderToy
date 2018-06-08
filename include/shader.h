#ifndef SHADER_H
#define SHADER_H

#include "common.h"

enum ShaderType {
    Vertex = 1 << 1,
    Fragment = 1 << 2
};

class Shader
{
public:
    typedef enum ShaderType ShaderType;

    Shader(Shader::ShaderType shaderType);
    ~Shader();

    bool compileSourceCode(const char *source);
    bool compileSourceCode(const std::string &source);
    bool compileSourceFile(const std::string &filename);

    bool isCompiled() const { return mCompiled; }

    GLuint shaderId() const { return mShaderId; }
    Shader::ShaderType shaderType() const { return mShaderType; }

    std::string sourceCode() const { return mSourceCode; }
    std::string log() const { return mLog; }

protected:
    bool create();
    void destroy();
    bool compile(const char *source);

private:
    friend class ShaderProgram;

    bool mCompiled;
    GLuint mShaderId;
    ShaderType mShaderType;

    std::string mLog;
    std::string mSourceCode;
};

#endif // GL_SHADER_H
