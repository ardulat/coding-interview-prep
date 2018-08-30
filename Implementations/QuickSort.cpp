#include <iostream>

using namespace std;

int partition(int* A, int start, int end);
void quickSort(int* A, int start, int end);

void quickSort(int* A, int start, int end) {
    if (start < end) {
        int pivot = partition(A, start, end);

        quickSort(A, start, pivot-1);
        quickSort(A, pivot+1, end);
    }
}

int partition(int* A, int start, int end) {
    int pivot = A[end];
    int pivotIndex = start;

    for (int i = start; i < end; i++) {
        if (pivot > A[i]) {
            swap(A[i], A[pivotIndex]);
            pivotIndex++;
        }
    }
    swap(A[pivotIndex], A[end]);

    return pivotIndex;
}

int main() {

    int N;
    cin >> N;
    int A[N];
    for (int j = 0; j < N; j++) {
        cin >> A[j];
    }
    quickSort(A, 0, N-1);
    // print
    for (int j = 0; j < N; j++) {
        cout << A[j] << " ";
    }
    cout << endl;

    return 0;
}