#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

/**
 * 128. 最长连续序列 (Longest Consecutive Sequence)
 * 题目: 给定未排序整数数组，找出最长连续序列的长度。
 * 
 * 算法: 使用 Set 存储所有数字，只从序列起点开始扩展（num-1 不存在）
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> num_set(nums.begin(), nums.end());
    int longest = 0;
    
    for (int num : num_set) {
        // 只从序列起点开始扩展
        if (!num_set.count(num - 1)) {
            int current = num;
            int streak = 1;
            while (num_set.count(current + 1)) {
                current++;
                streak++;
            }
            longest = max(longest, streak);
        }
    }
    
    return longest;
}

int main() {
    // 测试用例
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    cout << "输入: [100, 4, 200, 1, 3, 2] -> 输出: " << longestConsecutive(nums1) << endl;  // 预期: 4
    
    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << "输入: [0, 3, 7, 2, 5, 8, 4, 6, 0, 1] -> 输出: " << longestConsecutive(nums2) << endl;  // 预期: 9
    
    vector<int> nums3 = {};
    cout << "输入: [] -> 输出: " << longestConsecutive(nums3) << endl;  // 预期: 0
    
    vector<int> nums4 = {1, 2, 3, 4, 5};
    cout << "输入: [1, 2, 3, 4, 5] -> 输出: " << longestConsecutive(nums4) << endl;  // 预期: 5
    
    return 0;
}
