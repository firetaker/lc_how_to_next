/**
 * LeetCode #15: 三数之和
 * 题目: 给定一个数组，找出所有和为0的不重复三元组。
 * 解法: 排序 + 双指针 - 先对数组排序，固定一个数 i，然后使用双指针
 *       left=i+1, right=n-1 找剩余两个数。需跳过重复元素去重。
 * 时间 O(n^2)，空间 O(1)（不计结果空间）。
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = n - 1;
            while (left < right) {
                int total = nums[i] + nums[left] + nums[right];
                if (total == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    ++left;
                    --right;
                    while (left < right && nums[left] == nums[left - 1]) ++left;
                    while (left < right && nums[right] == nums[right + 1]) --right;
                } else if (total < 0) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    auto res = sol.threeSum(nums);
    for (const auto& tri : res) {
        cout << "[" << tri[0] << ", " << tri[1] << ", " << tri[2] << "]" << endl;
    }
    // [[-1, -1, 2], [-1, 0, 1]]
    return 0;
}
