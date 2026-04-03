/**
 * LeetCode #438: 找到字符串中所有字母异位词
 * 题目: 给定字符串 s 和 p，找出 s 中所有 p 的字母异位词的起始位置。
 * 解法: 不定长滑动窗口 + 字符计数 - 用数组记录目标字符串 p 的字符频次，
 *       在 s 上维护一个等长窗口，字符频次完全匹配时记录起点索引。
 * 时间 O(n)，空间 O(1)（字符集大小固定为26）。
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> need(26, 0), window(26, 0);
        for (char ch : p) need[ch - 'a']++;
        int left = 0, right = 0;
        vector<int> result;
        while (right < s.size()) {
            char ch = s[right++];
            int idx = ch - 'a';
            window[idx]++;
            // 收缩窗口使长度等于 p 的长度
            while (right - left >= p.size()) {
                bool is_anagram = true;
                for (int i = 0; i < 26; ++i) {
                    if (need[i] != window[i]) { is_anagram = false; break; }
                }
                if (is_anagram) result.push_back(left);
                char left_ch = s[left++];
                window[left_ch - 'a']--;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    auto res1 = sol.findAnagrams("cbaebabacd", "abc");
    for (int i : res1) cout << i << " "; // 0 6
    cout << endl;
    auto res2 = sol.findAnagrams("abab", "ab");
    for (int i : res2) cout << i << " "; // 0 1 2
    cout << endl;
    return 0;
}
