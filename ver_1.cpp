#include <iostream>
using namespace std;

void *NewMatrix(int row, int col) {
    float num;
    float (*a)[100] = new float[100][100];
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<"Enter value of m["<<i<<"]"<<"["<<j<<"]: ";
            cin>>num;
            a[i][j] = num;
        }
    }
    return a;
}


void PrintMatrix(float matrix[100][100], int row, int col) {
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<matrix[i][j]<<"  ";
        }
    }
    cout<<endl;
}

void *AddMatrix(float mat1[100][100], float mat2[100][100], float result[100][100], int row, int col){


    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }


}

void main() {


}