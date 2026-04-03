#include <iostream>
#include <vector>
#include <string>
using namespace std;

int strStr(string haystack, string needle) {
    if (needle.empty()) return 0;
    int n = haystack.size(), m = needle.size();
    if (n < m) return -1;

    // KMP 前缀表
    vector<int> lps(m, 0);
    int length = 0, i = 1;
    while (i < m) {
        if (needle[i] == needle[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    // KMP 搜索
    i = j = 0;
    while (i < n) {
        if (haystack[i] == needle[j]) {
            i++; j++;
            if (j == m) return i - j;
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return -1;
}

int main() {
    // 测试用例
    cout << strStr("sadbutsad", "sad") << endl;   // 预期: 0
    cout << strStr("leetcode", "leeto") << endl; // 预期: -1
    cout << strStr("aabaabaafa", "aabaaf") << endl; // 预期: 3
    return 0;
}
