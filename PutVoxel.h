#ifndef PUTVOXEL_H
#define PUTVOXEL_H

#include "FiguraGeometrica.h"
#include "Sculptor.h"

class PutVoxel: public FiguraGeometrica
{
protected:
int x, y, z;
public:
    PutVoxel(int x, int y, int z, float r, float g, float b, float a);
    ~PutVoxel(){};
    void draw(Sculptor &t);
};

#endif // PUTVOXEL_H