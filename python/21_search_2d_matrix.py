#!/usr/bin/env python3
"""
LeetCode #74: 搜索二维矩阵
题目: 给定 m×n 矩阵，每行升序，每行第一个元素大于上一行最后一个元素，
      判断目标值 target 是否存在。
解法: 排除法（二分） - 将二维矩阵看成一维有序数组，
      mid = (top + bottom) // 2，比较 matrix[mid//n][mid%n] 与 target。
      时间 O(log(mn))，空间 O(1)。
"""


def searchMatrix(matrix: list[list[int]], target: int) -> bool:
    """
    两次二分或一次二分: 将 2D 当作 1D，用一维的二分下标映射到 2D。
    更直观的"排除法"：从上角（matrix[0][n-1]）开始：
      - target == matrix[i][j] → 找到
      - target < matrix[i][j] → 排除当前列，j--
      - target > matrix[i][j] → 排除当前行，i++
    """
    if not matrix or not matrix[0]:
        return False
    m, n = len(matrix), len(matrix[0])
    i, j = 0, n - 1  # 从右上角出发
    while i < m and j >= 0:
        cur = matrix[i][j]
        if cur == target:
            return True
        elif cur < target:
            i += 1  # 往下走（当前行都太小）
        else:
            j -= 1  # 往左走（当前列都太大）
    return False


def searchMatrix_binary(matrix: list[list[int]], target: int) -> bool:
    """一维二分映射版"""
    if not matrix:
        return False
    m, n = len(matrix), len(matrix[0])
    left, right = 0, m * n - 1
    while left <= right:
        mid = (left + right) // 2
        val = matrix[mid // n][mid % n]
        if val == target:
            return True
        elif val < target:
            left = mid + 1
        else:
            right = mid - 1
    return False


if __name__ == "__main__":
    m = [[1,3,5,7],[10,11,16,20],[23,30,34,60]]
    print(searchMatrix(m, 3))   # True
    print(searchMatrix(m, 13))  # False
