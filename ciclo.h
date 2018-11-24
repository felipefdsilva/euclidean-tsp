/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 3 (Caixeiro Viajante - variação euclideana)
* Autores: Felipe Ferreira e Luis Fernando
* Declaração da classe Ciclo
*/

#ifndef CICLO_H
#define CICLO_H "ciclo.h"

#include <vector>
#include "vertice.h"

using namespace std;

Class Cicle {
  public:
    Cicle (unsigned);
    double computeDistance(Vertex, Vertex); //calcula distancia euclideana entre dois vertices
    double computeCicleCost (vector <Vertex>); //calcula o custo total do ciclo (soma das distancias)
    double NearestNeighbour(unsigned); //monta um ciclo escolhendo o vizinho mais proximo
    double BestNearestNeighbourCicle ();
    double TwoOPTSwap(pair, unsigned, unsigned);
    double TwoOPT (pair);
  private:
    unsigned mNumberOfVertices;
    vector <Vertex> mVertices;
    vector <Vertex> mCicle;
};
#endif
