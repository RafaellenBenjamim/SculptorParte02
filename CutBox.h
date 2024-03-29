#ifndef CUTBOX_H
#define CUTBOX_H

#include "FiguraGeometrica.h"
#include "Sculptor.h"

class CutBox : public FiguraGeometrica
{
protected:
    int x0; int x1; int y0; int y1; int z0; int z1;
public:
    CutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    ~CutBox(){};
    void draw(Sculptor &t);
};

#endif // CUTBOX_H