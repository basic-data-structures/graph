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
        int getPosition(Type key);
        int getElements();
        void insertIn(Type key, int pos);
        void insertAtEnd(Type key);
        void insertAtBeginning(Type key);
        void remove(int pos);
        bool empty();
        void printData();
        void listElements();
        Node<Type>* getNodeFrom(int pos);
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
    return getNodeFrom(pos)->getData();
}

template < typename Type >
int List<Type>:: getPosition(Type key) {
    for (int i = 0; i < elements; i++) {
        if (getData(i) == key)
            return i;
    }
    cout << "\tThe key '" << key << "' doesn't exist in the list!\n";
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
Node<Type>* List<Type>:: getNodeFrom(int pos) {
    Node<Type> *aux = first;
    int i = 0;
    while (i < pos) {
        aux = aux->getNext();
        i++;
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
        Node<Type>* previous = getNodeFrom(pos - 1);
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
        Node<Type>* previous = getNodeFrom(pos - 1);
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
            getNodeFrom(i)->printData();
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