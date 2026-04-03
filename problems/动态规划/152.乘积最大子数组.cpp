#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 152. 乘积最大子数组 (Maximum Product Subarray)
 *
 * 找出乘积最大的连续子数组。
 *
 * 动态规划思路：
 * - 需要同时维护最大值和最小值（因为负数会使最小变最大）
 * - max_dp[i] = max(nums[i], max_dp[i-1]*nums[i], min_dp[i-1]*nums[i])
 * - min_dp[i] = min(nums[i], max_dp[i-1]*nums[i], min_dp[i-1]*nums[i])
 */
int maxProduct(vector<int>& nums) {
    if (nums.empty()) return 0;

    int result = nums[0];
    int max_dp = nums[0];
    int min_dp = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        int old_max = max_dp;
        max_dp = max({nums[i], max_dp * nums[i], min_dp * nums[i]});
        min_dp = min({nums[i], old_max * nums[i], min_dp * nums[i]});
        result = max(result, max_dp);
    }

    return result;
}

int main() {
    // 测试用例1: [2,3,-2,4]
    vector<int> nums1 = {2, 3, -2, 4};
    assert(maxProduct(nums1) == 6);
    cout << "测试1通过: [2,3,-2,4] -> 6" << endl;

    // 测试用例2: 全负数
    vector<int> nums2 = {-2, -3, -1};
    assert(maxProduct(nums2) == 6);
    cout << "测试2通过: [-2,-3,-1] -> 6" << endl;

    // 测试用例3: 有0
    vector<int> nums3 = {-2, 0, -1};
    assert(maxProduct(nums3) == 0);
    cout << "测试3通过: [-2,0,-1] -> 0" << endl;

    cout << "所有测试用例通过!" << endl;
    return 0;
}
