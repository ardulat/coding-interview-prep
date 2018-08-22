// Silly implementation of MergeSort (from InterviewBit)

#include <iostream>
#include <vector>

using namespace std;

void merge(int* A, int* left, int nL, int* right, int nR) {
    int i = 0, j = 0, k = 0;

    while (i<nL && j<nR) {
        if (left[i] <= right[j]) {
            A[k] = left[i];
            i++;
        }
        else {
            A[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < nL) {
        A[k] = left[i];
        i++;
        k++;
    }
    while (j < nR) {
        A[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int* A, int n) {
    if (n<2) return;
    int mid = n/2;
    int left[mid];
    int right[n-mid];

    for (int i = 0; i < mid; i++)
        left[i] = A[i];

    for (int i = mid; i < n; i++)
        right[i-mid] = A[i];

    mergeSort(left, mid);
    mergeSort(right, n-mid);
    merge(A, left, mid, right, n-mid);
}

int main() {

    int A[] = {5, 6, 2, 3, 8, 4, 1};
    
    mergeSort(A, 7);

    for (int i=0; i<7; i++) {
        cout << A[i] << " ";
    }

    return 0;
}