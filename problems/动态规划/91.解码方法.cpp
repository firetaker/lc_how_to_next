#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/**
 * 91. 解码方法 (Decode Ways)
 *
 * 给定数字字符串 s，计算解码方法的总数。
 *
 * 动态规划思路：
 * - dp[i] 表示 s[0:i] 的解码方法总数
 * - dp[i] = dp[i-1] (if s[i-1] != '0') + dp[i-2] (if 10 <= s[i-2:i] <= 26)
 */
int numDecodings(string s) {
    if (s.empty() || s[0] == '0') return 0;

    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (s[i - 1] != '0') {
            dp[i] += dp[i - 1];
        }

        int two_digit = stoi(s.substr(i - 2, 2));
        if (two_digit >= 10 && two_digit <= 26) {
            dp[i] += dp[i - 2];
        }
    }

    return dp[n];
}

int main() {
    // 测试用例1: "12"
    assert(numDecodings("12") == 2);
    cout << "测试1通过: 12 -> 2" << endl;

    // 测试用例2: "226"
    assert(numDecodings("226") == 3);
    cout << "测试2通过: 226 -> 3" << endl;

    // 测试用例3: "0"
    assert(numDecodings("0") == 0);
    cout << "测试3通过: 0 -> 0" << endl;

    cout << "所有测试用例通过!" << endl;
    return 0;
}
