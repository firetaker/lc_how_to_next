#!/usr/bin/env python3
"""
200. 岛屿数量
"""
def num_islands(grid: list[list[str]]) -> int:
    if not grid:
        return 0
    m, n = len(grid), len(grid[0])
    count = 0

    def dfs(r, c):
        if r < 0 or r >= m or c < 0 or c >= n or grid[r][c] == '0':
            return
        grid[r][c] = '0'
        for dr, dc in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
            dfs(r+dr, c+dc)

    for r in range(m):
        for c in range(n):
            if grid[r][c] == '1':
                count += 1
                dfs(r, c)
    return count

if __name__ == "__main__":
    # 测试用例
    grid1 = [['1', '1', '1', '1', '0'], ['1', '1', '0', '1', '0'], ['1', '1', '0', '0', '0'], ['0', '0', '0', '0', '0']]
    print(num_islands(grid1))  # 预期: 1
    grid2 = [['1', '1', '0', '0', '0'], ['1', '1', '0', '0', '0'], ['0', '0', '1', '0', '0'], ['0', '0', '0', '1', '1']]
    print(num_islands(grid2))  # 预期: 3
