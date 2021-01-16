//
// Created by Dell on 2021-01-14.
//

#ifndef DIJKSTRA_NODE_H
#define DIJKSTRA_NODE_H

#include <iostream>
#include <vector>
#include <limits.h>
#include "Edge.h"

class Node {
public:
    constexpr static int max_value = INT_MAX;

    /** Skapar en nod med givet namn, utan bågar och med maximalt värde. */
    Node(const std::string &name);

    /** Hämtar nodens namn. */
    std::string getName() const;

    /** Sätter nodens värde till v. */
    void setValue(int v);

    /** Hämtar nodens värde. */
    int getValue() const;

    /** Lägger till en ny båge från denna nod till en given destination.
    Bågen ska ha längden length. */
    void addEdge(Node *destination, int length);

    /** Hämtar de bågar som utgår från denna nod. */
    const std::vector<Edge> &getEdges() const;

    /** Sätter parents värde till v. */
    void setParent(Node *);

    /** Hämtar parents värde. */
    Node *getParent() const;

private:
    std::string name;
    int value;
    Node *parent;
    std::vector<Edge> edges;
};


#endif //DIJKSTRA_NODE_H
