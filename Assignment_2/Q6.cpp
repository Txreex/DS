#include <iostream>
using namespace std;

struct Element {
    int row;
    int col;
    int val;
};

class SparseMatrix {
    int rows, cols, nonZero;
    Element *data; // array of triplets
public:
    SparseMatrix(int r, int c, int nz) {
        rows = r;
        cols = c;
        nonZero = nz;
        data = new Element[nonZero];
    }

    void setElement(int index, int r, int c, int v) {
        if (index >= 0 && index < nonZero) {
            data[index].row = r;
            data[index].col = c;
            data[index].val = v;
        }
    }

    void display() {
        int k = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (k < nonZero && data[k].row == i && data[k].col == j)
                    cout << data[k++].val << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }

    // (a) Transpose
    SparseMatrix transpose() {
        SparseMatrix T(cols, rows, nonZero);
        int k = 0;
        for (int c = 0; c < cols; c++) { // iterate column by column
            for (int i = 0; i < nonZero; i++) {
                if (data[i].col == c) {
                    T.data[k].row = data[i].col;
                    T.data[k].col = data[i].row;
                    T.data[k].val = data[i].val;
                    k++;
                }
            }
        }
        return T;
    }

    // (b) Addition of two sparse matrices
    SparseMatrix add(SparseMatrix &B) {
        if (rows != B.rows || cols != B.cols) {
            cout << "Matrix dimensions do not match!" << endl;
            return SparseMatrix(0,0,0);
        }

        Element *resultData = new Element[nonZero + B.nonZero];
        int i=0, j=0, k=0;

        while(i < nonZero && j < B.nonZero) {
            if (data[i].row < B.data[j].row || 
               (data[i].row == B.data[j].row && data[i].col < B.data[j].col)) {
                resultData[k++] = data[i++];
            } else if (B.data[j].row < data[i].row || 
                      (B.data[j].row == data[i].row && B.data[j].col < data[i].col)) {
                resultData[k++] = B.data[j++];
            } else { // same position
                int sum = data[i].val + B.data[j].val;
                if (sum != 0) {
                    resultData[k].row = data[i].row;
                    resultData[k].col = data[i].col;
                    resultData[k].val = sum;
                    k++;
                }
                i++; j++;
            }
        }

        while(i < nonZero) resultData[k++] = data[i++];
        while(j < B.nonZero) resultData[k++] = B.data[j++];

        SparseMatrix C(rows, cols, k);
        for (int p = 0; p < k; p++) C.data[p] = resultData[p];
        delete [] resultData;
        return C;
    }

    ~SparseMatrix() {
        delete [] data;
    }
};

int main() {
    // Example: 3x3 sparse matrix with 4 non-zero elements
    SparseMatrix A(3,3,4);
    A.setElement(0,0,0,5);
    A.setElement(1,0,2,8);
    A.setElement(2,1,1,3);
    A.setElement(3,2,0,6);

    cout << "Original Matrix A:" << endl;
    A.display();

    cout << "\nTranspose of A:" << endl;
    SparseMatrix T = A.transpose();
    T.display();

    // Another sparse matrix B
    SparseMatrix B(3,3,3);
    B.setElement(0,0,0,2);
    B.setElement(1,0,2,4);
    B.setElement(2,2,1,7);

    cout << "\nMatrix B:" << endl;
    B.display();

    cout << "\nA + B:" << endl;
    SparseMatrix C = A.add(B);
    C.display();

    return 0;
}
