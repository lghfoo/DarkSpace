#include "spaceobject.h"
#include"util.h"
SpaceObject::SpaceObject(){

}

QString SpaceObject::toString() const{
    return QString("space object: ") + Util::addressAsString(*this);
}

SpaceObject::~SpaceObject(){

}
