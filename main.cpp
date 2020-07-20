#include "Graph.h"

#include <iostream>
using namespace std;

typedef int type;
int main() {

    cout << "\n\t----------------------------------------------------------------\n";

    Graph<type>* graph = new Graph<type>(1,2,5);
    graph->addEdge(1,2,4);
    graph->addEdge(2,1,3);
    graph->addEdge(2,3,14);
    graph->addEdge(3,1,7);

    cout << "\t----------------------------------------------------------------\n";

    cout << boolalpha;
    cout << "\t\tV1 to V2: " << graph->existsEdge(1,2) << " - Cost: " << graph->getEdge(1,2)->getCost() << endl;
    cout << "\t\tV2 to V1: " << graph->existsEdge(2,1) << " - Cost: " << graph->getEdge(2,1)->getCost() << endl;
    cout << "\t\tV2 to V3: " << graph->existsEdge(2,3) << " - Cost: " << graph->getEdge(2,3)->getCost() << endl;
    cout << "\t\tV3 to V1: " << graph->existsEdge(3,1) << " - Cost: " << graph->getEdge(3,1)->getCost() <<  endl;
    cout << "\t\tV1 to V3: " << graph->existsEdge(1,3) << endl;

    cout << "\t----------------------------------------------------------------\n";

    cout << "\t\tV1 exists: " << graph->existsVertex(1) << endl;
    cout << "\t\tV2 exists: " << graph->existsVertex(2) << endl;
    cout << "\t\tV3 exists: " << graph->existsVertex(3) << endl;
    cout << "\t\tV4 exists: " << graph->existsVertex(4) << endl;

    cout << "\t----------------------------------------------------------------\n";

    cout << "\t\tV1 <- E2-E1 -> V2\n"
            "\t\t /\\            |\n"
            "\t\t  \\            |\n"
            "\t\t    \\          |\n"
            "\t\t      \\       E3\n"
            "\t\t        \\      |\n"
            "\t\t          \\    |\n"
            "\t\t            \\ \\/\n"
            "\t\t              V3\n";
    cout << "\t----------------------------------------------------------------\n";
    delete graph;
    return 0;
}
