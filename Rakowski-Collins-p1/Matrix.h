#ifndef MATRIX_H
#define MATRIX_H

typedef unsigned int uint;

class Matrix {

private:
    int r;
    int c;
    double** array;

public:

/**
 * Constructor (all elements initialized to 0).
 *
 * @param rows the number of rows the matrix is given
 * @param cols the number of cols the matrix is given
 */
    Matrix(uint rows, uint cols);

/**
 * Copy Constructor function creates a copy of the constructor.
 *
 * @param m the matrix that is being copied
 */
    Matrix(const Matrix & m);

/**
 * Destructor deallocates memory.
 */
    ~Matrix();

/**
 * Adds scalar value to any matrix.
 *
 * @param s the scalar value
 * @return temp the matrix after the addition of the scalar
 */
    Matrix add(double s) const;
/**
 * Adds two matrix of the same dimensions together.
 *
 * @param m the matrix that is being added to the initial matrix
 * @return temp the matrix after the addition of the matrices
 */
    Matrix add(const Matrix & m) const;

/**
 * Substracts a scalar value to every value in a matrix.
 *
 * @param s the scalar value being subtracted
 * @return temp the matrix after the scalar has been subtracted from the matrices
 */
    Matrix subtract(double s) const;

/**
 * Subtracts a matrix from a matrix of the same dimensions.
 *
 * @param m the matrix that is being substracted to the initial matrix
 * @return temp the matrix after the subtraction of the matrices
 */
    Matrix subtract(const Matrix & m) const;

/**
 * Multiplies the matrix by a scalar value.
 *
 * @param s the scalar value that is being multiplied to the matrix
 * @return temp the matrix after the scalar has been multiplied to the matrix
 */
    Matrix multiply(double s) const;

/**
 * Multiplies the matrix by another compatible matrix.
 *
 * @param m the matrix that is being multiplied by another matrix of a compatible dimenstions
 * @return temp the matrix after the matrices have been multiplied together
 */
    Matrix multiply(const Matrix & m) const;

/**
 * Divides the matrix by a scalar value.
 *
 * @param s the scalar value that is being divided into the matrix
 * @return temp the matrix after the scalar has been divided into the matrix
 */
    Matrix divide(double s) const;

/**
 * Tranposes the rows and columns.
 *
 * @return temp the array after transposition has taken place
 */
    Matrix t() const;

/**
 * Returns the number of rows in the matrix.
 *
 * @return r the number of rows in the matrix
 */
    const uint numRows() const;

/**
 * Returns the number of columns in the matrix.
 *
 * @return c the number of columns in the matrix
 */
    const uint numCols() const;

/**
 * Get/Set element at the row and column value in the matrix.
 *
 * @return array[row][col] the value in the row and col stored in the matrix
 */
    double & at(uint row, uint col);

/**
 * Get element at the row and column value in the matrix.
 *
 * @return array[row][col] the value in the row and col stored in the matrix
 */
    const double & at (uint row, uint col) const;

/**
 * Prints matrix in matrix format.
 *
 * @param m the matrix in which the print method derives the values from
 */
    void makeMat(const Matrix & m);

}; // Matrix

#endif
