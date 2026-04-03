#!/usr/bin/env python3
"""
131. 分割回文串 (Palindrome Partitioning)
题目: 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。返回所有可能的分割方案。
算法: 回溯 + 中心扩展判断回文
时间复杂度: O(n * 2^n)
空间复杂度: O(n)
"""

def partition(s):
    result = []
    path = []
    
    def is_palindrome(sub):
        return sub == sub[::-1]
    
    def backtrack(start):
        if start == len(s):
            result.append(path[:])
            return
        for i in range(start, len(s)):
            sub = s[start:i + 1]
            if is_palindrome(sub):
                path.append(sub)
                backtrack(i + 1)
                path.pop()
    
    backtrack(0)
    return result

if __name__ == "__main__":
    # 测试用例1
    print(partition("aab"))
    # 输出: [["a","a","b"], ["aa","b"]]
    
    # 测试用例2
    print(partition("a"))
    # 输出: [["a"]]
    
    # 测试用例3
    print(partition("abcba"))
    # 输出: 所有回文分割方案
