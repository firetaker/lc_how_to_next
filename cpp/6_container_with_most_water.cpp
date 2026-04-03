/**
 * LeetCode #11: 盛最多水的容器
 * 题目: 给定一个 height 数组，每条垂线宽度为1，求能盛放的最大水量。
 * 解法: 相向双指针 - 左右指针向中间移动，每次移动较短的那条边，
 *       因为水量由较短边决定。每次更新最大面积。
 * 时间 O(n)，空间 O(1)。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_water = 0;
        while (left < right) {
            int h = min(height[left], height[right]);
            int w = right - left;
            max_water = max(max_water, h * w);
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return max_water;
    }
};

int main() {
    Solution sol;
    vector<int> h1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << sol.maxArea(h1) << endl; // 49

    vector<int> h2 = {1, 1};
    cout << sol.maxArea(h2) << endl; // 1
    return 0;
}
