#ifndef GRAPHTEMPLATES_VECTOR_H
#define GRAPHTEMPLATES_VECTOR_H

#include <iostream>
using namespace std;

template<typename Type>
class Vector {

    private:
        unsigned size;
        Type* data;
        Type null;

    public:
        // PRE: -
        // POST: Sets size and data = 0
        Vector(Type null);

        // PRE: length > 1
        // POST: Builds a length
        Vector(unsigned length, Type null);

        // PRE: -
        // POST: -
        Vector(const Vector& vec);

        // PRE: -
        // POST: Free memory from length
        ~Vector();

        // PRE: 0 <= pos < size
        // POST: Inserts d in vector[pos]
        void insert(Type data, unsigned pos);

        // PRE: -
        // POST: Assign null to vector[pos]
        void remove(unsigned pos);

        // PRE: -
        // POST: Returns the position in which the data is stored
        unsigned getPosition(Type data);

        // PRE: -
        // POST: Returns vector's size
        unsigned getVectorSize();

        // PRE: 0 <= pos < size
        // POST: Returns data in vector[pos]
        Type getElement(unsigned pos);

        // PRE: lenght > 1
        // POST: if lenght > size lo agranda conservando los data anteriores y agregando vacios
        //       if lenght < size lo achica y se pierden los data que exceden
        //       if lenght = size nothing
        void resize(unsigned lenght);

        // PRE: -
        // POST: Prints vector on screen
        void printVector();

    private:
        // Coloca valores nulos al vector en las posiciones indicadas
        // PRE: 0 <= begin <= end <= longitud del vector
        // POST: en data coloca nulos desde d hasta h inclusive
        void assignNull(unsigned begin, unsigned end);

        // Copia los data del vector pasado por parametro desde d hasta h
        // PRE: 0 <= begin <= end <= longitud del vector
        // POST: en data coloca los valores del vector
        void copyData(Type* vec, unsigned begin, unsigned end);
};

template<typename Type>
Vector<Type>:: Vector(Type null) : size(0), data(0), null(null) {}

template<typename Type>
Vector<Type>:: Vector(unsigned size, Type null) {
    this->size = size;
    this->null = null;
    data = new Type[size];
    assignNull(0, size);
}

template<typename Type>
Vector<Type>:: Vector(const Vector& vec) {
    size = vec.size;
    if (size > 0) {
        data = new Type[size];
        copyData(vec.data, 0, size);
    } else data = 0;
}

template<typename Type>
Vector<Type>:: ~Vector() {
    if (size > 0)
        delete [] data;
}

template<typename Type>
void Vector<Type>:: insert(Type data, unsigned pos) {
    this->data[pos] = data;
}

template<typename Type>
void Vector<Type>:: remove(unsigned pos) {
    data[pos] = null;
}

template<typename Type>
unsigned Vector<Type>:: getPosition(Type data) {
    unsigned pos = null;
    for (int i = 0; i < size; i++) {
        if (getElement(i) == data)
            pos = i;
    }
    return pos;
}

template<typename Type>
unsigned Vector<Type>:: getVectorSize() {
    return size;
}

template<typename Type>
Type Vector<Type>:: getElement(unsigned pos) {
    return data[pos];
}

template<typename Type>
void Vector<Type>:: resize(unsigned newSize) {
    if (this->size != newSize) {
        Type* aux = data;
        data = new Type[newSize];
        cout << "\tBEFORE -- Begin: " << 0 << "\tEnd: " << newSize << "\tSize: " << this->size << "\n";
        copyData(aux, 0, size);
        delete []aux;
        if (this->size < newSize)
            assignNull(this->size, newSize);
        this->size = newSize;
        cout << "\tAFTER -- Begin: " << 0 << "\tEnd: " << newSize << "\tSize: " << this->size << "\n";
    }
}

template<typename Type>
void Vector<Type>:: printVector() {
    for (unsigned i = 0; i < size; i++)
        cout << data[i] << " ";
}

template<typename Type>
void Vector<Type>:: assignNull(unsigned begin, unsigned end) {
    for (unsigned i = begin; i < end; i++)
        data[i] = null;
}

template<typename Type>
void Vector<Type>:: copyData(Type* vec, unsigned begin, unsigned end) {
    if (begin < end) {
        for (unsigned i = begin; i < end; i++)
            data[i] = vec[i];
    }
}

#endif //GRAPHTEMPLATES_VECTOR_H