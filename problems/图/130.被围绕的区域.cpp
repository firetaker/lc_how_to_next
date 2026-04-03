#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void solve(vector<vector<char>>& board) {
    if (board.empty()) return;
    int m = board.size(), n = board[0].size();
    function<void(int,int)> dfs = [&](int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'O') return;
        board[r][c] = '#';
        for (auto& d : vector<pair<int,int>>{{0,1},{0,-1},{1,0},{-1,0}}) dfs(r+d.first, c+d.second);
    };
    for (int c = 0; c < n; c++) { dfs(0, c); dfs(m-1, c); }
    for (int r = 0; r < m; r++) { dfs(r, 0); dfs(r, n-1); }
    for (int r = 0; r < m; r++)
        for (int c = 0; c < n; c++) {
            if (board[r][c] == '#') board[r][c] = 'O';
            else if (board[r][c] == 'O') board[r][c] = 'X';
        }
}

int main() {
    // 测试用例
    vector<vector<char>> board1 = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    solve(board1);
    for (auto& row : board1) { for (char c : row) cout << c << " "; cout << endl; }
    // 预期: X X X X / X X X X / X X X X / X O X X
    vector<vector<char>> board2 = {{'X'}};
    solve(board2);
    for (char c : board2[0]) cout << c << " "; cout << endl;  // 预期: X
    return 0;
}
