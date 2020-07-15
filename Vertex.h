#ifndef GRAPHTEMPLATES_VERTEX_H
#define GRAPHTEMPLATES_VERTEX_H

#include "List.h"

template <typename Type>
class Vertex {

    private:
        Type key;
        bool visited;

    public:
        Vertex();
        Vertex(Type key);
        Type getKey();
        bool getVisited();
        void setKey(Type key);
        void setVisited(bool visited);
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
void Vertex<Type>:: setKey(Type key) {
    this->key = key;
}

/////////////////////////////////////////////
template <typename Type>
void Vertex<Type>:: setVisited(bool visited) {
    this->visited = visited;
}

#endif //GRAPHTEMPLATES_VERTEX_H