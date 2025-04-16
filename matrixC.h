#ifndef MATRIX_CPP
#define MATRIX_CPP

matrix* createMatrix(int len, int wid);

matrix* transpose(matrix* x);

matrix* add(matrix* x, matrix* y);

matrix* multiply(matrix* x, int num);

matrix* multiply(matrix* x, matrix* y);

void setData(matrix* x, int* nums);

void printMatrix(matrix* x);

#endif
