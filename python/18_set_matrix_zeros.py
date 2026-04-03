#!/usr/bin/env python3
"""
LeetCode #73: 矩阵置零
题目: 给定矩阵，若元素为 0，则将整行和整列置零。要求 O(mn) 时间，O(1) 空间。
解法: 两遍扫描 - 第一遍记录哪些行和列需要置零；
      第二遍执行置零。空间优化：用第一行和第一列自身作为标记，
      避免额外数组。
"""


def setZeroes(matrix: list[list[int]]) -> None:
    """
    第一遍：扫描所有格子，若 matrix[i][j]==0，则将
           matrix[i][0] 和 matrix[0][j] 标记为 0（利用首行首列）
    第二遍：从 matrix[i][0] 和 matrix[0][j] 的标记决定是否置零
    注意：首行首列需单独处理（用额外变量记录首行/首列是否需置零）
    """
    m, n = len(matrix), len(matrix[0])
    row_zero = False  # 标记首行是否需要置零
    col_zero = False  # 标记首列是否需要置零
    # 检查首行首列
    for j in range(n):
        if matrix[0][j] == 0:
            row_zero = True
            break
    for i in range(m):
        if matrix[i][0] == 0:
            col_zero = True
            break
    # 第一遍：用首行首列做标记
    for i in range(1, m):
        for j in range(1, n):
            if matrix[i][j] == 0:
                matrix[i][0] = 0
                matrix[0][j] = 0
    # 第二遍置零
    for i in range(1, m):
        if matrix[i][0] == 0:
            for j in range(n):
                matrix[i][j] = 0
    for j in range(1, n):
        if matrix[0][j] == 0:
            for i in range(m):
                matrix[i][j] = 0
    # 处理首行首列
    if row_zero:
        for j in range(n): matrix[0][j] = 0
    if col_zero:
        for i in range(m): matrix[i][0] = 0


if __name__ == "__main__":
    m = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
    setZeroes(m)
    print(m)  # [[1,0,1],[0,0,0],[1,0,1]]
