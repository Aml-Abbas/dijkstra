//
// Created by Dell on 2021-01-14.
//

#include "Edge.h"

Edge::Edge(Node *destination, int length) :
node{destination}, length{length} {}

Node *Edge::getDestination() const {
    return node;
}

int Edge::getLength() const {
    return length;
}