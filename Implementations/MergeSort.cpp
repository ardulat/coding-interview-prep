#include <iostream>

using namespace std;

void printArray(int* A, int n);

void merge(int* A, int* left, int leftSize, int* right, int rightSize) {
    int i=0, j=0, k=0;

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            A[k] = left[i];
            i++;
        } else {
            A[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        A[k] = left[i];
        i++;
        k++;
    }
    while (j < rightSize) {
        A[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int* A, int size) {
    if (size > 1) {
        int mid = size / 2;
        int left[mid], right[size-mid];

        // copy arrays
        for (int i = 0; i < mid; i++) {
            left[i] = A[i];
        }
        for (int i = mid; i < size; i++) {
            right[i-mid] = A[i];
        }

        mergeSort(left, mid);
        mergeSort(right, size-mid);

        merge(A, left, mid, right, size-mid);
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
    int C[] = {5, 6, 3, 7, 1, 2};

    mergeSort(A, 7);
    mergeSort(B, 7);
    mergeSort(C, 6);

    printArray(A, 7);
    printArray(B, 7);
    printArray(C, 6);

    return 0;
}