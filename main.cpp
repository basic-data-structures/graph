#include <iostream>
#include "headers/Graph.h"

using namespace std;

const string V0 = "V0", V1 = "V1", V2 = "V2", V3 = "V3", V4 = "V4", V5 = "V5", V6 = "V6", V7 = "V7";

int main() {

    cout << "\n\n\t========================= GRAPH ================================\n\n";
    int INFINITY = 99;
    string STR_NULL = "-";
    Graph<string, int> graph( V1, V2, 5, STR_NULL, INFINITY);

    cout << "\n";
    graph.addEdge(V1,V2,4);
    graph.addEdge(V3,V1,7);
    graph.addEdge(V2,V1,3);
    graph.addEdge(V1,V4,1);
    graph.addEdge(V2,V3,14);
    graph.addEdge(V4,V5,7);
    graph.addEdge(V6,V3,2);
    graph.addEdge(V3,V5,11);

    cout << boolalpha;
    cout << "\n\n\t\tV1 to V2: " << graph.existsEdge(V1,V2) << " - Cost: " << graph.getCost(V1,V2) << "\n";
    cout << "\t\tV1 to V4: " << graph.existsEdge(V1,V4) << " - Cost: " << graph.getCost(V1,V4) << "\n";
    cout << "\t\tV2 to V1: " << graph.existsEdge(V2,V1) << " - Cost: " << graph.getCost(V2,V1) << "\n";
    cout << "\t\tV2 to V3: " << graph.existsEdge(V2,V3) << " - Cost: " << graph.getCost(V2,V3) << "\n";
    cout << "\t\tV3 to V5: " << graph.existsEdge(V3,V5) << " - Cost: " << graph.getCost(V3,V5) << "\n";
    cout << "\t\tV1 to V3: " << graph.existsEdge(V1,V3) << " - Cost: " << graph.getCost(V1,V3) << "\n\n";

    cout << "\t\tV0 = 0 exists: " << graph.existsVertex(V0) << "\n";
    cout << "\t\tV1 = 1 exists: " << graph.existsVertex(V1) << "\n";
    cout << "\t\tV2 = 2 exists: " << graph.existsVertex(V2) << "\n";
    cout << "\t\tV3 = 3 exists: " << graph.existsVertex(V3) << "\n";
    cout << "\t\tV4 = 4 exists: " << graph.existsVertex(V4) << "\n";
    cout << "\t\tV5 = 5 exists: " << graph.existsVertex(V5) << "\n";
    cout << "\t\tV6 = 6 exists: " << graph.existsVertex(V6) << "\n";
    cout << "\t\tV7 = 7 exists: " << graph.existsVertex(V7) << "\n\n";

    cout << "\n\t\t\t\t\tV1 <-----------> V2\n"
            "\t\t\t\t\t | /\\            |\n"
            "\t\t\t\t\t |  \\            |\n"
            "\t\t\t\t\t |    \\          |\n"
            "\t\t\t\t\t |      \\        |\n"
            "\t\t\t\t\t |        \\      |\n"
            "\t\t\t\t\t |          \\    |\n"
            "\t\t\t\t\t\\/            \\ \\/\n"
            "\t\t\t\t\tV4              V3\n"
            "\t\t\t\t\t |             / /\\\n"
            "\t\t\t\t\t |           /   |\n"
            "\t\t\t\t\t |         /     |\n"
            "\t\t\t\t\t |       /       |\n"
            "\t\t\t\t\t |     /         |\n"
            "\t\t\t\t\t |   /           |\n"
            "\t\t\t\t\t\\/ \\/            |\n"
            "\t\t\t\t\tV5              V6\n";

    graph.showShortestPath(V1,V2);
    graph.showShortestPath(V1,V5);
    graph.showShortestPath(V6,V4);
    graph.showShortestPath(V1,V6);

    graph.showDFS(V1);
    graph.showDFS(V2);
    graph.showDFS(V3);
    graph.showDFS(V4);
    graph.showDFS(V5);
    graph.showDFS(V6);

    graph.showBFS(V1);
    graph.showBFS(V2);
    graph.showBFS(V3);
    graph.showBFS(V4);
    graph.showBFS(V5);
    graph.showBFS(V6);

    cout << "\n\t================================================================\n";

    return 0;
}
