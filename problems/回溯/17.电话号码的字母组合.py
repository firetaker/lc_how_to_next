#!/usr/bin/env python3
"""
17. 电话号码的字母组合 (Letter Combinations)
题目: 给定一个包含数字 2-9 的字符串，返回所有它能表示的字母组合。
算法: 回溯
时间复杂度: O(4^n)
空间复杂度: O(n)
"""

def letterCombinations(digits):
    if not digits:
        return []
    
    phone = {
        '2': 'abc',
        '3': 'def',
        '4': 'ghi',
        '5': 'jkl',
        '6': 'mno',
        '7': 'pqrs',
        '8': 'tuv',
        '9': 'wxyz'
    }
    
    result = []
    path = []
    
    def backtrack(index):
        if index == len(digits):
            result.append(''.join(path))
            return
        for letter in phone[digits[index]]:
            path.append(letter)
            backtrack(index + 1)
            path.pop()
    
    backtrack(0)
    return result

if __name__ == "__main__":
    # 测试用例1
    print(letterCombinations("23"))
    # 输出: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
    
    # 测试用例2
    print(letterCombinations(""))
    # 输出: []
    
    # 测试用例3
    print(letterCombinations("2"))
    # 输出: ["a","b","c"]
    
    # 测试用例4
    print(letterCombinations("79"))
    # 输出: ["pw","px","py","pz","qw","qx","qy","qz","rw","rx","ry","rz","sw","sx","sy","sz"]
