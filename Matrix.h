#ifndef GRAPHTEMPLATES_MATRIX_H
#define GRAPHTEMPLATES_MATRIX_H

#include "Vector.h"

template <typename Type>
class Matrix {

private:
    Type** matrix;
    unsigned size;
    Type null = null;

public:
    Matrix(unsigned size, Type null);
    ~Matrix();
    Type getData(unsigned row, unsigned col);
    void insert(Type data, unsigned row, unsigned col);
    void freeMatrixResources(Type** matrix);
    void resize(unsigned size);
    void assignNull(unsigned int beginRow, unsigned int endRow, unsigned int beginCol, unsigned int endCol);
    void copyData(Type** matrix, unsigned begin, unsigned end);
    void printMatrix();
};

template <typename Type>
Matrix<Type>:: Matrix(unsigned size, Type null) {
    matrix = new Type*[size];
    for (int i = 0; i < size; ++i)
        matrix[i] = new Type[size];
    this->size = size;
    this->null = null;
    assignNull(0, size, 0, size);
}

template <typename Type>
Matrix<Type>:: ~Matrix() {
    freeMatrixResources(matrix);
}

template <typename Type>
Type Matrix<Type>:: getData(unsigned row, unsigned col) {
    return matrix[row][col];
}

template <typename Type>
void Matrix<Type>:: insert(Type data, unsigned int row, unsigned int col) {
    matrix[row][col] = data;
}

template <typename Type>
void Matrix<Type>:: freeMatrixResources(Type** matrix) {
    for (int i = 0; i < size; ++i) {
        delete [] matrix[i];
    }
    delete [] matrix;
}

template <typename Type>
void Matrix<Type>:: resize(unsigned int newSize) {
    if (this->size != newSize) {

        Type** aux = matrix;
        matrix = new Type*[newSize];
        for (int i = 0; i < newSize; ++i)
            matrix[i] = new Type[newSize];

        if (this->size < newSize) {
            copyData(aux, 0, this->size);
            assignNull(this->size, newSize, 0, newSize);
            assignNull(0, newSize, this->size, newSize);
        }
        else
            copyData(aux, 0, newSize);

        freeMatrixResources(aux);
        this->size = newSize;
    }
}

template <typename Type>
void Matrix<Type>:: assignNull(unsigned int beginRow, unsigned int endRow, unsigned int beginCol, unsigned int endCol) {
    for (int i = beginRow; i < endRow; ++i) {
        for (int j = beginCol; j < endCol; ++j) {
            matrix[i][j] = null;
        }
    }
}

template <typename Type>
void Matrix<Type>:: copyData(Type** matrix, unsigned int begin, unsigned int end) {
    for (int i = begin; i < end; ++i) {
        for (int j = begin; j < end; ++j) {
            this->matrix[i][j] = matrix[i][j];
        }
    }
}

template <typename Type>
void Matrix<Type>:: printMatrix() {
    for (int i = 0; i < size; ++i) {
        cout << "\t";
        for (int j = 0; j < size; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

#endif //GRAPHTEMPLATES_MATRIX_H