#include <iostream>

using namespace std;

void insertionSort(int* A, int size);

void insertionSort(int* A, int size) {

    for (int i = 1; i < size; i++) {
        int key = A[i];
        int j = i - 1;

        while (j >= 0 && key < A[j]) {
            A[j+1] = A[j];
            j--;
        }

        A[j+1] = key;
    }
}

int main() {

    int N;
    cin >> N;
    int A[N];
    for (int j = 0; j < N; j++) {
        cin >> A[j];
    }
    insertionSort(A, N);
    // print
    for (int j = 0; j < N; j++) {
        cout << A[j] << " ";
    }
    cout << endl;

    return 0;
}