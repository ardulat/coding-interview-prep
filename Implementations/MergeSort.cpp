#include <iostream>

using namespace std;

void printArray(int* A, int n);

void merge(int* A, int* left, int nL, int* right, int nR) {
    int i = 0, j = 0, k = 0;

    while(i<nL && j<nR) {
        if (left[i] <= right[j]) {
            A[k] = left[i];
            i++;
        } else {
            A[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < nL) {
        A[k] = left[i];
        i++; k++;
    }
    while(j < nR) {
        A[k] = right[j];
        j++; k++;
    }
}

void mergeSort(int* A, int n) {
    if (n > 1) {
        int mid = n/2;
        int left[mid];
        int right[n-mid];

        for (int i=0; i<mid; i++)
            left[i] = A[i];
        for (int i=mid; i<n; i++)
            right[i-mid] = A[i];

        mergeSort(left, mid);
        mergeSort(right, n-mid);

        merge(A, left, mid, right, n-mid);
    }
}

void printArray(int* A, int n) {
    for (int i=0; i<n; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main() {

    int A[] = {1, 2, 3, 4, 5, 6, 7};
    int B[] = {7, 6, 5, 4, 3, 2, 1};
    int C[] = {5, 6, 3, 7, 1, 2, 4};

    mergeSort(A, 7);
    mergeSort(B, 7);
    mergeSort(C, 7);

    printArray(A, 7);
    printArray(B, 7);
    printArray(C, 7);

    return 0;
}