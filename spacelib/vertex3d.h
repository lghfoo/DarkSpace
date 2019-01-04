#ifndef VERTEX3D_H
#define VERTEX3D_H
#include<QVector3D>
#include"spaceobject.h"
#include"spacemesh.h"
class Vertex3DData: public SpaceMeshData{
public:
    Vertex3DData();
    Vertex3DData(const QVector3D& pos);
    static int posOffset();
    static int stride();
    const static int POS_TUPLE_SIZE = 3;

    QVector3D getPos() const;
private:
    QVector3D m_position;
};

class Vertex3D : public SpaceMesh{
public:
    Vertex3D();
    Vertex3D(const QVector3D& pos);
    virtual QString toString()const Q_DECL_OVERRIDE;
    virtual void paint(QOpenGLFunctions* func) Q_DECL_OVERRIDE;
    virtual void init(SpaceWindow* context) Q_DECL_OVERRIDE;
};

#endif // VERTEX3D_H
