#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/**
 * 64. 最小路径和 (Minimum Path Sum)
 *
 * 网格中找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 *
 * 动态规划思路：
 * - dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])
 */
int minPathSum(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) return 0;

    int m = grid.size(), n = grid[0].size();
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0) {
                dp[j] += grid[i][j];
            } else {
                dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
            }
        }
    }

    return dp[n - 1];
}

int main() {
    // 测试用例1: [[1,3,1],[1,5,1],[4,2,1]]
    vector<vector<int>> grid1 = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    assert(minPathSum(grid1) == 7);
    cout << "测试1通过: 网格1 -> 7" << endl;

    // 测试用例2: 单元素
    vector<vector<int>> grid2 = {{5}};
    assert(minPathSum(grid2) == 5);
    cout << "测试2通过: [[5]] -> 5" << endl;

    // 测试用例3: [[1,2],[1,1]]
    vector<vector<int>> grid3 = {{1, 2}, {1, 1}};
    assert(minPathSum(grid3) == 3);
    cout << "测试3通过: [[1,2],[1,1]] -> 3" << endl;

    cout << "所有测试用例通过!" << endl;
    return 0;
}
