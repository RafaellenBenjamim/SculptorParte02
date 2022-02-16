#include <iostream>
#include <fstream>
#include <string>
#include "sculptor.h"
#include "Interpretador.h"
#include <vector>
#include "PutVoxel.h"
#include "PutBox.h"
#include "PutSphere.h"
#include "PutEllipsoid.h"
#include "CutVoxel.h"
#include "CutBox.h"
#include "CutSphere.h"
#include "CutEllipsoid.h"
#include "FiguraGeometrica.h"
using namespace std;


int main()
{
    Sculptor *alien;
    Interpretador parse;
    vector<FiguraGeometrica*> fig;

    fig = parse.parse("entrada.txt"); 

    alien = new Sculptor(parse.getdimx(),parse.getdimy(),parse.getdimz());   

    for (size_t x=0; x<fig.size(); x++){
        fig[x] -> draw(*alien);
    }

    alien->writeOFF((char*)"Alien.off"); // criação do arquivo .off

    for (size_t x=0; x<fig.size(); x++){
        delete fig[x];
    }
    delete alien;

}