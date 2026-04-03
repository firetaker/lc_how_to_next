#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size(), count = 0;
    function<void(int,int)> dfs = [&](int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == '0') return;
        grid[r][c] = '0';
        for (auto& d : vector<pair<int,int>>{{0,1},{0,-1},{1,0},{-1,0}}) dfs(r+d.first, c+d.second);
    };
    for (int r = 0; r < m; r++)
        for (int c = 0; c < n; c++)
            if (grid[r][c] == '1') { count++; dfs(r, c); }
    return count;
}

int main() {
    // 测试用例
    vector<vector<char>> grid1 = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    cout << numIslands(grid1) << endl;  // 预期: 1
    vector<vector<char>> grid2 = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
    cout << numIslands(grid2) << endl;  // 预期: 3
    return 0;
}
