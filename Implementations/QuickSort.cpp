#include <iostream>

using namespace std;

// function interface is written for understanding what to expect from methods
int partition(int* A, int start, int end);

void quickSort(int* A, int start, int end);

void printArray(int* A, int n) {
    for (int i=0; i<n; i++)
        cout << A[i] << " ";
    cout << endl;
}

int partition(int* A, int start, int end) {
    int pivot = A[end];
    int partitionIndex = start;

    for (int i=start; i<end; i++) {
        if (A[i] < pivot) {
            swap(A[i], A[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(A[partitionIndex], A[end]);

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

    int A[] = {7, 1, 3, 8, 2, 5, 4};

    quickSort(A, 0, 6);

    printArray(A, 7);

    return 0;
}