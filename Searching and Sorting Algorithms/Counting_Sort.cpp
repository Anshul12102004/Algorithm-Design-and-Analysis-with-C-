#include <iostream>
#include <vector>
using namespace std;

void countingSort(int A[], int n) {
    // Step 1: Find the maximum element in A[]
    int max_val = A[0];
    for (int i = 1; i < n; ++i)
        if (A[i] > max_val) max_val = A[i];

    // Step 2: Initialize count array with zeros
    vector<int> count(max_val + 1, 0);

    // Step 3: Store the count of each element
    for (int i = 0; i < n; ++i)
        count[A[i]]++;

    // Step 4: Overwrite A[] with sorted elements
    int index = 0;
    for (int val = 0; val <= max_val; ++val)
        while (count[val]--)
            A[index++] = val;
}

int main() {
    int A[] = {2, 1, 3, 4};
    int n = sizeof(A) / sizeof(A[0]);

    countingSort(A, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}
