/**
 * LeetCode #238: 除自身以外数组的乘积
 * 题目: 返回 answer[i] = 除 nums[i] 以外所有元素的乘积。
 * 解法: 前后缀分解 - answer[i] = prefix[i-1] * suffix[i+1]。
 *       两次遍历完成。O(n)，O(1) 额外空间。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);
        int prefix = 1;
        for (int i = 0; i < n; ++i) {
            answer[i] = prefix;
            prefix *= nums[i];
        }
        int suffix = 1;
        for (int i = n - 1; i >= 0; --i) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }
        return answer;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    auto res = sol.productExceptSelf(nums);
    for (int v : res) cout << v << " "; // 24 12 8 6
    cout << endl;
    return 0;
}
