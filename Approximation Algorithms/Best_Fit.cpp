#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> weights = {11, 2, 15, 5, 6, 17, 7};
    int binCapacity = 20;
    vector<vector<int>> bins; // stores items in each bin
    vector<int> binRemaining;

    for (int w : weights) {
        int bestBin = -1, minSpace = binCapacity + 1;
        for (size_t i = 0; i < binRemaining.size(); ++i) {
            if (binRemaining[i] >= w && binRemaining[i] - w < minSpace) {
                bestBin = i;
                minSpace = binRemaining[i] - w;
            }
        }
        if (bestBin == -1) {
            bins.push_back({w});
            binRemaining.push_back(binCapacity - w);
        } else {
            bins[bestBin].push_back(w);
            binRemaining[bestBin] -= w;
        }
    }

    cout << "Best Fit Bin Packing:" << endl;
    for (size_t i = 0; i < bins.size(); ++i) {
        cout << "Bin " << i+1 << " (Capacity remaining " << binRemaining[i] << "): ";
        for (int item : bins[i])
            cout << item << " ";
        cout << endl;
    }
    return 0;
}
