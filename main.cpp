#include "Graph.h"

#include <iostream>
using namespace std;

int main() {

    cout << "\n\n\t========================= GRAPH ================================\n\n";
    int INFINITY = 999999;
    Graph<int, int> graph( 1, 2, 5, INFINITY);

    cout << "\n\n";
    graph.showMatrix();
    graph.addEdge(1,2,4);
    graph.addEdge(3,1,7);
    graph.addEdge(2,1,3);
    graph.addEdge(1,4,1);
    graph.addEdge(2,3,14);
    graph.addEdge(4,5,7);
    graph.addEdge(6,3,2);
    graph.addEdge(3,5,11);
    graph.showMatrix();

    cout << boolalpha;
    cout << "\n\n\t\tV1 to V2: " << graph.existsEdge(1,2) << " - Cost: " << graph.getCost(1,2) << "\n";
    cout << "\t\tV1 to V4: " << graph.existsEdge(1,4) << " - Cost: " << graph.getCost(1,4) << "\n";
    cout << "\t\tV2 to V1: " << graph.existsEdge(2,1) << " - Cost: " << graph.getCost(2,1) << "\n";
    cout << "\t\tV2 to V3: " << graph.existsEdge(2,3) << " - Cost: " << graph.getCost(2,3) << "\n";
    cout << "\t\tV3 to V5: " << graph.existsEdge(3,5) << " - Cost: " << graph.getCost(3,5) << "\n";
    cout << "\t\tV1 to V3: " << graph.existsEdge(1,3) << " - Cost: " << graph.getCost(1,3) << "\n\n\n";

    cout << "\t\tV0 = 0 exists: " << graph.existsVertex(0) << "\n";
    cout << "\t\tV1 = 1 exists: " << graph.existsVertex(1) << "\n";
    cout << "\t\tV2 = 2 exists: " << graph.existsVertex(2) << "\n";
    cout << "\t\tV3 = 3 exists: " << graph.existsVertex(3) << "\n";
    cout << "\t\tV4 = 4 exists: " << graph.existsVertex(4) << "\n";
    cout << "\t\tV5 = 5 exists: " << graph.existsVertex(5) << "\n";
    cout << "\t\tV6 = 6 exists: " << graph.existsVertex(6) << "\n";
    cout << "\t\tV7 = 7 exists: " << graph.existsVertex(7) << "\n";

    cout << "\n\n";
    graph.showMatrix();

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
            "\t\t\t\t\tV5              V6\n\n";

    graph.dijkstra(1);/*
    graph.dijkstra(2);
    graph.dijkstra(3);
    graph.dijkstra(4);
    graph.dijkstra(5);
    graph.dijkstra(6);*/

    cout << "\n\t================================================================\n";

    return 0;
}
