#include <iostream>
using namespace std;

int binarySearch(int A[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (A[mid] == key)
            return mid; // Key found at index mid
        else if (A[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // Key not found
}

int main() {
    int A[] = {0, 4, 7, 10, 14, 23, 45, 47, 53};
    int n = sizeof(A) / sizeof(A[0]);
    int key = 47;

    int result = binarySearch(A, n, key);

    if (result != -1)
        cout << "Element " << key << " found at index " << result << endl;
    else
        cout << "Element " << key << " not found in the array." << endl;

    return 0;
}
