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
  ifstream data (dataFile, ifstream::in); //abre arquivo com os pontos para leitura
  unsigned x, y, index = 1;
  Vertex vertex;

  data >> mNumberOfVertices; //salva o número de vértices do grafo

  while (data.good()){ //enquanto houver vértices
    data >> x >> y; //obtém as coordenada x e y do arquivo
    vertex.setIndex(index); //configura o indice de acordo com a ordem em que o vértice aparece no arquivo
    vertex.setX(x); //configura a coordenada x
    vertex.setY(y); //configura a coordenada y
    mCicle.push_back(vertex); //adiciona vertice lido a mCicle
    mVertices.push_back(vertex); //adiciona o mesmo vértice a mVertices (vetor de referência)
    index++; //proximo vertice lido terá o indice do anterior mais um
  }
  mCicle.pop_back();//eliminando releitura da ultima linha
  mVertices.pop_back();//eliminando releitura da ultima linha
  data.close(); //fecha o arquivo
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
  double cicleCost=0; //inicializando a variavel que guarda do custo do ciclo (é sempre incrementada)
  double distance;
  Vertex aux;

  mCicle.assign(mVertices.begin(), mVertices.end()); //resetando mCicle ao arranjo original de vertices (por indice)

  aux = mCicle.at(0);
  mCicle.at(0) = mCicle.at(root);//Jogando o vertice raiz (distancia 0) para o começo do vetor do ciclo
  mCicle.at(root) = aux;//vertice anteriormente no inicio vai para a posição original do vertice raiz

  for (unsigned i=0; i < mNumberOfVertices-1; i++){//calcula o vizinho mais próximo de cada vertice, menos do ultimo
    for (unsigned j = i+1; j < mNumberOfVertices; j++){//vertices não explorados estão dispostos após os vertices explorados em mCicle
      distance = computeDistance(mCicle.at(i), mCicle.at(j));//calcula a distancia entre o vertice atual e o vizinho não explorado
      if (distance < minDistance){//se este vizinho for o mais próximo conhecido...
        minDistance = distance;//salvar a distancia para o mesmo...
        nextVertexPosition = j;//e sua posição, para usá-las fora do laço
      }
    }
    aux = mCicle.at(i+1);//reornada o ciclo com o proximo vertice a ser explorado (o mais próximo)
    mCicle.at(i+1) = mCicle.at(nextVertexPosition); //posiciona o vizinho mais próximo no vetor ciclo
    mCicle.at(nextVertexPosition) = aux;
    cicleCost += minDistance;//adiciona a distancia ao vertice seleciona no custo do ciclo
    minDistance = INT_MAX;//vertice a ser explorado não conhece as distancias para os vertices não explorados
  }
  cicleCost += computeDistance(mCicle.back(), mCicle.front()); //fechando o ciclo, voltando do ultimo vertice para o primeiro
  return cicleCost; //retorna o custo do ciclo
}
/*Escolhe o menor ciclo obtido em NearestNeighbour*/
void Cicle::LeastCostNearestNeighbour (){
  vector <Vertex> cicle;
  double SmallestCost = INT_MAX;
  double currentCost;

  for (unsigned i = 0; i < mNumberOfVertices; i++){ //laço para usar cada vertice do grafo como raiz em NN
    currentCost = NearestNeighbour(i); //rodando algoritmo NN e salvando o custo do ciclo obtido
    if (currentCost < SmallestCost){ //comparando com o menor custo. Se for menor, salva.
      SmallestCost = currentCost;
      cicle.assign(mCicle.begin(), mCicle.end());//salvando ciclo de menor custo, pois mCicle é resetado a cada chamada de NN
    }
  }
  mCicle.assign(cicle.begin(), cicle.end());//salvando o menor ciclo no vetor atributo da classe ciclo
  mCost = SmallestCost; //salvando o menor custo no atributo da classe ciclo
  cout << "Final SmallestCost= " << computeCicleCost(&mCicle) << endl; //imprime menor custo
}
/*método que reverte um segmento do ciclo (usado por TwoOptimization)*/
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
/*Método que reduz o custo do ciclo buscando eliminar cruzamentos*/
void Cicle::TwoOptimization (){
  vector <Vertex> cicle;
  unsigned newCost;
  unsigned bestCost = computeCicleCost(&mCicle);//calcula o custo do ciclo atual
  unsigned costDiff = bestCost;

  cout << "Original cost: " << bestCost << endl;//imprime custo original

  while (costDiff > 0){
    for (unsigned i = 1; i < mNumberOfVertices-2; i++){
      for (unsigned j = i+1; j < mNumberOfVertices-1; j++){
        cicle.assign (mCicle.begin(), mCicle.end());//copia do ciclo original (gerado por NN)
        TwoOptimizationSwap(&cicle, i, j);//invertendo um segmento de forma ingênua (sem saber se há cruzamento)
        newCost = computeCicleCost(&cicle); //calculando novo custo
        if (newCost < bestCost){ //se novo custo é menor que o original
          bestCost = newCost; //novo custo se torna o custo original
          mCicle.assign(cicle.begin(), cicle.end()); //ciclo gerado pelo 2-opt se torna o ciclo hamiltoniano desejado
        }
      }
    }
    if (bestCost < costDiff){//como costDiff é unsigned, deve tomar cuidado de gerar numero negativo
      costDiff -= bestCost; //
    } else {
      costDiff = 0; //caso a subtração fosse feita, costDiff seria promovido a INT_MAX e o laço não teria fim
    }
  }
  cout << "Cost after 2-opt: " << bestCost << endl;//imprime custo após otimização 2-opt
  cout << "Cicle after 2-opt: ";//imprime custo após otimização 2-opt

  for (unsigned i= 0; i < mNumberOfVertices; i++){//imprime cada vertice (apenas o indice)
    cout << mCicle.at(i).getIndex() << " ";
  }
  cout << endl;
}
