//
// Created by Dell on 2021-01-14.
//

#include <algorithm>
#include <sstream>
#include "dijkstra.h"

dijkstra::dijkstra() {}

void dijkstra::begin_dijkstra(Node *start) {
    start->setValue(0);
    start->setParent(nullptr);

    NodeSet nodeSet{};
    nodeSet.add(start);
    while (!nodeSet.isEmpty()){
        Node* node= nodeSet.removeMin();
        std::vector<Edge> edges= node->getEdges();
        for(auto edge:edges){
            auto length= edge.getLength();
            auto destanition_node= edge.getDestination();
            auto new_value= node->getValue()+length;
            if (new_value< destanition_node->getValue()){
                destanition_node->setValue(new_value);
                destanition_node->setParent(node);
                nodeSet.add(destanition_node);
            }
        }
    }
}
/** skriva ut noderna. */
std::string dijkstra::get_shortest_way(Node *destination) {

    std::vector<Node* > way;
    way.push_back(destination);
    Node* node= destination;
    if (destination->getParent()== nullptr){
        return "didnt find a way. ";
    }
    while (node->getParent()!= nullptr){
        way.push_back(node->getParent());
        node= node->getParent();

    }
    std::stringstream string_to_return {};
    for (size_t i= way.size()-1; i>=0;i++){
        string_to_return<<way[i]->getName()<<" ";
    }
    string_to_return<<destination->getValue();
    return string_to_return.str();
}

void dijkstra::begin_dijkstra(Node * start, int (*f)(Edge *)) {
    start->setValue(0);
    start->setParent(nullptr);

    NodeSet nodeSet{};
    nodeSet.add(start);
    while (!nodeSet.isEmpty()){
        Node* node= nodeSet.removeMin();
        std::vector<Edge> edges= node->getEdges();
        for(auto edge:edges){
            auto destanition_node= edge.getDestination();
            auto new_value= node->getValue()+f(&edge);

            if (new_value< destanition_node->getValue()){
                destanition_node->setValue(new_value);
                destanition_node->setParent(node);
                nodeSet.add(destanition_node);
            }
        }
    }
}

std::string dijkstra::get_the_way(std::string start, std::string destination, int (*f)(Edge *)) {
    Node new_start{start};
    Node new_destination{destination};
        begin_dijkstra(&new_start, f);
        return get_shortest_way(&new_destination);

}


/** functions to use when counting the way. */

/** functions to use when counting the way accordig to the city.
 * b) antal passerade orter */
int city_dijkstra(Edge* edge){
    return edge->getDestination()->getValue() * 0+1;
}
/** functions to use when counting the way accordig to the distance.
 * a) vägavstånd enligt uppgiften */
int distance_dijkstra(Edge* edge){
    return edge->getLength();
}

