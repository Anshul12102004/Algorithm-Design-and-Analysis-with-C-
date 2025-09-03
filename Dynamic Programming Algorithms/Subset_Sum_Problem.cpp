#include <bits/stdc++.h>
using namespace std;

bool subSetSum(vector<int>& a, int k) {
    if (a.empty()) return false;

    int n = a.size();
    vector<vector<bool>> m(n + 1, vector<bool>(k + 1, false));

    // populate matrix m
    for (int i = 1; i <= n; i++) {
        for (int s = 0; s <= k; s++) {
            if (s - a[i - 1] >= 0) {
                m[i][s] = (m[i - 1][s] || a[i - 1] == s || m[i - 1][s - a[i - 1]]);
            } else {
                m[i][s] = (m[i - 1][s] || a[i - 1] == s);
            }
        }
    }

    // print matrix with numbering
    cout << "    "; // space before header
    for (int j = 0; j <= k; j++) {
        cout << setw(2) << j << " "; // column headers
    }
    cout << "\n";

    for (int i = 0; i <= n; i++) {
        cout << setw(2) << i << " "; // row header
        for (int j = 0; j <= k; j++) {
            cout << " " << (m[i][j] ? "T" : "F") << " ";
        }
        cout << "\n";
    }

    return m[n][k];
}

int main() {
    vector<int> array = {1, 3, 5, 2, 8};
    int k = 9;

    bool result = subSetSum(array, k);
    cout << "\nSubset sum " << (result ? "exists" : "does not exist") << endl;

    return 0;
}
