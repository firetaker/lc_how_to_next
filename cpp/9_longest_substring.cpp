/**
 * LeetCode #3: 无重复字符的最长子串
 * 题目: 给定一个字符串，找出不含重复字符的最长子串长度。
 * 解法: 滑动窗口 + 哈希表 - 使用左右指针维护一个窗口，
 *       用 unordered_map 记录窗口内字符出现的最新位置。
 *       遇到重复字符时收缩 left 端点直到无重复。
 * 时间 O(n)，空间 O(min(n, sigma))。
 */

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> char_index;
        int left = 0;
        int max_len = 0;
        for (int right = 0; right < s.size(); ++right) {
            char ch = s[right];
            if (char_index.count(ch) && char_index[ch] >= left) {
                left = char_index[ch] + 1;
            }
            char_index[ch] = right;
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};

int main() {
    Solution sol;
    cout << sol.lengthOfLongestSubstring("abcabcbb") << endl; // 3
    cout << sol.lengthOfLongestSubstring("bbbbb") << endl;    // 1
    cout << sol.lengthOfLongestSubstring("pwwkew") << endl;    // 3
    return 0;
}
