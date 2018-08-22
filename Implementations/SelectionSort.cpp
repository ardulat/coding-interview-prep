// My first implementation of selectionSort

#include <iostream>

using namespace std;

void selectionSort(int *A, int n) {
    // for each element in array swap with local min
    for (int i=0; i<n; i++) {
        // find local min element
        int min = A[i];
        int minIndex = i;
        for (int j=i; j<n; j++)
            if (A[j] < min) {
                min = A[j];
                minIndex = j;
            }
            // we found local min element
        // swap it with current element in the loop
        swap(A[i], A[minIndex]);
    }
}

int main() {

    int A[] = {5, 6, 2, 3, 8, 4, 1};
    
    selectionSort(A, 7);

    for (int i=0; i<7; i++) {
        cout << A[i] << " ";
    }

    return 0;
}