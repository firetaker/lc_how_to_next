#!/usr/bin/env python3
"""
130. 被围绕的区域
"""
def solve(board: list[list[str]]) -> None:
    if not board:
        return
    m, n = len(board), len(board[0])

    def dfs(r, c):
        if r < 0 or r >= m or c < 0 or c >= n or board[r][c] != 'O':
            return
        board[r][c] = '#'
        for dr, dc in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
            dfs(r+dr, c+dc)

    for c in range(n):
        dfs(0, c)
        dfs(m-1, c)
    for r in range(m):
        dfs(r, 0)
        dfs(r, n-1)

    for r in range(m):
        for c in range(n):
            if board[r][c] == '#':
                board[r][c] = 'O'
            elif board[r][c] == 'O':
                board[r][c] = 'X'

if __name__ == "__main__":
    # 测试用例
    board1 = [['X', 'X', 'X', 'X'], ['X', 'O', 'O', 'X'], ['X', 'X', 'O', 'X'], ['X', 'O', 'X', 'X']]
    solve(board1)
    print(board1)  # 预期: [['X','X','X','X'],['X','X','X','X'],['X','X','X','X'],['X','O','X','X']]
    board2 = [['X']]
    solve(board2)
    print(board2)  # 预期: [['X']]
