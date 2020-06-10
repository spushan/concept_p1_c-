#include <iostream>

using namespace std;

float** NewMatrix(int row, int col) {
    
    float** matrix = new float*[row];
    for(int i=0;i<col;i++){
        matrix[i] = new float[col];
    }
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<"Enter value of ["<<i<<"]"<<"["<<j<<"]: ";
            cin>>matrix[i][j];
            
        }
    }
    
    return matrix;
}

