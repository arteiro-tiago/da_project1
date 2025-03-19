//
// Created by tiago on 19-03-2025.
//

#include "builder.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
using namespace std;

Graph<string> buildGraph(string locationsFile, string distancesFile) {
    Graph<string> graph;
    unordered_map<string, int> locationToId;  // Maps location codes to their ID

    ifstream locFile(locationsFile);


    string line;
    getline(locFile, line);
    while (getline(locFile, line)) {
        stringstream ss(line);
        string name, idStr, code, parkingStr;
        if (getline(ss, name, ',') && getline(ss, idStr, ',') && getline(ss, code, ',') && getline(ss, parkingStr, ',')) {
            int id = stoi(idStr);
            int parking = stoi(parkingStr);
            graph.addVertex(code);
            Vertex<string>* v = graph.findVertex(code);
            v->setId(id);
            v->setParking(parking);
            v->setName(name);
            locationToId[code] = id;
        }
    }
    locFile.close();




    ifstream distFile(distancesFile);


    getline(distFile, line);
    while (getline(distFile, line)) {
        stringstream ss(line);
        string location1, location2, drivingStr, walkingStr;
        int driving, walking;
        if (getline(ss, location1, ',') && getline(ss, location2, ',') && getline(ss, drivingStr, ',') && getline(ss, walkingStr, ',')) {
            if (drivingStr == "X")
                driving = 0;
            else
                driving = stoi(drivingStr);

            if (walkingStr == "X")
                walking = 0;
            else
                walking = stoi(walkingStr);

            graph.addBidirectionalEdge(location1, location2, {driving, walking});
        }
    }
    distFile.close();

    return graph;
}