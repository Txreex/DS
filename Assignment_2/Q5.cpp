#include <iostream>
using namespace std;

//
// (a) Diagonal Matrix
//
class Diagonal {
    int n;
    int *A;  // size n
public:
    Diagonal(int size) {
        n = size;
        A = new int[n];
        for (int i=0; i<n; i++) A[i] = 0;
    }
    void set(int i, int j, int x) {
        if (i == j) A[i] = x;
    }
    int get(int i, int j) {
        return (i == j) ? A[i] : 0;
    }
    void display() {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
    ~Diagonal() { delete [] A; }
};

//
// (b) Tri-diagonal Matrix
//
class Tridiagonal {
    int n;
    int *A; // size 3n-2
public:
    Tridiagonal(int size) {
        n = size;
        A = new int[3*n-2];
        for (int i=0; i<3*n-2; i++) A[i] = 0;
    }
    void set(int i, int j, int x) {
        if (i-j==1) A[i-1] = x;              // lower diag
        else if (i==j) A[n-1+i] = x;         // main diag
        else if (j-i==1) A[2*n-1+i] = x;     // upper diag
    }
    int get(int i, int j) {
        if (i-j==1) return A[i-1];
        else if (i==j) return A[n-1+i];
        else if (j-i==1) return A[2*n-1+i];
        return 0;
    }
    void display() {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
    ~Tridiagonal() { delete [] A; }
};

//
// (c) Lower Triangular Matrix
//
class LowerTriangular {
    int n;
    int *A; // size n(n+1)/2
public:
    LowerTriangular(int size) {
        n = size;
        A = new int[n*(n+1)/2];
        for (int i=0; i<n*(n+1)/2; i++) A[i] = 0;
    }
    void set(int i, int j, int x) {
        if (i>=j) A[i*(i+1)/2 + j] = x;
    }
    int get(int i, int j) {
        if (i>=j) return A[i*(i+1)/2 + j];
        return 0;
    }
    void display() {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
    ~LowerTriangular() { delete [] A; }
};

//
// (d) Upper Triangular Matrix
//
class UpperTriangular {
    int n;
    int *A; // size n(n+1)/2
public:
    UpperTriangular(int size) {
        n = size;
        A = new int[n*(n+1)/2];
        for (int i=0; i<n*(n+1)/2; i++) A[i] = 0;
    }
    void set(int i, int j, int x) {
        if (i<=j) A[i*n - (i*(i-1))/2 + (j-i)] = x;
    }
    int get(int i, int j) {
        if (i<=j) return A[i*n - (i*(i-1))/2 + (j-i)];
        return 0;
    }
    void display() {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
    ~UpperTriangular() { delete [] A; }
};

//
// (e) Symmetric Matrix
//
class Symmetric {
    int n;
    int *A; // size n(n+1)/2 (store lower triangular)
public:
    Symmetric(int size) {
        n = size;
        A = new int[n*(n+1)/2];
        for (int i=0; i<n*(n+1)/2; i++) A[i] = 0;
    }
    void set(int i, int j, int x) {
        if (i>=j) A[i*(i+1)/2 + j] = x;
        else A[j*(j+1)/2 + i] = x; // mirror
    }
    int get(int i, int j) {
        if (i>=j) return A[i*(i+1)/2 + j];
        return A[j*(j+1)/2 + i];
    }
    void display() {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
    ~Symmetric() { delete [] A; }
};

//
// Main test
//
int main() {
    int n = 4;

    cout << "Diagonal Matrix:" << endl;
    Diagonal D(n);
    D.set(0,0,5); D.set(1,1,8); D.set(2,2,9); D.set(3,3,12);
    D.display();

    cout << "\nTri-diagonal Matrix:" << endl;
    Tridiagonal T(n);
    T.set(0,0,1); T.set(1,1,2); T.set(2,2,3); T.set(3,3,4);
    T.set(1,0,5); T.set(2,1,6); T.set(3,2,7);
    T.set(0,1,9); T.set(1,2,10); T.set(2,3,11);
    T.display();

    cout << "\nLower Triangular Matrix:" << endl;
    LowerTriangular L(n);
    L.set(0,0,1); L.set(1,0,2); L.set(1,1,3);
    L.set(2,0,4); L.set(2,1,5); L.set(2,2,6);
    L.set(3,0,7); L.set(3,1,8); L.set(3,2,9); L.set(3,3,10);
    L.display();

    cout << "\nUpper Triangular Matrix:" << endl;
    UpperTriangular U(n);
    U.set(0,0,1); U.set(0,1,2); U.set(0,2,3); U.set(0,3,4);
    U.set(1,1,5); U.set(1,2,6); U.set(1,3,7);
    U.set(2,2,8); U.set(2,3,9);
    U.set(3,3,10);
    U.display();

    cout << "\nSymmetric Matrix:" << endl;
    Symmetric S(n);
    S.set(0,0,1); S.set(1,1,2); S.set(2,2,3); S.set(3,3,4);
    S.set(1,0,5); S.set(2,0,6); S.set(3,0,7);
    S.set(2,1,8); S.set(3,1,9); S.set(3,2,10);
    S.display();

    return 0;
}
