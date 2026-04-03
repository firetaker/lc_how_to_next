#include <iostream>
#include <vector>
using namespace std;

int islandPerimeter(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), perimeter = 0;
    for (int r = 0; r < m; r++)
        for (int c = 0; c < n; c++)
            if (grid[r][c] == 1) {
                if (r == 0 || grid[r-1][c] == 0) perimeter++;
                if (r == m-1 || grid[r+1][c] == 0) perimeter++;
                if (c == 0 || grid[r][c-1] == 0) perimeter++;
                if (c == n-1 || grid[r][c+1] == 0) perimeter++;
            }
    return perimeter;
}

int main() {
    // 测试用例
    vector<vector<int>> grid1 = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{0,1,1,0}};
    cout << islandPerimeter(grid1) << endl;  // 预期: 16
    vector<vector<int>> grid2 = {{1}};
    cout << islandPerimeter(grid2) << endl;  // 预期: 4
    vector<vector<int>> grid3 = {{1, 0}};
    cout << islandPerimeter(grid3) << endl;  // 预期: 4
    return 0;
}
