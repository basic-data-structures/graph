#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include <iostream>

using namespace std;

template < typename Type >
class List {

    private:
        Node<Type>* first;
        int elements;

    public:
        List();
        ~List();

        Type getData(int pos);
        bool existsData(Type key);
        int getElements();
        Node<Type>* getNode(Type key);
        void insertIn(Type key, int pos);
        void insertAtEnd(Type key);
        void insertAtBeginning(Type key);
        void remove(int pos);
        bool empty();
        void printData();
        void listElements();

    private:
        Node<Type>* getNode(int pos);
};

///////////////////////////////////////////// IMPLEMENTATION /////////////////////////////////////////////
template < typename Type >
List<Type>:: List () {
    first = 0;
    elements = 0;
}
template < typename Type >
List<Type>:: ~List() {
    while (!empty())
        remove(0);
}

template < typename Type >
Type List<Type>:: getData(int pos) {
    return getNode(pos)->getData();
}

template < typename Type >
bool List<Type>:: existsData(Type data) {
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
int List<Type>:: getElements() {
    return elements;
}

template < typename Type >
Node<Type>* List<Type>:: getNode(int pos) {
    Node<Type> *aux = first;
    int i = 0;
    while (i < pos) {
        aux = aux->getNext();
        i++;
    }
    return aux;
}

template < typename Type >
Node<Type>* List<Type>:: getNode(Type key) {
    Node<Type> *aux = 0;
    if (existsData(key)) {
        aux = first;
        while (aux->getData() != key) {
            aux = aux->getNext();
        }
    }
    return aux;
}

template < typename Type >
bool List<Type>:: empty() {
    return first == 0;
}

template < typename Type >
void List<Type>:: insertAtEnd(Type key) {
    insertIn(key, elements);
}

template < typename Type >
void List<Type>:: insertAtBeginning(Type key) {
    insertIn(key, 0);
}

template < typename Type >
void List<Type>:: insertIn(Type key, int pos) {
    Node<Type>* newNode = new Node<Type>(key);

    if (pos == 0) {
        newNode->setNext(first);
        first = newNode;
    }
    else {
        Node<Type>* previous = getNode(pos - 1);
        newNode->setNext(previous->getNext());
        previous->setNext(newNode);
    }
    elements++;
}

template < typename Type >
void List<Type>:: remove(int pos) {
    Node<Type>* erase = first;

    if (pos == 0) {
        first = erase->getNext();
    }

    else {
        Node<Type>* previous = getNode(pos - 1);
        erase = previous->getNext();
        previous->setNext(erase->getNext());
    }
    delete erase;
    elements--;
}

template < typename Type >
void List<Type>:: printData() {
    if (!empty()) {
        for (int i = 0; i < elements; i++) {
            getNode(i)->mostrarType();
        }
    }
}

template < typename Type >
void List<Type>:: listElements() {
    cout << "\n";
    for (int i = 0; i <= elements; i++) {
        cout << "\t" << i << ". " << getData(i) << "\n";
    }
    cout << "\n";
}

#endif //LIST_H