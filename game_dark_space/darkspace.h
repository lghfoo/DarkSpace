#ifndef DARK_SPACE_H
#define DARK_SPACE_H
#include<qopenglwindow.h>
#include<qopenglfunctions.h>
#include<qopenglbuffer.h>
#include<qopenglvertexarrayobject.h>
#include"../spacelib/line3d.h"
#include"../spacelib/space3d.h"
#include"../spacelib/spacewindow.h"
class QOpenGLShaderProgram;

class DarkSpace : public SpaceWindow
{
    Q_OBJECT
public:
    DarkSpace();
    ~DarkSpace();
    protected slots:
        void update();

protected:
  void keyPressEvent(QKeyEvent *event);
  void keyReleaseEvent(QKeyEvent *event);
  void mousePressEvent(QMouseEvent *event);
  void mouseReleaseEvent(QMouseEvent *event);
};

#endif // SPACEWINDOW_H
