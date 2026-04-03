#!/usr/bin/env python3
"""
528. 按权重随机选择
"""
import random

class Solution:
    def __init__(self, w: list[int]):
        self.prefix = []
        total = 0
        for weight in w:
            total += weight
            self.prefix.append(total)
        self.total = total

    def pick_index(self) -> int:
        target = random.randint(1, self.total)
        left, right = 0, len(self.prefix) - 1
        while left < right:
            mid = (left + right) // 2
            if self.prefix[mid] >= target:
                right = mid
            else:
                left = mid + 1
        return left

if __name__ == "__main__":
    # 测试用例
    sol = Solution([1])
    print(sol.pick_index())
    # 预期: 0

    sol2 = Solution([1, 3])
    print(sol2.pick_index())
    # 预期: 0 或 1，权重1:3

    sol3 = Solution([2, 5, 3, 4])
    print(sol3.pick_index())
    # 预期: 0, 1, 2, 或 3
