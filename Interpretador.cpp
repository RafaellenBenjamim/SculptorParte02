#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "PutVoxel.h"
#include "PutBox.h"
#include "PutSphere.h"
#include "PutEllipsoid.h"
#include "CutVoxel.h"
#include "CutBox.h"
#include "CutSphere.h"
#include "CutEllipsoid.h"
#include "Interpretador.h"

using namespace std;

Interpretador::Interpretador()
{
}

vector<FiguraGeometrica*> Interpretador:: parse(string filename){

    vector<FiguraGeometrica*> figuras; // onde será armazenado os desenhos
    ifstream entrada;
    string stng, s;
    stringstream ss;

    entrada.open(filename.c_str());

    if(!entrada.is_open()){
        cout << "Não foi possivel abrir " << filename << ".\n" << endl;
        exit(0);
    }

    while (getline(entrada,stng)){

    ss.clear();
    ss.str(stng);
    ss >> s;
    cout << scanf << " ";

    if(s.compare("dim")==0){
        ss >> dimx >> dimy >> dimz;
    }
    else if(s.compare("putvoxel")==0){
        int x_,y_,z_;
        ss >> x_ >> y_ >> z_ >> r >> g >> b >> a;
        figuras.push_back(new PutVoxel(x_, y_, z_, r, g, b, a));
    }
    else if(s.compare("cutvoxel")==0){
        int x_, y_, z_;
        ss >> x_ >> y_ >> z_;
        figuras.push_back(new CutVoxel(x_,y_,z_));
    }
    else if(s.compare("putbox")==0){
        int x0; int x1; int y0; int y1; int z0; int z1;
        ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
        //cout << x0<< x1 << y0 << y1 << z0 << z1 << r << g << b << a << endl;
        figuras.push_back(new PutBox(x0,x1,y0, y1, z0,z1, r, g, b, a));
    }
    else if(s.compare("cutbox")==0){
        int x0; int x1; int y0; int y1; int z0; int z1;
        ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
        figuras.push_back(new CutBox(x0,x1,y0, y1, z0,z1));
    }
    else if(s.compare("putsphere")==0){
        int xcenter; int ycenter; int zcenter; int radius;
        ss >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
        figuras.push_back(new PutSphere(xcenter, ycenter, zcenter, radius, r, g, b, a));
    }
    else if(s.compare("cutsphere")==0){
        int xcenter; int ycenter; int zcenter; int radius;
        ss >> xcenter >> ycenter >> zcenter >> radius;
        figuras.push_back(new CutSphere(xcenter, ycenter, zcenter, radius));
    }
    else if(s.compare("putellipsoid")==0){
        int xcenter, ycenter, zcenter, rx, ry, rz;
        ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
        figuras.push_back(new PutEllipsoid(xcenter,ycenter,zcenter,rx,ry,rz, r, g, b, a));
    }
    else if(s.compare("cutellipsoid")==0){
        int xcenter_, ycenter_, zcenter_, rx_, ry_, rz_;
        ss >> xcenter_ >> ycenter_ >> zcenter_ >> rx_ >> ry_ >> rz_;
        figuras.push_back(new CutEllipsoid(xcenter_,ycenter_,zcenter_,rx_,ry_,rz_));
    }
    }

    entrada.close();
    return(figuras);
}

int Interpretador::getdimx()
{
    return dimx;
}

int Interpretador::getdimy()
{
    return dimy;
}

int Interpretador::getdimz()
{
    return dimz;
}