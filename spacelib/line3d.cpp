#include "line3d.h"
#include "shader.h"
#include"space3d.h"
#include"spacewindow.h"
Line3DData::Line3DData():Line3DData(QVector3D(), QVector3D()){

}

Line3DData::Line3DData(const QVector3D& p1, const QVector3D& p2){
    this->p1 = p1;
    this->p2 = p2;
}

Line3D::Line3D():Line3D(QVector3D(), QVector3D()){
}

Line3D::Line3D(const QVector3D& p1, const QVector3D& p2){
    m_data = new Line3DData(p1, p2);
    m_dataCnt = sizeof(Line3DData);
    m_transform.translate(0,0,-1.0);
}

QString Line3D::toString() const{
    QVector3D p1 = ((Line3DData*)m_data)->p1.getPos();
    QVector3D p2 = ((Line3DData*)m_data)->p2.getPos();
    return QString("space line:(%1, %2, %3) -> (%4, %5, %6)").arg(QString::number(p1.x()),
                                                                  QString::number(p1.y()),
                                                                  QString::number(p1.z()),
                                                                  QString::number(p2.x()),
                                                                  QString::number(p2.y()),
                                                                  QString::number(p2.z()));
}

void Line3D::paint(QOpenGLFunctions* func){
//    Shader::defaultShader->bind();
//    Shader::defaultShader->setUniformValue(m_space3d->worldToCamera(), m_space3d->camera().toMatrix());
//    Shader::defaultShader->setUniformValue(m_space3d->cameraToView(), m_space3d->projection());
    m_program->bind();
    m_program->setUniformValue(u_worldToCamera, m_space3d->camera().toMatrix());
    m_program->setUniformValue(u_cameraToView, m_space3d->projection());
    m_object.bind();
    m_program->setUniformValue(u_modelToWorld, m_transform.toMatrix());
//    Shader::defaultShader->setUniformValue(u_modelToWorld, m_transform.toMatrix());
    func->glDrawArrays(GL_LINES, 0, 2);
    m_object.release();
    m_program->release();
//    Shader::defaultShader->release();
}

void Line3D::init(SpaceWindow* context){
    m_isInitialized = true;
    m_program = context->createShaderProgram();
    context->addShaderFromSourceFile(m_program, QOpenGLShader::Vertex, ":/space_shaders/simple_vertex_shader.vsh");
    context->addShaderFromSourceFile(m_program, QOpenGLShader::Fragment, ":/space_shaders/simple_fragment_shader.fsh");
    context->linkShaderProgram(m_program);

    u_worldToCamera = context->shaderUniformLocation(m_program, "worldToCamera");
    u_cameraToView = context->shaderUniformLocation(m_program, "cameraToView");
    u_modelToWorld = context->shaderUniformLocation(m_program, "modelToWorld");

    context->createGLBuffer(m_vertices);
    context->createGLBufferObject(m_object);
    context->bindGLBuffer(m_vertices);
    context->bindGLBufferObject(m_object);
    context->setGLBufferUsagePattern(m_vertices, QOpenGLBuffer::StaticDraw);
    context->allocateGLBuffer(m_vertices, m_data, m_dataCnt);


    context->bindShaderProgram(m_program);
    context->enableProgramAttributeArray(m_program, 0);
    context->setProgramAttributeBuffer(m_program, 0, GL_FLOAT, Vertex3DData::posOffset(), Vertex3DData::POS_TUPLE_SIZE, Vertex3DData::stride());
    context->releaseShaderProgram(m_program);
    context->releaseGLBufferObject(m_object);
    context->releaseGLBuffer(m_vertices);
}
