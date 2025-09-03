#include <iostream>
using namespace std;

void insertionSort(int A[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = A[i];
        int j = i - 1;
        // Move elements of A[0..i-1] that are greater than key to one position ahead
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main() {
    int A[] = {6, 5, 3, 1, 8, 7, 2, 4};
    int n = sizeof(A) / sizeof(A[0]);

    insertionSort(A, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}
