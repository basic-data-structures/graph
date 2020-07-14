#ifndef GRAPHTEMPLATES_EDGE_H
#define GRAPHTEMPLATES_EDGE_H

#include "Vertex.h"

template <class Type> class Vertex;

template <typename Type>
class Edge {

    private:
        Vertex<Type>* end;

    public:
        Edge(Vertex<Type>* end);
        Type getEndVertexData();
        Vertex<Type>* getEndVertex();
};

///////////////////////////////////////////// IMPLEMENTATION /////////////////////////////////////////////
template <typename Type>
Edge<Type>:: Edge(Vertex<Type> *end) {
    this->end = end;
}

template <typename Type>
Type Edge<Type>:: getEndVertexData() {
    return end->getKey();
}

template <typename Type>
Vertex<Type>* Edge<Type>:: getEndVertex() {
    return end;
}

#endif //GRAPHTEMPLATES_EDGE_H