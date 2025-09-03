#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to store activities with start and finish times
struct Activity {
    int start, finish, index;
    Activity(int s, int f, int i) : start(s), finish(f), index(i) {}
};

bool activityComp(Activity a1, Activity a2) {
    return a1.finish < a2.finish; // sort by finish time
}

int main() {
    // Activities (start, finish)
    vector<Activity> activities = {
        {5, 9, 1},  // W1
        {1, 2, 2},  // W2
        {3, 4, 3},  // W3
        {0, 6, 4},  // W4
        {5, 7, 5},  // W5
        {8, 9, 6}   // W6
    };

    int n = activities.size();
    // Sort activities by finish time
    sort(activities.begin(), activities.end(), activityComp);

    cout << "Selected activities (Greedy): ";
    int lastFinish = -1;
    for (int i = 0; i < n; ++i) {
        if (activities[i].start >= lastFinish) {
            cout << "W" << activities[i].index << " ";
            lastFinish = activities[i].finish;
        }
    }
    cout << endl;
    return 0;
}
