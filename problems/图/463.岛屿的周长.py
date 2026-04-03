#!/usr/bin/env python3
"""
463. 岛屿的周长
"""
def island_perimeter(grid: list[list[int]]) -> int:
    m, n = len(grid), len(grid[0])
    perimeter = 0
    for r in range(m):
        for c in range(n):
            if grid[r][c] == 1:
                if r == 0 or grid[r-1][c] == 0: perimeter += 1
                if r == m-1 or grid[r+1][c] == 0: perimeter += 1
                if c == 0 or grid[r][c-1] == 0: perimeter += 1
                if c == n-1 or grid[r][c+1] == 0: perimeter += 1
    return perimeter

if __name__ == "__main__":
    # 测试用例
    grid1 = [[0, 1, 0, 0], [1, 1, 1, 0], [0, 1, 0, 0], [0, 1, 1, 0]]
    print(island_perimeter(grid1))  # 预期: 16
    grid2 = [[1]]
    print(island_perimeter(grid2))  # 预期: 4
    grid3 = [[1, 0]]
    print(island_perimeter(grid3))  # 预期: 4
