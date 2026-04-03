#!/usr/bin/env python3
"""
LeetCode #239: 滑动窗口最大值
题目: 给定数组和滑动窗口大小 k，返回每个窗口中的最大值。
解法: 单调递减队列 - 维护一个存储索引的 deque，队首始终是当前窗口最大值的索引。
      右端点入队时弹出所有小于当前元素的索引（它们永远不会再成为最大值）；
      左端点出队时若离开的是队首则弹出。整体 O(n)。
"""


from collections import deque


def maxSlidingWindow(nums: list[int], k: int) -> list[int]:
    """
    单调递减队列: deque 存索引，递减排列。
    右入：弹出所有比 nums[i] 小的元素索引（它们不可能是最大值）
    左出：若离开的是队首（最大值的索引），则弹出
    """
    if not nums or k == 0:
        return []
    dq = deque()  # 存索引，递减
    result = []
    for i in range(len(nums)):
        # 右入：弹出所有小于当前元素的索引
        while dq and nums[dq[-1]] < nums[i]:
            dq.pop()
        dq.append(i)
        # 左出：窗口已形成，窗口左端点 i-k+1，队首过期则弹出
        if dq[0] <= i - k:
            dq.popleft()
        # 窗口长度达到 k 时记录最大值
        if i >= k - 1:
            result.append(nums[dq[0]])
    return result


if __name__ == "__main__":
    print(maxSlidingWindow([1, 3, -1, -3, 5, 3, 6, 7], 3))  # [3, 3, 5, 5, 6, 7]
    print(maxSlidingWindow([1], 1))  # [1]
