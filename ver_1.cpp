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

void main() {

}