#!/usr/bin/env python3
"""
225. 用队列实现栈
"""
from collections import deque


class MyStack:
    def __init__(self):
        self.q = deque()

    def push(self, x: int) -> None:
        self.q.append(x)
        for _ in range(len(self.q) - 1):
            self.q.append(self.q.popleft())

    def pop(self) -> int:
        return self.q.popleft()

    def top(self) -> int:
        return self.q[0]

    def empty(self) -> bool:
        return not self.q


if __name__ == "__main__":
    # 测试用例
    stack = MyStack()
    stack.push(1)
    stack.push(2)
    print(stack.top())   # 预期: 2
    print(stack.pop())   # 预期: 2
    print(stack.empty())  # 预期: False
    stack.push(3)
    print(stack.pop())   # 预期: 3
    print(stack.pop())   # 预期: 1
    print(stack.empty()) # 预期: True
