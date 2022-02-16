#include "PutEllipsoid.h"
#include "sculptor.h"

PutEllipsoid::PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a)
{
    this->xcenter=xcenter; 
    this->ycenter=ycenter; 
    this->zcenter=zcenter; 
    this->rx=rx; 
    this->ry=ry; 
    this->rz=rz;
    this->r=r; 
    this->g=g; 
    this->b=b; 
    this->a=a;
}

void PutEllipsoid::draw(Sculptor& t) {

	t.setColor(r, g, b, a);

	double x, y, z;

	for (int i = 0; i < t.getx(); i++)
		for (int j = 0; j < t.gety(); j++)
			for (int k = 0; k < t.getz(); k++) {
				x = ((double)(i - xcenter) * (double)(i - xcenter)) / (rx * rx);
				y = ((double)(j - ycenter) * (double)(j - ycenter)) / (ry * ry);
				z = ((double)(k - zcenter) * (double)(k - zcenter)) / (rz * rz);

				if ((x + y + z) < 1)
					t.putVoxel(i, j, k);
			}
}