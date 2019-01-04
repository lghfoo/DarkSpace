#include "polygon3d.h"
#include"spacewindow.h"
#include"space3d.h"

Polygon3D::Polygon3D()
{

}

Polygon3D::Polygon3D(int dataCnt, QVector3D* points){
    this->points = points;
    m_dataCnt = dataCnt;
}

void Polygon3D::paint(QOpenGLFunctions* func){
//    Shader::defaultShader->bind();
//    Shader::defaultShader->setUniformValue(m_space3d->worldToCamera(), m_space3d->camera().toMatrix());
//    Shader::defaultShader->setUniformValue(m_space3d->cameraToView(), m_space3d->projection());
    m_program->bind();
    m_program->setUniformValue(u_worldToCamera, m_space3d->camera().toMatrix());
    m_program->setUniformValue(u_cameraToView, m_space3d->projection());
    m_object.bind();
    m_program->setUniformValue(u_modelToWorld, m_transform.toMatrix());
//    Shader::defaultShader->setUniformValue(u_modelToWorld, m_transform.toMatrix());
    func->glDrawArrays(GL_LINE_LOOP, 0, m_dataCnt);
    m_object.release();
    m_program->release();
//    Shader::defaultShader->release();
}

void Polygon3D::init(SpaceWindow* context){
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
    context->allocateGLBuffer(m_vertices, points, m_dataCnt * 12);


    context->bindShaderProgram(m_program);
    context->enableProgramAttributeArray(m_program, 0);
    context->setProgramAttributeBuffer(m_program, 0, GL_FLOAT, Vertex3DData::posOffset(), Vertex3DData::POS_TUPLE_SIZE, Vertex3DData::stride());
    context->releaseShaderProgram(m_program);
    context->releaseGLBufferObject(m_object);
    context->releaseGLBuffer(m_vertices);
}



