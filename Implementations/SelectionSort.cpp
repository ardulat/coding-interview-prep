#include <iostream>

using namespace std;

void selectionSort(int* A, int size);

void selectionSort(int* A, int size) {
    for (int i = 0; i < size; i++) {
        int min = A[i];
        int minIndex = i;
        for (int j = i; j < size; j++) {
            if (A[j] < min) {
                min = A[j];
                minIndex = j;
            }
        }
        swap(A[i], A[minIndex]);
    }
}

int main() {

    int N;
    cin >> N;
    int A[N];
    for (int j = 0; j < N; j++) {
        cin >> A[j];
    }
    selectionSort(A, N);
    // print
    for (int j = 0; j < N; j++) {
        cout << A[j] << " ";
    }
    cout << endl;

    return 0;
}