// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// function to display matrix nicely
void printMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// function to input matrix elements
void inputMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// PART A - transpose matrix
void transposeMatrix(int matrix[10][10], int rows, int cols)
{
    int transposed[10][10];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transposed[j][i] = matrix[i][j];
        }
    }

    cout << "\nTransposed Matrix:" << endl;
    printMatrix(transposed, cols, rows);
}

// PART B - add two matrices
void addMatrices(int A[10][10], int B[10][10], int rows, int cols)
{
    int result[10][10];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "\nSum of Matrices:" << endl;
    printMatrix(result, rows, cols);
}

// PART C - multiply two matrices
void multiplyMatrices(int A[10][10], int B[10][10], int rowsA, int colsA, int colsB)
{
    int result[10][10];

    // initialize result matrix with zeros first
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nProduct Matrix (A x B):" << endl;
    printMatrix(result, rowsA, colsB);
}

int main()
{
    cout << "--- PART A: TRANSPOSE ---" << endl;
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int matrixA[10][10];
    inputMatrix(matrixA, rows, cols);

    cout << "\nOriginal Matrix:" << endl;
    printMatrix(matrixA, rows, cols);
    transposeMatrix(matrixA, rows, cols);

    cout << "\n--- PART B: ADDITION ---" << endl;
    int matrixB[10][10];
    cout << "Enter elements for second matrix of same size (" << rows << "x" << cols << "):" << endl;
    inputMatrix(matrixB, rows, cols);
    addMatrices(matrixA, matrixB, rows, cols);

    cout << "\n--- PART C: MULTIPLICATION ---" << endl;
    int rowsB, colsB;
    cout << "Enter rows for Matrix B (must equal " << cols << "): ";
    cin >> rowsB;
    cout << "Enter columns for Matrix B: ";
    cin >> colsB;

    if (cols != rowsB)
    {
        cout << "Error: Columns of A must match rows of B for multiplication!" << endl;
    }
    else
    {
        int multB[10][10];
        cout << "Enter elements for Matrix B:" << endl;
        inputMatrix(multB, rowsB, colsB);
        multiplyMatrices(matrixA, multB, rows, cols, colsB);
    }

    return 0;
}
