#!/usr/bin/env python3
"""
452. 用最少数量的箭引爆气球
算法: 贪心（按右端点排序）
时间复杂度: O(n log n)
空间复杂度: O(1)
"""
def find_min_arrow_shots(points: list[list[int]]) -> int:
    if not points:
        return 0
    points.sort(key=lambda x: x[1])
    arrows = 1
    end = points[0][1]
    for i in range(1, len(points)):
        if points[i][0] > end:
            arrows += 1
            end = points[i][1]
    return arrows


if __name__ == "__main__":
    print(find_min_arrow_shots([[10, 16], [2, 8], [1, 6], [7, 12]]))  # 预期: 2
    print(find_min_arrow_shots([[1, 2], [3, 4], [5, 6]]))             # 预期: 3
    print(find_min_arrow_shots([[1, 2], [2, 3]]))                    # 预期: 1
