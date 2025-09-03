#include <iostream>
using namespace std;

// Function to swap two elements
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function
int partition(int A[], int low, int high) {
    int pivot = A[high]; // Choose the last element as pivot
    int i = (low - 1);   // Index of smaller element

    for (int j = low; j < high; j++) {
        if (A[j] <= pivot) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[high]);
    return (i + 1);
}

// Quick Sort function
void quickSort(int A[], int low, int high) {
    if (low < high) {
        int pi = partition(A, low, high);

        // Recursively sort elements before and after partition
        quickSort(A, low, pi - 1);
        quickSort(A, pi + 1, high);
    }
}

int main() {
    int A[] = {6, 5, 3, 1, 8, 7, 2, 4};
    int n = sizeof(A) / sizeof(A[0]);

    quickSort(A, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}
