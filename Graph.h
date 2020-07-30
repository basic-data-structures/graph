#ifndef GRAPHTEMPLATES_GRAPH_H
#define GRAPHTEMPLATES_GRAPH_H

#include "Matrix.h"
#include "List.h"
#include <limits>

const int INFINITY = 9999999;
const int NULL_COST = -1;

template <typename Type, typename Cost>
class Graph {

    private:
        Matrix<Cost>* costsMatrix;
        List<Type>* vertices;
        int elements;

    public:

        //  PRE: -
        // POST: Creates a graph with elements = 0, vertices and costMatrix pointing to NULL
        Graph();

        //  PRE: -
        // POST: Creates a graph with an edge connecting begin and end
        Graph(Type begin, Type end, Cost cost);

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

        void dijkstra(Type begin);

private:

    int minDistanceIndex(int distances[], bool visited[]);
    void DFS(Type begin);
    void BFS(Type begin);
};

///////////////////////////////////////////// IMPLEMENTATION /////////////////////////////////////////////
template<typename Type, typename Cost>
Graph<Type, Cost>:: Graph() {
    costsMatrix = 0;
    vertices = 0;
    elements = 0;
}

template<typename Type, typename Cost>
Graph<Type, Cost>:: Graph(Type begin, Type end, Cost cost) {
    elements = 0;
    vertices = new List<Type>;
    costsMatrix = new Matrix<Cost>(elements, INFINITY);
    addEdge(begin, end, cost);
}

template<typename Type, typename Cost>
Graph<Type, Cost>:: ~Graph() {
    delete costsMatrix;
    delete vertices;
}

template<typename Type, typename Cost>
int Graph<Type, Cost>:: getCost(Type begin, Type end) {
    int cost = NULL;
    if (existsEdge(begin, end)) {
        int begPos = vertices->getPosition(begin);
        int endPos = vertices->getPosition(end);
        cost = costsMatrix->getData(begPos, endPos);
    }
    return cost;
}


template<typename Type, typename Cost>
void Graph<Type, Cost>:: showMatrix() {
    cout << "\n";
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
    bool exists = true;
    if (existsVertex(begin) && existsVertex(end)) {
        if (costsMatrix->getData(vertices->getPosition(begin), vertices->getPosition(end)) == INFINITY)
            exists = false;
    }
    else
        exists = false;
    return exists;
}

template<typename Type, typename Cost>
void Graph<Type, Cost>:: showDFS(Type key) {
    cout << "\t---------------------------- DFS -------------------------------\n";
    if (existsVertex(key)) {
        cout << "\t\tStarting DFS from " << key << "...\n\t";
        DFS(key);
    } else
        cout << "\tOps! That value doesn't exist in the graph. Try again!\n";
    cout << "\n\t----------------------------------------------------------------\n\n";
}

template<typename Type, typename Cost>
void Graph<Type, Cost>:: showBFS(Type key) {
    cout << "\t---------------------------- BFS -------------------------------\n";
    if (existsVertex(key)) {
        cout << "\t\tStarting BFS from " << key << "...\n\t";
        BFS(key);
    } else
        cout << "\tOps! That value doesn't exist in the graph. Try again!\n";
    cout << "\n\t----------------------------------------------------------------\n\n";
}

template<typename Type, typename Cost>
int Graph<Type, Cost>:: minDistanceIndex(int distances[], bool visited[]) {
    int minCost = INFINITY, minIndex;
    for (int v = 0; v < vertices->getElements(); v++) {
        if (visited[v] == false && distances[v] <= minCost) {
            minCost = distances[v];
            minIndex = v;
        }
    }
    return minIndex;
}

template<typename Type, typename Cost>
void Graph<Type, Cost>:: dijkstra(Type begin) {

    if (existsVertex(begin)) {

        int minDist, newCost, begPos = vertices->getPosition(begin), elements = vertices->getElements();
        Type distances[elements];
        bool visited[elements];

        for (int i = 0; i < elements; i++) {
            distances[i] = INFINITY;
            visited[i] = false;
        }

        distances[begPos] = 0;

        for (int i = 0; i < elements; i++) {
            minDist = minDistanceIndex(distances, visited);
            visited[vertices->getPosition(minDist)] = true;

            for (int v = 0; v < elements; v++) {
                if (!visited[v] && costsMatrix->getData(minDist, v) != INFINITY && distances[minDist] != INFINITY) {
                    newCost =  costsMatrix->getData(minDist, v) + distances[minDist];
                    if(newCost < distances[v])
                        distances[v] = newCost;
                }

            }
        }
        cout << "\n\t\t---- Min Distances from " << begin << "----\n"
                "\t\t Vertex\t\t\tDistance\n";
        for (int j = 0; j < elements; ++j) {
            cout << "\t\t\t" << vertices->getData(j) << "\t\t\t" << distances[j] << "\n";
        }
    }
}

#endif //GRAPHTEMPLATES_GRAPH_H