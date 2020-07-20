#ifndef GRAPHTEMPLATES_VERTEX_H
#define GRAPHTEMPLATES_VERTEX_H

#include "List.h"

template <typename Type>
class Vertex {

    private:
        Type key;
        bool visited;
        List<Vertex<Type>*> neighbors;

    public:
        Vertex(Type key);
        Type getKey();
        bool getVisited();
        List<Vertex<Type>*>* getNeighbors();
        void setKey(Type key);
        void setVisited(bool visited);
        void addNeighbor(Vertex<Type>* neighbor);
};

///////////////////////////////////////////// IMPLEMENTATION /////////////////////////////////////////////
template <typename Type>
Vertex<Type>:: Vertex(Type key) {
    this->key = key;
    this->visited = false;
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
List<Vertex<Type>*>* Vertex<Type>:: getNeighbors() {
    return &neighbors;
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
void Vertex<Type>:: addNeighbor(Vertex<Type>* neighbor) {
    neighbors.insertAtBeginning(neighbor);
}

#endif //GRAPHTEMPLATES_VERTEX_H