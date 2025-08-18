#include <iostream>
using namespace std;

int removeDuplicates(int arr[], int n) {
    int uniqueCount = 0;  

    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;

        for (int j = 0; j < uniqueCount; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            arr[uniqueCount] = arr[i];
            uniqueCount++;
        }
    }
    return uniqueCount; 
}

int main() {
    int arr[] = {5, 2, 8, 2, 3, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int newSize = removeDuplicates(arr, n);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newSize; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
