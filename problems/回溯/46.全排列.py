#!/usr/bin/env python3
"""
46. 全排列 (Permutations)
题目: 给定一个不含重复数字的数组，返回其所有可能的全排列。
算法: 回溯
时间复杂度: O(n! * n)
空间复杂度: O(n)
"""

def permute(nums):
    result = []
    path = []
    used = [False] * len(nums)
    
    def backtrack():
        if len(path) == len(nums):
            result.append(path[:])
            return
        for i in range(len(nums)):
            if used[i]:
                continue
            used[i] = True
            path.append(nums[i])
            backtrack()
            path.pop()
            used[i] = False
    
    backtrack()
    return result

if __name__ == "__main__":
    # 测试用例1
    print(permute([1, 2, 3]))
    # 输出: [[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]]
    
    # 测试用例2
    print(permute([0, 1]))
    # 输出: [[0,1], [1,0]]
    
    # 测试用例3
    print(permute([1]))
    # 输出: [[1]]
