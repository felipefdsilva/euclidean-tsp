/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 3 (Caixeiro Viajante - variação euclideana)
* Autores: Felipe Ferreira e Luis Fernando
* Declaraçãp da classe Vertice
*/

#ifndef VERTEX_H
#define VERTEX_H "vertice.h"

Class Vertex {
  public:
    Vertex(double, double);
    double getX ();
    double getY ();
  private:
    double mX;
    double mY;
};

#endif
