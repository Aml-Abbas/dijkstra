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
    while (!nodeSet.isEmpty()) {
        Node *node = nodeSet.removeMin();
        std::vector<Edge> edges = node->getEdges();
        for (auto edge:edges) {
            auto length = edge.getLength();
            auto destanition_node = edge.getDestination();
            auto new_value = node->getValue() + length;
            if (new_value < destanition_node->getValue()) {
                destanition_node->setValue(new_value);
                destanition_node->setParent(node);
                nodeSet.add(destanition_node);
            }
        }
    }
}


/** skriva ut noderna. */
std::string dijkstra::get_shortest_path(Node *destination) {
    if (destination->getParent() == nullptr) {
        return "did not find a path. ";
    }

    std::vector<Node *> path;
    Node *node = destination;
    path.push_back(destination);

    while (node->getParent() != nullptr) {
        path.push_back(node->getParent());
        node = node->getParent();
    }
    std::string pathstr;
    std::reverse(path.begin(), path.end());
    for (auto &node : path) {
        pathstr += (node->getName());
        pathstr += " ";
    }
    pathstr += std::to_string(destination->getValue());
    return pathstr;
}

void dijkstra::begin_dijkstra(Node *start, int (*f)(Edge *)) {
    start->setValue(0);
    start->setParent(nullptr);
    NodeSet nodeSet{};
    nodeSet.add(start);

    while (!nodeSet.isEmpty()) {
        Node *node = nodeSet.removeMin();
        std::vector<Edge> edges = node->getEdges();
        for (auto edge : edges) {
            Node *destination_node = edge.getDestination();
            int new_value = node->getValue() + f(&edge);

            if (new_value < destination_node->getValue()) {
                destination_node->setValue(new_value);
                destination_node->setParent(node);
                nodeSet.add(destination_node);
            }
        }
    }
}

std::string dijkstra::get_the_way(Node *start, Node *destination,
                                  int (*f)(Edge *)) {
    begin_dijkstra(start, f);
    return get_shortest_path(destination);

}


/** functions to use when counting the way. */


