#ifndef GRAPHTEMPLATES_GRAPH_H
#define GRAPHTEMPLATES_GRAPH_H

#include "Vertex.h"

template <typename Type>
class Graph {

    private:
        List<Vertex<Type>*> adjList;
        int elements;

    public:
        //  PRE: -
        // POST: Creates an empty graph
        Graph();

        //  PRE: -
        // POST: Free resources
        ~Graph();

        //  PRE: -
        // POST: Creates a graph with an edge connecting begin and end
        Graph(Type begin, Type end);

        //  PRE: -
        // POST: If the key exists in the graph, it returns the vertex. Otherwise it returns NULL
        Vertex<Type>* getVertex(Type key);

        //  PRE: The edge connecting begin and end must not exist yet
        // POST: Inserts a new edge from begin to end
        void addEdge(Type begin, Type end);

        //  PRE: -
        // POST: Returns true if a vertex with that key exists
        bool existsVertex(Type key);

        //  PRE: -
        // POST: Returns true if a edge from begin to end exists
        bool existsEdge(Type begin, Type end);

        //  PRE: -
        // POST: Sets all the vertices in the graph to "not-visited"
        void setAllNotVisited();
};

///////////////////////////////////////////// IMPLEMENTATION /////////////////////////////////////////////
template<typename Type>
Graph<Type>:: Graph() {
    elements = 0;
}

template<typename Type>
Graph<Type>:: ~Graph() {
    for (int i = 0; i < adjList.getElements(); i ++) {
        delete adjList.getData(i);
    }
}

template<typename Type>
Graph<Type>:: Graph(Type begin, Type end) {
    Vertex<Type>* beg = new Vertex<Type>(begin);
    Vertex<Type>* en = new Vertex<Type>(end);
    beg->addNeighbor(en);
    adjList.insertAtEnd(beg);
    adjList.insertAtEnd(en);
    elements += 2;
}

template<typename Type>
Vertex<Type>* Graph<Type>:: getVertex(Type key) {
    for (int i = 0; i < adjList.getElements(); ++i) {
        if (adjList.getData(i)->getKey() == key)
            return adjList.getData(i);
    }
    return 0;
}

template<typename Type>
void Graph<Type>:: addEdge(Type begin, Type end) {
    if (!existsEdge(begin, end)) {
        Vertex<Type>* begAux;
        Vertex<Type>* endAux;
        if (existsVertex(begin) && existsVertex(end)) {
            begAux = getVertex(begin);
            endAux = getVertex(end);
            begAux->addNeighbor(endAux);
        }
        else if (existsVertex(begin)) {
            begAux = getVertex(begin);
            endAux = new Vertex<Type>(end);
            begAux->addNeighbor(endAux);
            adjList.insertAtEnd(endAux);
            elements += 1;
        }
        else if (existsVertex(end)) {
            begAux = new Vertex<Type>(begin);
            endAux = getVertex(end);
            begAux->addNeighbor(endAux);
            adjList.insertAtEnd(begAux);
            elements += 1;
        }
        else {
            begAux = new Vertex<Type>(begin);
            endAux = new Vertex<Type>(end);
            begAux->addNeighbor(endAux);
            adjList.insertAtEnd(begAux);
            adjList.insertAtEnd(endAux);
            elements += 2;
        }
        cout << "\n\tEdge connecting " << begin << " and " << end << " added successfully!\n";
    }
    else
        cout << "\n\tThere's already an edge connecting " << begin << " and " << end << "!\n";
}

template<typename Type>
bool Graph<Type>:: existsVertex(Type key) {
    for (int i = 0; i < adjList.getElements(); ++i) {
        if (adjList.getData(i)->getKey() == key) {
            return true;
        }
    }
    return false;
}

template<typename Type>
bool Graph<Type>:: existsEdge(Type begin, Type end) {
    if (existsVertex(begin) && existsVertex(end)) {
        Vertex<Type>* begAux = getVertex(begin);
        for (int i = 0; i < begAux->getNeighbors()->getElements(); i++) {
            if (begAux->getNeighbors()->getData(i)->getKey() == end)
                return true;
        }
    }
    return false;
}

template<typename Type>
void Graph<Type>:: setAllNotVisited() {
    for (int i = 0; i < adjList.getElements(); i++) {
        adjList.getData(i)->setVisited(false);
    }
}

#endif //GRAPHTEMPLATES_GRAPH_H