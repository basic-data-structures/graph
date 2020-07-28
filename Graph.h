#ifndef GRAPHTEMPLATES_GRAPH_H
#define GRAPHTEMPLATES_GRAPH_H

#include "Matrix.h"
#include "List.h"

const int INFINITY = 1000001;
const int NULL_COST = -1;

template <typename Type, typename Cost>
class Graph {

    private:
        Matrix<Cost>* costsMatrix;
        List<Type>* vertices;
        Cost nullCost;
        int elements;

    public:

        //  PRE: -
        // POST: Creates a graph with an edge connecting begin and end
        Graph(Type begin, Type end, Cost cost, Cost null);

        //  PRE: -
        // POST: Free resources
        ~Graph();

        //  PRE: The edge connecting begin and end must not exist yet
        // POST: Inserts a new edge from begin to end
        void addEdge(Type begin, Type end, Cost cost);

        //  PRE: -
        // POST: Returns true if a vertex with that key exists
        bool existsVertex(Type key);

        //  PRE: -
        // POST: Returns true if a edge from begin to end exists
        bool existsEdge(Type begin, Type end);

        // PRE: -
        // POST: Returns the cost of going from begin to end
        int getCost(Type begin, Type end);

        // PRE: -
        // POST: Prints matrix on screen
        void showMatrix();

        //  PRE: -
        // POST: Depth First Search all the vertices starting from the key given.
        //       If the key doesn't exist in the graph, a message is printed on the screen.
        void showDFS(Type key);

        //  PRE: -
        // POST: Breadth First Search all the vertices of the graph starting from the key given.
        //       If the key doesn't exist in the graph, a message is printed on the screen.
        void showBFS(Type key);

        int getMinCost(Type begin, Type end);
        void showShortestPath(Type begin, Type end);

private:

    void dijkstra(Type begin, Type end);

    //  PRE: The vertex must exist in the graph
    // POST: Recursive algorithm that searches all the vertices of a graph starting from the given vertex
    void DFS(Type vertex);

    //  PRE: The vertex must exist in the graph
    // POST:
    void BFS(Type vertex);
};

///////////////////////////////////////////// IMPLEMENTATION /////////////////////////////////////////////
template<typename Type, typename Cost>
Graph<Type, Cost>:: Graph(Type begin, Type end, Cost cost, Cost nullCost) {
    this->nullCost = nullCost;
    costsMatrix = new Matrix<Cost>(2, nullCost);
    vertices = new List<Type>;

    vertices->insertAtEnd(begin);
    vertices->insertAtEnd(end);
    elements += 2;

    costsMatrix->insert(cost, vertices->getPosition(begin), vertices->getPosition(end));
    cout << "\t\tEdge connecting " << begin << " and " << end << " with cost " << cost << " added successfully!\n";
}

template<typename Type, typename Cost>
Graph<Type, Cost>:: ~Graph() {
    delete costsMatrix;
    delete vertices;
}

template<typename Type, typename Cost>
int Graph<Type, Cost>:: getCost(Type begin, Type end) {
    if (existsEdge(begin, end)) {
        int begPos = vertices->getPosition(begin);
        int endPos = vertices->getPosition(end);
        return costsMatrix->getData(begPos, endPos);
    }
    return nullCost;
}


template<typename Type, typename Cost>
void Graph<Type, Cost>:: showMatrix() {
    costsMatrix->printMatrix();
}


template<typename Type, typename Cost>
void Graph<Type, Cost>:: addEdge(Type begin, Type end, Cost cost) {
    if (!existsEdge(begin, end)) {
        if (existsVertex(begin) && existsVertex(end)) {
            costsMatrix->insert(cost, vertices->getPosition(begin), vertices->getPosition(end));
        }
        else if (existsVertex(begin)) {
            costsMatrix->resize(elements + 1);
            vertices->insertAtEnd(end);
            costsMatrix->insert(cost, vertices->getPosition(begin), elements);
            elements += 1;
        }
        else if(existsVertex(end)) {
            costsMatrix->resize(elements + 1);
            vertices->insertAtEnd(begin);
            costsMatrix->insert(cost, elements, vertices->getPosition(end));
            elements += 1;
        }
        else {
            costsMatrix->resize(elements + 2);
            vertices->insertAtEnd(begin);
            vertices->insertAtEnd(end);
            elements += 2;
            costsMatrix->insert(cost, vertices->getPosition(begin), vertices->getPosition(end));
        }
        cout << "\t\tEdge connecting " << begin << " and " << end << " with cost " << cost << " added successfully!\n";
    }
    else
        cout << "\t\tThere's already an edge connecting " << begin << " and " << end << "!\n";
}

template<typename Type, typename Cost>
bool Graph<Type, Cost>:: existsVertex(Type key) {
    return vertices->existsData(key);
}

template<typename Type, typename Cost>
bool Graph<Type, Cost>:: existsEdge(Type begin, Type end) {
    bool exists;
    if (existsVertex(begin) && existsVertex(end)) {
        unsigned begPos = vertices->getPosition(begin);
        unsigned endPos = vertices->getPosition(end);
        if (nullCost == costsMatrix->getData(begPos, endPos))
            exists = false;
        else
            exists = true;
    }
    return exists;
}

template<typename Type, typename Cost>
void Graph<Type, Cost>:: showDFS(Type key) {
    cout << "\t---------------------------- DFS -------------------------------\n";
    if (existsVertex(key)) {
        cout << "\t\tStarting DFS from " << key << "...\n\t";
        DFS(getVertex(key));
    } else
        cout << "\tOps! That value doesn't exist in the graph. Try again!\n";
    cout << "\n\t----------------------------------------------------------------\n\n";
}

template<typename Type, typename Cost>
void Graph<Type, Cost>:: showBFS(Type key) {
    cout << "\t---------------------------- BFS -------------------------------\n";
    if (existsVertex(key)) {
        cout << "\t\tStarting BFS from " << key << "...\n\t";
        BFS(getVertex(key));
    } else
        cout << "\tOps! That value doesn't exist in the graph. Try again!\n";
    cout << "\n\t----------------------------------------------------------------\n\n";
}

template<typename Type, typename Cost>
int Graph<Type, Cost>:: getMinCost(Type begin, Type end) {
    //TODO
}

template<typename Type, typename Cost>
void Graph<Type, Cost>:: showShortestPath(Type begin, Type end) {
    //TODO
}

template<typename Type, typename Cost>
void Graph<Type, Cost>:: dijkstra(Type begin, Type end) {
    //TODO
}

template<typename Type, typename Cost>
void Graph<Type, Cost>:: DFS(Type vertex) {
    //TODO
}

template<typename Type, typename Cost>
void Graph<Type, Cost>:: BFS(Type vertex) {
    //TODO
}

#endif //GRAPHTEMPLATES_GRAPH_H