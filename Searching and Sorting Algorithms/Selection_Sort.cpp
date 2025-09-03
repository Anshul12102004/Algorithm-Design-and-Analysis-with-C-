#include <iostream>
using namespace std;

void selectionSort(int A[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (A[j] < A[min_idx])
                min_idx = j;
        }
        // Swap the found minimum element with the first element
        if (min_idx != i) {
            int temp = A[i];
            A[i] = A[min_idx];
            A[min_idx] = temp;
        }
    }
}

int main() {
    int A[] = {5, 3, 4, 1, 2};
    int n = sizeof(A) / sizeof(A[0]);

    selectionSort(A, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}
