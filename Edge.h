#ifndef GRAPHTEMPLATES_EDGE_H
#define GRAPHTEMPLATES_EDGE_H

#include "Vertex.h"

template <class Type> class Vertex;

template <typename Type>
class Edge {

    private:
        Vertex<Type>* end;
        unsigned cost;

    public:
        Edge(Vertex<Type>* end, unsigned cost);
        Type getEndVertexData();
        Vertex<Type>* getEndVertex();
        unsigned getCost();
};

///////////////////////////////////////////// IMPLEMENTATION /////////////////////////////////////////////
template <typename Type>
Edge<Type>:: Edge(Vertex<Type> *end, unsigned cost) {
    this->end = end;
    this->cost = cost;
}

template <typename Type>
Type Edge<Type>:: getEndVertexData() {
    return end->getKey();
}

template <typename Type>
Vertex<Type>* Edge<Type>:: getEndVertex() {
    return end;
}

template <typename Type>
unsigned Edge<Type>:: getCost() {
    return cost;
}

#endif //GRAPHTEMPLATES_EDGE_H