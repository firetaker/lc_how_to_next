#!/usr/bin/env python3
"""
381. O(1)时间插入删除和获取随机 II （允许重复）
"""
import random


class RandomizedCollection:
    def __init__(self):
        self.vals = []
        self.pos = {}

    def insert(self, val: int) -> bool:
        if val not in self.pos:
            self.pos[val] = set()
        first = len(self.pos[val]) == 0
        self.pos[val].add(len(self.vals))
        self.vals.append(val)
        return first

    def remove(self, val: int) -> bool:
        if not self.pos.get(val):
            return False
        idx = next(iter(self.pos[val]))
        last = self.vals[-1]
        self.vals[idx] = last
        self.pos[val].remove(idx)
        if idx != len(self.vals) - 1:
            self.pos[last].add(idx)
            self.pos[last].remove(len(self.vals) - 1)
        self.vals.pop()
        if not self.pos[val]:
            del self.pos[val]
        return True

    def get_random(self) -> int:
        return random.choice(self.vals)


if __name__ == "__main__":
    # 测试用例
    rc = RandomizedCollection()
    print(rc.insert(1))      # 预期: True
    print(rc.remove(2))      # 预期: False
    rc.insert(2)
    print(rc.get_random())   # 预期: 1 或 2
    rc.remove(1)
    print(rc.insert(2))      # 预期: False
    print(rc.get_random())   # 预期: 2

    # 额外测试重复元素
    rc2 = RandomizedCollection()
    print(rc2.insert(1))     # True
    print(rc2.insert(1))     # False (重复)
    print(rc2.insert(2))     # True
    print(rc2.remove(1))     # True
    print(rc2.get_random())  # 1 或 2
