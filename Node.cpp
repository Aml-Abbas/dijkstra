//
// Created by Dell on 2021-01-14.
//

#include <iostream>
#include "Node.h"

Node::Node(const std::string &name) : name{name}, value{INT_MAX}, parent{nullptr} {}

std::string Node::getName() const { return name; }

void Node::addEdge(Node *destination, int length) {
    edges.push_back(Edge(destination, length));
}

const std::vector<Edge> &Node::getEdges() const {
    return edges;
}

int Node::getValue() const { return value; }

void Node::setValue(int v) { value = v; }

Node *Node::getParent() const { return parent; }

void Node::setParent(Node *n) { parent = n; }