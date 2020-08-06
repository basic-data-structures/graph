#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include "Node.h"

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
    int getElements();
    Type peek();
    void enqueue(Type key);
    void dequeue();
    bool empty();
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
int Queue<Type>:: getElements() {
    return elements;
}

template < typename Type >
Type Queue<Type>:: peek() {
    return first->getData();
}

template < typename Type >
void Queue<Type>:: enqueue(Type key) {
    Node<Type>* newNode = new Node<Type>(key);
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
bool Queue<Type>:: empty() {
    return elements == 0;
}

#endif //QUEUE_QUEUE_H