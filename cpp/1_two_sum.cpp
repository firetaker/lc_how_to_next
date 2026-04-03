/**
 * LeetCode #1: 两数之和
 * 题目: 给定一个整数数组 nums 和一个目标值 target，请你在数组中找出和为目标值的两个整数。
 * 解法: 哈希表 - 遍历时用 unordered_map 记录已遍历元素及其索引，
 *       对于当前元素 nums[i]，查找 target - nums[i] 是否在字典中。
 * 时间 O(n)，空间 O(n)。
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index_map; // val -> index
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (index_map.count(complement)) {
                return {index_map[complement], i};
            }
            index_map[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {2, 7, 11, 15};
    auto res1 = sol.twoSum(nums1, 9);
    cout << "[" << res1[0] << ", " << res1[1] << "]" << endl; // [0, 1]

    vector<int> nums2 = {3, 2, 4};
    auto res2 = sol.twoSum(nums2, 6);
    cout << "[" << res2[0] << ", " << res2[1] << "]" << endl; // [1, 2]

    vector<int> nums3 = {3, 3};
    auto res3 = sol.twoSum(nums3, 6);
    cout << "[" << res3[0] << ", " << res3[1] << "]" << endl; // [0, 1]
    return 0;
}
