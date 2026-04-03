#!/usr/bin/env python3
"""
232. 用栈实现队列
"""


class MyQueue:
    def __init__(self):
        self.s1 = []
        self.s2 = []

    def push(self, x: int) -> None:
        self.s1.append(x)

    def pop(self) -> int:
        if not self.s2:
            while self.s1:
                self.s2.append(self.s1.pop())
        return self.s2.pop()

    def peek(self) -> int:
        if not self.s2:
            while self.s1:
                self.s2.append(self.s1.pop())
        return self.s2[-1]

    def empty(self) -> bool:
        return not self.s1 and not self.s2


if __name__ == "__main__":
    # 测试用例
    q = MyQueue()
    q.push(1)
    q.push(2)
    print(q.peek())    # 预期: 1
    print(q.pop())     # 预期: 1
    print(q.empty())    # 预期: False
    q.push(3)
    print(q.pop())      # 预期: 2
    print(q.pop())      # 预期: 3
    print(q.empty())    # 预期: True
