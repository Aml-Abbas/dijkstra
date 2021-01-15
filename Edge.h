//
// Created by Dell on 2021-01-14.
//

#ifndef DIJKSTRA_EDGE_H
#define DIJKSTRA_EDGE_H

#include <iostream>

class Node;

class Edge {
public:
    /** Skapa en ny båge till noden destination, med längden length. */
    Edge(Node* destination, int length);
    /** Hämtar bågens destination. */
    Node* getDestination() const;
    /** Hämtar bågens längd. */
    int getLength() const;
private:
    Node* node;
    int length;
};


#endif //DIJKSTRA_EDGE_H
