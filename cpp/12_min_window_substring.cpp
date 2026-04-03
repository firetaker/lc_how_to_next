/**
 * LeetCode #76: 最小覆盖子串
 * 题目: 在 s 中找出包含 t 所有字符的最小子串。
 * 解法: 滑动窗口 + 字符计数 - need 记录 t 的字符需求，
 *       less 变量表示还有多少种字符的需求未满足。
 *       窗口扩展到满足条件后收缩。O(n)，O(1) 空间。
 */

#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(256, 0), window(256, 0);
        for (char ch : t) need[(int)ch]++;
        int less = 0;
        for (int x : need) if (x > 0) less++;
        int left = 0;
        int min_len = INT_MAX;
        int min_start = 0;
        for (int right = 0; right < (int)s.size(); ++right) {
            int idx = (int)s[right];
            if (need[idx] > 0) {
                window[idx]++;
                if (window[idx] == need[idx]) less--;
            }
            while (less == 0) {
                int cur_len = right - left + 1;
                if (cur_len < min_len) {
                    min_len = cur_len;
                    min_start = left;
                }
                int lidx = (int)s[left];
                if (need[lidx] > 0) {
                    if (window[lidx] == need[lidx]) less++;
                    window[lidx]--;
                }
                ++left;
            }
        }
        return min_len == INT_MAX ? "" : s.substr(min_start, min_len);
    }
};

int main() {
    Solution sol;
    cout << sol.minWindow("ADOBECODEBANC", "ABC") << endl; // BANC
    return 0;
}
