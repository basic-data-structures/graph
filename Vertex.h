#ifndef GRAPHTEMPLATES_VERTEX_H
#define GRAPHTEMPLATES_VERTEX_H

#include "Edge.h"
#include "List.h"

template <typename Type>
class Vertex {

    private:
        List<Edge<Type>*> edges;
        Type key;
        bool visited;

    public:
        Vertex();
        Vertex(Type key);
        Type getKey();
        bool getVisited();
        List<Vertex<Type>*> getEdges();
        void setKey(Type key);
        void setVisited(bool visited);
        void addAdjEdge(Edge<Type>* edge);
};

///////////////////////////////////////////// IMPLEMENTATION /////////////////////////////////////////////
template <typename Type>
Vertex<Type>:: Vertex(Type key) {
    this->key = key;
}

/////////////////////////////////////////////
template <typename Type>
Type Vertex<Type>:: getKey() {
    return key;
}

/////////////////////////////////////////////
template <typename Type>
bool Vertex<Type>:: getVisited() {
    return visited;
}

/////////////////////////////////////////////
template <typename Type>
List<Vertex<Type>*> Vertex<Type>:: getEdges() {
    return edges;
}

/////////////////////////////////////////////
template <typename Type>
void Vertex<Type>:: setKey(Type key) {
    this->key = key;
}

/////////////////////////////////////////////
template <typename Type>
void Vertex<Type>:: setVisited(bool visited) {
    this->visited = visited;
}

/////////////////////////////////////////////
template <typename Type>
void Vertex<Type>:: addAdjEdge(Edge<Type>* edge) {
    edges.insertAtEnd(edge);
}



#endif //GRAPHTEMPLATES_VERTEX_H