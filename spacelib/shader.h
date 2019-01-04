#ifndef SHADER_H
#define SHADER_H
#include<qopenglshaderprogram.h>
#include<qlist.h>
#include<qstring.h>
#include<qpair.h>
struct AttributeBufferInfo{
public:
    AttributeBufferInfo(){

    }

    int location;
    GLenum type;
    int offset;
    int tupleSize;
    int stride;
};

class Shader{
public:
    static QOpenGLShaderProgram* defaultShader;
    QList<QPair<QOpenGLShader::ShaderType, QString> >shaderFileInfos;
    QList<QPair<int, QString> >shaderUniformInfos;

};

//QOpenGLShaderProgram* Shader::defaultShader = nullptr;

#endif // SHADER_H
