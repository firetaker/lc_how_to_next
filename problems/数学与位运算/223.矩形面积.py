#!/usr/bin/env python3
"""
223. 矩形面积
"""
def compute_area(ax1: int, ay1: int, ax2: int, ay2: int,
                 bx1: int, by1: int, bx2: int, by2: int) -> int:
    area1 = (ax2 - ax1) * (ay2 - ay1)
    area2 = (bx2 - bx1) * (by2 - by1)
    overlap = max(0, min(ax2, bx2) - max(ax1, bx1)) * max(0, min(ay2, by2) - max(ay1, by1))
    return area1 + area2 - overlap

if __name__ == "__main__":
    # 测试用例
    print(compute_area(-3, 0, 3, 4, 0, -1, 9, 2))  # 预期: 45
    print(compute_area(0, 0, 0, 0, -1, -1, 1, 1))  # 预期: 4
    print(compute_area(-2, -2, 2, 2, -4, -4, 0, 0))  # 预期: 20
