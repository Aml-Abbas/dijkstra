//
// Created by Dell on 2021-01-15.
//


#include <iostream>
#include <cassert>
#include "Node.h"
#include "dijkstra.h"

using std::cout;
using std::endl;


void test()
{
    dijkstra dis{};
    Node lund{"Lund"};
    Node malmo{"malmo"};
    Node lanskrona{"lanskrona"};
    Node helsingborg{"helsingborg"};
    Node goteborg{"goteborg"};
    Node stockholm{"stockholm"};

    Node dalby{"Dalby"};
    Node sandby{"Sodra Sandby"};
    Node hallestad{"Torna Hallestad"};
    Node flyinge{"Flyinge"};
    Node veberod{"Veberod"};

    lund.addEdge(&dalby,1);
    lund.addEdge(&sandby,19);
    lund.addEdge(&hallestad,3);
    lund.addEdge(&flyinge,5);
    lund.addEdge(&stockholm,2);
    lund.addEdge(&veberod,10);

    lund.addEdge(&malmo,4);
    lund.addEdge(&helsingborg,9);

    malmo.addEdge(&helsingborg,1);
    helsingborg.addEdge(&lanskrona,9);

    malmo.addEdge(&goteborg,4);
    goteborg.addEdge(&stockholm,10);


    dalby.addEdge(&sandby,5);
    dalby.addEdge(&veberod,7);
    dalby.addEdge(&hallestad,9);
    sandby.addEdge(&lund,7);
    sandby.addEdge(&flyinge,4);
    hallestad.addEdge(&veberod,8);
    dis.begin_dijkstra(&lund);

    std::string to_return{};
    Node noNode{"lund"};
    Edge edge{&noNode, 0};
    to_return= dis.get_the_way("lund","stockholm", distance_dijkstra(&edge));

    assert(to_return=="");


#ifdef INFO
    cout << "----\nAll distances from Lund:\n";

    for(auto& t : {lund, dalby, sandby, hallestad, veberod, flyinge}) {
        cout << t.getName() << " : " << t.getValue() << " ";
        cout << endl;
    }
#endif
    cout << "test_dijkstra passed" << endl;
}


int main()
{
    test();
    return 0;
}
