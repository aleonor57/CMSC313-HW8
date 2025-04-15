#include <iostream>
using namespace std;

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

Matrix::Matrix(){
    width = 0;
    length = 0;
    arr = nullptr;
}

Matrix::Matrix(int values[], int x, int y){
    width = x;
    length = y;
    arr = new int *[length];
    for (int i = 0; i<length; i++){
        arr[i] = new int[width];
        for (int j = 0; j<width; j++){
            arr[i][j] = values[j+width*(i)];
        }
    }
} 

Matrix::~Matrix(){
    clear();
}

void Matrix::clear(){
    if (arr != nullptr){
        for (int i = 0; i < length; i++){
            delete arr[i];
        }
        delete arr;
    }
}


void Matrix::printMatrix(){
    for (int i = 0; i < length; i++){
        for (int j = 0; j < width; j++) {
            cout<< arr[i][j] << " "; 
        }
        cout << endl;
    }
}

int** Matrix::getMatrix(){
    return arr;
}

void Matrix::setMatrix(Matrix* x){
    clear();
    length = x->getLength();
    width = x->getWidth();
    arr = x->getMatrix();
}

int Matrix::getLength(){
    return length;
}

int Matrix::getWidth(){
    return width;
}

Matrix* Matrix::add(Matrix* x){
    for (int i = 0; i < width; i++){
        for (int j = 0; j < length; j++){
            arr[j][i] += (x->getMatrix())[j][i];
        }
    }
    return this;
}

Matrix* Matrix::multiply(int x){
    for (int i = 0; i < width; i++){
        for (int j = 0; j < length; j++){
            arr[j][i] = arr[j][i]*x;
        }
    }
    return this;
}

Matrix* Matrix::multiply(Matrix *x){
    int **newarr;
    int newlength = length;
    int newwidth = x->getWidth();

    newarr = new int *[newlength];
    for (int i = 0; i < newlength; i++){
        newarr[i] = new int[newwidth];
    }
    
    for (int i = 0; i < newwidth; i++){

        for (int j = 0; j < length; j++){ 
            int rowsum = 0;
            for (int k = 0; k < width; k++){
                rowsum += arr[j][k]*(x->getMatrix())[k][i];
            }
            newarr[j][i] = rowsum;
       }
        
    }
    clear();
    arr = newarr;
    width = newwidth;
    length = newlength;
    return this;
}


Matrix* Matrix::transpose(){
    int **newarr;
    int newlength = width;
    int newwidth = length;
    
    newarr = new int *[newlength];
    for (int i = 0; i<newlength; i++){
        newarr[i] = new int[newwidth];
        for (int j = 0; j<newwidth; j++){
            newarr[i][j] = arr[j][i];
        }
    }

    clear();
    arr = newarr;
    width = newwidth;
    length = newlength;
    return this;
}

int main() {
    int A[4] = {6,4,8,3};
    Matrix a(A,2,2);
    int B[6] = {1,2,3,4,5,6};
    Matrix b(B,3,2);
    int C[6] = {2,4,6,1,3,5};
    Matrix c(C,3,2);
    Matrix d;


    d.setMatrix(a.add((b.multiply(3))->multiply(c.transpose())));
    d.printMatrix();
    return 0;
  } 
