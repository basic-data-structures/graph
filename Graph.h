#ifndef GRAPHTEMPLATES_GRAPH_H
#define GRAPHTEMPLATES_GRAPH_H

#include "Vertex.h"
#include "Matrix.h"
#include "Vector.h"

template <typename Type>
class Graph {

    private:
        List<Vertex<Type>*> adjList;
        Matrix<int>* costsMatrix;
        Vector<Type>* dataIndex;
        int elements;

    public:

        //  PRE: -
        // POST: Creates a graph with an edge connecting begin and end
        Graph(Type begin, Type end, int cost = 0);

        //  PRE: -
        // POST: Free resources
        ~Graph();

        //  PRE: The edge connecting begin and end must not exist yet
        // POST: Inserts a new edge from begin to end
        void addEdge(Type begin, Type end, int cost = 0);

        //  PRE: -
        // POST: Returns true if a vertex with that key exists
        bool existsVertex(Type key);

        //  PRE: -
        // POST: Returns true if a edge from begin to end exists
        bool existsEdge(Type begin, Type end);

        //  PRE: -
        // POST: Sets all the vertices in the graph to "not-visited"
        void setAllNotVisited();

        //  PRE: -
        // POST: If the key exists in the graph, it returns the vertex. Otherwise it returns NULL
        Vertex<Type>* getVertex(Type key);

        // PRE: -
        // POST: Returns the cost of going from begin to end
        int getCost(Type begin, Type end);

        //  PRE: -
        // POST: Depth First Search all the vertices starting from the key given.
        //       If the key doesn't exist in the graph, a message is printed on the screen.
        void showDFS(Type key);

        //  PRE: -
        // POST: Breadth First Search all the vertices of the graph starting from the key given.
        //       If the key doesn't exist in the graph, a message is printed on the screen.
        void showBFS(Type key);

private:

    //  PRE: The vertex must exist in the graph
    // POST: Recursive algorithm that searches all the vertices of a graph starting from the given vertex
    void DFS(Vertex<Type>* vertex);

    //  PRE: The vertex must exist in the graph
    // POST:
    void BFS(Vertex<Type>* vertex);

};

///////////////////////////////////////////// IMPLEMENTATION /////////////////////////////////////////////
template<typename Type>
constexpr std::size_t size_of(Type const&) {
    return sizeof(Type);
}

template<typename Type>
Graph<Type>:: Graph(Type begin, Type end, int cost) {
    // Initialize matrix and vector with null
    costsMatrix = new Matrix<int>(20, -1);
    dataIndex = new Vector<Type>(2, -1);

    Vertex<Type>* beg = new Vertex<Type>(begin);
    Vertex<Type>* en = new Vertex<Type>(end);

    // Add end to begin neighbor's
    beg->addNeighbor(en);

    // Add begin
    adjList.insertAtEnd(beg);
    dataIndex->insert(begin, elements);
    elements += 1;

    // Add end
    adjList.insertAtEnd(en);
    dataIndex->insert(end, elements);
    elements += 1;

    costsMatrix->insert(cost, dataIndex->getPosition(begin), dataIndex->getPosition(end));
    cout << "\t\tEdge connecting " << begin << " and " << end << " with cost " << cost << " added successfully!\n";
}

template<typename Type>
Graph<Type>:: ~Graph() {
    for (int i = 0; i < adjList.getElements(); i ++) {
        delete adjList.getData(i);
    }
    delete costsMatrix;
    delete dataIndex;
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
int Graph<Type>:: getCost(Type begin, Type end) {
    int begPos = dataIndex->getPosition(begin);
    int endPos = dataIndex->getPosition(end);
    return costsMatrix->getData(begPos, endPos);
}

template<typename Type>
void Graph<Type>:: addEdge(Type begin, Type end, int cost) {

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
            cout << "\tData Index Size Before: " << dataIndex->getVectorSize() << "\n";
            dataIndex->resize(dataIndex->getVectorSize() + 1);
            cout << "\tData Index Size After: " << dataIndex->getVectorSize() << "\n";
            dataIndex->insert(end, elements);
            elements += 1;
        }

        else if (existsVertex(end)) {
            begAux = new Vertex<Type>(begin);
            endAux = getVertex(end);
            begAux->addNeighbor(endAux);
            adjList.insertAtEnd(begAux);
            cout << "\tData Index Size Before: " << dataIndex->getVectorSize() << "\n";
            dataIndex->resize(dataIndex->getVectorSize() + 1);
            cout << "\tData Index Size After: " << dataIndex->getVectorSize() << "\n";
            dataIndex->insert(begin, elements);
            elements += 1;
        }

        else {
            begAux = new Vertex<Type>(begin);
            endAux = new Vertex<Type>(end);
            begAux->addNeighbor(endAux);
            adjList.insertAtEnd(begAux);
            cout << "\tData Index Size Before: " << dataIndex->getVectorSize() << "\n";
            dataIndex->resize(dataIndex->getVectorSize() + 2);
            cout << "\tData Index Size After: " << dataIndex->getVectorSize() << "\n";
            dataIndex->insert(begin, elements);
            elements += 1;
            adjList.insertAtEnd(endAux);
            dataIndex->insert(end, elements);
            elements += 1;
        }
        costsMatrix->insert(cost, dataIndex->getPosition(begin), dataIndex->getPosition(end));
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

template<typename Type>
void Graph<Type>:: showDFS(Type key) {
    cout << "\t---------------------------- DFS -------------------------------\n";
    if (existsVertex(key)) {
        cout << "\t\tStarting DFS from " << key << "...\n\t";
        setAllNotVisited();
        DFS(getVertex(key));
    } else
        cout << "\tOps! That value doesn't exist in the graph. Try again!\n";
    cout << "\n\t----------------------------------------------------------------\n\n";
}

template<typename Type>
void Graph<Type>:: showBFS(Type key) {
    cout << "\t---------------------------- BFS -------------------------------\n";
    if (existsVertex(key)) {
        cout << "\t\tStarting BFS from " << key << "...\n\t";
        setAllNotVisited();
        BFS(getVertex(key));
    } else
        cout << "\tOps! That value doesn't exist in the graph. Try again!\n";
    cout << "\n\t----------------------------------------------------------------\n\n";
}

template<typename Type>
void Graph<Type>:: DFS(Vertex<Type> *vertex) {
    vertex->setVisited(true);
    cout << "\t" << vertex->getKey();
    for (int i = 0; i < vertex->getNeighbors()->getElements(); i++) {
        if (!vertex->getNeighbors()->getData(i)->getVisited()) {
            DFS(vertex->getNeighbors()->getData(i));
        }
    }
}

template<typename Type>
void Graph<Type>:: BFS(Vertex<Type> *vertex) {
    vertex->setVisited(true);
    cout << "\t" << vertex->getKey();
    for (int i = 0; i < adjList.getElements(); i++) {
        if (!adjList.getData(i)->getVisited()) {
            BFS(adjList.getData(i));
        }
    }
}

#endif //GRAPHTEMPLATES_GRAPH_H