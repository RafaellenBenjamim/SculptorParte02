#ifndef SCULPTOR_H
#define SCULPTOR_H

struct Voxel {
  float r,g,b; // Cores
  float a; // Transparencia
  bool isOn; // Incluido ou nao
};

class Sculptor {

protected:
  Voxel ***vox; // Matriz 3D, um asterisco para cada dimensão
  float lado;
  int nx,ny,nz; // Eixos - Dimensões
  float r,g,b,a; // Definir as cores e transparência

public:
  Sculptor(int _nx = 0, int _ny = 0, int _nz = 0); //Construtor da classe
  ~Sculptor(); // Destrutor da classe
  void setColor(float _r = 0, float _g = 0, float _b = 0, float alpha = 0); // Define a cor atual de desenho.
  void putVoxel(int x0 = 0, int y0 = 0, int z0 = 0); // Ativa o voxel na posição (x,y,z) (fazendo isOn = true) e atribui ao mesmo a cor atual de desenho
  void cutVoxel(int x0 = 0, int y0 = 0, int z0 = 0); // Desativa o voxel na posição (x,y,z) (fazendo isOn = false)
  int getx();
  int gety();
  int getz();
  void writeOFF(char* filename); // grava a escultura no formato OFF no arquivo filename

};

# endif // SCULPTOR_H