#!/usr/bin/env python3
"""
77. 组合 (Combinations)
题目: 给定两个整数 n 和 k，返回 1...n 中所有可能的 k 个数的组合。
算法: 回溯
时间复杂度: O(C(n,k) * k)
空间复杂度: O(k)
"""

def combine(n, k):
    result = []
    path = []
    
    def backtrack(start):
        if len(path) == k:
            result.append(path[:])
            return
        for i in range(start, n + 1):
            path.append(i)
            backtrack(i + 1)
            path.pop()
    
    backtrack(1)
    return result

if __name__ == "__main__":
    # 测试用例1
    print(combine(4, 2))
    # 输出: [[1,2], [1,3], [1,4], [2,3], [2,4], [3,4]]
    
    # 测试用例2
    print(combine(1, 1))
    # 输出: [[1]]
    
    # 测试用例3
    print(combine(5, 3))
    # 输出: 10个组合
