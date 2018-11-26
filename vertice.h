/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 3 (Caixeiro Viajante - variação euclideana)
* Autores: Felipe Ferreira e Luis Fernando
* Declaraçãp da classe Vertice
*/

#ifndef VERTEX_H
#define VERTEX_H "vertice.h"

class Vertex {
  public:
    Vertex();
    Vertex&  operator=(const Vertex&);
    void setIndex(unsigned);
    void setX (float);
    void setY (float);
    unsigned getIndex() const;
    float getX () const;
    float getY () const;
  private:
    unsigned mIndex;
    double mX;
    double mY;
};

#endif
