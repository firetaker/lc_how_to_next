#!/usr/bin/env python3
"""
93. 复原 IP 地址 (Restore IP Addresses)
题目: 给定一个只包含数字的字符串 s，向其中插入点号来形成有效的 IP 地址。
算法: 回溯
时间复杂度: O(3^4) = O(1)
空间复杂度: O(1)
"""

def restoreIpAddresses(s):
    result = []
    path = []
    
    def is_valid(segment):
        if len(segment) > 1 and segment[0] == '0':
            return False
        return 0 <= int(segment) <= 255
    
    def backtrack(start):
        if len(path) == 4:
            if start == len(s):
                result.append('.'.join(path))
            return
        for i in range(start, min(start + 3, len(s))):
            segment = s[start:i + 1]
            if is_valid(segment):
                path.append(segment)
                backtrack(i + 1)
                path.pop()
    
    backtrack(0)
    return result

if __name__ == "__main__":
    # 测试用例1
    print(restoreIpAddresses("25525511135"))
    # 输出: ["255.255.11.135", "255.255.111.35"]
    
    # 测试用例2
    print(restoreIpAddresses("0000"))
    # 输出: ["0.0.0.0"]
    
    # 测试用例3
    print(restoreIpAddresses("101023"))
    # 输出: ["1.0.10.23", "1.0.102.3", "10.1.0.23", "10.10.2.3", "101.0.2.3"]
