#!/usr/bin/env python3
"""
380. O(1)时间插入删除和获取随机
"""
import random


class RandomizedSet:
    def __init__(self):
        self.val = []
        self.pos = {}

    def insert(self, val: int) -> bool:
        if val in self.pos:
            return False
        self.pos[val] = len(self.val)
        self.val.append(val)
        return True

    def remove(self, val: int) -> bool:
        if val not in self.pos:
            return False
        idx = self.pos[val]
        last = self.val[-1]
        self.val[idx] = last
        self.pos[last] = idx
        self.val.pop()
        del self.pos[val]
        return True

    def get_random(self) -> int:
        return random.choice(self.val)


if __name__ == "__main__":
    # 测试用例
    rs = RandomizedSet()
    print(rs.insert(1))      # 预期: True
    print(rs.remove(2))       # 预期: False
    rs.insert(2)
    print(rs.get_random())    # 预期: 1 或 2
    rs.remove(1)
    print(rs.insert(2))       # 预期: False (2已存在)
    print(rs.get_random())     # 预期: 2
