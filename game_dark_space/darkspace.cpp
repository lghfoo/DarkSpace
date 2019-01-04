#include "darkspace.h"
#include<qdatetime.h>
#include<qevent.h>
#include<qopenglshaderprogram.h>
#include"../spacelib/vertex3d.h"
#include"../spacelib/line3d.h"
#include"../spacelib/input.h"
#include"../spacelib/polygon3d.h"

DarkSpace::DarkSpace()
{
    QVector3D flt(-0.5f, 0.5f, -0.5f);
    QVector3D flb(-0.5f, -0.5f, -0.5f);
    QVector3D frt(0.5f, 0.5f, -0.5f);
    QVector3D frb(0.5f, -0.5f, -0.5f);
    QVector3D blt(-0.5f, 0.5f, -1.0f);
    QVector3D blb(-0.5f, -0.5f, -1.0f);
    QVector3D brt(0.5f, 0.5f, -1.0f);
    QVector3D brb(0.5f, -0.5f, -1.0f);
//   m_space3d->addMesh(new Line3D(QVector3D(-0.5f, 0.5f, -0.5f), QVector3D(0.5f, 0.5f, -0.5f)))
//           ->addMesh(new Line3D(QVector3D(0.5f, 0.5f, -0.5f), QVector3D(0.75f, -0.75f, 0.0f)));
//    m_space3d->addMesh(new Line3D(flt, flb));
//    m_space3d->addMesh(new Line3D(flb, frb));
//    m_space3d->addMesh(new Line3D(frb, frt));
//    m_space3d->addMesh(new Line3D(frt, flt));
//    m_space3d->addMesh(new Line3D(flt, blt));
//    m_space3d->addMesh(new Line3D(flb, blb));
//    m_space3d->addMesh(new Line3D(frt, brt));
//    m_space3d->addMesh(new Line3D(frb, brb));
//    m_space3d->addMesh(new Line3D(blt, blb));
//    m_space3d->addMesh(new Line3D(blb, brb));
//    m_space3d->addMesh(new Line3D(brb, brt));
//    m_space3d->addMesh(new Line3D(brt, blt));
    QVector3D* points = new QVector3D[4];
    points[0] = blt;
    points[1] = blb;
    points[2] = brb;
    points[3] = brt;
    m_space3d->addMesh(new Polygon3D(4, points));


    connect(this, SIGNAL(frameSwapped()), this, SLOT(update()));
}

DarkSpace::~DarkSpace(){

}


void DarkSpace::update(){
    // Update input
    Input::update();

    // Camera Transformation
    if (Input::buttonPressed(Qt::RightButton))
    {
      static const float transSpeed = 0.5f;
      static const float rotSpeed   = 0.5f;

      // Handle rotations
      Camera3D& m_camera = m_space3d->camera();
      m_camera.rotate(-rotSpeed * Input::mouseDelta().x(), Camera3D::LocalUp);
      m_camera.rotate(-rotSpeed * Input::mouseDelta().y(), m_camera.right());

      // Handle translations
      QVector3D translation;
      if (Input::keyPressed(Qt::Key_W))
      {
        translation += m_camera.forward();
      }
      if (Input::keyPressed(Qt::Key_S))
      {
        translation -= m_camera.forward();
      }
      if (Input::keyPressed(Qt::Key_A))
      {
        translation -= m_camera.right();
      }
      if (Input::keyPressed(Qt::Key_D))
      {
        translation += m_camera.right();
      }
      if (Input::keyPressed(Qt::Key_Q))
      {
        translation -= m_camera.up();
      }
      if (Input::keyPressed(Qt::Key_E))
      {
        translation += m_camera.up();
      }
      m_camera.translate(transSpeed * translation);
    }

//    m_transform.rotate(30.0f, QVector3D(0.0f, 0.0f, -0.3f));
    QOpenGLWindow::update();
}

void DarkSpace::keyPressEvent(QKeyEvent *event)
{
  if (event->isAutoRepeat())
  {
    event->ignore();
  }
  else
  {
    Input::registerKeyPress(event->key());
  }
}

void DarkSpace::keyReleaseEvent(QKeyEvent *event)
{
  if (event->isAutoRepeat())
  {
    event->ignore();
  }
  else
  {
    Input::registerKeyRelease(event->key());
  }
}

void DarkSpace::mousePressEvent(QMouseEvent *event)
{
  Input::registerMousePress(event->button());
}

void DarkSpace::mouseReleaseEvent(QMouseEvent *event)
{
  Input::registerMouseRelease(event->button());
}
