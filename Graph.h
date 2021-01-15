//
// Created by Dell on 2021-01-14.
//

#ifndef DIJKSTRA_GRAPH_H
#define DIJKSTRA_GRAPH_H

#include <iostream>
#include <vector>
#include <memory>
#include "Node.h"


class Graph {
public:
public:
    constexpr static int max_value = INT_MAX;
    Graph();
    /** Skapar en graf med noder och bågar som läses från strömmen in. */
    Graph(std::istream& in);
    void addNode(const std::string&);
    void resetVals();
    Node* find(const std::string&);
    std::vector<std::unique_ptr<Node>>::iterator begin();
    std::vector<std::unique_ptr<Node>>::iterator end();

private:
    std::vector<std::unique_ptr<Node>> nodes;
};


#endif //DIJKSTRA_GRAPH_H
