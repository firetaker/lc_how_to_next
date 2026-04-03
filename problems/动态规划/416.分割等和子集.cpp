#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 416. 分割等和子集 (Partition Equal Subset Sum)
 *
 * 判断是否可以将数组分成两个和相等的子集。
 *
 * 动态规划思路：
 * - 转换为 0-1 背包问题：是否能挑选一些元素使其和等于 sum/2
 * - dp[i] 表示是否能凑成和 i
 */
bool canPartition(vector<int>& nums) {
    int total = 0;
    for (int num : nums) total += num;
    if (total % 2 != 0) return false;

    int target = total / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int num : nums) {
        for (int i = target; i >= num; i--) {
            dp[i] = dp[i] || dp[i - num];
        }
    }

    return dp[target];
}

int main() {
    // 测试用例1: [1,5,11,5]
    vector<int> nums1 = {1, 5, 11, 5};
    assert(canPartition(nums1) == true);
    cout << "测试1通过: [1,5,11,5] -> true" << endl;

    // 测试用例2: [1,2,3,5]
    vector<int> nums2 = {1, 2, 3, 5};
    assert(canPartition(nums2) == false);
    cout << "测试2通过: [1,2,3,5] -> false" << endl;

    // 测试用例3: [1,1]
    vector<int> nums3 = {1, 1};
    assert(canPartition(nums3) == true);
    cout << "测试3通过: [1,1] -> true" << endl;

    cout << "所有测试用例通过!" << endl;
    return 0;
}
