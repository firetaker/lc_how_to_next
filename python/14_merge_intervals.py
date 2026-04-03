#!/usr/bin/env python3
"""
LeetCode #56: 合并区间
题目: 给定若干区间，合并所有重叠的区间。
解法: 按左端点排序，然后依次合并 - 维护当前区间 [cur_l, cur_r]，
      若下一个区间的左端点 <= cur_r，则合并（cur_r = max(cur_r, next_r)）；
      否则保存当前区间，开始新区间。时间 O(n log n)，空间 O(1)。
"""


def merge(intervals: list[list[int]]) -> list[list[int]]:
    """
    排序 + 合并: 按左端点排序，遍历合并重叠区间。
    """
    if not intervals:
        return []
    intervals.sort(key=lambda x: x[0])
    result = [[intervals[0][0], intervals[0][1]]]
    for l, r in intervals[1:]:
        if l <= result[-1][1]:          # 有重叠，合并
            result[-1][1] = max(result[-1][1], r)
        else:                           # 无重叠，开新区间
            result.append([l, r])
    return result


if __name__ == "__main__":
    print(merge([[1, 3], [2, 6], [8, 10], [15, 18]]))  # [[1,6],[8,10],[15,18]]
    print(merge([[1, 4], [4, 5]]))                    # [[1,5]]
