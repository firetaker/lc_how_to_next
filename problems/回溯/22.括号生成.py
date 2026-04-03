#!/usr/bin/env python3
"""
22. 括号生成 (Generate Parentheses)
题目: 给出 n 代表生成括号的对数，请你生成一个所有可能的有效括号组合。
算法: 回溯
时间复杂度: O(4^n / sqrt(n))
空间复杂度: O(n)
"""

def generateParenthesis(n):
    result = []
    path = []
    
    def is_valid(path):
        balance = 0
        for p in path:
            if p == '(':
                balance += 1
            else:
                balance -= 1
            if balance < 0:
                return False
        return balance == 0
    
    def backtrack():
        if len(path) == 2 * n:
            if is_valid(path):
                result.append(''.join(path))
            return
        # 剪枝：可以提前判断
        for p in ['(', ')']:
            path.append(p)
            backtrack()
            path.pop()
    
    backtrack()
    return result

if __name__ == "__main__":
    # 测试用例1
    print(generateParenthesis(3))
    # 输出: ["((()))","(()())","(())()","()(())","()()()"]
    
    # 测试用例2
    print(generateParenthesis(1))
    # 输出: ["()"]
    
    # 测试用例3
    print(generateParenthesis(4))
    # 输出: 14个有效括号组合
