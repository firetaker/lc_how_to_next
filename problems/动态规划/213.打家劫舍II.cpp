#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 213. 打家劫舍 II (House Robber II)
 *
 * 房屋围成一圈，第一间和最后一间不能同时偷。
 *
 * 动态规划思路：
 * - 分两种情况：不偷第一间或不偷最后一间，取最大值
 */
int robLinear(vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];

    int prev2 = 0;
    int prev1 = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        int current = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

int rob(vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];

    // 两种情况取最大
    vector<int> nums1(nums.begin() + 1, nums.end());
    vector<int> nums2(nums.begin(), nums.end() - 1);

    return max(robLinear(nums1), robLinear(nums2));
}

int main() {
    // 测试用例1: [2,3,2]
    vector<int> nums1 = {2, 3, 2};
    assert(rob(nums1) == 3);
    cout << "测试1通过: [2,3,2] -> 3" << endl;

    // 测试用例2: [1,2,3,1]
    vector<int> nums2 = {1, 2, 3, 1};
    assert(rob(nums2) == 4);
    cout << "测试2通过: [1,2,3,1] -> 4" << endl;

    // 测试用例3: [1,2,3]
    vector<int> nums3 = {1, 2, 3};
    assert(rob(nums3) == 3);
    cout << "测试3通过: [1,2,3] -> 3" << endl;

    cout << "所有测试用例通过!" << endl;
    return 0;
}
