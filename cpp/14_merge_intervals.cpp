/**
 * LeetCode #56: 合并区间
 * 题目: 合并所有重叠的区间。
 * 解法: 按左端点排序，然后依次合并 - 维护当前区间，
 *       若下一区间左端点 <= cur_r 则合并，否则开新区间。
 * 时间 O(n log n)，空间 O(1)。
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for (size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= result.back()[1])
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            else
                result.push_back(intervals[i]);
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    auto res = sol.merge(intervals);
    for (auto& v : res)
        cout << "[" << v[0] << "," << v[1] << "] ";
    cout << endl;
    return 0;
}
