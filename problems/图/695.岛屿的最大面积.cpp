#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), area = 0;
    function<int(int,int)> dfs = [&](int r, int c) -> int {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) return 0;
        grid[r][c] = 0;
        return 1 + dfs(r+1, c) + dfs(r-1, c) + dfs(r, c+1) + dfs(r, c-1);
    };
    for (int r = 0; r < m; r++)
        for (int c = 0; c < n; c++)
            if (grid[r][c]) area = max(area, dfs(r, c));
    return area;
}

int main() {
    // 测试用例
    vector<vector<int>> grid1 = {{0,0,1,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1},{0,1,1,0,1,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0}};
    cout << maxAreaOfIsland(grid1) << endl;  // 预期: 6
    vector<vector<int>> grid2 = {{0,0,0,0,0,0,0,0}};
    cout << maxAreaOfIsland(grid2) << endl;  // 预期: 0
    vector<vector<int>> grid3 = {{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
    cout << maxAreaOfIsland(grid3) << endl;  // 预期: 4
    return 0;
}
