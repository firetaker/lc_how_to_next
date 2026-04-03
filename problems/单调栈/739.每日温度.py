#!/usr/bin/env python3
"""
739. 每日温度
"""
def daily_temperatures(temperatures: list[int]) -> list[int]:
    n = len(temperatures)
    result = [0] * n
    stack = []
    for i, temp in enumerate(temperatures):
        while stack and temperatures[stack[-1]] < temp:
            prev = stack.pop()
            result[prev] = i - prev
        stack.append(i)
    return result

if __name__ == "__main__":
    # 测试用例
    print(daily_temperatures([73, 74, 75, 71, 69, 72, 76, 73]))
    # 预期: [1, 1, 4, 2, 1, 1, 0, 0]
    print(daily_temperatures([30, 40, 50, 60]))
    # 预期: [1, 1, 1, 0]
    print(daily_temperatures([30, 60, 90]))
    # 预期: [1, 1, 0]
