#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;
    sort(intervals.begin(), intervals.end(),
         [](auto& a, auto& b) { return a[1] < b[1]; });
    int count = 0, end = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] < end) count++;
        else end = intervals[i][1];
    }
    return count;
}

int main() {
    // 测试用例
    vector<vector<int>> i1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    cout << eraseOverlapIntervals(i1) << endl;  // 预期: 0

    vector<vector<int>> i2 = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << eraseOverlapIntervals(i2) << endl;  // 预期: 1

    vector<vector<int>> i3 = {{1, 2}, {1, 2}, {1, 2}};
    cout << eraseOverlapIntervals(i3) << endl;  // 预期: 2

    return 0;
}
