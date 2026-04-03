#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 300. 最长递增子序列 (Longest Increasing Subsequence)
 *
 * 给定一个整数数组 nums，找到其中最长严格递增子序列的长度。
 *
 * 动态规划思路：
 * - dp[i] 表示以第 i 个元素结尾的最长递增子序列长度
 * - dp[i] = max(dp[j] + 1) for j in [0, i-1] if nums[j] < nums[i]
 */
int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;

    int n = nums.size();
    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    // 测试用例1: 普通情况
    vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    assert(lengthOfLIS(nums1) == 4);
    cout << "测试1通过: [10,9,2,5,3,7,101,18] -> 4" << endl;

    // 测试用例2: 全降序
    vector<int> nums2 = {5, 4, 3, 2, 1};
    assert(lengthOfLIS(nums2) == 1);
    cout << "测试2通过: [5,4,3,2,1] -> 1" << endl;

    // 测试用例3: 全升序
    vector<int> nums3 = {1, 2, 3, 4, 5};
    assert(lengthOfLIS(nums3) == 5);
    cout << "测试3通过: [1,2,3,4,5] -> 5" << endl;

    cout << "所有测试用例通过!" << endl;
    return 0;
}
