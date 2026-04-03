#!/usr/bin/env python3
"""
34. 在排序数组中查找元素的第一个和最后一个位置
算法: 二分查找（分别找左边界和右边界）
时间复杂度: O(log n)
空间复杂度: O(1)
"""
def search_range(nums: list[int], target: int) -> list[int]:
    def find_bound(nums, target, find_first):
        left, right = 0, len(nums) - 1
        bound = -1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                bound = mid
                if find_first:
                    right = mid - 1
                else:
                    left = mid + 1
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return bound
    return [find_bound(nums, target, True), find_bound(nums, target, False)]


if __name__ == "__main__":
    print(search_range([5, 7, 7, 8, 8, 10], 8))       # 预期: [3, 4]
    print(search_range([5, 7, 7, 8, 8, 10], 6))       # 预期: [-1, -1]
    print(search_range([], 0))                         # 预期: [-1, -1]
