#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 53. 最大子数组和 (Maximum Subarray)
 *
 * 给定一个整数数组 nums，找到一个具有最大和的连续子数组，返回其最大和。
 *
 * 动态规划思路：
 * - dp[i] 表示以第 i 个元素结尾的最大子数组和
 * - dp[i] = max(dp[i-1] + nums[i], nums[i])
 */
int maxSubArray(vector<int>& nums) {
    if (nums.empty()) return 0;

    int prev = nums[0];
    int maxResult = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        int current = max(prev + nums[i], nums[i]);
        maxResult = max(maxResult, current);
        prev = current;
    }

    return maxResult;
}

int main() {
    // 测试用例1: 普通情况
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    assert(maxSubArray(nums1) == 6);
    cout << "测试1通过: [-2,1,-3,4,-1,2,1,-5,4] -> 6" << endl;

    // 测试用例2: 全正数
    vector<int> nums2 = {1, 2, 3, 4, 5};
    assert(maxSubArray(nums2) == 15);
    cout << "测试2通过: [1,2,3,4,5] -> 15" << endl;

    // 测试用例3: 全负数
    vector<int> nums3 = {-1, -2, -3, -4};
    assert(maxSubArray(nums3) == -1);
    cout << "测试3通过: [-1,-2,-3,-4] -> -1" << endl;

    cout << "所有测试用例通过!" << endl;
    return 0;
}
