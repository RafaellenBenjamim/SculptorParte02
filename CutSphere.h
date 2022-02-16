#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "FiguraGeometrica.h"
#include "Sculptor.h"

class CutSphere : public FiguraGeometrica
{
protected:
    int xcenter; int ycenter; int zcenter; int radius;
public:
    CutSphere(int xcenter, int ycenter, int zcenter, int radius);
    void draw(Sculptor &t);
    ~CutSphere(){};
};

#endif // CUTSPHERE_H