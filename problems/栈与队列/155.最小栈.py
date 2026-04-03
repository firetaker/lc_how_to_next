#!/usr/bin/env python3
"""
155. 最小栈
算法: 双栈（主栈+辅助最小栈）
时间复杂度: O(1)（push/pop/top/getMin均为O(1)）
空间复杂度: O(n)
"""
class MinStack:
    def __init__(self):
        self.stack = []
        self.min_stack = []

    def push(self, val: int) -> None:
        self.stack.append(val)
        if not self.min_stack or val <= self.min_stack[-1]:
            self.min_stack.append(val)

    def pop(self) -> None:
        if self.stack.pop() == self.min_stack[-1]:
            self.min_stack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.min_stack[-1]


if __name__ == "__main__":
    min_stack = MinStack()
    min_stack.push(-2)
    min_stack.push(0)
    min_stack.push(-3)
    print(min_stack.getMin())  # 预期: -3
    min_stack.pop()
    print(min_stack.top())     # 预期: 0
    print(min_stack.getMin())  # 预期: -2
