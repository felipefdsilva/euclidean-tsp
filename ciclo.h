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

class Cicle {
  public:
    Cicle (char *);//construtor - recebe o nome do arquivo com as coordenadas dos pontos e monta mCicle e mNumberOfVertices
    double computeDistance(Vertex, Vertex); //calcula distancia euclideana entre dois vertices
    double computeCicleCost (vector <Vertex> *); //calcula o custo total do ciclo (soma das distancias)
    double NearestNeighbour(unsigned); //monta um ciclo escolhendo o vizinho mais proximo
    void BestNearestNeighbourCicle (); //teste todas as possibilidades de NearestNeighbour
    void TwoOptimizationSwap(vector <Vertex> *, unsigned, unsigned);//função auxiliar para TwoOptimization
    void TwoOptimization ();//otimização eliminando cruzamentos
  private:
    unsigned mNumberOfVertices;
    unsigned mCost;
    vector <Vertex> mVertices;
    vector <Vertex> mCicle;
};
#endif
