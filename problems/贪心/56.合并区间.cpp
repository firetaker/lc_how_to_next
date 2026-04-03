#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result = {intervals[0]};
    for (auto& interval : intervals) {
        if (interval[0] <= result.back()[1])
            result.back()[1] = max(result.back()[1], interval[1]);
        else
            result.push_back(interval);
    }
    return result;
}

int main() {
    // 测试用例
    vector<vector<int>> i1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    auto r1 = merge(i1);
    for (auto& row : r1) cout << "[" << row[0] << "," << row[1] << "] ";
    cout << endl;  // 预期: [1,6] [8,10] [15,18]

    vector<vector<int>> i2 = {{1, 4}, {4, 5}};
    auto r2 = merge(i2);
    for (auto& row : r2) cout << "[" << row[0] << "," << row[1] << "] ";
    cout << endl;  // 预期: [1,5]

    vector<vector<int>> i3 = {{1, 4}, {0, 4}};
    auto r3 = merge(i3);
    for (auto& row : r3) cout << "[" << row[0] << "," << row[1] << "] ";
    cout << endl;  // 预期: [0,4]

    return 0;
}
