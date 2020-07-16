#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include "Node.h"
#include <iostream>

using namespace std;

template < typename Type >
class Queue {

private:
    Node<Type>* first;
    Node<Type>* last;
    int elements;

public:
    Queue();
    ~Queue();
    Type getData(int pos);
    bool existsData(Type key);
    int getElements();
    void enqueue(Type key);
    void dequeue();
    bool empty();
    void printData();
    void showElements();

private:
    Node<Type>* getNode(int pos);
};

///////////////////////////////////////////// IMPLEMENTATION /////////////////////////////////////////////
template < typename Type >
Queue<Type>:: Queue () {
    first = 0;
    last = 0;
    elements = 0;
}
template < typename Type >
Queue<Type>:: ~Queue() {
    while (!empty())
        dequeue();
}

template < typename Type >
Type Queue<Type>:: getData(int pos) {
    return getNode(pos)->getData();
}

template < typename Type >
bool Queue<Type>:: existsData(Type data) {
    bool found = false;
    int i = 0;
    while((i < elements) && !found) {
        if(data == getData(i)) {
            found = true;
        }
        i++;
    }
    return found;
}

template < typename Type >
int Queue<Type>:: getElements() {
    return elements;
}

template < typename Type >
Node<Type>* Queue<Type>:: getNode(int pos) {
    Node<Type> *aux = first;
    int i = 0;
    while (i < pos) {
        aux = aux->getNext();
        i++;
    }
    return aux;
}

template < typename Type >
bool Queue<Type>:: empty() {
    return elements == 0;
}

template < typename Type >
void Queue<Type>:: enqueue(Type key) {
    Node<Type>* newNode = new Node<Type>(key);
    cout << "\tQueueing " << key << " in " << newNode << "...\n";
    if (empty())
        first = newNode;
    else
        last->setNext(newNode);
    last = newNode;
    elements++;
}

template < typename Type >
void Queue<Type>:: dequeue() {
    if (!empty()) {
        cout << "\tDequeueing " << first->getData() << " from " << first << "...\n";
        Node<Type>* aux = first;
        if (first == last)
            first = last = 0;
        else
            first = first->getNext();
        delete aux;
        elements--;
    }
}

template < typename Type >
void Queue<Type>:: printData() {
    if (!empty()) {
        for (int i = 0; i < elements; i++) {
            getNode(i)->printData();
        }
    }
}

template < typename Type >
void Queue<Type>:: showElements() {
    cout << "\n";
    for (int i = 0; i < elements; i++) {
        cout << "\t" << i << ". " << getData(i) << "\n";
    }
    cout << "\n";
}
#endif //QUEUE_QUEUE_H