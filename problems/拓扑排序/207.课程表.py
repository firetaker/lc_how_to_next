#!/usr/bin/env python3
"""
207. 课程表
判断是否可能完成所有课程的学习（拓扑排序/BFS）。
"""
from collections import deque, defaultdict

def can_finish(num_courses: int, prerequisites: list[list[int]]) -> bool:
    graph = defaultdict(list)
    indegree = [0] * num_courses
    for u, v in prerequisites:
        graph[v].append(u)
        indegree[u] += 1
    queue = deque([i for i in range(num_courses) if indegree[i] == 0])
    count = 0
    while queue:
        course = queue.popleft()
        count += 1
        for neighbor in graph[course]:
            indegree[neighbor] -= 1
            if indegree[neighbor] == 0:
                queue.append(neighbor)
    return count == num_courses

if __name__ == "__main__":
    # 测试用例
    print(can_finish(2, [[1, 0]]))        # 预期: True
    print(can_finish(2, [[1, 0], [0, 1]]))  # 预期: False
    print(can_finish(4, [[1, 0], [2, 0], [3, 1], [3, 2]]))  # 预期: True
    print(can_finish(3, [[1, 0], [1, 2], [0, 1]]))  # 预期: False
