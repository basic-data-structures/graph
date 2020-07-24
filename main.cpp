#include "Graph.h"
#include "Vector.h"
#include "Matrix.h"

#include <iostream>
using namespace std;

int main() {
/*
    cout << "\n\n\t========================== MATRIX ===============================\n\n";
    Matrix<int> matrix(15,-1);
    cout << "\tInserting " << 4 << " in [0,0]\n";
    matrix.insert(4,0,0);
    cout << "\t" << matrix.getData(0,0) << "\n";
    matrix.printMatrix();
*/
    cout << "\n\n\t========================= VECTOR ===============================\n\n";
    Vector<int> vector(5,-1);
    for (int i = 0; i < vector.getVectorSize(); ++i) {
        cout << "\tInserting " << i+2 << " in " << i << "\n";
        vector.insert(i+2,i);
    }
    cout << "\n\tThe vector can store up to " << vector.getVectorSize() << " elements\n";

    vector.resize(7);
    cout << "\n\tThe vector was resized! Now it can store up to " << vector.getVectorSize() << " elements\n";
    for (int i = 0; i < vector.getVectorSize(); ++i) {
        cout << "\t" << i << " -> " << vector.getElement(i) << "\n";
    }

    vector.resize(9);
    cout << "\n\tThe vector was resized! Now it can store up to " << vector.getVectorSize() << " elements\n";
    for (int i = 0; i < vector.getVectorSize(); ++i) {
        cout << "\t" << i << " -> " << vector.getElement(i) << "\n";
    }

    cout << "\n\n\t========================= GRAPH ================================\n\n";

    Graph<int> graph(1,2,5);
    graph.addEdge(1,2,4);
    graph.addEdge(1,4,7);
    graph.addEdge(2,1,3);
    graph.addEdge(2,3,14);
    graph.addEdge(5,6,7);
    graph.addEdge(6,3,2);

    cout << "\n\n";

    cout << boolalpha;
    cout << "\t\tV1 to V2: " << graph.existsEdge(1,2) << " - Cost: " << graph.getCost(1,2) << "\n";
    cout << "\t\tV1 to V4: " << graph.existsEdge(1,4) << " - Cost: " << graph.getCost(1,4) << "\n";
    cout << "\t\tV2 to V1: " << graph.existsEdge(2,1) << " - Cost: " << graph.getCost(2,1) << "\n";
    cout << "\t\tV2 to V3: " << graph.existsEdge(2,3) << " - Cost: " << graph.getCost(2,3) << "\n";
    cout << "\t\tV1 to V3: " << graph.existsEdge(1,3) << "\n";

    cout << "\n\n";

    cout << "\t\tV0 exists: " << graph.existsVertex(0) << "\n";
    cout << "\t\tV1 exists: " << graph.existsVertex(1) << "\n";
    cout << "\t\tV2 exists: " << graph.existsVertex(2) << "\n";
    cout << "\t\tV3 exists: " << graph.existsVertex(3) << "\n";
    cout << "\t\tV4 exists: " << graph.existsVertex(4) << "\n";
    cout << "\t\tV5 exists: " << graph.existsVertex(5) << "\n";

    cout << "\n\n";

    graph.showDFS(2);
    cout << "\n";
    graph.showBFS(2);

    cout << "\t\t\t\t\tV1 <-- E2-E1 --> V2\n"
            "\t\t\t\t\t | /\\            |\n"
            "\t\t\t\t\t |  \\            |\n"
            "\t\t\t\t\t |    \\          |\n"
            "\t\t\t\t\t |      \\       E3\n"
            "\t\t\t\t\t |        \\      |\n"
            "\t\t\t\t\t |          \\    |\n"
            "\t\t\t\t\t\\/            \\ \\/\n"
            "\t\t\t\t\tV4              V3\n\n";

    graph.showDFS(2);
    cout << "\n";
    graph.showBFS(2);

    cout << "\n\t================================================================\n";
    return 0;
}
