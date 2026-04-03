#!/usr/bin/env python3
"""
239. 滑动窗口最大值
算法: 单调递减双端队列
时间复杂度: O(n)
空间复杂度: O(k)
"""
from collections import deque


def max_sliding_window(nums: list[int], k: int) -> list[int]:
    deque_indices = deque()
    result = []

    for i in range(len(nums)):
        while deque_indices and nums[deque_indices[-1]] <= nums[i]:
            deque_indices.pop()
        deque_indices.append(i)

        if deque_indices[0] <= i - k:
            deque_indices.popleft()

        if i >= k - 1:
            result.append(nums[deque_indices[0]])
    return result


if __name__ == "__main__":
    print(max_sliding_window([1, 3, -1, -3, 5, 3, 6, 7], 3))
    # 预期: [3, 3, 5, 5, 6, 7]
    print(max_sliding_window([1], 1))  # 预期: [1]
    print(max_sliding_window([1, -1], 1))  # 预期: [1, -1]
