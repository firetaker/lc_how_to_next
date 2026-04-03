#!/usr/bin/env python3
"""
LeetCode #54: 螺旋矩阵
题目: 给定 m×n 矩阵，按顺时针螺旋顺序返回所有元素。
解法: 方向数组 + 边界收缩 - 维护上下左右四个边界，
      顺序为右→下→左→上，每走完一条边就收缩对应边界。
      时间 O(mn)，空间 O(1)。
"""


def spiralOrder(matrix: list[list[int]]) -> list[int]:
    """
    边界收缩法: top/bottom/left/right 四边界不断收缩。
    走完一条边后对应边界内缩，防止重复访问。
    """
    result = []
    if not matrix:
        return result
    m, n = len(matrix), len(matrix[0])
    top, bottom, left, right = 0, m - 1, 0, n - 1
    while left <= right and top <= bottom:
        # 右→下→左→上 四个方向
        for j in range(left, right + 1):
            result.append(matrix[top][j])
        top += 1
        for i in range(top, bottom + 1):
            result.append(matrix[i][right])
        right -= 1
        if top <= bottom:
            for j in range(right, left - 1, -1):
                result.append(matrix[bottom][j])
            bottom -= 1
        if left <= right:
            for i in range(bottom, top - 1, -1):
                result.append(matrix[i][left])
            left += 1
    return result


if __name__ == "__main__":
    m1 = [[1,2,3],[4,5,6],[7,8,9]]
    print(spiralOrder(m1))  # [1,2,3,6,9,8,7,4,5]
    m2 = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
    print(spiralOrder(m2))  # [1,2,3,4,8,12,11,10,9,5,6,7]
