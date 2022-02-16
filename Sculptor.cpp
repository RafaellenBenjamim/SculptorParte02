#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz){ // Construtor

    nx = _nx;
    ny = _ny;
    nz = _nz;

    vox = new Voxel **[nx];

for (int i = 0; i < nx; i++){
    vox[i] = new Voxel*[ny];
    }
    for (int i = 0; i < nx; i++){
        for (int j = 0; j < ny; j++){
            vox[i][j] = new Voxel[nz];
        }
    }
    for(int i = 0; i < nx; i++){ // Atribuição dos valores iniciais das cores
        for (int j = 0; j < ny; j++){
            for (int k = 0; k < nz; k++){
                vox[i][j][k].isOn = false;

                vox[i][j][k].r = 0;
                vox[i][j][k].g = 0;
                vox[i][j][k].b = 0;
                vox[i][j][k].a = 0;
            }
        }
    }
}

Sculptor::~Sculptor(){ // Destrutor - Liberação das memórias
        for(int i = 0; i < nx; i++){
           for (int j = 0; j < ny; j++){
                delete[] vox[i][j];
            }
        }
        for (int i = 0; i < nx; i++){
            delete[] vox[i];
        }
        delete[] vox;

        nx=ny=nz=0;

}

void Sculptor::setColor(float _r, float _g, float _b, float alpha){

    r = _r;
    g = _g;
    b = _b;
    a = alpha;
}

void Sculptor::putVoxel(int x0, int y0, int z0){

    vox[x0][y0][z0].isOn = true;
    vox[x0][y0][z0].r = r;
    vox[x0][y0][z0].g = g;
    vox[x0][y0][z0].b = b;
    vox[x0][y0][z0].a = a;

}

void Sculptor::cutVoxel(int x0, int y0, int z0){

    vox[x0][y0][z0].isOn = false;

}

int Sculptor::getx(){
    return nx;
}
int Sculptor::gety(){
    return ny;
}
int Sculptor::getz(){
    return nz;
}

void Sculptor::writeOFF(char* filename){

ofstream outFile;
	outFile.open(filename);

	int Nvoxel = 0;

	for (int i = 0; i < nx; i++) { // Conta quantos voxels tem no desenho
		for (int j = 0; j < ny; j++) {
			for (int k = 0; k < nz; k++) {
				if (vox[i][j][k].isOn) {
					Nvoxel++;
				}
			}
		}
	}

	outFile << "OFF" << endl << Nvoxel * 8 << " " << Nvoxel * 6 << " " << 0 << endl; // Calcula a quantidade de vertices e faces


	for (int i = 0; i < nx; i++) { // Declarando os pontos centrais de cada voxel
		for (int j = 0; j < ny; j++) {
			for (int k = 0; k < nz; k++) {
				if (vox[i][j][k].isOn) {
					outFile << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
					outFile << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
					outFile << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
					outFile << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
					outFile << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
					outFile << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
					outFile << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
					outFile << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
				}
			}
		}
	}

	int vertice = 0;
	outFile << setiosflags(ios::fixed); // Fixa a saida das cores em decimal float <iomanip>

	for (int i = 0; i < nx; i++) { // Declarando as faces
		for (int j = 0; j < ny; j++) {
			for (int k = 0; k < nz; k++) {
				if (vox[i][j][k].isOn) {
					outFile << 4 << " " << vertice + 0 << " " << vertice + 3 << " " << vertice + 2 << " " << vertice + 1 << " " << vox[i][j][k].r << " " << vox[i][j][k].g << " " << vox[i][j][k].b << " " << vox[i][j][k].a << endl;
					outFile << 4 << " " << vertice + 4 << " " << vertice + 5 << " " << vertice + 6 << " " << vertice + 7 << " " << vox[i][j][k].r << " " << vox[i][j][k].g << " " << vox[i][j][k].b << " " << vox[i][j][k].a << endl;
					outFile << 4 << " " << vertice + 0 << " " << vertice + 1 << " " << vertice + 5 << " " << vertice + 4 << " " << vox[i][j][k].r << " " << vox[i][j][k].g << " " << vox[i][j][k].b << " " << vox[i][j][k].a << endl;
					outFile << 4 << " " << vertice + 0 << " " << vertice + 4 << " " << vertice + 7 << " " << vertice + 3 << " " << vox[i][j][k].r << " " << vox[i][j][k].g << " " << vox[i][j][k].b << " " << vox[i][j][k].a << endl;
					outFile << 4 << " " << vertice + 3 << " " << vertice + 7 << " " << vertice + 6 << " " << vertice + 2 << " " << vox[i][j][k].r << " " << vox[i][j][k].g << " " << vox[i][j][k].b << " " << vox[i][j][k].a << endl;
					outFile << 4 << " " << vertice + 1 << " " << vertice + 2 << " " << vertice + 6 << " " << vertice + 5 << " " << vox[i][j][k].r << " " << vox[i][j][k].g << " " << vox[i][j][k].b << " " << vox[i][j][k].a << endl;
					vertice = vertice + 8;
				}
			}
		}
	}
	outFile.close();
}
