#include "Vertex.h"
#include "Edge.h"

#include <iostream>
using namespace std;

typedef int type;
int main() {

    Vertex<type>* v1 = new Vertex<type>(1);
    Vertex<type>* v2 = new Vertex<type>(2);
    Vertex<type>* v3 = new Vertex<type>(3);

    Edge<type>* e1 = new Edge<type>(v1, v2);
    Edge<type>* e2 = new Edge<type>(v2, v1);
    Edge<type>* e3 = new Edge<type>(v3, v1);
    Edge<type>* e4 = new Edge<type>(v2, v3);

    cout << "\n\tV1 key: " << v1->getKey() << endl;
    v1->setVisited(true);
    cout << "\tV1 visited: " << v1->getVisited() << endl;
    cout << "\tE1 origin vertex: " << e1->getBeginVertex() << endl;
    cout << "\tE1 origin vertex key: " << e1->getBeginVertexData() << endl;
    cout << "\tE1 destination vertex: " << e1->getEndVertex() << endl;
    cout << "\tE1 destination vertex key: " << e1->getEndVertexData() << endl;
    cout << "\n\tV1 ---- E1 ----> V2\n";

    cout << "\n\tV2 key: " << v2->getKey() << endl;
    v2->setVisited(true);
    cout << "\tV2 visited: " << v2->getVisited() << endl;
    cout << "\tE2 origin vertex: " << e2->getBeginVertex() << endl;
    cout << "\tE2 origin vertex key: " << e2->getBeginVertexData() << endl;
    cout << "\tE2 destination vertex: " << e2->getEndVertex() << endl;
    cout << "\tE2 destination vertex key: " << e2->getEndVertexData() << endl;
    cout << "\n\tV1 <---- E2 ---- V2\n\n";
    cout << "\tE4 origin vertex: " << e4->getBeginVertex() << endl;
    cout << "\tE4 origin vertex key: " << e4->getBeginVertexData() << endl;
    cout << "\tE4 destination vertex: " << e4->getEndVertex() << endl;
    cout << "\tE4 destination vertex key: " << e4->getEndVertexData() << endl;
    cout << "\n\tV2 ---- E4 ----> V3\n\n";

    cout << "\n\tV3 key: " << v2->getKey() << endl;
    v3->setVisited(false);
    cout << "\tV3 visited: " << v3->getVisited() << endl;
    cout << "\tE3 origin vertex: " << e3->getBeginVertex() << endl;
    cout << "\tE3 origin vertex key: " << e3->getBeginVertexData() << endl;
    cout << "\tE3 destination vertex: " << e3->getEndVertex() << endl;
    cout << "\tE3 destination vertex key: " << e3->getEndVertexData() << endl;
    cout << "\n\tV1 <---- E3 ---- V3\n\n";

    cout << "\n\n\tV1 <- E2-E1 -> V2\n"
                "\t ^             |\n"
                "\t  \\            |\n"
                "\t    \\          |\n"
                "\t      \\       E3\n"
                "\t        \\      |\n"
                "\t          \\    |\n"
                "\t            \\ \\/\n"
                "\t              V3\n";

    delete v1;
    delete v2;
    delete v3;
    delete e1;
    delete e2;
    delete e3;
    delete e4;

    return 0;
}
