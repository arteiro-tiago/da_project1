//
// Created by tiago_catelas on 17-03-2025.
//

#include <iostream>
#include "menu.h"
#include "builder.h"

using namespace std;

Graph<string> g;
void LoadMap() {
     g = buildGraph("../CSV/Locations.csv","../CSV/Distances.csv");

     cout << "Mapa carregado com sucesso!" << endl;
}


void ShowMenu() {
     cout << "\n======= Route Planning Tool =======\n";
     cout << "0. Mostrar Grafo\n";
     cout << "1. Encontrar a rota mais rápida\n";
     cout << "2. Encontrar uma rota alternativa independentes\n";
     cout << "3. Planeamento de rota com restriçoes\n";
     cout << "4. Planeamento de rota sustentável (carrp + caminhada)\n";
     cout << "5. Sair\n";
     cout << "Escolha uma opção\n";
}

void HandleUserInput(int option) {
     switch (option) {
          case 0:
               for (const Vertex<string> *v : g.getVertexSet()) {
                    cout << v->getName() << endl;
               }
          case 1:
               cout << "Procurar a rota mais rápida...\n";
          break;
          case 2:
               cout << "A procurar uma rota alternativa independente...\n";
          break;
          case 3:
               cout << "Aplicando restrições à rota...\n";
          break;
          case 4:
               cout << "Planeando uma rota sustentável...\n";
          break;
          case 5:
               cout << "Saindo...\n";
               exit(0);
          default:
               cout << "Opção inválida! Tente novamente.\n";
     }
}

void runMenu() {
     LoadMap();
     int option;
     while (true) {
          ShowMenu();
          cin >> option;
          HandleUserInput(option);
     }
}

