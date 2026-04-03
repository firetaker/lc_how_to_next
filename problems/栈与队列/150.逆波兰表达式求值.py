#!/usr/bin/env python3
"""
150. 逆波兰表达式求值
算法: 栈
时间复杂度: O(n)
空间复杂度: O(n)
"""
def eval_rpn(tokens: list[str]) -> int:
    stack = []
    for t in tokens:
        if t == '+':
            stack.append(stack.pop() + stack.pop())
        elif t == '-':
            b, a = stack.pop(), stack.pop()
            stack.append(a - b)
        elif t == '*':
            stack.append(stack.pop() * stack.pop())
        elif t == '/':
            b, a = stack.pop(), stack.pop()
            stack.append(int(a / b))
        else:
            stack.append(int(t))
    return stack[0]


if __name__ == "__main__":
    print(eval_rpn(["2", "1", "+", "3", "*"]))        # 预期: 9
    print(eval_rpn(["4", "13", "5", "/", "+"]))       # 预期: 6
    print(eval_rpn(["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]))
    # 预期: 22
