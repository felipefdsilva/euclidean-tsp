/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 3 (Caixeiro Viajante - variação euclideana)
* Autores: Felipe Ferreira e Luis Fernando
* Implementação da classe Ciclo
*/

#import "ciclo.h"

/*Construtor da classe ciclo*/
Cicle::Cicle (unsigned numberOfVertices){
  mNumberOfVertices = numberOfVertices;
}
/*Método que calcula a distância entre dois vértices*/
double Cicle::computeDistance(Vertex v1, Vertex v2){
  return sqrt((v1.getX()-v2.getX())*(v1.getX()-v2.getX()) +
              (v1.getY()-v2.getY())*(v1.getY()-v2.getY()))
}
/*Método que calcula a distância total para percorrer o ciclo*/
double Cicle::computeCicleCost (vector <Vertex> cicle){
  double cicleCost = 0;

  for (unsigned i=0; i < mNumberOfVertices-1; i++){
    cicleCost += computeDistance(cicle[i], cicle[i+1]);
  }
}
/*Método que monta o ciclo adicionando o vizinho mais próximo por rodada*/
double Cicle::NearestNeighbour(unsigned root){
  unsigned aux, nextVertexPosition;
  unsigned minDistance = INT_MAX; //as distancias para os outros vertices são inicialmente infinitas (desconhecidas)
  double distance;
  Vextex currentVextex;

  /*Jogando o vertice raiz (menor distancia) para o começo do vetor do ciclo*/
  aux = mCicle.at(0);
  mCicle.at(0) = mCicle.at(root);
  mCicle.at(root) = aux;
  double cicleCost;

  for (unsigned i=0; i < mNumberOfVertices-1; i++){//calcular o vizinho mais próximo de cada vertice
    currentVextex = mCicle.at(i);
    for (unsigned j = i+1; j < mNumberOfVertices; j++){
      distance = computeDistance(currentVextex, mCicle.at(j));
      if (distance < minDistance){
        minDistance = distance;
        nextVertexPosition = j;
      }
    }
    aux = mCicle.at(i+1);
    mCicle.at(i+1) = mCicle.at(nextVertexPosition); //posiciona o vizinho mais próximo no vetor ciclo
    mCicle.at(nextVertexPosition) = aux;

    cicleCost += minDistance;
  }
  cicleCost += computeDistance(mCicle.back(), mCicle().front()); //fechando o ciclo, voltando do ultimo vertice para o primeiro
}
/*Escolhe o menor ciclo obtido em NearestNeighbour*/
double BestNearestNeighbourCicle (){
  vector <Vertex> cicle;
  double SmallestCost = INT_MAX;
  double currentCost;

  for (unsigned i = 0; i < mNumberOfVertices; i++){
    currentCost = NearestNeighbour(i);
    if (currentCost < SmallestCost){
      SmallestCost = currentCost;
      cicle.assign(mCicle);
    }
  }
  mCicle.assign(cicle);
  return SmallestCost;
}

/*
pair TwoOPTSwap(pair, unsigned, unsigned);
pair TwoOPT (pair);
*/
