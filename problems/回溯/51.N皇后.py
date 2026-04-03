#!/usr/bin/env python3
"""
51. N 皇后 (N-Queens)
题目: 给你一个整数 n，返回所有不同的 n 皇后问题 的解决方案。
算法: 回溯
时间复杂度: O(n!)
空间复杂度: O(n)
"""

def solveNQueens(n):
    result = []
    board = [['.' for _ in range(n)] for _ in range(n)]
    cols = set()
    diag1 = set()  # row + col
    diag2 = set()  # row - col
    
    def is_valid(row, col):
        if col in cols or (row + col) in diag1 or (row - col) in diag2:
            return False
        return True
    
    def backtrack(row):
        if row == n:
            result.append([''.join(row) for row in board])
            return
        for col in range(n):
            if is_valid(row, col):
                board[row][col] = 'Q'
                cols.add(col)
                diag1.add(row + col)
                diag2.add(row - col)
                backtrack(row + 1)
                board[row][col] = '.'
                cols.remove(col)
                diag1.remove(row + col)
                diag2.remove(row - col)
    
    backtrack(0)
    return result

def print_solutions(solutions):
    for i, sol in enumerate(solutions):
        print(f"Solution {i + 1}:")
        for row in sol:
            print(row)
        print()

if __name__ == "__main__":
    # 测试用例1
    print("n=4:")
    solutions = solveNQueens(4)
    print(f"Total: {len(solutions)} solutions")
    print_solutions(solutions[:1])  # 打印第一个解
    
    # 测试用例2
    print("n=1:")
    solutions = solveNQueens(1)
    print(f"Total: {len(solutions)} solution")
    print_solutions(solutions)
    
    # 测试用例3
    print("n=8:")
    solutions = solveNQueens(8)
    print(f"Total: {len(solutions)} solutions")
