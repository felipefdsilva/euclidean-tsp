/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 3 (Caixeiro Viajante - variação euclideana)
* Autores: Felipe Ferreira e Luis Fernando
* Declaraçãp da classe Vertice
*/

#ifndef VERTICE_H
#define VERTICE_H "vertice.h"

class Vertex {
  public:
    Vertex(); //construtor
    Vertex&  operator=(const Vertex&); //sobrecarga do operador "=" para igualar coordenadas facilmente
    void setIndex(unsigned); //define o indice do vertice
    void setX (float); //define a coordenada x do vertice
    void setY (float); //define a coordenada y do vertice
    unsigned getIndex() const; //retorna o indice do vertice
    float getX () const; //retorna a coordenada x do vértice
    float getY () const; //retorna a coordenada y do vértice
  private:
    unsigned mIndex; //atrituto que guarda o indice do vertice
    double mX; //atributo que guarda a coordenada x do vértice
    double mY; //atributo que guarda a coordenada y do vértice
};

#endif
