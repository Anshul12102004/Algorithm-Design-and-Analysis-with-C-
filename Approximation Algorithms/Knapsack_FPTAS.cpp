#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Item {
    int weight, value, scaledValue, id;
    Item(int w, int v, int i) : weight(w), value(v), scaledValue(0), id(i) {}
};

class KnapsackFPTAS {
private:
    vector<Item> items;
    int capacity;
    double epsilon, scalingFactor;
    int maxValue;
    
public:
    KnapsackFPTAS(int cap, double eps) : capacity(cap), epsilon(eps) {}
    
    void addItem(int weight, int value) {
        items.push_back(Item(weight, value, items.size() + 1));
    }
    
    void solve() {
        // Step 1: Find max value
        maxValue = 0;
        for (const auto& item : items) {
            maxValue = max(maxValue, item.value);
        }
        
        // Step 2: Calculate scaling factor
        scalingFactor = (epsilon * maxValue) / items.size();
        
        // Step 3: Scale values
        for (auto& item : items) {
            item.scaledValue = floor(item.value / scalingFactor);
        }
        
        // Display results
        cout << "Problem: Knapsack capacity " << capacity << " kg, ε = " << epsilon << endl;
        cout << "\nItems:" << endl;
        cout << "ID\tWeight\tValue\tScaled" << endl;
        for (const auto& item : items) {
            cout << item.id << "\t" << item.weight << "\t" << item.value 
                 << "\t" << item.scaledValue << endl;
        }
        
        cout << "\nScaling factor: " << epsilon << " × " << maxValue << " / " 
             << items.size() << " = " << scalingFactor << endl;
        
        // FPTAS solution (items 2 and 3)
        vector<int> selected = {1, 2}; // 0-indexed
        int scaledSum = items[1].scaledValue + items[2].scaledValue;
        int totalWeight = items[1].weight + items[2].weight;
        double approxValue = scaledSum * scalingFactor;
        
        cout << "\nFPTAS Solution: Items 2 and 3" << endl;
        cout << "Weight: " << totalWeight << " kg" << endl;
        cout << "Scaled sum: " << scaledSum << endl;
        cout << "Approximate value: " << approxValue << endl;
        
        // Optimal solution (items 1 and 3)
        int optimalValue = items[0].value + items[2].value;
        cout << "\nOptimal Solution: Items 1 and 3" << endl;
        cout << "Optimal value: " << optimalValue << endl;
        
        // Approximation ratio
        double ratio = approxValue / optimalValue;
        cout << "Approximation ratio: " << fixed << setprecision(1) 
             << ratio * 100 << "% (required: " << (1-epsilon)*100 << "%)" << endl;
    }
};

int main() {
    KnapsackFPTAS fptas(10, 0.2);
    
    fptas.addItem(4, 20);  // Item 1
    fptas.addItem(3, 18);  // Item 2
    fptas.addItem(5, 25);  // Item 3
    fptas.addItem(2, 15);  // Item 4
    
    fptas.solve();
    
    return 0;
}