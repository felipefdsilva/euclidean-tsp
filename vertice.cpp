/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 3 (Caixeiro Viajante - variação euclideana)
* Autores: Felipe Ferreira e Luis Fernando
* Implementação da classe Vertice
*/

#include "vertice.h"

/*Construtor padrão da classe Vertex*/
Vertex::Vertex(){
}
/*Sobrecarga do operador '=' para atribuir um objeto Vertex a outro*/
Vertex&  Vertex::operator=(const Vertex&v1){
  this->setIndex(v1.getIndex()); //atribui o indice de v1 (lado direito) ao vertex no lado esquerdo de =
  this->setX(v1.getX()); //atribui a coordenada x de v1 (lado direito) ao vertex no lado esquerdo de =
  this->setY(v1.getY()); //atribui a coordenada y de v1 ao vertex no lado esquedo de =
  return *this;
}
/*Configura o indice do vertice*/
void Vertex::setIndex (unsigned index){
  mIndex = index;
}
/*Configura a coordenada x do vértice*/
void Vertex::setX(float x){
  mX = x;
}
/*Configura a coordenada y do vértice*/
void Vertex::setY(float y){
  mY = y;
}
/*Retorna o indice do vértice*/
unsigned Vertex::getIndex () const{
  return mIndex;
}
/*Retorna a coordenada x do vértice*/
float Vertex::getX () const{
  return mX;
}
/*Retorna a coordenada y do vértice*/
float Vertex::getY () const{
  return mY;
}
