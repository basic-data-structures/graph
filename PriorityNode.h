#ifndef PRIORITY_NODE_H
#define PRIORITY_NODE_H

#include <iostream>

using namespace std;

template < typename Key, typename Priority >
class PriorityNode {

private:
    Key data;
    Priority priority;
    PriorityNode* pNext;

public:

    PriorityNode(Key data, Priority priority);

    // Setters
    void setData(Key data);
    void setPriority(Priority priority);
    void setNext(PriorityNode* pNextOut);

    // Getters
    Key getData();
    Priority getPriority();
    PriorityNode* getNext();

    void printData();
};

///////////////////////////////////////////// IMPLEMENTATION /////////////////////////////////////////////
template < typename Key, typename Priority >
PriorityNode<Key, Priority>:: PriorityNode(Key data, Priority priority) {
    this->data = data;
    this->priority = priority;
    pNext = 0;
}

template < typename Key, typename Priority >
void PriorityNode<Key, Priority>:: setNext(PriorityNode<Key, Priority>* pNextOut) {
    pNext = pNextOut;
}

template < typename Key, typename Priority >
PriorityNode<Key, Priority>* PriorityNode<Key, Priority>:: getNext() {
    return pNext;
}

template < typename Key, typename Priority >
void PriorityNode<Key, Priority>:: setData(Key data) {
    this->data = data;
}

template < typename Key, typename Priority >
Key PriorityNode<Key, Priority>:: getData() {
    return data;
}

template < typename Key, typename Priority >
void PriorityNode<Key, Priority>:: setPriority(Priority priority) {
    this->priority = priority;
}

template < typename Key, typename Priority >
Priority PriorityNode<Key, Priority>:: getPriority() {
    return priority;
}

template < typename Key, typename Priority >
void PriorityNode<Key, Priority>:: printData() {
    cout << "\t--------------------------------------------------------------------------\n";
    cout << "\tNode ->   Type: " << data << "   Address: " << this << "   Next: " << pNext << "\n";
    cout << "\t--------------------------------------------------------------------------\n\n";
}

#endif //PRIORITY_NODE_H