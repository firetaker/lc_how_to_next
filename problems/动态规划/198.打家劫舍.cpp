#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 198. 打家劫舍 (House Robber)
 *
 * 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有现金，
 * 但相邻的房屋装有防盗系统，如果两间相邻的房屋在同一晚上被闯入，会自动报警。
 *
 * 动态规划思路：
 * - dp[i] 表示偷窃第 i 间房屋能获得的最高金额
 * - dp[i] = max(dp[i-1], dp[i-2] + nums[i])
 */
int rob(vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];

    int prev2 = 0;       // dp[i-2]
    int prev1 = nums[0]; // dp[i-1]

    for (int i = 1; i < nums.size(); i++) {
        int current = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

int main() {
    // 测试用例1: [1,2,3,1]
    vector<int> nums1 = {1, 2, 3, 1};
    assert(rob(nums1) == 4);
    cout << "测试1通过: [1,2,3,1] -> 4" << endl;

    // 测试用例2: [2,7,9,3,1]
    vector<int> nums2 = {2, 7, 9, 3, 1};
    assert(rob(nums2) == 12);
    cout << "测试2通过: [2,7,9,3,1] -> 12" << endl;

    // 测试用例3: 全为0
    vector<int> nums3 = {0, 0, 0};
    assert(rob(nums3) == 0);
    cout << "测试3通过: [0,0,0] -> 0" << endl;

    cout << "所有测试用例通过!" << endl;
    return 0;
}
