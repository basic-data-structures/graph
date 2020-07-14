#ifndef GRAPHTEMPLATES_GRAPH_H
#define GRAPHTEMPLATES_GRAPH_H

#include "Vertex.h"
#include "Edge.h"

template <typename Type>
class Graph {

    private:
        Vertex<Type>* first;
        int vertexes;

    public:
        //  PRE: -
        // POST: Creates an empty graph
        Graph();

        //  PRE: -
        // POST: Creates a graph with vertex and edge
        Graph(Vertex<Type>* vertex, Edge<Type>* edge);

        //  PRE: The graph exists
        // POST: Free resources
        ~Graph();

        //  PRE: The vertex must not exist yet
        // POST: Inserts a new vertex
        void insertVertex(Vertex<Type>* vertex);

        //  PRE: The edge must not exist yet, there must be a begining and an ending vertex
        // POST: Inserts a new edge
        void insertEdge(Edge<Type>* edge);

        //  PRE: -
        // POST: Deletes vertex
        void deleteVertex(Vertex<Type>* vertex);

        //  PRE: -
        // POST: Deletes edge
        void deleteEdge(Edge<Type>* edge);

        //  PRE: -
        // POST: Returns true if a vertex with that key exists
        bool existsVertex(Type key);

        //  PRE: -
        // POST: Returns true if a edge from begin to end exists
        bool existsEdge(Vertex<Type>* begin, Vertex<Type>* end);

    private:
        bool existsVertex(Vertex<Type>* vertex);
        bool existsEdge(Edge<Type>* edge);

};

///////////////////////////////////////////// IMPLEMENTATION /////////////////////////////////////////////

#endif //GRAPHTEMPLATES_GRAPH_H