#!/usr/bin/env python3
"""
435. 无重叠区间
算法: 贪心（按右端点排序）
时间复杂度: O(n log n)
空间复杂度: O(1)
"""
def erase_overlap_intervals(intervals: list[list[int]]) -> int:
    if not intervals:
        return 0
    intervals.sort(key=lambda x: x[1])
    count = 0
    end = intervals[0][1]
    for i in range(1, len(intervals)):
        if intervals[i][0] < end:
            count += 1
        else:
            end = intervals[i][1]
    return count


if __name__ == "__main__":
    print(erase_overlap_intervals([[1, 3], [2, 6], [8, 10], [15, 18]]))  # 预期: 0
    print(erase_overlap_intervals([[1, 2], [2, 3], [3, 4], [1, 3]]))      # 预期: 1
    print(erase_overlap_intervals([[1, 2], [1, 2], [1, 2]]))            # 预期: 2
