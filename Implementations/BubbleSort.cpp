#include <iostream>

using namespace std;

void bubbleSort(int* A, int n) {
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (A[i] < A[j])
                swap(A[i], A[j]);
}

int main() {

    int A[] = {5, 6, 2, 3, 8, 4, 1};
    
    bubbleSort(A, 7);

    for (int i=0; i<7; i++) {
        cout << A[i] << " ";
    }

    return 0;
}