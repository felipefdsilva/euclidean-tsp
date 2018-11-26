/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 3 (Caixeiro Viajante - variação euclideana)
* Autores: Felipe Ferreira e Luis Fernando
* Implementação da função principal
*/

#include <iostream>
#include "vertice.h"
#include "ciclo.h"

using namespace std;

int main (int argc, char *argv[]){

  if (argc != 2) {
    cout << "Usage: ./" << argv[0] << " <filename>" << endl;
    exit(1);
  }

  Cicle cicle (argv[1]);
  cicle.BestNearestNeighbourCicle();
  cicle.TwoOptimization();
  return 0;
}
