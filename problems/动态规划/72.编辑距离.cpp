#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 72. 编辑距离 (Edit Distance)
 *
 * 给你两个单词 word1 和 word2，计算将 word1 转换成 word2 所使用的最少操作数。
 * 操作：插入、删除、替换
 *
 * 动态规划思路：
 * - dp[i][j] 表示 word1[0:i] 转换成 word2[0:j] 的最少操作数
 * - if word1[i-1] == word2[j-1]: dp[i][j] = dp[i-1][j-1]
 * - else: dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
 */
int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            }
        }
    }

    return dp[m][n];
}

int main() {
    // 测试用例1: horse -> ros
    assert(minDistance("horse", "ros") == 3);
    cout << "测试1通过: horse -> ros = 3" << endl;

    // 测试用例2: 相同单词
    assert(minDistance("intention", "intention") == 0);
    cout << "测试2通过: intention -> intention = 0" << endl;

    // 测试用例3: 空字符串
    assert(minDistance("", "abc") == 3);
    cout << "测试3通过: '' -> abc = 3" << endl;

    cout << "所有测试用例通过!" << endl;
    return 0;
}
