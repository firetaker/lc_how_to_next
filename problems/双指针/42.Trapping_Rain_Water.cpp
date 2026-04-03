#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 42. 接雨水 (Trapping Rain Water)
//
// 题目: 给定 n 个非负整数表示宽度为 1 的条形图，计算下雨后能接多少雨水。
//
// 算法: 相向双指针 + 前后缀分解
//       - 维护 left_max 和 right_max 分别记录左右两侧的最大高度
//       - 从低的一端向中间推进
//       - 每个位置的水量 = min(左侧最高, 右侧最高) - 当前高度
//       - 时间复杂度 O(n)，空间复杂度 O(1)

int trap(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int left_max = 0, right_max = 0;
    int water = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            left_max = max(left_max, height[left]);
            water += left_max - height[left];
            left++;
        } else {
            right_max = max(right_max, height[right]);
            water += right_max - height[right];
            right--;
        }
    }
    return water;
}

int main() {
    // 测试用例1: 标准情况
    vector<int> ht1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "[0,1,0,2,1,0,1,3,2,1,2,1] -> " << trap(ht1) << endl;  // 预期: 6

    // 测试用例2: 简单情况
    vector<int> ht2 = {4, 2, 0, 3, 2, 5};
    cout << "[4,2,0,3,2,5] -> " << trap(ht2) << endl;  // 预期: 9

    // 测试用例3: 空数组
    vector<int> ht3 = {};
    cout << "[] -> " << trap(ht3) << endl;  // 预期: 0

    return 0;
}
