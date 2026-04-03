/**
 * LeetCode #189: 轮转数组
 * 题目: 将数组向右轮转 k 个位置。
 * 解法: 三次反转 - 整体反转 → 前 k%n 反转 → 后 n-k%n 反转。
 * 等价于将尾部 k%n 个元素移到前面。O(n)，O(1)。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        auto reverse_range = [&](int l, int r) {
            while (l < r) swap(nums[l++], nums[r--]);
        };
        reverse_range(0, n - 1);
        reverse_range(0, k - 1);
        reverse_range(k, n - 1);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {-1, -100, 3, 99};
    sol.rotate(arr, 2);
    for (int v : arr) cout << v << " "; // 3 99 -1 -100
    cout << endl;
    return 0;
}
