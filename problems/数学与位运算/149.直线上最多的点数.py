#!/usr/bin/env python3
"""
149. 直线上最多的点数
"""
import math
from collections import defaultdict

def max_points(points: list[list[int]]) -> int:
    n = len(points)
    if n <= 2:
        return n
    max_count = 0
    for i in range(n):
        slopes = defaultdict(int)
        same = 1
        for j in range(i+1, n):
            dx = points[j][0] - points[i][0]
            dy = points[j][1] - points[i][1]
            if dx == 0 and dy == 0:
                same += 1
            else:
                g = math.gcd(dx, dy)
                slope = (dx // g, dy // g)
                slopes[slope] += 1
        local_max = same + (max(slopes.values()) if slopes else 0)
        max_count = max(max_count, local_max)
    return max_count

if __name__ == "__main__":
    # 测试用例
    print(max_points([[1, 1], [2, 2], [3, 3]]))  # 预期: 3
    print(max_points([[1, 1], [3, 2], [5, 3], [4, 1], [2, 3], [1, 4]]))  # 预期: 4
    print(max_points([[0, 0]]))  # 预期: 1
