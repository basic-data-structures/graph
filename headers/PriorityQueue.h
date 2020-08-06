#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>
#include "PriorityNode.h"

using namespace std;

template < typename Key, typename Priority >
class PriorityQueue {

private:
    PriorityNode<Key, Priority>* first;
    int elements;

public:
    PriorityQueue();
    ~PriorityQueue();
    int getElements();
    Key peekKey();
    Priority peekPriority();
    void enqueue(Key key, Priority priority);
    void dequeue();
    void show();
    bool empty();
};

///////////////////////////////////////////// IMPLEMENTATION /////////////////////////////////////////////

template < typename Key, typename Priority >
PriorityQueue<Key, Priority>:: PriorityQueue () {
    first = 0;
    elements = 0;
}

template < typename Key, typename Priority >
PriorityQueue<Key, Priority>:: ~PriorityQueue() {
    while (!empty())
        dequeue();
}


template < typename Key, typename Priority >
int PriorityQueue<Key, Priority>:: getElements() {
    return elements;
}


template < typename Key, typename Priority >
Key PriorityQueue<Key, Priority>:: peekKey() {
    return first->getData();
}


template < typename Key, typename Priority >
Priority PriorityQueue<Key, Priority>:: peekPriority() {
    return first->getPriority();
}


template < typename Key, typename Priority >
bool PriorityQueue<Key, Priority>:: empty() {
    return elements == 0;
}

template < typename Key, typename Priority >
void PriorityQueue<Key, Priority>:: enqueue(Key key, Priority priority) {
    PriorityNode<Key, Priority>* newNode = new PriorityNode<Key, Priority>(key, priority);
    if (empty())
        first = newNode;
    else if (priority < first->getPriority()) {
        newNode->setNext(first);
        first = newNode;
    }
    else { // priority >= aux->getPriority()
        PriorityNode<Key, Priority>* aux = first;
        while (aux->getNext() != 0 && priority >= aux->getNext()->getPriority()) {
            aux = aux->getNext();
        }
        newNode->setNext(aux->getNext());
        aux->setNext(newNode);
    }
    elements++;
}

template < typename Key, typename Priority >
void PriorityQueue<Key, Priority>:: dequeue() {
    if (!empty()) {
        PriorityNode<Key, Priority>* aux = first;
        first = first->getNext();
        delete aux;
        elements--;
    }
}


template < typename Key, typename Priority >
void PriorityQueue<Key, Priority>:: show() {
    if (!empty()) {
        PriorityNode<Key, Priority>* aux = first;
        cout << "\n\t==================== Priority Queue ====================\n";
        while (aux) {
            cout << "\tPriority: " << aux->getPriority() << "\tKey: " << aux->getData() << "\n";
            aux = aux->getNext();
        }
    }

}


#endif //PRIORITY_QUEUE_H