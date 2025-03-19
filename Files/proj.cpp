//
// Created by tiago on 19-03-2025.
//
#include "builder.h"

int main(int argc, char *argv[]){
    Graph<string> g = buildGraph("Locations.csv","Distances.csv");
    return 0;
}