#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
    int m = h.size(), n = h[0].size();
    vector<vector<char>> pac(m, vector<char>(n, 0)), atl(m, vector<char>(n, 0));
    function<void(int,int,vector<vector<char>>&,int)> dfs = [&](int r, int c, vector<vector<char>>& v, int h0) {
        if (r < 0 || r >= m || c < 0 || c >= n || v[r][c] || h[r][c] < h0) return;
        v[r][c] = 1;
        for (auto& d : vector<pair<int,int>>{{0,1},{0,-1},{1,0},{-1,0}})
            dfs(r+d.first, c+d.second, v, h[r][c]);
    };
    for (int c = 0; c < n; c++) dfs(0, c, pac, 0);
    for (int r = 0; r < m; r++) dfs(r, 0, pac, 0);
    for (int c = 0; c < n; c++) dfs(m-1, c, atl, 0);
    for (int r = 0; r < m; r++) dfs(r, n-1, atl, 0);
    vector<vector<int>> result;
    for (int r = 0; r < m; r++)
        for (int c = 0; c < n; c++)
            if (pac[r][c] && atl[r][c])
                result.push_back({r, c});
    return result;
}

int main() {
    // 测试用例
    vector<vector<int>> h1 = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    auto r1 = pacificAtlantic(h1);
    for (auto& p : r1) cout << "(" << p[0] << "," << p[1] << ") "; cout << endl;
    // 预期: (0,4)(1,3)(1,4)(2,2)(3,0)(3,1)(4,0)
    vector<vector<int>> h2 = {{1}};
    auto r2 = pacificAtlantic(h2);
    for (auto& p : r2) cout << "(" << p[0] << "," << p[1] << ") "; cout << endl;  // 预期: (0,0)
    return 0;
}
