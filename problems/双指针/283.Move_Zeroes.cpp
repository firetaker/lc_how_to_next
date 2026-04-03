#include <iostream>
#include <vector>
using namespace std;

// 283. 移动零 (Move Zeroes)
//
// 题目: 给定一个数组 nums，将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
//       必须在原地修改数组，且最少操作次数。
//
// 算法: 快慢指针
//       - 慢指针 left 指向已处理区域（不含零）的最后一个位置
//       - 快指针 right 遍历数组，寻找非零元素
//       - 找到非零元素时与 left 位置交换，然后 left 右移
//       - 时间复杂度 O(n)，空间复杂度 O(1)

void moveZeroes(vector<int>& nums) {
    int left = 0;
    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] != 0) {
            swap(nums[left], nums[right]);
            left++;
        }
    }
}

int main() {
    // 测试用例1: 标准情况
    vector<int> nz1 = {0, 1, 0, 3, 12};
    moveZeroes(nz1);
    cout << "[0, 1, 0, 3, 12] -> ";
    for (int x : nz1) cout << x << " ";
    cout << endl;  // 预期: 1 3 12 0 0

    // 测试用例2: 零在前面
    vector<int> nz2 = {0, 0, 1};
    moveZeroes(nz2);
    cout << "[0, 0, 1] -> ";
    for (int x : nz2) cout << x << " ";
    cout << endl;  // 预期: 1 0 0

    // 测试用例3: 全为零
    vector<int> nz3 = {0, 0, 0};
    moveZeroes(nz3);
    cout << "[0, 0, 0] -> ";
    for (int x : nz3) cout << x << " ";
    cout << endl;  // 预期: 0 0 0

    return 0;
}
