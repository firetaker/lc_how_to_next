#!/usr/bin/env python3
"""
79. 单词搜索 (Word Search)
题目: 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。
如果 word 存在于网格中，返回 true ，否则返回 false 。
算法: 回溯 + DFS
时间复杂度: O(m * n * 4^L) 其中 L 是单词长度
空间复杂度: O(m * n)
"""

def exist(board, word):
    if not board or not board[0]:
        return False
    
    m, n = len(board), len(board[0])
    visited = [[False] * n for _ in range(m)]
    
    def dfs(r, c, index):
        if index == len(word):
            return True
        if r < 0 or r >= m or c < 0 or c >= n:
            return False
        if visited[r][c] or board[r][c] != word[index]:
            return False
        
        visited[r][c] = True
        found = (dfs(r + 1, c, index + 1) or
                 dfs(r - 1, c, index + 1) or
                 dfs(r, c + 1, index + 1) or
                 dfs(r, c - 1, index + 1))
        visited[r][c] = False
        return found
    
    for i in range(m):
        for j in range(n):
            if board[i][j] == word[0]:
                if dfs(i, j, 0):
                    return True
    return False

if __name__ == "__main__":
    # 测试用例1
    board1 = [
        ["A", "B", "C", "E"],
        ["S", "F", "C", "S"],
        ["A", "D", "E", "E"]
    ]
    print(exist(board1, "ABCCED"))  # True
    print(exist(board1, "SEE"))      # True
    print(exist(board1, "ABCB"))     # False
    
    # 测试用例2
    board2 = [["a"]]
    print(exist(board2, "a"))        # True
    print(exist(board2, "b"))        # False
    
    # 测试用例3
    board3 = [
        ["A", "A", "A"],
        ["A", "A", "A"],
        ["A", "A", "A"]
    ]
    print(exist(board3, "AAAAA"))     # True
    print(exist(board3, "AAAAAAA")) # False
