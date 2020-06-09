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


void PrintMatrix(float matrix[100][100], int row, int col) {
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

int main() {
    
    float mat1[100][100];
    float mat2[100][100];
    float result[100][100];

    NewMatrix(5,5,mat1);
    NewMatrix(5,5,mat2);
    AddMatrix(5,5,mat1,mat2,result);
    PrintMatrix(result,5,5);

    return 0;
}