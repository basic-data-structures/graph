#ifndef GRAPHTEMPLATES_GRAPH_H
#define GRAPHTEMPLATES_GRAPH_H

#include "Matrix.h"
#include "List.h"
#include "Queue.h"

template <typename Type, typename Cost>
struct ShortestPath{
    Matrix<Cost>* weights;
    Matrix<Type>* paths;
};

template <typename Type, typename Cost>
class Graph {

    private:
        Matrix<Cost>* costsMatrix;
        List<Type>* vertices;
        Type null;
        Cost infinity;
        int elements;

    public:

        //  PRE: -
        // POST: Creates a graph with elements = 0, vertices and costMatrix pointing to NULL
        Graph();

        //  PRE: -
        // POST: Creates a graph with an edge connecting begin and end
        Graph(Type begin, Type end, Cost cost, Type null, Cost infinity);

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
        Cost getCost(Type begin, Type end);

        // PRE: -
        // POST: Prints matrix on screen
        void showMatrix();

        //  PRE: -
        // POST: Depth First Search all the vertices of the graph starting from the key given.
        //       If the key doesn't exist in the graph, a message is printed on the screen.
        void showDFS(Type key);

        //  PRE: -
        // POST: Breadth First Search all the vertices of the graph starting from the key given.
        //       If the key doesn't exist in the graph, a message is printed on the screen.
        void showBFS(Type key);

        //  PRE: -
        // POST: Finds the shortest paths from begin to every vertex in the graph, then calls
        //       showMinDistances to print the results on the screen.
        void showShortestPath(Type begin, Type end);

private:

    //  PRE: -
    // POST: Returns the matrix with the min weight from every origin node to every destination node
    ShortestPath<Type, Cost> findShortestPath();

    //  PRE: -
    // POST: Depth First Search all the vertices of the graph starting from begin.
    //       If the key doesn't exist in the graph, a message is printed on the screen.
    void DFS(Type begin, bool visited[]);

    //  PRE: -
    // POST: Breadth First Search all the vertices of the graph starting from begin.
    //       If the key doesn't exist in the graph, a message is printed on the screen.
    void BFS(Type begin);
};

///////////////////////////////////////////// IMPLEMENTATION /////////////////////////////////////////////
template<typename Type, typename Cost>
Graph<Type, Cost>:: Graph() {
    costsMatrix = 0;
    vertices = 0;
    elements = 0;
    null = 0;
    infinity = 999999;
}

template<typename Type, typename Cost>
Graph<Type, Cost>:: Graph(Type begin, Type end, Cost cost, Type null, Cost infinity) {
    elements = 0;
    this->infinity = infinity;
    this->null = null;
    vertices = new List<Type>;
    costsMatrix = new Matrix<Cost>(elements, infinity);
    addEdge(begin, end, cost);
}

template<typename Type, typename Cost>
Graph<Type, Cost>:: ~Graph() {
    delete costsMatrix;
    delete vertices;
}

template<typename Type, typename Cost>
Cost Graph<Type, Cost>:: getCost(Type begin, Type end) {
    Cost cost = infinity;
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
            costsMatrix->insert(cost, vertices->getPosition(begin), vertices->getPosition(end));
            elements += 2;
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
    bool exists = false;
    if (existsVertex(begin) && existsVertex(end)) {
        if (costsMatrix->getData(vertices->getPosition(begin), vertices->getPosition(end)) < infinity)
            exists = true;
    }
    return exists;
}

template<typename Type, typename Cost>
void Graph<Type, Cost>:: showDFS(Type key) {
    cout << "\t---------------------------- DFS -------------------------------\n";
    if (existsVertex(key)) {
        cout << "\t\tStarting DFS from " << key << "...\n\t";
        bool visited[elements];
        for (int i = 0; i < elements; ++i)
            visited[i] = false;
        DFS(key, visited);
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
void Graph<Type, Cost>:: showShortestPath(Type begin, Type end) {

    if (existsVertex(begin) && existsVertex(end)) {

        ShortestPath<Type, Cost> shortestPath = findShortestPath();
        int begPos = vertices->getPosition(begin), endPos = vertices->getPosition(end);
        int minCost = shortestPath.weights->getData(begPos, endPos), i = 1;

        if (minCost < infinity) {
            cout << "\n\n\tThe shortest path from " << begin << " to " << end << " weights " << minCost;
            if (shortestPath.paths->getData(begPos, endPos) != end)
                cout << "\n\t  To get there, you'll need to go through:";
            else
                cout << "\n\t  There are no connections needed!";
            while (shortestPath.paths->getData(begPos, endPos) != end) {
                cout << "\n\t\t" << i << ". " << shortestPath.paths->getData(begPos, endPos);
                begPos = vertices->getPosition(shortestPath.paths->getData(begPos, endPos));
                i++;
            }
        }
        else
            cout << "\n\tThere's no path from " << begin << " to " << end << "\n";

        delete shortestPath.paths;
        delete shortestPath.weights;
    }
    else
        cout << "\tOrigin or destination vertex doesn't exist\n";
}

template<typename Type, typename Cost>
ShortestPath<Type, Cost> Graph<Type, Cost>::findShortestPath() {
    ShortestPath<Type, Cost> shortestPath;
    shortestPath.weights = new Matrix<Cost>(elements, infinity);
    shortestPath.paths = new Matrix<Type>(elements, null);

    for (int i = 0; i < elements; ++i) {
        for (int j = 0; j < elements; ++j) {
            if (i != j) {
                shortestPath.weights->insert(costsMatrix->getData(i, j), i, j);
                shortestPath.paths->insert(vertices->getData(j), i, j);
            }
        }
    }

    for(int k = 0; k < elements; k++) {
        for (int i = 0; i < elements; i++) {
            for (int j = 0; j < elements; j++) {
                Cost distance = shortestPath.weights->getData(i, k) + shortestPath.weights->getData(k, j);
                if (i != j && distance < shortestPath.weights->getData(i, j)) {
                    shortestPath.weights->insert(distance, i, j);
                    shortestPath.paths->insert(vertices->getData(k), i, j);
                }
            }
        }
    }
    return shortestPath;
}

template<typename Type, typename Cost>
void Graph<Type, Cost>:: DFS(Type begin, bool visited[]) {
    int begPos = vertices->getPosition(begin);
    visited[begPos] = true;
    cout << "\t" << begin;
    for (int i = 0; i < elements; ++i) {
        if (costsMatrix->getData(begPos, i) != infinity && !visited[i])
            DFS(vertices->getData(i), visited);
    }
}

template<typename Type, typename Cost>
void Graph<Type, Cost>:: BFS(Type begin) {

    Queue<int> queue;
    bool visited[elements];
    Type current;
    int currentPos = vertices->getPosition(begin);

    for (int i = 0; i < elements; ++i)
        visited[i] = false;
    queue.enqueue(currentPos);
    visited[currentPos] = true;

    while (!queue.empty()) {
        currentPos = queue.peek();
        current = vertices->getData(currentPos);
        cout << "\t" << current;
        queue.dequeue();
        for (int i = 0; i < elements; ++i) {
            if (costsMatrix->getData(currentPos, i) != infinity && !visited[i]) {
                queue.enqueue(i);
                visited[i] = true;
            }
        }
    }
}

#endif //GRAPHTEMPLATES_GRAPH_H