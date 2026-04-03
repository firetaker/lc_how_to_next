#!/usr/bin/env python3
"""
LeetCode #48: 旋转图像
题目: 给定 n×n 矩阵，顺时针旋转 90 度。要求原地修改。
解法: 两次翻转 - 先沿主对角线翻转（转置），再沿水平中线翻转。
      等价于：先转置，再左右镜像。
      时间 O(n²)，空间 O(1)。
"""


def rotate(matrix: list[list[int]]) -> None:
    """
    两次翻转:
    1. 主对角线翻转（转置）: matrix[i][j] → matrix[j][i]
    2. 水平中线翻转: matrix[i][j] → matrix[i][n-1-j]
    合并：顺时针90度 = 转置 + 每行reverse
    """
    n = len(matrix)
    # 先转置
    for i in range(n):
        for j in range(i + 1, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
    # 再每行反转
    for i in range(n):
        matrix[i].reverse()


if __name__ == "__main__":
    m = [[1,2,3],[4,5,6],[7,8,9]]
    rotate(m)
    print(m)  # [[7,4,1],[8,5,2],[9,6,3]]
