#!/usr/bin/env python3
"""
210. 课程表 II
返回完成所有课程的学习顺序。
"""
from collections import deque, defaultdict

def find_order(num_courses: int, prerequisites: list[list[int]]) -> list[int]:
    graph = defaultdict(list)
    indegree = [0] * num_courses
    for u, v in prerequisites:
        graph[v].append(u)
        indegree[u] += 1
    queue = deque([i for i in range(num_courses) if indegree[i] == 0])
    order = []
    while queue:
        course = queue.popleft()
        order.append(course)
        for neighbor in graph[course]:
            indegree[neighbor] -= 1
            if indegree[neighbor] == 0:
                queue.append(neighbor)
    return order if len(order) == num_courses else []

if __name__ == "__main__":
    # 测试用例
    print(find_order(2, [[1, 0]]))                    # 预期: [0, 1] 或其他有效顺序
    print(find_order(4, [[1, 0], [2, 0], [3, 1], [3, 2]]))  # 预期: [0, 1, 2, 3] 或其他有效顺序
    print(find_order(1, []))                         # 预期: [0]
    print(find_order(2, [[1, 0], [0, 1]]))            # 预期: [] (有环)
