#include <iostream>
using namespace std;

void bubbleSort(int A[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (A[j] > A[j + 1]) {
                // Swap adjacent elements if they are in the wrong order
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

int main() {
    int A[] = {6, 5, 3, 1, 8, 7, 2, 4};
    int n = sizeof(A) / sizeof(A[0]);

    bubbleSort(A, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}
