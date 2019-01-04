#ifndef SPACEMESH_H
#define SPACEMESH_H
#include"spaceobject.h"
#include<qopenglbuffer.h>
#include<qopenglvertexarrayobject.h>
#include<qopenglshaderprogram.h>
#include<qopenglfunctions.h>
#include"transform3d.h"
class Space3D;
class SpaceWindow;

class SpaceMeshData{

};

class SpaceMesh: public SpaceObject{
public:
    SpaceMesh():m_isInitialized(false), m_program(nullptr){}
    SpaceMeshData* m_data;
    int m_dataCnt;
    bool m_isInitialized;
    Space3D* m_space3d;
    Transform3D m_transform;
    int u_modelToWorld;
    int u_worldToCamera;
    int u_cameraToView;
    QOpenGLBuffer m_vertices;
    QOpenGLVertexArrayObject m_object;
    QOpenGLShaderProgram* m_program;
    virtual void paint(QOpenGLFunctions* func) = 0;
    virtual void init(SpaceWindow* context) = 0;

};

#endif // SPACEMESH_H
