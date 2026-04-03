#!/usr/bin/env python3
"""
695. 岛屿的最大面积
"""
def max_area_of_island(grid: list[list[int]]) -> int:
    m, n = len(grid), len(grid[0])

    def dfs(r, c):
        if r < 0 or r >= m or c < 0 or c >= n or grid[r][c] == 0:
            return 0
        grid[r][c] = 0
        return 1 + dfs(r+1, c) + dfs(r-1, c) + dfs(r, c+1) + dfs(r, c-1)

    max_area = 0
    for r in range(m):
        for c in range(n):
            if grid[r][c] == 1:
                max_area = max(max_area, dfs(r, c))
    return max_area

if __name__ == "__main__":
    # 测试用例
    grid1 = [[0, 0, 1, 0, 0, 0, 0, 1, 0, 0], [0, 0, 0, 0, 0, 0, 0, 1, 1, 1], [0, 1, 1, 0, 1, 0, 0, 0, 0, 0], [0, 1, 0, 0, 1, 1, 0, 0, 1, 0]]
    print(max_area_of_island(grid1))  # 预期: 6
    grid2 = [[0, 0, 0, 0, 0, 0, 0, 0]]
    print(max_area_of_island(grid2))  # 预期: 0
    grid3 = [[1, 1, 0, 0, 0], [1, 1, 0, 0, 0], [0, 0, 0, 1, 1], [0, 0, 0, 1, 1]]
    print(max_area_of_island(grid3))  # 预期: 4
