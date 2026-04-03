#!/usr/bin/env python3
"""
974. 和可被K整除的子数组
"""
def subarrays_div_by_k(nums: list[int], k: int) -> int:
    prefix_mod = 0
    mod_count = [0] * k
    mod_count[0] = 1
    count = 0
    for num in nums:
        prefix_mod = (prefix_mod + num) % k
        if prefix_mod < 0:
            prefix_mod += k
        count += mod_count[prefix_mod]
        mod_count[prefix_mod] += 1
    return count

if __name__ == "__main__":
    # 测试用例
    print(subarrays_div_by_k([4, 5, 0, -2, -3, 1], 5))
    # 预期: 7
    print(subarrays_div_by_k([5], 9))
    # 预期: 0
    print(subarrays_div_by_k([-1, 2, 9], 2))
    # 预期: 2
