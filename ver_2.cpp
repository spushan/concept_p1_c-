#include <iostream>
#include <stdlib.h>
using namespace std;


float** NewMatrix(int row, int col) {
    
    float** matrix = new float* [row];
    
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


void PrintMatrix(int row, int col, float** matrix) {
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<matrix[i][j]<<"  ";
        }
        cout<<endl;
    }
}


float** AddMatrix(int row, int col, float** mat1, float** mat2){
    
    float** result = new float* [row];
    
    for(int i=0;i<row;i++){
        result[i] = new float[col];
    }
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return result;
}


float** SubMatrix(int row, int col, float** mat1, float** mat2){

    float** result = new float*[row];
    
    for(int i=0;i<row;i++){
        result[i] = new float[col];
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    
    return result;
}


float** MulMatrix(int row, int col, int row2, int col2, float** mat1, float** mat2){

    float** result = new float* [row];
    
    for(int i=0;i<row;i++){
        result[i] = new float[col2];
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col2;j++){
            for(int k=0;k<col;k++){
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    
    return result;
}


int OpMenu(){
    
    int choice;
    cout<<"Menu:"<< endl;
    cout<<"[1] Add"<<endl;
    cout<<"[2] Subtract"<<endl;
    cout<<"[3] Multiply"<<endl;
    cout<<"Please enter a choice: ";
    cin>>choice;
    return choice;
}


void InMenu(int dim[4], int choice){
    
    bool isCorrect = true;
    while(isCorrect){
        cout<<"\nEnter Number of rows for First Matrix: ";
        cin>>dim[0];
        cout<<"\nEnter Number of columns for First Matrix: ";
        cin>>dim[1];
        cout<<"\nEnter Number of rows for Second Matrix: ";
        cin>>dim[2];
        cout<<"\nEnter Number of columns for Second Matrix: ";
        cin>>dim[3];

        if (choice == 1 || choice == 2) {
            if(dim[0] == dim[2] && dim[1] == dim[3]){
                isCorrect = false;
            } else{
                cout<<"Error: Matrix Dimension not Equal"<<endl;
                continue;
            }
        } else{
            if(dim[1] == dim[2]){
                isCorrect = false;
            } else {
                cout<<"Error: Column of Matrix 1 not equal with Row of Matrix 2"<<endl;
                continue;
            }
        }    
    }
}


int main(){
    
    float** mat1;
    float** mat2;
    int dim[4];
    int choice; 
    int contMenu;
    choice = OpMenu();
    InMenu(dim, choice);
    cout<<"Input First Matrix"<<endl;
    mat1 = NewMatrix(dim[0], dim[1]);
    cout<<"Input Second Matrix"<<endl;
    mat2 = NewMatrix(dim[2], dim[3]);

    
    while(true) {
        float** answer;
        switch (choice)
        {
        case 1:
            answer = AddMatrix(dim[0], dim[1], mat1, mat2);
            PrintMatrix(dim[0], dim[1], answer);
            delete answer;
            break;
        case 2:
            answer = SubMatrix(dim[0], dim[1], mat1, mat2);
            PrintMatrix(dim[0], dim[1], answer);
            delete answer;
            break;
        case 3:
            answer = MulMatrix(dim[0], dim[1], dim[2], dim[3], mat1, mat2);
            PrintMatrix(dim[0], dim[3], answer);
            delete answer;
            break;
        default:
            break;
        }
        cout<<"[1] change operation [2] change matrix [3] quit: ";
        cin>>contMenu;
        
        if(contMenu == 1){
            if(dim[0] != dim[2] && dim[1] != dim[3]){
                cout<<"Dimensions not equal for Add or Subtract! Change Matrix";
                InMenu(dim,choice);
            }
            choice = OpMenu();
        }else if(contMenu == 2) {
            delete mat1;
            delete mat2;
            InMenu(dim, choice);
            cout<<"Input First Matrix"<<endl;
            mat1 = NewMatrix(dim[0], dim[1]);
            cout<<"Input Second Matrix"<<endl;
            mat2 = NewMatrix(dim[2], dim[3]);
        }else{
            exit(1);
        }
    }
    return 0;
}

