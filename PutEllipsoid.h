#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "FiguraGeometrica.h"
#include "Sculptor.h"

class PutEllipsoid : public FiguraGeometrica
{
protected:
    int xcenter; int ycenter; int zcenter; int rx; int ry; int rz;
public:
    PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a);
    void draw(Sculptor &t);
    ~PutEllipsoid(){};
};

#endif // PUTELLIPSOID_H