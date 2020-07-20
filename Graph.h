#ifndef GRAPHTEMPLATES_GRAPH_H
#define GRAPHTEMPLATES_GRAPH_H

#include "Vertex.h"
#include "Edge.h"

template <typename Type>
class Graph {

    private:
        List<Vertex<Type>*> adjList;
        List<Edge<Type>*> edges;
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
        Graph(Type begin, Type end, unsigned cost = 0);

        //  PRE: -
        // POST: If the key exists in the graph, it returns the vertex. Otherwise it returns NULL
        Vertex<Type>* getVertex(Type key);

        //  PRE: -
        // POST: If a path from begin to end exists, it returns the edge. Otherwise it returns NULL
        Edge<Type>* getEdge(Type begin, Type end);

        //  PRE: The edge connecting begin and end must not exist yet
        // POST: Inserts a new edge from begin to end
        void addEdge(Type begin, Type end, unsigned cost = 0);

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
    for (int j = 0; j < edges.getElements(); ++j) {
        delete edges.getData(j);
    }
}

template<typename Type>
Graph<Type>:: Graph(Type begin, Type end, unsigned cost) {
    Vertex<Type>* beg = new Vertex<Type>(begin);
    Vertex<Type>* en = new Vertex<Type>(end);
    Edge<Type>* edge = new Edge<Type>(beg, en, cost);
    beg->addNeighbor(en);
    adjList.insertAtEnd(beg);
    adjList.insertAtEnd(en);
    edges.insertAtBeginning(edge);
    cout << "\t\tEdge connecting " << begin << " and " << end << " with cost " << cost << " added successfully!\n";
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
Edge<Type>* Graph<Type>:: getEdge(Type begin, Type end) {
    Edge<Type>* edge = 0;
    if (existsEdge(begin, end)) {
        for (int i = 0; i < edges.getElements(); ++i) {
            if (edges.getData(i)->getBeginVertex() == getVertex(begin) && edges.getData(i)->getEndVertex() == getVertex(end)) {
                edge = edges.getData(i);
            }
        }
    }
    return edge;
}

template<typename Type>
void Graph<Type>:: addEdge(Type begin, Type end, unsigned cost) {
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
        Edge<Type>* edge = new Edge<Type>(begAux, endAux, cost);
        edges.insertAtBeginning(edge);
        cout << "\t\tEdge connecting " << begin << " and " << end << " with cost " << cost << " added successfully!\n";
    }
    else
        cout << "\t\tThere's already an edge connecting " << begin << " and " << end << "!\n";
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