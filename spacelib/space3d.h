#ifndef SPACE3D_H
#define SPACE3D_H
#include"spacemesh.h"
#include<qlist.h>
#include"camera3d.h"

class Space3D
{
public:
    Space3D();
    QList<SpaceMesh*>& meshes();
    QMatrix4x4& projection();
    Camera3D& camera();
    Space3D* addMesh(SpaceMesh* mesh);
    int worldToCamera();
    int cameraToView();
    void setWorldToCamera(int wtc);
    void setCameraToView(int ctv);
private:
    QList<SpaceMesh*>m_meshes;
    QMatrix4x4 m_projection;
    Camera3D m_camera;
    int u_worldToCamera;
    int u_cameraToView;
};

#endif // SPACE3D_H
