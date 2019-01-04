#include <QGuiApplication>
#include "spacelib/spacewindow.h"
#include "spacelib/util.h"
#include"spacelib/spaceobject.h"
#include"spacelib/vertex3d.h"
#include"game_dark_space/darkspace.h"
#include<qdebug.h>

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);
    DarkSpace sw;
    sw.show();
    return a.exec();
}
