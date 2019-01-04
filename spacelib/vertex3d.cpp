#include "vertex3d.h"
Vertex3DData::Vertex3DData(){
}

Vertex3DData::Vertex3DData(const QVector3D& pos){
    m_position = pos;
}

int Vertex3DData::posOffset(){
    return offsetof(Vertex3DData, m_position);
}

int Vertex3DData::stride(){
    return sizeof(Vertex3DData);
}

QVector3D Vertex3DData::getPos() const{
    return m_position;
}

Vertex3D::Vertex3D():Vertex3D(QVector3D()){
}

Vertex3D::Vertex3D(const QVector3D& pos){
    m_data = new Vertex3DData(pos);
    m_dataCnt = sizeof(Vertex3DData);
}

QString Vertex3D::toString() const{
    QVector3D m_position = ((Vertex3DData*)m_data)->getPos();
    return QString("vertex: (%1, %2, %3)").arg(QString::number(m_position.x()), QString::number(m_position.y()), QString::number(m_position.z())) ;
}

void Vertex3D::paint(QOpenGLFunctions* func){

}

void Vertex3D::init(SpaceWindow *context){

}
