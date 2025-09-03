#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> weights = {11, 2, 15, 5, 6, 17, 7};
    int binCapacity = 20;
    vector<vector<int>> bins; // stores items in each bin
    vector<int> binRemaining;

    for (int w : weights) {
        bool placed = false;
        for (size_t i = 0; i < binRemaining.size(); ++i) {
            if (binRemaining[i] >= w) {
                bins[i].push_back(w);
                binRemaining[i] -= w;
                placed = true;
                break;
            }
        }
        if (!placed) {
            bins.push_back({w});
            binRemaining.push_back(binCapacity - w);
        }
    }

    cout << "First Fit Bin Packing:" << endl;
    for (size_t i = 0; i < bins.size(); ++i) {
        cout << "Bin " << i+1 << " (Capacity remaining " << binRemaining[i] << "): ";
        for (int item : bins[i])
            cout << item << " ";
        cout << endl;
    }
    return 0;
}
