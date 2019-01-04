#ifndef POLYGON3D_H
#define POLYGON3D_H
#include"spacemesh.h"

class Polygon3D : public SpaceMesh
{
public:
    Polygon3D();
    Polygon3D(int dataCnt, QVector3D* points);
    virtual void paint(QOpenGLFunctions* func) Q_DECL_OVERRIDE;
    virtual void init(SpaceWindow* context) Q_DECL_OVERRIDE;
private:
    QVector3D* points;
};

#endif // POLYGON3D_H
