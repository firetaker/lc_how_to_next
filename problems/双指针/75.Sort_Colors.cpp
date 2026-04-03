#include <iostream>
#include <vector>
using namespace std;

// 75. 颜色分类 (Sort Colors)
//
// 题目: 给定一个包含红色、白色和蓝色，共 n 个元素的数组 nums，
//       原地对它们进行排序，使得相同颜色的元素相邻，并按红色、白色、蓝色的顺序排列。
//       本题中，使用整数 0、1 和 2 分别表示红色、白色和蓝色。
//
// 算法: 荷兰国旗三路指针
//       - left 指针左侧全是 0（红色）
//       - right 指针右侧全是 2（蓝色）
//       - cur 指针遍历数组，遇到 0 或 2 就交换
//       - 时间复杂度 O(n)，空间复杂度 O(1)

void sortColors(vector<int>& nums) {
    int left = 0, cur = 0, right = nums.size() - 1;
    while (cur <= right) {
        if (nums[cur] == 0) {
            swap(nums[left++], nums[cur++]);
        } else if (nums[cur] == 2) {
            swap(nums[cur], nums[right--]);
        } else {
            cur++;
        }
    }
}

int main() {
    // 测试用例1: 标准情况
    vector<int> sc1 = {2, 0, 2, 1, 1, 0};
    sortColors(sc1);
    cout << "[2,0,2,1,1,0] -> ";
    for (int x : sc1) cout << x << " ";
    cout << endl;  // 预期: 0 0 1 1 2 2

    // 测试用例2: 简单情况
    vector<int> sc2 = {2, 0, 1};
    sortColors(sc2);
    cout << "[2,0,1] -> ";
    for (int x : sc2) cout << x << " ";
    cout << endl;  // 预期: 0 1 2

    // 测试用例3: 全相同颜色
    vector<int> sc3 = {1, 1, 1};
    sortColors(sc3);
    cout << "[1,1,1] -> ";
    for (int x : sc3) cout << x << " ";
    cout << endl;  // 预期: 1 1 1

    return 0;
}
