#include "Vertex.h"
#include "Edge.h"

#include <iostream>
using namespace std;

typedef int type;
int main() {

    Vertex<type>* v1 = new Vertex<type>(1);
    Vertex<type>* v2 = new Vertex<type>(2);

    Edge<type>* e1 = new Edge<type>(v2);
    Edge<type>* e2 = new Edge<type>(v1);

    v1->addAdjEdge(e1);
    v2->addAdjEdge(e2);

    cout << "\n\tV1 key: " << v1->getKey() << endl;
    v1->setVisited(true);
    cout << "\tV1 visited: " << v1->getVisited() << endl;
    cout << "\tE1 destination vertex: " << e1->getEndVertex() << endl;
    cout << "\tE1 destination vertex key: " << e1->getEndVertexData() << endl;
    cout << "\n\tV1 ---- E1 ----> V2\n";

    cout << "\n\tV2 key: " << v2->getKey() << endl;
    v2->setVisited(true);
    cout << "\tV2 visited: " << v1->getVisited() << endl;
    cout << "\tE2 destination vertex: " << e2->getEndVertex() << endl;
    cout << "\tE2 destination vertex key: " << e2->getEndVertexData() << endl;

    cout << "\n\tV1 <---- E2 ---- V2\n\n";

    delete v1;
    delete v2;
    delete e1;
    delete e2;

    return 0;
}
