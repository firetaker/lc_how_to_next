#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

string minWindow(string s, string t) {
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;

    int left = 0, valid = 0, start = 0, min_len = INT_MAX;
    for (int right = 0; right < s.size(); right++) {
        char c = s[right];
        if (need.count(c)) {
            window[c]++;
            if (window[c] >= need[c]) valid++;
        }
        while (valid == need.size()) {
            if (right - left + 1 < min_len) {
                start = left;
                min_len = right - left + 1;
            }
            char d = s[left];
            if (need.count(d)) {
                if (window[d] <= need[d]) valid--;
                window[d]--;
            }
            left++;
        }
    }
    return min_len == INT_MAX ? "" : s.substr(start, min_len);
}

int main() {
    // 测试用例
    cout << minWindow("ADOBECODEBANC", "ABC") << endl;  // 预期: BANC
    cout << minWindow("a", "a") << endl;               // 预期: a
    cout << minWindow("a", "b") << endl;               // 预期: (empty)

    return 0;
}
