/**
 * LeetCode #42: 接雨水
 * 题目: 给定 n 个非负整数表示的高度图，计算能接多少雨水。
 * 解法: 前后缀分解 / 相向双指针 - 预处理每个位置左右最高墙，
 *       第 i 位能接的雨水 = max(0, min(left_max[i], right_max[i]) - height[i])。
 *       优化: 相向双指针只需 O(1) 额外空间。
 * 时间 O(n)，空间 O(n)（双指针优化为 O(1)）。
 */

#include <iostream>
#include <vector>
using namespace std;

// 前后缀分解版本
class Solution1 {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int n = height.size();
        vector<int> left_max(n), right_max(n);
        left_max[0] = height[0];
        for (int i = 1; i < n; ++i)
            left_max[i] = max(left_max[i - 1], height[i]);
        right_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i)
            right_max[i] = max(right_max[i + 1], height[i]);
        int water = 0;
        for (int i = 0; i < n; ++i)
            water += max(0, min(left_max[i], right_max[i]) - height[i]);
        return water;
    }
};

// 相向双指针优化版本 O(1) 空间
class Solution2 {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0;
        int water = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= left_max)
                    left_max = height[left];
                else
                    water += left_max - height[left];
                ++left;
            } else {
                if (height[right] >= right_max)
                    right_max = height[right];
                else
                    water += right_max - height[right];
                --right;
            }
        }
        return water;
    }
};

int main() {
    Solution1 sol1;
    Solution2 sol2;
    vector<int> h = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << sol1.trap(h) << endl; // 6
    cout << sol2.trap(h) << endl; // 6
    return 0;
}
