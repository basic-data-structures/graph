#include "Graph.h"

#include <iostream>
using namespace std;

typedef int type;
int main() {

    cout << "\n\n\t========================= GRAPH ================================\n\n";

    Graph<type>* graph = new Graph<type>(1,2,5);
    graph->addEdge(1,2,4);
    graph->addEdge(2,1,3);
    graph->addEdge(2,3,14);
    graph->addEdge(3,1,7);
    graph->addEdge(1,4,2);

    cout << "\n\n";

    cout << boolalpha;
    cout << "\t\tV1 to V2: " << graph->existsEdge(1,2) << " - Cost: " << graph->getEdge(1,2)->getCost() << "\n";
    cout << "\t\tV1 to V4: " << graph->existsEdge(1,4) << " - Cost: " << graph->getEdge(1,4)->getCost() << "\n";
    cout << "\t\tV2 to V1: " << graph->existsEdge(2,1) << " - Cost: " << graph->getEdge(2,1)->getCost() << "\n";
    cout << "\t\tV2 to V3: " << graph->existsEdge(2,3) << " - Cost: " << graph->getEdge(2,3)->getCost() << "\n";
    cout << "\t\tV3 to V1: " << graph->existsEdge(3,1) << " - Cost: " << graph->getEdge(3,1)->getCost() <<  "\n";
    cout << "\t\tV1 to V3: " << graph->existsEdge(1,3) << "\n";

    cout << "\n\n";

    cout << "\t\tV0 exists: " << graph->existsVertex(0) << "\n";
    cout << "\t\tV1 exists: " << graph->existsVertex(1) << "\n";
    cout << "\t\tV2 exists: " << graph->existsVertex(2) << "\n";
    cout << "\t\tV3 exists: " << graph->existsVertex(3) << "\n";
    cout << "\t\tV4 exists: " << graph->existsVertex(4) << "\n";
    cout << "\t\tV5 exists: " << graph->existsVertex(5) << "\n";

    cout << "\n\n";

    graph->DFS(2);
    cout << "\n";
    graph->BFS(2);

    cout << "\t\t\t\t\tV1 <-- E2-E1 --> V2\n"
            "\t\t\t\t\t | /\\            |\n"
            "\t\t\t\t\t |  \\            |\n"
            "\t\t\t\t\t |    \\          |\n"
            "\t\t\t\t\t |      \\       E3\n"
            "\t\t\t\t\t |        \\      |\n"
            "\t\t\t\t\t |          \\    |\n"
            "\t\t\t\t\t\\/            \\ \\/\n"
            "\t\t\t\t\tV4              V3\n\n";

    graph->DFS(2);
    cout << "\n";
    graph->BFS(2);

    cout << "\n\t================================================================\n";

    delete graph;
    return 0;
}
