#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template < typename Type >
class Node {

    private:
        Type data;
        Node* pNext;

    public:

        Node(Type data);
        ~Node();

        // Setters
        void setNext(Node* pNextOut);
        void setData(Type data);

        // Getters
        Type getData();
        Node* getNext();

        void printData();
};

///////////////////////////////////////////// IMPLEMENTATION /////////////////////////////////////////////
template < typename Type >
Node<Type>:: Node(Type data) {
    this->data = data;
    pNext = 0;
}
template < typename Type >
Node<Type>:: ~Node<Type>() {
    delete data;
}

template < typename Type >
void Node<Type>:: setNext(Node<Type>* pNextOut) {
    pNext = pNextOut;
}

template < typename Type >
Node<Type>* Node<Type>:: getNext() {
    return pNext;
}

template < typename Type >
void Node<Type>:: setData(Type data) {
    this->data = data;
}

template < typename Type >
Type Node<Type>:: getData() {
    return data;
}

template < typename Type >
void Node<Type>:: printData() {
    cout << "\t--------------------------------------------------------------------------\n";
    cout << "\tNode ->   Type: " << data << "   Address: " << this << "   Next: " << pNext << "\n";
    cout << "\t--------------------------------------------------------------------------\n\n";
}

#endif //NODE_H