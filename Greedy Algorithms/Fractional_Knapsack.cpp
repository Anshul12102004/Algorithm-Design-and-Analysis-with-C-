#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int index, weight, profit;
    double pw; // profit/weight ratio
    Item(int idx, int w, int p) : index(idx), weight(w), profit(p), pw((double)p/w) {}
};

bool cmp(Item a, Item b) {
    return a.pw > b.pw; // sort by profit/weight ratio descending
}

int main() {
    int capacity = 10;
    vector<Item> items;
    // Items as per table (index, weight, profit)
    items.push_back(Item(5, 1, 8));
    items.push_back(Item(2, 3, 15));
    items.push_back(Item(3, 2, 10));
    items.push_back(Item(4, 5, 20));
    items.push_back(Item(1, 3, 10));

    // Sort items by profit/weight ratio
    sort(items.begin(), items.end(), cmp);

    double totalProfit = 0.0;
    int curWeight = 0;
    cout << "Items included in knapsack:\n";

    for (auto &item : items) {
        if (curWeight + item.weight <= capacity) {
            curWeight += item.weight;
            totalProfit += item.profit;
            cout << "Item " << item.index << ": full, "
                 << "weight=" << item.weight << ", profit=" << item.profit << endl;
        } else {
            // Take fractional part
            int remain = capacity - curWeight;
            double fraction = (double)remain / item.weight;
            totalProfit += item.profit * fraction;
            curWeight += remain;
            cout << "Item " << item.index << ": fraction " << fraction << ", "
                 << "used weight=" << remain << ", profit=" << item.profit * fraction << endl;
            break; // knapsack is full
        }
    }

    cout << "Maximum profit: " << totalProfit << endl;
    return 0;
}
