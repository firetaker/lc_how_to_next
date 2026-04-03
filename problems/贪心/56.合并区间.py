#!/usr/bin/env python3
"""
56. 合并区间
算法: 贪心（按起点排序，合并重叠）
时间复杂度: O(n log n)
空间复杂度: O(n)
"""
def merge(intervals: list[list[int]]) -> list[list[int]]:
    if not intervals:
        return []
    intervals.sort()
    result = [intervals[0]]
    for start, end in intervals[1:]:
        if start <= result[-1][1]:
            result[-1][1] = max(result[-1][1], end)
        else:
            result.append([start, end])
    return result


if __name__ == "__main__":
    print(merge([[1, 3], [2, 6], [8, 10], [15, 18]]))
    # 预期: [[1, 6], [8, 10], [15, 18]]
    print(merge([[1, 4], [4, 5]]))
    # 预期: [[1, 5]]
    print(merge([[1, 4], [0, 4]]))
    # 预期: [[0, 4]]
