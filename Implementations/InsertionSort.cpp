// Implementation of insertionSort (from Interviewbit pseudocode)

#include <iostream>

using namespace std;

void insertionSort(int *A, int n) {
    for (int i=1; i<n; i++) {
        int value = A[i];
        int holeIndex = i;

        while(holeIndex>0 && A[holeIndex-1]>value) {
            A[holeIndex] = A[holeIndex-1];
            holeIndex--;
        }
        A[holeIndex] = value;
    }
}

int main() {

    int A[] = {5, 6, 2, 3, 8, 4, 1};
    
    insertionSort(A, 7);

    for (int i=0; i<7; i++) {
        cout << A[i] << " ";
    }

    return 0;
}