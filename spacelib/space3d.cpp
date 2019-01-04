#include "space3d.h"

Space3D::Space3D()
{

}
QList<SpaceMesh*>& Space3D::meshes(){
    return this->m_meshes;
}

Space3D* Space3D::addMesh(SpaceMesh* mesh){
    mesh->m_space3d = this;
    this->m_meshes.append(mesh);
    return this;
}

QMatrix4x4& Space3D::projection(){
    return m_projection;
}

Camera3D& Space3D::camera(){
    return m_camera;
}

int Space3D::worldToCamera(){
    return u_worldToCamera;
}

int Space3D::cameraToView(){
    return u_cameraToView;
}

void Space3D::setWorldToCamera(int wtc){
    u_worldToCamera = wtc;
}

void Space3D::setCameraToView(int ctv){
    u_cameraToView = ctv;
}
