// InterviewBit implementation

#include <iostream>

using namespace std;

int partition(int* A, int start, int end) {
    int pivot = A[end];
    int partitionIndex = start;

    for (int i=start; i<end; i++) {
        if (A[i] <= pivot) {
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
    int A[] = {5, 6, 2, 3, 8, 4, 1};
    
    quickSort(A, 0, 6);

    for (int i=0; i<7; i++) {
        cout << A[i] << " ";
    }

    return 0;
}