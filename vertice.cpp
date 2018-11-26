/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 3 (Caixeiro Viajante - variação euclideana)
* Autores: Felipe Ferreira e Luis Fernando
* Implementação da classe Vertice
*/

#include "vertice.h"

Vertex&  Vertex::operator=(const Vertex&v1){
  this ->setIndex(v1.getIndex());
  this->setX(v1.getX());
  this->setY(v1.getY());
  return *this;
}
Vertex::Vertex(){
}
void Vertex::setIndex (unsigned index){
  mIndex = index;
}
void Vertex::setX(float x){
  mX = x;
}
void Vertex::setY(float y){
  mY = y;
}
unsigned Vertex::getIndex () const{
  return mIndex;
}
float Vertex::getX () const{
  return mX;
}
float Vertex::getY () const{
  return mY;
}
