#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n = 4; // number of items
    int W = 8; // knapsack capacity

    vector<int> profit = {2, 4, 7, 10};
    vector<int> weight = {1, 3, 5, 7};

    // DP table
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    // Fill DP table
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (weight[i-1] <= w)
                dp[i][w] = max(dp[i-1][w], profit[i-1] + dp[i-1][w - weight[i-1]]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    // Print table for reference
    cout << "    ";
    for (int w = 0; w <= W; ++w) cout << setw(3) << w;
    cout << endl;
    for (int i = 0; i <= n; ++i) {
        if (i > 0)
            cout << i << " (" << weight[i-1] << "," << profit[i-1] << ")";
        else
            cout << "0   ";
        cout << " ";
        for (int w = 0; w <= W; ++w)
            cout << setw(3) << dp[i][w];
        cout << endl;
    }

    cout << "\nMaximum profit for capacity " << W << " is: " << dp[n][W] << endl;
    return 0;
}
