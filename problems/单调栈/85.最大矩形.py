#!/usr/bin/env python3
"""
85. 最大矩形
"""
def maximal_rectangle(matrix: list[list[str]]) -> int:
    if not matrix:
        return 0
    heights = [0] * len(matrix[0])
    max_area = 0
    for row in matrix:
        for j, val in enumerate(row):
            heights[j] = heights[j] + 1 if val == '1' else 0
        stack = []
        for j, h in enumerate(heights + [0]):
            while stack and heights[stack[-1]] > h:
                height = heights[stack.pop()]
                width = j if not stack else j - stack[-1] - 1
                max_area = max(max_area, height * width)
            stack.append(j)
    return max_area

if __name__ == "__main__":
    # 测试用例
    print(maximal_rectangle([["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]))
    # 预期: 6
    print(maximal_rectangle([["0"]]))
    # 预期: 0
    print(maximal_rectangle([["1"]]))
    # 预期: 1
