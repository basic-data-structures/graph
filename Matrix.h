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
    void freeMatrixResources();
    void insert(Type data, unsigned row, unsigned col);
    Type getData(unsigned row, unsigned col);
    void printMatrix();
};

template <typename Type>
Matrix<Type>:: Matrix(unsigned size, Type null) {
    matrix = new Type*[size];
    for (int i = 0; i < size; ++i) {
        matrix[i] = new Type[size];
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = null;
        }
    }
    this->size = size;
    this->null = null;
}

template <typename Type>
Matrix<Type>:: ~Matrix() {
    freeMatrixResources();
}

template <typename Type>
void Matrix<Type>:: freeMatrixResources() {
    for (int i = 0; i < size; ++i) {
        delete [] matrix[i];
    }
    delete [] matrix;
}

template <typename Type>
void Matrix<Type>:: insert(Type data, unsigned int row, unsigned int col) {
    matrix[row][col] = data;
}

template <typename Type>
Type Matrix<Type>:: getData(unsigned row, unsigned col) {
    return matrix[row][col];
}

template <typename Type>
void Matrix<Type>:: printMatrix() {
    for (int i = 0; i < size; ++i) {
        cout << "\t";
        for (int j = 0; j < size; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

#endif //GRAPHTEMPLATES_MATRIX_H