#include "spacewindow.h"
#include<qdatetime.h>
#include<qopenglshaderprogram.h>
#include"vertex3d.h"
#include"line3d.h"
#include"shader.h"
SpaceWindow::SpaceWindow()
{
    QSurfaceFormat format;
    format.setRenderableType(QSurfaceFormat::OpenGL);
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setSamples(4);
    format.setVersion(4, 0);
    this->setFormat(format);
    this->resize(800, 600);
//    lines.append(new Line3D(QVector3D(0.00f, 0.00f, 0.00f), QVector3D(0, -0.75, 0.00f)));
//    lines.append(new Line3D(QVector3D(0.00f, 0.00f, 0.00f), QVector3D(0.75, 0, 0.00f)));
//    lines.append(new Line3D(QVector3D(0.00f, 0.00f, 0.00f), QVector3D(0, 0.75, 0.00f)));
    m_space3d = new Space3D();
//    m_space3d->addMesh(lines[0])->addMesh(lines[1])->addMesh(lines[2]);
}

SpaceWindow::~SpaceWindow(){

}

void SpaceWindow::initializeGL(){
    initializeOpenGLFunctions();
//    connect(this, SIGNAL(frameSwapped()), this, SLOT(update()));
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_MULTISAMPLE);
//    Shader::defaultShader = new QOpenGLShaderProgram();
//    Shader::defaultShader->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/space_shaders/simple_vertex_shader.vsh");
//    Shader::defaultShader->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/space_shaders/simple_fragment_shader.fsh");
//    Shader::defaultShader->link();

//    m_space3d->setWorldToCamera(Shader::defaultShader->uniformLocation("worldToCamera"));
//    m_space3d->setCameraToView(Shader::defaultShader->uniformLocation("cameraToView"));

    QList<SpaceMesh*>& list = m_space3d->meshes();
//    for(int i = 0; i < list.size(); i++){
//        iniMesh(list[i]);
//    }
    for(int i = 0; i <list.size(); i++){
        list[i]->init(this);
    }
}



void SpaceWindow::resizeGL(int width, int height){
    m_space3d->projection().setToIdentity();
    m_space3d->projection().perspective(45.0f, width / float(height), 0.0f, 1000.0f);
}

void SpaceWindow::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT);
//    for(int i = 0; i < lines.size(); i++){
//        lines[i]->paint(this);
//    }
    QList<SpaceMesh*>& list = m_space3d->meshes();
    for(int i = 0; i < list.size(); i++){
//        if(!list[i]->m_isInitialized)this->iniMesh(list[i]);
        if(!list[i]->m_isInitialized)list[i]->init(this);
        list[i]->paint(this);
    }
}

void SpaceWindow::update(){
    QOpenGLWindow::update();
}

