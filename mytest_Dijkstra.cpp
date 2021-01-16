/*
//
// Created by Dell on 2021-01-15.
//


#include <iostream>
#include <cassert>
#include "Node.h"
#include "dijkstra.h"

using std::cout;
using std::endl;

*/
/** functions to use when counting the way according to the city.
 * b) antal passerade orter *//*

int city_dijkstra(Edge *edge) {
    return edge->getDestination()->getValue() * 0 + 1;
}

*/

//
// Created by Dell on 2021-01-14.
//

#include <iostream>
#include <cassert>
#include "Node.h"
// #include "graph.h"
#include "dijkstra.h"
#include "NodeSet.h"

using std::cout;
using std::endl;

/** functions to use when counting the way accordig to the distance.
 * a) vägavstånd enligt uppgiften */

int distance_dijkstra(Edge *edge) {
    return edge->getLength();
}

int city_dijkstra(Edge *edge) {
    return edge->getDestination()->getValue() * 0 + 1;
}

void test_city_dijkstra()
{
    dijkstra dis{};
    Node lund{"Lund"};
    Node dalby{"Dalby"};
    Node sandby{"Sodra Sandby"};
    Node hallestad{"Torna Hallestad"};
    Node flyinge{"Flyinge"};
    Node veberod{"Veberod"};

    lund.addEdge(&dalby,12);
    lund.addEdge(&sandby,12);
    dalby.addEdge(&sandby,12);
    dalby.addEdge(&veberod,11);
    dalby.addEdge(&hallestad,5);
    sandby.addEdge(&lund,12);
    sandby.addEdge(&flyinge,4);
    hallestad.addEdge(&veberod,8);

    dis.begin_dijkstra(&lund, city_dijkstra);


    assert(lund.getValue() == 0);
    assert(dalby.getValue() == 1);
    assert(sandby.getValue() == 1);
    assert(hallestad.getValue() == 2);
    assert(veberod.getValue() == 2);
    assert(flyinge.getValue() == 2);


#ifdef INFO
    cout << "----\nAll distances from Lund:\n";

    for(auto& t : {lund, dalby, sandby, hallestad, veberod, flyinge}) {
        cout << t.getName() << " : " << t.getValue() << " ";
        cout << endl;
    }
#endif
    cout << "test_city_dijkstra passed" << endl;
}

void test_distance_dijkstra()
{
    dijkstra dis{};
    Node lund{"Lund"};
    Node dalby{"Dalby"};
    Node sandby{"Sodra Sandby"};
    Node hallestad{"Torna Hallestad"};
    Node flyinge{"Flyinge"};
    Node veberod{"Veberod"};

    lund.addEdge(&dalby,12);
    lund.addEdge(&sandby,12);
    dalby.addEdge(&sandby,12);
    dalby.addEdge(&veberod,11);
    dalby.addEdge(&hallestad,5);
    sandby.addEdge(&lund,12);
    sandby.addEdge(&flyinge,4);
    hallestad.addEdge(&veberod,8);

    dis.begin_dijkstra(&lund, distance_dijkstra);


    assert(lund.getValue() == 0);
    assert(dalby.getValue() == 12);
    assert(sandby.getValue() == 12);
    assert(hallestad.getValue() == 17);
    assert(veberod.getValue() == 23);
    assert(flyinge.getValue() == 16);

#ifdef INFO
    cout << "----\nAll distances from Lund:\n";

    for(auto& t : {lund, dalby, sandby, hallestad, veberod, flyinge}) {
        cout << t.getName() << " : " << t.getValue() << " ";
        cout << endl;
    }
#endif
    cout << "test_distance_dijkstra passed" << endl;
}

void test_get_the_way() {
    dijkstra dis{};
    Node lund{"Lund"};
    Node dalby{"Dalby"};
    Node sandby{"Sodra Sandby"};
    Node hallestad{"Torna Hallestad"};
    Node flyinge{"Flyinge"};
    Node veberod{"Veberod"};

    lund.addEdge(&dalby,12);
    lund.addEdge(&sandby,12);
    dalby.addEdge(&sandby,12);
    dalby.addEdge(&veberod,11);
    dalby.addEdge(&hallestad,5);
    sandby.addEdge(&lund,12);
    sandby.addEdge(&flyinge,4);
    hallestad.addEdge(&veberod,8);

    std::string way = dis.get_the_way(&lund, &hallestad, distance_dijkstra);
//    cout << "way: " << way << "\n";
    assert(way == "Lund Dalby Torna Hallestad 17");

#ifdef INFO
    cout << "----\nAll distances from Lund:\n";

    for(auto& t : {lund, dalby, sandby, hallestad, veberod, flyinge}) {
        cout << t.getName() << " : " << t.getValue() << " ";
        cout << endl;
    }
#endif
    cout << "test_get_the_way passed" << endl;
}

int main()
{
    test_city_dijkstra();
    test_distance_dijkstra();
    test_get_the_way();
    return 0;
}
