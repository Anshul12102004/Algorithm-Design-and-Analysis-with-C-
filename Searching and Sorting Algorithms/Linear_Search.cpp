#include <iostream>
using namespace std;

// Function to perform linear search in an array
int linearSearch(int A[], int n, int x) {
    for (int i = 0; i < n; ++i) {
        if (A[i] == x)
            return i; // Element found at index i
    }
    return -1; // Element not found
}

int main() {
    int A[] = {13, 9, 21, 15, 39, 19, 27};
    int n = sizeof(A) / sizeof(A[0]);
    int x = 39; // Element to search for

    int result = linearSearch(A, n, x);

    if (result != -1)
        cout << "Element " << x << " found at index " << result << endl;
    else
        cout << "Element " << x << " not found in the array." << endl;

    return 0;
}
