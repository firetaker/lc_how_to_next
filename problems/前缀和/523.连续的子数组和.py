#!/usr/bin/env python3
"""
523. 连续的子数组和
"""
def check_subarray_sum(nums: list[int], k: int) -> bool:
    prefix = 0
    prefix_index = {0: -1}
    for i, num in enumerate(nums):
        prefix = (prefix + num) % k
        if prefix in prefix_index:
            if i - prefix_index[prefix] > 1:
                return True
        else:
            prefix_index[prefix] = i
    return False

if __name__ == "__main__":
    # 测试用例
    print(check_subarray_sum([23, 2, 4, 6, 7], 6))
    # 预期: True
    print(check_subarray_sum([23, 2, 6, 4, 7], 6))
    # 预期: True
    print(check_subarray_sum([23, 2, 6, 4, 7], 13))
    # 预期: False
