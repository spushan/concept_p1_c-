#include <iostream>
#include <stdio.h>

using namespace std;

void NewMatrix(int row, int col, float matrix[][100]) {
    float num;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<"Enter value of m["<<i<<"]"<<"["<<j<<"]: ";
            cin>>num;
            matrix[i][j] = num;
        }
    }
}


void PrintMatrix(int row, int col, float matrix[100][100]) {
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<matrix[i][j]<<"  ";
        }
        cout<<endl;
    }
    
}


void AddMatrix(int row, int col, float mat1[100][100], float mat2[100][100], float result[100][100]){

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}


void SubMatrix(int row, int col, float mat1[100][100], float mat2[100][100], float result[100][100]){

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}


void MulMatrix(int row, int col, int row2, int col2, float mat1[100][100], float mat2[100][100], float result[100][100]){

    for(int i=0;i<row;i++){
        for(int j=0;j<col2;j++){
            for(int k=0;k<col;k++){
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}


int main() {
    
    float mat1[100][100];
    float mat2[100][100];
    float result[100][100];

    NewMatrix(5,3,mat1);
    NewMatrix(3,2,mat2);
    MulMatrix(5,3,3,2,mat1,mat2,result);
    PrintMatrix(5,2,result);

    return 0;
}