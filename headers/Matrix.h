#ifndef GRAPHTEMPLATES_MATRIX_H
#define GRAPHTEMPLATES_MATRIX_H

#include <iostream>

using namespace std;

template <typename Type>
class Matrix {

private:
    Type** matrix;
    unsigned size;
    Type null;

public:
    Matrix();
    Matrix(unsigned size, Type null);
    Matrix(const Matrix& matrix);
    ~Matrix();
    Type getData(unsigned row, unsigned col);
    void insert(Type data, unsigned row, unsigned col);
    void freeMatrixResources(Type** matrix);
    void resize(unsigned size);
    void assignNull(unsigned int beginRow, unsigned int endRow, unsigned int beginCol, unsigned int endCol);
    void copyData(Type** matrix, unsigned begin, unsigned end);
    void printMatrix();
    Type operator()(unsigned int row, unsigned int col);
    friend ostream& operator << (ostream& o, const Matrix<Type> &m);
};

///////////////////////////////////////////// IMPLEMENTATION /////////////////////////////////////////////
template <typename Type>
ostream& operator << (ostream& out, const Matrix<Type> &m) {
    for (int i = 0; i < m.size; ++i) {
        out << "\t\t";
        for (int j = 0; j < m.size; ++j) {
            out << m.getData(i, j) << "\t";
        }
        out << "\n";
    }
    out << "\n";
    return out;
}

template <typename Type>
Type Matrix<Type>:: operator()(unsigned int row, unsigned int col) {
    return matrix[row][col];
}

template <typename Type>
Matrix<Type>:: Matrix() {
    matrix = 0;
    size = 0;
    null = 0;
}

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
Matrix<Type>:: Matrix(const Matrix<Type> &matrix) {
    this->matrix = new Type*[matrix.size];
    for (int i = 0; i < matrix.size; ++i)
        matrix[i] = new Type[matrix.size];
    copyData(matrix,0,0);
}

template <typename Type>
Matrix<Type>:: ~Matrix() {
    freeMatrixResources(matrix);
}

template <typename Type>
Type Matrix<Type>:: getData(unsigned row, unsigned col) {
    if (row < size && col < size)
        return matrix[row][col];
    else
        return null;
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
        cout << "\t\t";
        for (int j = 0; j < size; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

#endif //GRAPHTEMPLATES_MATRIX_H