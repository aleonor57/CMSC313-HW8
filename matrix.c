#include <stdlib.h>
#include <iostream>

typedef struct matrix{
    int rows;
    int cols;
    int* data;
}matrix;

matrix* createMatrix(int len, int wid){
    struct matrix* mat = (matrix*)malloc(sizeof(struct matrix));
    mat->rows = len;
    mat->cols = wid;
    mat->data = (int*)malloc(sizeof(int)*mat->rows*mat->cols);
    return mat;
}

matrix* transpose(matrix* x){
    matrix* y = createMatrix(x->cols, x->rows);
    for (int i = 0; i < x->rows; i++){
        for (int j = 0; j < x->cols; j++){
            y->data[j*x->rows+i] = x->data[i*x->cols+j];
        }
    }
    return y;
}

matrix* add(matrix* x, matrix* y){
    matrix* out = createMatrix(x->rows,x->cols); 
    for (int i = 0; i < x->rows; i++){
        for (int j = 0; j < x->cols; j++){
            out->data[i*out->cols+j] = x->data[i*x->cols+j] + y->data[i*y->cols+j];
        }
    }
    return out;
}

matrix* multiply(matrix* x, int num){
    for (int i = 0; i < x->rows; i++){
        for (int j = 0; j < x->cols; j++){
            x->data[i*x->cols+j] = x->data[i*x->cols+j]*num;
        }
    }
    return x;
}

matrix* multiply(matrix* x, matrix* y){
    matrix* out = createMatrix(x->rows,y->cols); 
    for (int k = 0; k < y->cols; k++){
        for (int i = 0; i < x->rows; i++){
            int rowsum = 0;
            for (int j = 0; j < x->cols; j++){
                rowsum += x->data[i*x->cols+j]*y->data[k+j*y->cols];
            }
            out->data[k+i*out->cols] = rowsum;
        }
    }
    return out;
}

void setData(matrix* x, int* nums){
    x->data = nums;
}

void printMatrix(matrix* x){
    for (int i = 0; i < x->rows; i++){
        for (int j = 0; j < x->cols; j++){
            printf("%d ", x->data[i*x->cols+j]);
        }
        printf("\n");
    }
}

int main() {
    matrix* a = createMatrix(2,2);
    int A[4] = {6,4,8,3};
    setData(a, A);

    matrix* b = createMatrix(2,3);
    int B[6] = {1,2,3,4,5,6};
    setData(b, B);

    matrix* c = createMatrix(2,3);
    int C[6] = {2,4,6,1,3,5};
    setData(c, C);

    printMatrix(add(a,multiply(multiply(b,3),transpose(c))));
    return 0;
}
