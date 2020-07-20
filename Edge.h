#ifndef GRAPHTEMPLATES_EDGE_H
#define GRAPHTEMPLATES_EDGE_H

#include "Vertex.h"

template <typename Type>
class Edge {

private:
    Vertex<Type>* begin;
    Vertex<Type>* end;
    unsigned cost;

public:
    Edge(Vertex<Type>* begin, Vertex<Type>* end, unsigned cost = 0);
    void setBeginVertex(Vertex<Type>* begin);
    void setEndVertex(Vertex<Type>* end);
    void setBeginVertexData(Type data);
    void setEndVertexData(Type data);
    Type getBeginVertexData();
    Type getEndVertexData();
    Vertex<Type>* getBeginVertex();
    Vertex<Type>* getEndVertex();
    unsigned getCost();
};

///////////////////////////////////////////// IMPLEMENTATION /////////////////////////////////////////////
template <typename Type>
Edge<Type>:: Edge(Vertex<Type>* begin,Vertex<Type> *end, unsigned cost) {
    this->begin = begin;
    this->end = end;
    this->cost = cost;
}

template <typename Type>
void Edge<Type>:: setBeginVertex(Vertex<Type> *begin) {
    this->begin = begin;
}

template <typename Type>
void Edge<Type>:: setBeginVertexData(Type data) {
    this->begin.setKey(data);
}

template <typename Type>
void Edge<Type>:: setEndVertex(Vertex<Type> *end) {
    this->end = end;
}

template <typename Type>
void Edge<Type>:: setEndVertexData(Type data) {
    this->end.setKey(data);
}

template <typename Type>
Type Edge<Type>:: getBeginVertexData() {
    return begin->getKey();
}

template <typename Type>
Vertex<Type>* Edge<Type>:: getBeginVertex() {
    return begin;
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
