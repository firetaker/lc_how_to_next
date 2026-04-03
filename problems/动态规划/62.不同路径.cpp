#include <iostream>
#include <vector>
using namespace std;

/**
 * 62. 不同路径 (Unique Paths)
 *
 * 机器人从左上角到右下角，每次只能向下或向右移动，问有多少条不同路径。
 *
 * 动态规划思路：
 * - dp[i][j] = dp[i-1][j] + dp[i][j-1]
 * - 空间优化为一维数组
 */
int uniquePaths(int m, int n) {
    vector<int> dp(n, 1);

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[j] += dp[j - 1];
        }
    }

    return dp[n - 1];
}

int main() {
    // 测试用例1: 3x7 网格
    assert(uniquePaths(3, 7) == 28);
    cout << "测试1通过: 3x7 -> 28" << endl;

    // 测试用例2: 1x1 网格
    assert(uniquePaths(1, 1) == 1);
    cout << "测试2通过: 1x1 -> 1" << endl;

    // 测试用例3: 2x2 网格
    assert(uniquePaths(2, 2) == 2);
    cout << "测试3通过: 2x2 -> 2" << endl;

    cout << "所有测试用例通过!" << endl;
    return 0;
}
