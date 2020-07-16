#ifndef GRAPHTEMPLATES_GRAPH_H
#define GRAPHTEMPLATES_GRAPH_H

#include "Vertex.h"
#include "Edge.h"

template <typename Type>
class Graph {

    private:
        List<Edge<Type>*> edges;
        List<Vertex<Type>*> vertices;
        int elements;

    public:
        //  PRE: -
        // POST: Creates an empty graph
        Graph();

        //  PRE: -
        // POST: Creates a graph with an edge connecting begin and end
        Graph(Type begin, Type end);

        //  PRE: -
        // POST: If the key exists in the graph, it returns the vertex. Otherwise it returns NULL
        Vertex<Type>* getVertex(Type key);

        //  PRE: The edge connecting begin and end must not exist yet
        // POST: Inserts a new edge from begin to end
        void insertEdge(Type begin, Type end);

        //  PRE: -
        // POST: Returns true if a vertex with that key exists
        bool existsVertex(Type key);

        //  PRE: -
        // POST: Returns true if a edge from begin to end exists
        bool existsEdge(Type begin, Type end);
};

///////////////////////////////////////////// IMPLEMENTATION /////////////////////////////////////////////
template<typename Type>
Graph<Type>:: Graph() {
    elements = 0;
}

template<typename Type>
Graph<Type>:: Graph(Type begin, Type end) {
    Vertex<Type>* beg = new Vertex<Type>(begin);
    Vertex<Type>* en = new Vertex<Type>(end);
    vertices.insertAtEnd(beg);
    vertices.insertAtEnd(en);
    Edge<Type>* edge = new Edge<Type>(beg, en);
    edges.insertAtEnd(edge);
}

template<typename Type>
Vertex<Type>* Graph<Type>:: getVertex(Type key) {
    for (int i = 0; i < vertices.getElements(); ++i) {
        if (vertices.getData(i)->getKey() == key)
            return vertices.getData(i);
    }
    return 0;
}

template<typename Type>
void Graph<Type>:: insertEdge(Type begin, Type end) {
    if (existsVertex(begin) && existsVertex(end)) {
        Edge<Type>* edge = new Edge<Type>(getVertex(begin), getVertex(end));
        edges.insertAtEnd(edge);
    }
    else if (!existsVertex(begin)) {
        Vertex<Type>* aux = new Vertex<Type>(begin);
        vertices.insertAtEnd(aux);
        elements += 1;
        Edge<Type>* edge = new Edge<Type>(aux, getVertex(end));
        edges.insertAtEnd(edge);
    }
    else if (!existsVertex(end)) {
        Vertex<Type>* aux = new Vertex<Type>(end);
        vertices.insertAtEnd(aux);
        elements += 1;
        Edge<Type>* edge = new Edge<Type>(getVertex(begin), aux);
        edges.insertAtEnd(edge);
    }
    else {
        Vertex<Type>* auxBeg = new Vertex<Type>(end);
        Vertex<Type>* auxEnd = new Vertex<Type>(end);
        vertices.insertAtEnd(auxBeg);
        vertices.insertAtEnd(auxEnd);
        elements += 2;
        Edge<Type>* edge = new Edge<Type>(auxBeg, auxEnd);
        edges.insertAtEnd(edge);
    }
}

template<typename Type>
bool Graph<Type>:: existsVertex(Type key) {
    for (int i = 0; i < vertices.getElements(); ++i) {
        if (vertices.getData(i)->getKey() == key) {
            return true;
        }
    }
    return false;
}

template<typename Type>
bool Graph<Type>:: existsEdge(Type begin, Type end) {
    for (int i = 0; i < edges.getElements(); ++i) {
        Edge<Type>* aux = edges.getData(i);
        if (aux->getBeginVertex()->getKey() == begin && aux->getEndVertex()->getKey() == end) {
            return true;
        }
    }
    return false;
}

#endif //GRAPHTEMPLATES_GRAPH_H