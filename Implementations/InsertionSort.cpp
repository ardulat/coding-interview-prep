// Implementation of insertionSort (pseudocode from Interviewbit)

#include <iostream>

using namespace std;

void insertionSort(int *A, int n) {
    for (int i = 1; i < n; i++) {
        int key = A[i];
        int j = i-1;

        while (j >= 0 && A[j] > key) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

int main() {

    int A[] = {5, 6, 2, 3, 8, 4, 1};
    
    insertionSort(A, 7);

    for (int i=0; i<7; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}