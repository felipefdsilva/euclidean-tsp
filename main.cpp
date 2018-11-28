/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 3 (Caixeiro Viajante - variação euclideana)
* Autores: Felipe Ferreira e Luis Fernando
* Implementação do programa de testes da biblioteca de solução do tsp
*/

#include <chrono> //para marcação do tempo de execução do algoritmo
#include <iostream> //para imprimir mensagens na tela
#include "ciclo.h" //biblioteca de resolução do tsp

using namespace std::chrono;

int main (int argc, char *argv[]){

  float duration;
  high_resolution_clock::time_point t1, t2;

  if (argc != 2) { //se o número de argumentos passados pela CLI for diferente de 2, uma mensagem de erro é exibida
    cout << "Usage: ./" << argv[0] << " <filename>" << endl; //indica como usar o programa
    exit(1); //sai do programa
  }
  Cicle cicle (argv[1]); //instanciação de um objeto da classe Cicle

  t1 = high_resolution_clock::now(); //marca o tempo de inicio da execução do algoritmo
  cicle.LeastCostNearestNeighbour(); //encontra o menor ciclo gerado pelo algoritmo NN
  cicle.TwoOptimization(); //realiza a otimização 2-opt, removendo cruzamentos
  t2 = high_resolution_clock::now(); //marca o tempo de fim da execução do algoritmo
  duration = duration_cast<microseconds>(t2-t1).count(); //calcula o tempo gasto para resolver o problema
  cout << "Tempo de Execucao: " << duration/1000000 << " s" << endl; //imprime o tempo na tela
  return 0; //retorna sucesso
}
