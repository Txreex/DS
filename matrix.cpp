#include<iostream>
using namespace std;

void swap(int &a , int &b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}   

class Matrix{
public : 
    int ** mat;
    int row;
    int col;

    Matrix(int r , int c , int* arr){
        row = r;
        col = c;

        mat = new int*[row];
        for(int i = 0 ; i < row ; i++){
            mat[i] = new int[col];
            for (int j = 0; j < c; j++) {
                mat[i][j] = arr[i * col + j];
            }
        }
    }

    Matrix(int r , int c){
        row = r;
        col = c;

        mat = new int*[row];
        for(int i = 0 ; i < row ; i++){
            mat[i] = new int[col];
        }
    }

    void diplay(){
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    Matrix operator+(Matrix m){
        if(row != m.row || col != m.col){
            throw invalid_argument("Matrix dimensions must match!");
        }

        Matrix res(row , col);

        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                res.mat[i][j] = this->mat[i][j] + m.mat[i][j];
            }
        }

        return res;
    }

    Matrix operator*(Matrix m){
        if(col != m.row){
            throw invalid_argument("Matrix dimensions must match!");
        }

        Matrix res(row , m.col);

        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < m.col ; j++){
                res.mat[i][j] = 0;
                for(int k = 0 ; k < col ; k++){
                    res.mat[i][j] += this->mat[i][k]*m.mat[k][j];
                }   
            }
        }
        
        return res;
    }

    Matrix T(){
        Matrix res(col, row);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                res.mat[j][i] = this->mat[i][j];
            }
        }

        return res;
    }

};

int main(){
    int mat1_data[] = {1,1,1 , 1,1,1};
    int mat2_data[] = {1,1,1 , 1,1,1 , 1,1,1};

    Matrix m1(2 , 3 , mat1_data);
    Matrix m2(3 , 3 , mat2_data);

    Matrix m3 = m1.T();

    m3.diplay();
}