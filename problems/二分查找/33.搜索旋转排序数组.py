#!/usr/bin/env python3
"""
33. 搜索旋转排序数组
算法: 二分查找（先判断哪半边有序）
时间复杂度: O(log n)
空间复杂度: O(1)
"""
def search(nums: list[int], target: int) -> int:
    left, right = 0, len(nums) - 1
    while left <= right:
        mid = (left + right) // 2
        if nums[mid] == target:
            return mid
        if nums[left] <= nums[mid]:
            if nums[left] <= target < nums[mid]:
                right = mid - 1
            else:
                left = mid + 1
        else:
            if nums[mid] < target <= nums[right]:
                left = mid + 1
            else:
                right = mid - 1
    return -1


if __name__ == "__main__":
    print(search([4, 5, 6, 7, 0, 1, 2], 0))      # 预期: 4
    print(search([4, 5, 6, 7, 0, 1, 2], 3))      # 预期: -1
    print(search([1], 0))                         # 预期: -1
