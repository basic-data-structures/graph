#include "Graph.h"

#include <iostream>
using namespace std;

typedef int type;
int main() {

    Graph<type>* graph = new Graph<type>(1,2);
    graph->addEdge(1,2);
    graph->addEdge(2,1);
    graph->addEdge(2,3);
    graph->addEdge(3,1);

    cout << boolalpha;
    cout << "\n\tV1 to V2: " << graph->existsEdge(1,2) << endl;
    cout << "\tV2 to V1: " << graph->existsEdge(2,1) << endl;
    cout << "\tV2 to V3: " << graph->existsEdge(2,3) << endl;
    cout << "\tV1 to V3: " << graph->existsEdge(1,3) << endl;
    cout << "\tV3 to V2: " << graph->existsEdge(3,2) << endl;

    cout << "\n\tV1 exists: " << graph->existsVertex(1) << endl;
    cout << "\tV2 exists: " << graph->existsVertex(2) << endl;
    cout << "\tV3 exists: " << graph->existsVertex(3) << endl;
    cout << "\tV4 exists: " << graph->existsVertex(4) << endl;

    cout << "\n\tV1 <- E2-E1 -> V2\n"
                "\t /\\            |\n"
                "\t  \\            |\n"
                "\t    \\          |\n"
                "\t      \\       E3\n"
                "\t        \\      |\n"
                "\t          \\    |\n"
                "\t            \\ \\/\n"
                "\t              V3\n";

    delete graph;
    return 0;
}
