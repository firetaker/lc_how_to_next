#!/usr/bin/env python3
"""
133. 克隆图
"""
class Node:
    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors else []

def clone_graph(node):
    if not node:
        return None
    visited = {}
    def dfs(n):
        if n in visited:
            return visited[n]
        clone = Node(n.val)
        visited[n] = clone
        for neighbor in n.neighbors:
            clone.neighbors.append(dfs(neighbor))
        return clone
    return dfs(node)

if __name__ == "__main__":
    # 测试用例
    # 构建节点 1->2->4, 1->3->4
    node1 = Node(1)
    node2 = Node(2)
    node3 = Node(3)
    node4 = Node(4)
    node1.neighbors = [node2, node3]
    node2.neighbors = [node4]
    node3.neighbors = [node4]
    cloned = clone_graph(node1)
    print(cloned.val)  # 预期: 1
    print(len(cloned.neighbors))  # 预期: 2
