#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/**
 * 63. 不同路径 II (Unique Paths II)
 *
 * 有障碍物的网格中，机器人从左上角到右下角的不同路径数。
 *
 * 动态规划思路：
 * - dp[i][j] 表示到达 (i,j) 的不同路径数
 * - 如果是障碍: dp[i][j] = 0
 * - 否则: dp[i][j] = dp[i-1][j] + dp[i][j-1]
 */
int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) return 0;

    int m = grid.size(), n = grid[0].size();
    if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) return 0;

    vector<int> dp(n, 0);
    dp[0] = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                dp[j] = 0;
            } else if (j > 0) {
                dp[j] += dp[j - 1];
            }
        }
    }

    return dp[n - 1];
}

int main() {
    // 测试用例1: 有障碍物
    vector<vector<int>> grid1 = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    assert(uniquePathsWithObstacles(grid1) == 2);
    cout << "测试1通过: 有障碍 -> 2" << endl;

    // 测试用例2: 起点即障碍
    vector<vector<int>> grid2 = {{1, 0}};
    assert(uniquePathsWithObstacles(grid2) == 0);
    cout << "测试2通过: 起点障碍 -> 0" << endl;

    // 测试用例3: 无障碍
    vector<vector<int>> grid3 = {{0, 0}, {0, 0}};
    assert(uniquePathsWithObstacles(grid3) == 2);
    cout << "测试3通过: 无障碍 -> 2" << endl;

    cout << "所有测试用例通过!" << endl;
    return 0;
}
