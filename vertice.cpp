/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 3 (Caixeiro Viajante - variação euclideana)
* Autores: Felipe Ferreira e Luis Fernando
* Implementação da classe Vertice
*/

#include "vertice.h"

Vertex::Vertex(double x, double y){
  mX = x;
  mY = y;
}
double Vertex::getX (){
  return mX;
}
double Vertex::getY (){
  return mY;
}
