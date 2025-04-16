#ifndef MATRIX_CPP
#define MATRIX_CPP

using namespace std;

Matrix::Matrix(){
    width = 0;
    length = 0;
    arr = nullptr;
}

class Matrix{
    public:
    Matrix();
    Matrix(int values[], int x, int y);
    ~Matrix();
    void clear();
    void printMatrix();
    int** getMatrix();
    void setMatrix(Matrix* x);
    int getWidth();
    int getLength();
    Matrix* add(Matrix* x);
    Matrix* multiply(Matrix *x);
    Matrix* multiply(int x);
    Matrix* transpose();
    int **arr;

    private:
    int length;
    int width;
};


#endif
