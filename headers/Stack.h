#ifndef STACK_H
#define STACK_H

#include "Node.h"

using namespace std;

template < typename Type >
class Stack {

private:
    Node<Type>* last;
    int elements;

public:
    Stack();
    ~Stack();
    int getElements();
    Type peek();
    void push(Type key);
    void pop();
    bool empty();
};

///////////////////////////////////////////// IMPLEMENTATION /////////////////////////////////////////////
template < typename Type >
Stack<Type>:: Stack () {
    last = 0;
    elements = 0;
}
template < typename Type >
Stack<Type>:: ~Stack() {
    while (!empty())
        pop();
}

template < typename Type >
int Stack<Type>:: getElements() {
    return elements;
}

template < typename Type >
Type Stack<Type>:: peek() {
    if (!empty())
        return last->getData();
}

template < typename Type >
void Stack<Type>:: push(Type key) {
    Node<Type>* newNode = new Node<Type>(key);
    newNode->setNext(last);
    last = newNode;
    elements++;
}

template < typename Type >
void Stack<Type>:: pop() {
    if (!empty()) {
        Node<Type>* aux = last;
        last = last->getNext();
        delete aux;
        elements--;
    }
}

template < typename Type >
bool Stack<Type>:: empty() {
    return elements == 0;
}

#endif //STACK_H