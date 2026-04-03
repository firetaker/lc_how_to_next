#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> char_index;
    int left = 0, max_len = 0;
    for (int right = 0; right < s.size(); right++) {
        if (char_index.count(s[right]) && char_index[s[right]] >= left)
            left = char_index[s[right]] + 1;
        char_index[s[right]] = right;
        max_len = max(max_len, right - left + 1);
    }
    return max_len;
}

int main() {
    // 测试用例
    cout << lengthOfLongestSubstring("abcabcbb") << endl;  // 预期: 3
    cout << lengthOfLongestSubstring("bbbbb") << endl;    // 预期: 1
    cout << lengthOfLongestSubstring("pwwkew") << endl;   // 预期: 3
    cout << lengthOfLongestSubstring("") << endl;          // 预期: 0

    return 0;
}
