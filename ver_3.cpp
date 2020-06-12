#include <iostream>

using namespace std;

class Matrix {
    
    private:
        float** mat;
        int row;
        int col;

    public:
        Matrix(int row, int col){
        
            this->row = row;
            this->col = col;
            this->mat = new float* [row];
            cout<<"Enter Values for the Matrix"<<endl;
            for(int i=0;i<row;i++){
                mat[i] = new float[col];
                for(int j = 0; j<col; j++){
                    cout<<"Enter value of ["<<i<<"]"<<"["<<j<<"]: ";
                    cin>>mat[i][j];
                }       
            }
        }
        
        ~Matrix(){
            cout<<"decon"<<endl;
        }
        
        void setMatrix(int row, int col){
            this->row = row;
            this->col = col;
            cout<<"Enter Values for the Matrix"<<endl;
            for(int i=0;i<row;i++){
                mat[i] = new float[col];
                for(int j = 0; j<col; j++){
                    cout<<"Enter value of ["<<i<<"]"<<"["<<j<<"]: ";
                    cin>>mat[i][j];
                }       
            }
        }
        
        float** getMatrix(){
            return mat;
        }

        int getRow(){
            return row;
        }

        int getCol(){
            return col;
        }

        void operator+ (Matrix other){
            float** m = other.getMatrix();
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    cout<<mat[i][j] + m[i][j]<<"  ";
                }
                cout<<endl;
            }
        }

        void operator- (Matrix other){
            float** m = other.getMatrix();
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    cout<<mat[i][j] - m[i][j]<<"  ";
                }
                cout<<endl;
            }
        }

        void operator* (Matrix other){
            float ans=0;
            float** m = other.getMatrix();
            int col2 = other.getCol();
            for(int i=0;i<row;i++){
                for(int j=0;j<col2;j++){
                    for(int k=0;k<col;k++){
                        ans += mat[i][k] * m[k][j];
                    }
                    cout<<ans<<"  ";
                    ans = 0;
                }
                cout<<endl;
            }
        }
        
};


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
    
    int choice;
    int contMenu;
    int dim[4];

    choice = OpMenu();
    InMenu(dim, choice);
    Matrix mat1(dim[0],dim[1]);
    Matrix mat2(dim[2],dim[3]);
    while(true){
        switch (choice)
        {
        case 1:
            mat1 + mat2;
            break;
        case 2:
            mat1 - mat2;
            break;
        case 3:
            mat1 * mat2;
            break;
        default:
            break;
        }
    
    cout<<"[1] change operation [2] change matrix [3] quit: ";
    cin>>contMenu;
        
        if(contMenu == 1){
            if(dim[0] != dim[2] && dim[1] != dim[3]){
                cout<<"Dimensions not equal for Add or Subtract! Exiting"<<endl;
                exit(1);
            }
            choice = OpMenu();
        }else if(contMenu == 2) {
            InMenu(dim, choice);
            mat1.setMatrix(dim[0],dim[1]);
            mat2.setMatrix(dim[2],dim[3]);
        }else{
            exit(1);
        }
    }
    return 0;
}