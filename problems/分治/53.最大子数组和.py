#!/usr/bin/env python3
"""
53. 最大子数组和（分治法）
"""
def max_sub_array_dc(nums: list[int]) -> int:
    def divide_conquer(nums, left, right):
        if left == right:
            return nums[left], nums[left], nums[left]
        mid = (left + right) // 2
        left_max, left_presum, left_sufsum = divide_conquer(nums, left, mid)
        right_max, right_presum, right_sufsum = divide_conquer(nums, mid+1, right)
        cross_max = left_sufsum + right_presum
        max_part = max(left_max, right_max)
        total_sum = left_max + right_max - min(left_max, right_max)
        return max(max_part, cross_max), max(left_presum, left_sufsum + right_presum), max(right_sufsum, left_sufsum + right_sufsum)
    return divide_conquer(nums, 0, len(nums)-1)[0]

if __name__ == "__main__":
    # 测试用例
    print(max_sub_array_dc([-2, 1, -3, 4, -1, 2, 1, -5, 4]))  # 预期: 6
    print(max_sub_array_dc([1]))  # 预期: 1
    print(max_sub_array_dc([5, 4, -1, 7, 8]))  # 预期: 23
