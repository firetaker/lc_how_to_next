#!/usr/bin/env python3
"""
240. 搜索二维矩阵 II
"""
def search_matrix(matrix: list[list[int]], target: int) -> bool:
    if not matrix:
        return False
    row, col = 0, len(matrix[0]) - 1
    while row < len(matrix) and col >= 0:
        if matrix[row][col] == target:
            return True
        elif matrix[row][col] > target:
            col -= 1
        else:
            row += 1
    return False

if __name__ == "__main__":
    # 测试用例
    matrix = [[1, 4, 7, 11, 15], [2, 5, 8, 12, 19], [3, 6, 9, 16, 22], [10, 13, 14, 17, 24], [18, 21, 23, 26, 30]]
    print(search_matrix(matrix, 5))   # 预期: True
    print(search_matrix(matrix, 20))  # 预期: False
    matrix2 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    print(search_matrix(matrix2, 9))  # 预期: True
