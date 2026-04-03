#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 11. 盛最多水的容器 (Container With Most Water)
//
// 题目: 给定 n 个非负整数，每个数代表一条垂直线段，位置 i 的线段高度为 ai。
//       两线段 i 和 j 之间的面积定义为 min(ai, aj) * |j - i|。
//       找出其中的两条线段，使它们组成的容器能装最多的水。
//
// 算法: 相向双指针
//       - 左指针指向起始位置，右指针指向结束位置
//       - 每次移动较短边的指针（因为移动较长边只会减少宽度）
//       - 时间复杂度 O(n)，空间复杂度 O(1)

int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int max_water = 0;
    while (left < right) {
        int width = right - left;
        int h = min(height[left], height[right]);
        max_water = max(max_water, width * h);
        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return max_water;
}

int main() {
    // 测试用例1: 标准情况
    vector<int> h1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "height = [1, 8, 6, 2, 5, 4, 8, 3, 7] -> " << maxArea(h1) << endl;  // 预期: 49

    // 测试用例2: 最小情况
    vector<int> h2 = {1, 1};
    cout << "height = [1, 1] -> " << maxArea(h2) << endl;  // 预期: 1

    // 测试用例3: 对称情况
    vector<int> h3 = {4, 3, 2, 1, 4};
    cout << "height = [4, 3, 2, 1, 4] -> " << maxArea(h3) << endl;  // 预期: 16

    return 0;
}
