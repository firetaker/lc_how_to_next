#!/usr/bin/env python3
"""
1269. 停在原地的方案数
"""
def num_ways(steps: int, arr_len: int) -> int:
    MOD = 10**9 + 7
    max_pos = min(steps // 2, arr_len - 1)
    dp = [0] * (max_pos + 1)
    dp[0] = 1
    for _ in range(1, steps + 1):
        new_dp = [0] * (max_pos + 1)
        for pos in range(max_pos + 1):
            new_dp[pos] = (new_dp[pos] + dp[pos]) % MOD
            if pos > 0:
                new_dp[pos] = (new_dp[pos] + dp[pos-1]) % MOD
            if pos < max_pos:
                new_dp[pos] = (new_dp[pos] + dp[pos+1]) % MOD
        dp = new_dp
    return dp[0]

if __name__ == "__main__":
    # 测试用例
    print(num_ways(3, 2))   # 预期: 3
    print(num_ways(2, 4))   # 预期: 2
    print(num_ways(4, 2))   # 预期: 8
