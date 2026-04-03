#!/usr/bin/env python3
"""
LeetCode #189: 轮转数组
题目: 将数组向右轮转 k 个位置（k 可以大于数组长度）。
解法: 三次反转 - 整体反转 → 前 k% n 反转 → 后 n-k%n 反转。
      等价于将尾部 k%n 个元素移到前面。时间 O(n)，空间 O(1)。
"""


def rotate(nums: list[int], k: int) -> None:
    """
    三次反转:
    1. 反转整个数组
    2. 反转前 k 个（已移到正确位置）
    3. 反转后 n-k 个
    """
    n = len(nums)
    k %= n
    def reverse(l, r):
        while l < r:
            nums[l], nums[r] = nums[r], nums[l]
            l += 1; r -= 1
    reverse(0, n - 1)
    reverse(0, k - 1)
    reverse(k, n - 1)


if __name__ == "__main__":
    arr = [-1, -100, 3, 99]; rotate(arr, 2); print(arr)  # [3,99,-1,-100]
    arr2 = [1, 2, 3, 4, 5, 6, 7]; rotate(arr2, 3); print(arr2)  # [5,6,7,1,2,3,4]
