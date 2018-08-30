#include <iostream>

using namespace std;

void mergeSort(int* A, int size);
void merge(int* A, int* left, int leftSize, int* right, int rightSize);

void mergeSort(int* A, int size) {
    if (size > 1) {
        int mid = size / 2;
        int left[mid], right[size-mid];

        for (int i = 0; i < mid; i++)
            left[i] = A[i];
        for (int i = mid; i < size; i++) 
            right[i-mid] = A[i];
        
        mergeSort(left, mid);
        mergeSort(right, size-mid);
        merge(A, left, mid, right, size-mid);
    }
}

void merge(int* A, int* left, int leftSize, int* right, int rightSize) {
    int i = 0, j = 0, k = 0;

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
        i++; k++;
    }
    while (j < rightSize) {
        A[k] = right[j];
        j++; k++;
    }
}

int main() {

    int N;
    cin >> N;
    int A[N];
    for (int j = 0; j < N; j++) {
        cin >> A[j];
    }
    mergeSort(A, N);
    // print
    for (int j = 0; j < N; j++) {
        cout << A[j] << " ";
    }
    cout << endl;

    return 0;
}