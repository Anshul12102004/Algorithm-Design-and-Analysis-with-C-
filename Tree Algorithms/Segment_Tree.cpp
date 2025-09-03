#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

    void build(const vector<int>& arr, int node, int l, int r) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(arr, 2 * node + 1, l, mid);
        build(arr, 2 * node + 2, mid + 1, r);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || ql > r)
            return 0; // No overlap
        if (ql <= l && r <= qr)
            return tree[node]; // Total overlap
        int mid = l + (r - l) / 2;
        return query(2 * node + 1, l, mid, ql, qr) +
               query(2 * node + 2, mid + 1, r, ql, qr);
    }

    void updateUtil(int node, int l, int r, int idx, int newVal) {
        if (l == r) {
            tree[node] = newVal; // Update leaf
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid) updateUtil(2 * node + 1, l, mid, idx, newVal);
        else            updateUtil(2 * node + 2, mid + 1, r, idx, newVal);

        // Update ancestors after child update
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n, 0);
        build(arr, 0, 0, n - 1);
    }

    int rangeSum(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    void update(int idx, int newVal) {
        if (idx < 0 || idx >= n) return; // Boundary check
        updateUtil(0, 0, n - 1, idx, newVal);
    }
};

int main() {
    vector<int> arr = {1, 4, 5, 9, 10, 12};
    SegmentTree st(arr);

    cout << "Initial sum of [0, 5]: " << st.rangeSum(0, 5) << endl;

    // Update index 3 (value 9) to 7
    cout << "\nUpdating arr[3] from 9 to 7...\n";
    st.update(3, 7);

    cout << "New sum of [0, 5]: " << st.rangeSum(0, 5) << endl; // Updated total
    cout << "Sum of [3, 5]: " << st.rangeSum(3, 5) << endl;

    return 0;
}
