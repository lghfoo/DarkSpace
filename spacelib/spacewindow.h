#ifndef SPACEWINDOW_H
#define SPACEWINDOW_H
#include<qopenglwindow.h>
#include<qopenglfunctions.h>
#include<qopenglbuffer.h>
#include<qopenglvertexarrayobject.h>
#include"line3d.h"
#include"space3d.h"
#include"camera3d.h"
class QOpenGLShaderProgram;

class SpaceWindow : public QOpenGLWindow, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    SpaceWindow();
    ~SpaceWindow();
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

    void createGLBuffer(QOpenGLBuffer& buffer){buffer.create();}
    void createGLBufferObject(QOpenGLVertexArrayObject& object){object.create();}
    void bindGLBuffer(QOpenGLBuffer& buffer){buffer.bind();}
    void bindGLBufferObject(QOpenGLVertexArrayObject& object){object.bind();}
    void setGLBufferUsagePattern(QOpenGLBuffer& buffer, QOpenGLBuffer::UsagePattern pattern){buffer.setUsagePattern(pattern);}
    void allocateGLBuffer(QOpenGLBuffer& buffer, const void* data, int cnt){buffer.allocate(data, cnt);}
    QOpenGLShaderProgram* createShaderProgram(){return new QOpenGLShaderProgram();}
    void addShaderFromSourceFile(QOpenGLShaderProgram* program, QOpenGLShader::ShaderType type, const QString& src){program->addShaderFromSourceFile(type, src);}
    void linkShaderProgram(QOpenGLShaderProgram* program){program->link();}
    void bindShaderProgram(QOpenGLShaderProgram* program){program->bind();}
    int shaderUniformLocation(QOpenGLShaderProgram* program, const char* name){return program->uniformLocation(name);}
    void enableProgramAttributeArray(QOpenGLShaderProgram* program, int attr){program->enableAttributeArray(attr);}
    void setProgramAttributeBuffer(QOpenGLShaderProgram* program, int location, GLenum type, int offset, int tupleSize, int stride){program->setAttributeBuffer(location, type, offset, tupleSize, stride);}
    void releaseGLBuffer(QOpenGLBuffer& buffer){buffer.release();}
    void releaseGLBufferObject(QOpenGLVertexArrayObject& object){object.release();}
    void releaseShaderProgram(QOpenGLShaderProgram* program){program->release();}

protected slots:
    void update();

private:
    QList<SpaceMesh*>lines;
protected:
    Space3D* m_space3d;
};

#endif // SPACEWINDOW_H
