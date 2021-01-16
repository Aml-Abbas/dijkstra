//
// Created by Dell on 2021-01-14.
//

#include "NodeSet.h"
#include <algorithm>

bool compareInterval(Node *i1, Node *i2) {
    return (i1->getValue() < i2->getValue());
}

NodeSet::NodeSet() {}

void NodeSet::add(Node *node) {
    auto itr = std::find(nodes.begin(), nodes.end(), node);

    if (itr != nodes.end()) {
        Node *node1 = *itr;
        if (node1->getValue() > node->getValue()) {
            nodes.erase(itr);
            nodes.push_back(node);
        }
    } else {
        nodes.push_back(node);
    }
}

bool NodeSet::isEmpty() {
    return nodes.empty();
}

Node *NodeSet::removeMin() {
    if (isEmpty()) {
        return nullptr;
    }

    auto itr = std::min_element(nodes.begin(), nodes.end(),
                                [](Node *n1, Node *n2) { return n1->getValue() < n2->getValue(); });

    Node *node = *itr;
    nodes.erase(itr);

    return node;
}

