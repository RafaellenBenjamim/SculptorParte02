#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include <vector>
#include <string>
#include "FiguraGeometrica.h"

using namespace std;

class Interpretador
{
protected:
	int dimx, dimy, dimz;
	float r, g, b, a;
public:
    Interpretador();
    ~Interpretador(){};
    
    vector<FiguraGeometrica*> parse(string filename);

    int getdimx();
    int getdimy();
    int getdimz();
};

#endif // INTERPRETADOR_H