#ifndef GRAPHTEMPLATES_MATRIX_H
#define GRAPHTEMPLATES_MATRIX_H

#include <iostream>

using namespace std;

template <typename Type>
class Matrix {

private:
    Type** matrix;
    unsigned rows, cols;
    Type null;

public:
    Matrix();
    Matrix(unsigned squareSize, Type null);
    Matrix(unsigned rows, unsigned cols, Type null);
    Matrix(const Matrix& matrix);
    ~Matrix();
    Type getData(unsigned row, unsigned col);
    unsigned getRows();
    unsigned getCols();
    Type getNull();
    void setNull(Type null);
    void insert(Type data, unsigned row, unsigned col);
    void freeMatrixResources(Type** matrix);
    void resize(unsigned int rows, unsigned int cols);
    void assignNull(unsigned int beginRow, unsigned int endRow, unsigned int beginCol, unsigned int endCol);
    void copyData(Type** matrix, unsigned int beginRow, unsigned int endRow, unsigned int beginCol, unsigned int endCol);
    void printMatrix();
    Type& operator()(unsigned int row, unsigned int col); // To do matrix(i,j) = n
    Type operator()(unsigned int row, unsigned int col) const; // To do n = matrix(i,j)

    friend ostream& operator << (ostream& out, const Matrix<Type> &m) {
        for (int i = 0; i < m.rows; ++i) {
            out << "\t\t";
            for (int j = 0; j < m.cols; ++j) {
                out << m(i, j) << "\t";
            }
            out << "\n";
        }
        out << "\n";
        return out;
    }
};

///////////////////////////////////////////// IMPLEMENTATION /////////////////////////////////////////////
template <typename Type>
Type& Matrix<Type>:: operator()(unsigned int row, unsigned int col) {
    if(row < rows && col < cols)
        return matrix[row][col];
    else
        return null;
}

template <typename Type>
Type Matrix<Type>:: operator()(unsigned int row, unsigned int col) const {
    if(row < rows && col < cols)
        return matrix[row][col];
    else
        return null;
}

template <typename Type>
Matrix<Type>:: Matrix() {
    matrix = 0;
    rows = 0;
    cols = 0;
    null = 0;
}

template <typename Type>
Matrix<Type>:: Matrix(unsigned size, Type null) {
    matrix = new Type*[size];
    for (int i = 0; i < size; ++i)
        matrix[i] = new Type[size];
    this->rows = size;
    this->cols = size;
    this->null = null;
    assignNull(0, size, 0, size);
}

template <typename Type>
Matrix<Type>:: Matrix(unsigned rows, unsigned cols, Type null) {
    matrix = new Type*[rows];
    for (int i = 0; i < rows; ++i)
        matrix[i] = new Type[cols];
    this->rows = rows;
    this->cols = cols;
    this->null = null;
    assignNull(0, rows, 0, cols);
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
    if (row < rows && col < cols)
        return matrix[row][col];
    else
        return null;
}

template <typename Type>
unsigned Matrix<Type>:: getRows() {
    return rows;
}

template <typename Type>
unsigned Matrix<Type>:: getCols() {
    return cols;
}

template <typename Type>
Type Matrix<Type>:: getNull() {
    return null;
}

template <typename Type>
void Matrix<Type>:: setNull(Type null) {
    this->null = null;
}

template <typename Type>
void Matrix<Type>:: insert(Type data, unsigned int row, unsigned int col) {
    matrix[row][col] = data;
}

template <typename Type>
void Matrix<Type>:: freeMatrixResources(Type** matrix) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

template <typename Type>
void Matrix<Type>:: resize(unsigned int rows, unsigned int cols) {

    if (this->rows != rows && this->cols != cols) {
        Type** aux = matrix;
        matrix = new Type*[rows];
        for (int i = 0; i < rows; ++i)
            matrix[i] = new Type[cols];

        if (this->rows < rows && this->cols < cols) {
            copyData(aux, 0, this->rows, 0, this->cols);
            assignNull(this->rows, rows, 0, cols);
            assignNull(0, rows, this->cols, cols);
        }
        else if (this->rows < rows) {
            copyData(aux, 0, this->rows, 0, cols);
            assignNull(0, this->rows, this->cols, cols);
        }
        else if (this->cols < cols) {
            copyData(aux, 0, rows, 0, this->cols);
            assignNull(this->rows, rows, 0, this->cols);
        }
        else
            copyData(aux, 0, rows, 0, cols);

        freeMatrixResources(aux);
        this->rows = rows;
        this->cols = cols;
    }
}

template <typename Type>
void Matrix<Type>:: assignNull(unsigned int beginRow, unsigned int endRow, unsigned int beginCol, unsigned int endCol) {
    if (beginRow < endRow < rows && beginCol < endCol < rows) {
        for (int i = beginRow; i < endRow; ++i) {
            for (int j = beginCol; j < endCol; ++j) {
                matrix[i][j] = null;
            }
        }
    }
}

template <typename Type>
void Matrix<Type>:: copyData(Type** matrix, unsigned int beginRow, unsigned int endRow, unsigned int beginCol, unsigned int endCol) {
    if (beginRow < endRow < rows && beginCol < endCol < rows) {
        for (int i = beginRow; i < endRow; ++i) {
            for (int j = beginCol; j < endCol; ++j) {
                this->matrix[i][j] = matrix[i][j];
            }
        }
    }
}

template <typename Type>
void Matrix<Type>:: printMatrix() {
    if (rows > 0 && cols > 0) {
        for (int i = 0; i < rows; ++i) {
            cout << "\t\t";
            for (int j = 0; j < cols; ++j) {
                cout << matrix[i][j] << "\t";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

#endif //GRAPHTEMPLATES_MATRIX_H