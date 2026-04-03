/**
 * LeetCode #41: 缺失的第一个正数
 * 题目: 找未出现的最小正整数。要求 O(n) 时间，O(1) 空间。
 * 解法: 索引与值匹配 - 将正数 x (1 <= x <= n) 放到索引 x-1 处。
 *       第一遍：将数放到正确位置
 *       第二遍：第一个 nums[i] != i+1 的位置 i+1 即为答案
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i < n) {
            int x = nums[i];
            if (1 <= x && x <= n && nums[x - 1] != x)
                swap(nums[i], nums[x - 1]);
            else
                ++i;
        }
        for (int i = 0; i < n; ++i)
            if (nums[i] != i + 1) return i + 1;
        return n + 1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 4, -1, 1};
    cout << sol.firstMissingPositive(nums) << endl; // 2
    return 0;
}
