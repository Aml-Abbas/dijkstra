//
// Created by Dell on 2021-01-14.
//

#include <iostream>
#include <algorithm>
#include "Graph.h"

Graph::Graph():nodes{} {}

Graph::Graph(std::istream &in) {
    std::string line;
    while (getline(in, line)){
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        std::string name_of_node= line.substr(0, line.find(":"));
        line.erase(0, line.find(":")+2);
        std::string node_distance= line.substr(0, line.find(" "));
        line.erase(0, node_distance.length()+1);
        std::string destination = line.substr(0, line.length());
        int value = std::stoi(node_distance);
        addNode(name_of_node);
        addNode(destination);
        find(name_of_node)->addEdge(find(destination), value);
    }
}

void Graph::addNode(const std::string& name) {
    if (find(name)== nullptr){
        nodes.push_back(std::unique_ptr<Node>{new Node(name)});
    }
}

void Graph::resetVals() {
    for(auto& n: nodes){
        n->setParent(nullptr);
        n->setValue(max_value);
    }

}

Node* Graph::find(const std::string & name) {
    for(auto& n: nodes){
        if (n->getName()== name){
            return n.get();
        }
    }
    return nullptr;
}

std::vector<std::unique_ptr<Node>>::iterator Graph::begin() {
    return nodes.begin();
}

std::vector<std::unique_ptr<Node>>::iterator Graph::end() {
    return nodes.end();
}