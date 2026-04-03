/**
 * LeetCode #239: 滑动窗口最大值
 * 题目: 给定数组和滑动窗口大小 k，返回每个窗口中的最大值。
 * 解法: 单调递减队列 - 维护一个存储索引的 deque，队首始终是当前窗口最大值的索引。
 *       右端点入队时弹出所有小于当前元素的索引（它们永远不会再成为最大值）；
 *       左端点出队时若离开的是队首则弹出。整体 O(n)。
 */

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // 存索引，递减
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            if (dq.front() <= i - k) // 队首过期
                dq.pop_front();
            if (i >= k - 1)
                result.push_back(nums[dq.front()]);
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    auto res = sol.maxSlidingWindow(nums, 3);
    for (int v : res) cout << v << " "; // 3 3 5 5 6 7
    cout << endl;
    return 0;
}
