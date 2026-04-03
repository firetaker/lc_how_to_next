/**
 * LeetCode #128: 最长连续序列
 * 题目: 给定一个未排序的整数数组，找出最长连续序列的长度。
 * 解法: 哈希集合 - 将所有元素加入 unordered_set，遍历每个元素作为起点，
 *       只从连续序列的最小元素开始扩展（检测 num-1 不在集合中），
 *       从而避免重复遍历。
 * 时间 O(n)，空间 O(n)。
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int> num_set(nums.begin(), nums.end());
        int longest = 0;
        for (int num : num_set) {
            // 只从连续序列的最小元素开始
            if (num_set.find(num - 1) == num_set.end()) {
                int cur = num;
                int cur_len = 1;
                while (num_set.find(cur + 1) != num_set.end()) {
                    ++cur;
                    ++cur_len;
                }
                longest = max(longest, cur_len);
            }
        }
        return longest;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    cout << sol.longestConsecutive(nums1) << endl; // 4

    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << sol.longestConsecutive(nums2) << endl; // 9
    return 0;
}
