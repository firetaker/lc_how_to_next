#!/usr/bin/env python3
"""
1248. 统计「优美子数组」
"""
def number_of_subarrays(nums: list[int], k: int) -> int:
    prefix = 0
    prefix_count = {0: 1}
    count = 0
    for num in nums:
        prefix += num % 2
        count += prefix_count.get(prefix - k, 0)
        prefix_count[prefix] = prefix_count.get(prefix, 0) + 1
    return count

if __name__ == "__main__":
    # 测试用例
    print(number_of_subarrays([1, 1, 2, 1, 1], 3))
    # 预期: 2
    print(number_of_subarrays([2, 4, 6], 1))
    # 预期: 0
    print(number_of_subarrays([2, 2, 2, 1, 2, 2, 1, 2], 2))
    # 预期: 16
