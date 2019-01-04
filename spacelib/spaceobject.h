#ifndef SPACEOBJECT_H
#define SPACEOBJECT_H
#include<qstring.h>
class SpaceObject
{
public:
    SpaceObject();
    virtual ~SpaceObject();
    virtual QString toString() const;
};

#endif // SPACEOBJECT_H
