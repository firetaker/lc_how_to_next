#!/usr/bin/env python3
"""
218. 天际线问题
"""
import heapq

def get_skyline(buildings: list[list[int]]) -> list[list[int]]:
    events = []
    for l, r, h in buildings:
        events.append((l, -h, r))
        events.append((r, h, 0))
    events.sort()
    result = []
    heap = [(0, float('inf'))]
    for x, neg_h, r in events:
        h = -neg_h
        if neg_h < 0:
            if h > -heap[0][0]:
                result.append([x, h])
            heapq.heappush(heap, (-h, r))
        else:
            while heap and heap[0][1] <= r:
                heapq.heappop(heap)
            if -heap[0][0] != (result[-1][1] if result else 0):
                result.append([x, -heap[0][0]])
    return result

if __name__ == "__main__":
    # 测试用例
    print(get_skyline([[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]))
    # 预期: [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
    print(get_skyline([[0,2,3],[2,5,3]]))
    # 预期: [[0,3],[5,0]]
    print(get_skyline([[1,2,1],[1,2,2],[1,2,3]]))
    # 预期: [[1,3],[2,0]]
