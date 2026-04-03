/**
 * LeetCode #53: 最大子数组和
 * 题目: 找出连续子数组的最大和（至少包含一个元素）。
 * 解法: 贪心 / DP - cur_sum 记录以当前位置结尾的最大子序和。
 *       若 cur_sum < 0，则从下一个元素重新开始（舍去负累加和）。
 * 时间 O(n)，空间 O(1)。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int cur_sum = 0;
        for (int num : nums) {
            cur_sum = max(cur_sum + num, num);
            ans = max(ans, cur_sum);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << sol.maxSubArray(nums) << endl; // 6
    return 0;
}
