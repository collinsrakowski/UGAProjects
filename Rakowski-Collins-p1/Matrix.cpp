#include <iostream>
#include "Matrix.h"

using namespace std;
typedef unsigned int uint;

Matrix::Matrix(uint rows, uint cols) {
    this -> r = rows;
    this -> c = cols;
    this -> array = new double*[rows];

    for (uint i = 0; i < rows; i++) {
        array[i] = new double[cols]; // Creates all the elements in the array
        for (uint j = 0; j < cols; j++) {
            array[i][j] = 0; // Sets each element in new array to zero
        }
    }
} // constructor

Matrix::Matrix(const Matrix & m) {
    r = m.r;
    c = m.c;
    array = new double* [m.r];
    for (int i = 0; i < m.r; i++) {
        array[i] = new double[m.c];
    } // for
    for (int j = 0; j < r; j++) {
        for (int k = 0; k < c; k++) {
            array[j][k] = m.array[j][k]; // Copies the array to the new array
        } // for
    } //for
} // cc

Matrix::~Matrix() {
    for (int i = 0; i < r; i++) {
        delete[] this -> array[i]; // deletes the pointers in the first dimension
    } // for
    delete[] this -> array; // deletes the array
} // deconstructor

Matrix Matrix :: add(double s) const {
    Matrix temp(r, c); // temporary array
    uint tempRow = this -> r;
    uint tempCol = this -> c;
    for (uint i = 0; i < tempRow; i++) { // both for loops iterate through the array
        for (uint j = 0; j < tempCol; j++) {
            temp.array[i][j] = array[i][j] + s; // adds the constant to each element in the array
        } // for
    } // for
    return temp;
} // scalar

Matrix Matrix :: add(const Matrix & m) const {
    Matrix temp(this -> r, this -> c); // creates temporary array
    for (uint i = 0; i < m.numRows(); i++) {
        for (uint j = 0; j < m.numCols(); j++) {
            temp.array[i][j] = array[i][j] + m.array[i][j]; // add elements of the arrays together
        } // for
    } // for
    return temp;
} // Adds two Matrix together

Matrix Matrix :: subtract(double s) const {
    Matrix temp(this -> r, this -> c); // creates temporary array
    for (int i = 0; i < this -> r; i++) {
        for (int j = 0; j < this -> c; j++) {
            temp.array[i][j] = array[i][j] - s; // substracts the scalar constant from the array
          } // for
    } // for
    return temp;
} // subtract scalar

Matrix Matrix :: subtract(const Matrix & m) const {
    Matrix temp(this -> r, this -> c); // creates temporary array
    for (uint i = 0; i < m.numRows(); i++) {
        for (uint j = 0; j < m.numCols(); j++) {
            temp.array[i][j] = array[i][j] - m.array[i][j]; // performing subtraction operation
        } // for
    } // for
    return temp;
} // subtract matrix by matrix

Matrix Matrix :: multiply(double s) const {
    Matrix temp(this -> r, this -> c); // creates temporary array
    for (int i = 0; i < this -> r; i++) {
        for (int j = 0; j < this -> c; j++) {
            temp.array[i][j] = array[i][j] * s; // multiplies each element by a scalar
        } // for
    } // for
    return temp;
} // multiple matrix by scalar

Matrix Matrix :: multiply(const Matrix & m) const { // how does is want us to multiply
    Matrix temp(r, m.numCols());
    for (int i = 0; i < r; i++) {
        for (uint j = 0; j < m.numCols(); j++) {
            double val = 0; // resetting value to 0
            for (int k = 0; k < c; k++) {
                val += array[i][k]*m.array[k][j]; // Performing Multiplication
            } // for
            temp.array[i][j] = val; // Saving values to the correct places
        } // for
    } // for
    return temp;
} // matrix times matrix

Matrix Matrix :: divide(double s) const {
    Matrix temp(this -> r, this -> c); // creates a temporary array
    for (int i = 0; i < this -> r; i++) {
        for (int j = 0; j < this -> c; j++) {
            temp.array[i][j] = array[i][j] / s; // divides each element by the scalar
        } // for
    } // for
    return temp;
} // divide by scalar

Matrix Matrix :: t() const {
    Matrix temp(c, r); // creates a temporary array
    for (int i = 0; i < this -> r; i++) {
        for (int j = 0; j < this -> c; j++) {
            temp.array[j][i] = array[i][j]; // flips the positions of the numbers in the array
        } // for
    } // for
    return temp;
} // transpose

const uint Matrix :: numRows() const {
    return this -> r; // returns rows in the matrix
}

const uint Matrix :: numCols() const {
    return this -> c; // returns colums in the matrix
}

double & Matrix :: at(uint row, uint col) {
    return array[row][col]; // returns the value at a particular position
}

const double & Matrix :: at(uint row, uint col) const {
    return array[row][col]; // returns the value at a particular position
}

void Matrix :: makeMat(const Matrix & m) {
    for (uint i = 0; i < m.numRows(); i++) {
        cout << "[ "; // setting the format
        for (uint j = 0; j < m.numCols(); j++) {
            cout << m.at(i , j) << " "; // printing the values in the matrix
        } // for
        cout << "]" << endl; // setting the format
    } // for
}
