#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 1143. 最长公共子序列 (Longest Common Subsequence)
 *
 * 给定两个字符串 text1 和 text2，返回它们的最长公共子序列的长度。
 *
 * 动态规划思路：
 * - dp[i][j] 表示 text1[0:i] 和 text2[0:j] 的最长公共子序列长度
 * - if text1[i-1] == text2[j-1]: dp[i][j] = dp[i-1][j-1] + 1
 * - else: dp[i][j] = max(dp[i-1][j], dp[i][j-1])
 */
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= m; i++) {
        int prev = 0;
        for (int j = 1; j <= n; j++) {
            int temp = dp[j];
            if (text1[i - 1] == text2[j - 1]) {
                dp[j] = prev + 1;
            } else {
                dp[j] = max(dp[j], dp[j - 1]);
            }
            prev = temp;
        }
    }

    return dp[n];
}

int main() {
    // 测试用例1: "abcde" 和 "ace"
    assert(longestCommonSubsequence("abcde", "ace") == 3);
    cout << "测试1通过: abcde, ace -> 3" << endl;

    // 测试用例2: "abc" 和 "def"
    assert(longestCommonSubsequence("abc", "def") == 0);
    cout << "测试2通过: abc, def -> 0" << endl;

    // 测试用例3: "abcabc" 和 "abcabc"
    assert(longestCommonSubsequence("abcabc", "abcabc") == 6);
    cout << "测试3通过: abcabc, abcabc -> 6" << endl;

    cout << "所有测试用例通过!" << endl;
    return 0;
}
