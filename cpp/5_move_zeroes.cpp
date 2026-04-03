/**
 * LeetCode #283: 移动零
 * 题目: 给定一个数组，将所有 0 移动到数组末尾，同时保持非零元素的相对顺序。
 * 解法: 双指针 - left 指向已处理区域的最后一个非零位置（左侧都是非零元素），
 *       right 遍历数组。遇到非零元素时与 left 位置交换，left 右移。
 * 时间 O(n)，空间 O(1)。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] != 0) {
                swap(nums[left], nums[right]);
                ++left;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> arr = {0, 1, 0, 3, 12};
    sol.moveZeroes(arr);
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl; // 1 3 12 0 0
    return 0;
}
