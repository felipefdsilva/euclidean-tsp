/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 3 (Caixeiro Viajante - variação euclideana)
* Autores: Felipe Ferreira e Luis Fernando
* Implementação da função principal
*/

#include <chrono>
#include <iostream>
#include "vertice.h"
#include "ciclo.h"

using namespace std::chrono;

int main (int argc, char *argv[]){

  float duration;
  high_resolution_clock::time_point t1, t2;

  if (argc != 2) {
    cout << "Usage: ./" << argv[0] << " <filename>" << endl;
    exit(1);
  }

  Cicle cicle (argv[1]);
  //cicle.NearestNeighbour(0);
  //cicle.NearestNeighbour(1);
  //cicle.NearestNeighbour(2);
  //cicle.NearestNeighbour(3);
  //cicle.NearestNeighbour(4);
  t1 = high_resolution_clock::now();
  cicle.BestNearestNeighbourCicle();
  cicle.TwoOptimization();
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>(t2-t1).count();
  cout << "Tempo de Execucao: " << duration/1000000 << " s" << endl;
  return 0;
}
