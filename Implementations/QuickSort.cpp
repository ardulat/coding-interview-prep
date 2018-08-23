#include <iostream>

using namespace std;

void printArray(int* A, int n) {
    for (int i=0; i<n; i++)
        cout << A[i] << " ";
    cout << endl;
}

int partition(int* A, int start, int end) {
    int pivot = A[end];
    int partitionIndex = start;

    for (int i=start; i<end; i++) {
        if (A[i] <= pivot) {
            swap(A[i], A[partitionIndex]);
            partitionIndex++;
        }
    }

    swap(A[end], A[partitionIndex]);

    return partitionIndex;
}

void quickSort(int* A, int start, int end) {
    if (start < end) {
        int pivotIndex = partition(A, start, end);
        quickSort(A, start, pivotIndex-1);
        quickSort(A, pivotIndex+1, end);
    }
}

int main() {

    int A[] = {1, 2, 3, 4, 5, 6, 7};
    int B[] = {7, 6, 5, 4, 3, 2, 1};
    int C[] = {5, 6, 3, 7, 1, 2, 4};

    quickSort(A, 0, 6);
    quickSort(B, 0, 6);
    quickSort(C, 0, 6);

    printArray(A, 7);
    printArray(B, 7);
    printArray(C, 7);

    return 0;
}