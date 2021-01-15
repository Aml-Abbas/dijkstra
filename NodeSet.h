//
// Created by Dell on 2021-01-14.
//

#ifndef DIJKSTRA_NODESET_H
#define DIJKSTRA_NODESET_H

#include "Node.h"

class NodeSet {
public:
    /** Skapar en tom mängd av noder. */
    NodeSet();
    /** Lägger till noden node till mängden,
    om mängden inte redan innehåller en nod med samma namn. */
    void add(Node* node);
    /** Returnerar true om mängden noder är tom. */
    bool isEmpty() ;
    /** Väljer ut den nod som har lägst värde och returnerar den.
    Den returnerade noden tas bort ur mängden.
    Om mängden är tom returneras null. */
    Node* removeMin();
private:
    std::vector<Node*> nodes;
};


#endif //DIJKSTRA_NODESET_H
