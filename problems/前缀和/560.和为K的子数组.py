#!/usr/bin/env python3
"""
560. 和为 K 的子数组
"""
def subarray_sum(nums: list[int], k: int) -> int:
    count = 0
    prefix = 0
    prefix_count = {0: 1}
    for num in nums:
        prefix += num
        count += prefix_count.get(prefix - k, 0)
        prefix_count[prefix] = prefix_count.get(prefix, 0) + 1
    return count

if __name__ == "__main__":
    # 测试用例
    print(subarray_sum([1, 1, 1], 2))
    # 预期: 2
    print(subarray_sum([1, 2, 3], 3))
    # 预期: 2
    print(subarray_sum([3, 4, 7, 2, -3, 1, 4, 2], 7))
    # 预期: 4
