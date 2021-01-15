//
// Created by Dell on 2021-01-14.
//

#ifndef DIJKSTRA_DIJKSTRA_H
#define DIJKSTRA_DIJKSTRA_H

#include "Node.h"
#include "NodeSet.h"
#include "Edge.h"

class dijkstra {
public:
    dijkstra();
    /** Dijkstras algoritm. Varje nod som kan nås från start ges ett värde,
    där värdet anger det kortaste avståndet från noden start.
    Alla noder förutsätts, när funktionen anropas, ha ett värde som är
    större än alla faktiska avstånd i grafen.
    */
    void begin_dijkstra(Node* start);
    /** Return the name of the nodes from the destination to the start
   */
    std::string get_shortest_way(Node* destination);
    void begin_dijkstra(Node*, int (*f) (Edge*) );
    std::string get_the_way(std::string start , std::string destination, int(*f)(Edge*));

    };


#endif //DIJKSTRA_DIJKSTRA_H
