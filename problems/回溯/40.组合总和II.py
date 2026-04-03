#!/usr/bin/env python3
"""
40. 组合总和 II (Combination Sum II)
题目: 给定一个数组 candidates 和一个目标数 target，找出 candidates 中所有使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用一次。
算法: 回溯 + 排序 + 剪枝
时间复杂度: O(2^n)
空间复杂度: O(n)
"""

def combinationSum2(candidates, target):
    result = []
    path = []
    used = [False] * len(candidates)
    candidates.sort()  # 排序用于去重
    
    def backtrack(start, target):
        if target == 0:
            result.append(path[:])
            return
        if target < 0:
            return
        for i in range(start, len(candidates)):
            # 剪枝：相同元素跳过
            if i > start and candidates[i] == candidates[i - 1]:
                continue
            path.append(candidates[i])
            backtrack(i + 1, target - candidates[i])
            path.pop()
    
    backtrack(0, target)
    return result

if __name__ == "__main__":
    # 测试用例1
    print(combinationSum2([10, 1, 2, 7, 6, 1, 5], 8))
    # 输出: [[1,1,6], [1,2,5], [1,7], [2,6]]
    
    # 测试用例2
    print(combinationSum2([2, 5, 2, 1, 2], 5))
    # 输出: [[1,2,2], [5]]
    
    # 测试用例3
    print(combinationSum2([1, 1, 1, 1, 1], 3))
    # 输出: 3个组合
