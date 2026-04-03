#!/usr/bin/env python3
"""
37. 解数独 (Sudoku Solver)
题目: 编写一个程序，通过填充空格来解决数独问题。
算法: 回溯
时间复杂度: O(9!)
空间复杂度: O(81)
"""

def solveSudoku(board):
    def is_valid(board, row, col, num):
        # 检查行
        for i in range(9):
            if board[row][i] == num:
                return False
        # 检查列
        for i in range(9):
            if board[i][col] == num:
                return False
        # 检查 3x3 宫格
        start_row, start_col = 3 * (row // 3), 3 * (col // 3)
        for i in range(start_row, start_row + 3):
            for j in range(start_col, start_col + 3):
                if board[i][j] == num:
                    return False
        return True
    
    def backtrack():
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    for num in '123456789':
                        if is_valid(board, i, j, num):
                            board[i][j] = num
                            if backtrack():
                                return True
                            board[i][j] = '.'
                    return False
        return True
    
    backtrack()
    return board

def print_board(board):
    for row in board:
        print(''.join(row))

if __name__ == "__main__":
    # 测试用例
    board = [
        ["5","3",".",".","7",".",".",".","."],
        ["6",".",".","1","9","5",".",".","."],
        [".","9","8",".",".",".",".","6","."],
        ["8",".",".",".","6",".",".",".","3"],
        ["4",".",".","8",".","3",".",".","1"],
        ["7",".",".",".","2",".",".",".","6"],
        [".","6",".",".",".",".","2","8","."],
        [".",".",".","4","1","9",".",".","5"],
        [".",".",".",".","8",".",".","7","9"]
    ]
    print("Before solving:")
    print_board(board)
    solveSudoku(board)
    print("\nAfter solving:")
    print_board(board)
