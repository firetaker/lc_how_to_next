#!/usr/bin/env python3
"""
241. 为运算表达式设计优先级
"""
def diff_ways_to_compute(expression: str) -> list[int]:
    if expression.isdigit():
        return [int(expression)]
    result = []
    for i, ch in enumerate(expression):
        if ch in '+-*':
            left = diff_ways_to_compute(expression[:i])
            right = diff_ways_to_compute(expression[i+1:])
            for l in left:
                for r in right:
                    if ch == '+':
                        result.append(l + r)
                    elif ch == '-':
                        result.append(l - r)
                    else:
                        result.append(l * r)
    return result

if __name__ == "__main__":
    # 测试用例
    print(diff_ways_to_compute("2-1-1"))  # 预期: [0, 2]
    print(diff_ways_to_compute("2*3-4*5"))  # 预期: [-34, -14, -10, -10, 10]
    print(diff_ways_to_compute("1+1"))  # 预期: [2]
