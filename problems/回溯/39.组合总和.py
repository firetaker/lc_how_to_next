#!/usr/bin/env python3
"""
39. 组合总和 (Combination Sum)
题目: 给定一个无重复元素的数组 candidates 和一个目标数 target，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的数字可以无限制重复被选取。
算法: 回溯
时间复杂度: O(S) 其中 S 是所有可行解的总和
空间复杂度: O(target)
"""

def combinationSum(candidates, target):
    result = []
    path = []
    
    def backtrack(start, target):
        if target == 0:
            result.append(path[:])
            return
        if target < 0:
            return
        for i in range(start, len(candidates)):
            path.append(candidates[i])
            backtrack(i, target - candidates[i])  # i 不变因为可以重复选
            path.pop()
    
    backtrack(0, target)
    return result

if __name__ == "__main__":
    # 测试用例1
    print(combinationSum([2, 3, 6, 7], 7))
    # 输出: [[2,2,3], [7]]
    
    # 测试用例2
    print(combinationSum([2, 3, 5], 8))
    # 输出: [[2,2,2,2], [2,3,3], [3,5]]
    
    # 测试用例3
    print(combinationSum([2], 1))
    # 输出: []
