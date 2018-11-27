/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 3 (Caixeiro Viajante - variação euclideana)
* Autores: Felipe Ferreira e Luis Fernando
* Implementação da classe Ciclo
*/

#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include "ciclo.h"

using namespace std;

/*Construtor da classe ciclo*/
Cicle::Cicle (char *dataFile){
  ifstream data (dataFile, ifstream::in); //abre arquivo para leitura
  unsigned x, y, index = 1;
  Vertex vertex;

  data >> mNumberOfVertices;

  while (data.good()){
    data >> x >> y;
    vertex.setIndex(index);
    vertex.setX(x);
    vertex.setY(y);
    mCicle.push_back(vertex);
    mVertices.push_back(vertex);
    index++;
  }
  mCicle.pop_back();//eliminando releitura da ultima linha
  mVertices.pop_back();//eliminando releitura da ultima linha
  data.close();
}
/*Método que calcula a distância entre dois vértices*/
double Cicle::computeDistance(Vertex v1, Vertex v2){
  return sqrt((v1.getX()-v2.getX()) * (v1.getX()-v2.getX()) +
              (v1.getY()-v2.getY()) * (v1.getY()-v2.getY()));
}
/*Método que calcula a distância total para percorrer o ciclo*/
double Cicle::computeCicleCost (vector <Vertex> *cicle){
  double cicleCost = 0;

  for (unsigned i=0; i < mNumberOfVertices-1; i++){
    cicleCost += computeDistance(cicle->at(i), cicle->at(i+1));
  }
  cicleCost += computeDistance(cicle->front(), cicle->back());
  return cicleCost;
}
/*Método que monta o ciclo adicionando o vizinho mais próximo por rodada*/
double Cicle::NearestNeighbour(unsigned root){
  unsigned nextVertexPosition;
  unsigned minDistance = INT_MAX; //as distancias para os outros vertices são inicialmente infinitas (desconhecidas)
  double distance;
  Vertex aux;

  mCicle.assign(mVertices.begin(), mVertices.end());
  /*Jogando o vertice raiz (menor distancia) para o começo do vetor do ciclo*/
  aux = mCicle.at(0);

  mCicle.at(0) = mCicle.at(root);
  mCicle.at(root) = aux;
  double cicleCost=0;

  for (unsigned i=0; i < mNumberOfVertices-1; i++){//calcular o vizinho mais próximo de cada vertice, menos o ultimo
    for (unsigned j = i+1; j < mNumberOfVertices; j++){
      distance = computeDistance(mCicle.at(i), mCicle.at(j));
      if (distance < minDistance){
        minDistance = distance;
        nextVertexPosition = j;
      }
    }
    aux = mCicle.at(i+1);
    mCicle.at(i+1) = mCicle.at(nextVertexPosition); //posiciona o vizinho mais próximo no vetor ciclo
    mCicle.at(nextVertexPosition) = aux;
    cicleCost += minDistance;
    //cout << "cicleCost = " << cicleCost << endl;
    minDistance = INT_MAX;
  }
  cicleCost += computeDistance(mCicle.back(), mCicle.front()); //fechando o ciclo, voltando do ultimo vertice para o primeiro
  //cout << "Custo = " << cicleCost << endl;
  return cicleCost;
}
/*Escolhe o menor ciclo obtido em NearestNeighbour*/
void Cicle::BestNearestNeighbourCicle (){
  vector <Vertex> cicle;
  double SmallestCost = INT_MAX;
  double currentCost;

  for (unsigned i = 0; i < mNumberOfVertices; i++){
    currentCost = NearestNeighbour(i);
    if (currentCost < SmallestCost){
      SmallestCost = currentCost;
      cicle.assign(mCicle.begin(), mCicle.end());
    }
  }
  mCicle.assign(cicle.begin(), cicle.end());
  mCost = SmallestCost;
  cout << "Final SmallestCost= " << computeCicleCost(&mCicle) << endl;
}
void Cicle::TwoOptimizationSwap(vector <Vertex> *cicle,unsigned begin, unsigned end){
  Vertex aux;

  while (begin < end){
    aux = cicle->at(end);
    cicle->at(end) = cicle->at(begin);
    cicle->at(begin) = aux;
    begin++;
    end--;
  }
}
void Cicle::TwoOptimization (){
  vector <Vertex> cicle;
  unsigned newCost;
  unsigned bestCost = computeCicleCost(&mCicle);
  unsigned costDiff = bestCost;

  cout << "Original cost (BNN):  " << bestCost << endl;
  unsigned i=0;
  while (costDiff > 0){
    i++;
    for (unsigned i = 1; i < mNumberOfVertices-2; i++){
      for (unsigned j = i+1; j < mNumberOfVertices-1; j++){
        cicle.assign (mCicle.begin(), mCicle.end());
        TwoOptimizationSwap(&cicle, i, j);
        newCost = computeCicleCost(&cicle);
        if (newCost < bestCost){
          bestCost = newCost;
          mCicle.assign(cicle.begin(), cicle.end());
        }
      }
    }
    if (bestCost < costDiff){
      costDiff -= bestCost;
    } else {
      costDiff = 0;
    }
  }
  cout << "Cost after 2-opt: " << bestCost << endl;
  cout << "Cicle after 2-opt: ";

  for (unsigned i= 0; i < mNumberOfVertices; i++){
    cout << mCicle.at(i).getIndex() << " ";
  }
  cout << endl;
}
