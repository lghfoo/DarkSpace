#ifndef LINE3D_H
#define LINE3D_H
#include"spaceobject.h"
#include"vertex3d.h"
#include<qopenglbuffer.h>
#include<qopenglvertexarrayobject.h>
#include<qopenglshaderprogram.h>
#include<qopenglfunctions.h>
#include<qopenglwindow.h>
#include"spacemesh.h"
class Line3DData: public SpaceMeshData{
public:
    Line3DData();
    Line3DData(const QVector3D& p1, const QVector3D& p2);
    Vertex3DData p1;
    Vertex3DData p2;
};

class Line3D : public SpaceMesh{
public:
    Line3D();
    Line3D(const QVector3D& p1, const QVector3D& p2);
    virtual QString toString() const Q_DECL_OVERRIDE;
    virtual void paint(QOpenGLFunctions* func) Q_DECL_OVERRIDE;
    virtual void init(SpaceWindow* context) Q_DECL_OVERRIDE;
//private:

};

#endif // LINE3D_H
