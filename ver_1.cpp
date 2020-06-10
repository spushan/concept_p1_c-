#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//changes all the value of the passed matrix to zero
void Zero(float matrix[100][100]){
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            matrix[i][j] = 0;
        }
    }
}

//changes the values of the passed matrix to user input
void NewMatrix(int row, int col, float matrix[100][100]) {

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<"Enter value of ["<<i<<"]"<<"["<<j<<"]: ";
            cin>>matrix[i][j];
        }
    }
}

//prints the matrix
void PrintMatrix(int row, int col, float matrix[100][100]) {
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<matrix[i][j]<<"  ";
        }
        cout<<endl;
    }
}

//adds two matrices
void AddMatrix(int row, int col, float mat1[100][100], float mat2[100][100], float result[100][100]){

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

//subtract two matrices
void SubMatrix(int row, int col, float mat1[100][100], float mat2[100][100], float result[100][100]){

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

//multiply two matrices
void MulMatrix(int row, int col, int row2, int col2, float mat1[100][100], float mat2[100][100], float result[100][100]){

    for(int i=0;i<row;i++){
        for(int j=0;j<col2;j++){
            for(int k=0;k<col;k++){
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

//menu for  the operation
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

//menu for the size of the two matrices
void InMenu(int dim[4], int choice,float mat1[100][100], float mat2[100][100]){
    
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
    cout<<"Input First Matrix"<<endl;
    NewMatrix(dim[0],dim[1],mat1);
    cout<<"Input Second Matrix"<<endl;
    NewMatrix(dim[2],dim[3],mat2);

}


int main(){
    
    float mat1[100][100];
    float mat2[100][100];
    float result[100][100];
    int dim[4];
    int choice; 
    bool notQuit = true;
    int contMenu;
    choice = OpMenu();
    InMenu(dim, choice,mat1,mat2);
    
    while(notQuit) {
        switch (choice)
        {
        case 1:
            AddMatrix(dim[0],dim[1],mat1,mat2,result);
            PrintMatrix(dim[0],dim[1],result);
            result[100][100];
            break;
        case 2:
            SubMatrix(dim[0],dim[1],mat1,mat2,result);
            PrintMatrix(dim[0],dim[1],result);
            break;
        case 3:
            Zero(result);
            MulMatrix(dim[0],dim[1],dim[2],dim[3],mat1,mat2,result);
            PrintMatrix(dim[0],dim[3],result);
        default:
            break;
        }
        cout<<"[1] change operation [2] change matrix [3] quit: ";
        cin>>contMenu;
        
        if(contMenu == 1){
            choice = OpMenu();
        }else if(contMenu == 2) {
            InMenu(dim,choice,mat1,mat2);
        }else{
            exit(1);
        }
    }

    return 0;
}