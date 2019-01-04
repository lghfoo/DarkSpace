#include "transform3d.h"
#include <QDebug>

const QVector3D Transform3D::LocalForward(0.0f, 0.0f, 1.0f);
const QVector3D Transform3D::LocalUp(0.0f, 1.0f, 0.0f);
const QVector3D Transform3D::LocalRight(1.0f, 0.0f, 0.0f);

void Transform3D::translate(const QVector3D &dt){
    m_dirty = true;
    m_translation += dt;
}

void Transform3D::scale(const QVector3D &ds){
    m_dirty = true;
    m_scale *= ds;
}

void Transform3D::rotate(const QQuaternion &dr){
    m_dirty = true;
    m_rotation = dr * m_rotation;
}

void Transform3D::grow(const QVector3D &ds){
    m_dirty = true;
    m_scale += ds;
}

void Transform3D::setTranslation(const QVector3D &t){
    m_dirty = true;
    m_translation = t;
}

void Transform3D::setScale(const QVector3D &s){
    m_dirty = true;
    m_scale = s;
}

void Transform3D::setRotation(const QQuaternion &r){
    m_dirty = true;
    m_rotation = r;
}

const QMatrix4x4& Transform3D::toMatrix(){
    if(m_dirty){
        m_dirty = false;
        m_world.setToIdentity();
        m_world.translate(m_translation);
        m_world.rotate(m_rotation);
        m_world.scale(m_scale);
    }
    return m_world;
}

// Queries
QVector3D Transform3D::forward() const
{
  return m_rotation.rotatedVector(LocalForward);
}

QVector3D Transform3D::up() const
{
  return m_rotation.rotatedVector(LocalUp);
}

QVector3D Transform3D::right() const
{
  return m_rotation.rotatedVector(LocalRight);
}

QDebug operator<<(QDebug dbg, const Transform3D& transform){
    QVector3D t = transform.translation();
    QVector3D s = transform.scale();
    QQuaternion r = transform.rotation();
    dbg << "Tansform3D\n{\n";
    dbg <<"Translation: <"<<t.x()<<", "<<t.y()<<", "<<t.z()<<">\n";
    dbg <<"Scale: <"<<s.x()<<", "<<s.y()<<", "<<s.z()<<">\n";
    dbg <<"Rotation: <"<<r.x()<<", "<<r.y()<<", "<<r.z()<<" | "<<r.scalar()<<">\n}";
    return dbg;
}

QDataStream &operator<<(QDataStream& out, const Transform3D& transform){
    out << transform.m_translation;
    out <<transform.m_scale;
    out<<transform.m_rotation;
    return out;
}

QDataStream &operator>>(QDataStream& in, Transform3D& transform){
    in >> transform.m_translation;
    in >> transform.m_scale;
    in >> transform.m_rotation;
    return in;
}
