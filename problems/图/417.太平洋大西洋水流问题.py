#!/usr/bin/env python3
"""
417. 太平洋大西洋水流问题
"""
def pacific_atlantic(heights: list[list[int]]) -> list[list[int]]:
    if not heights:
        return []
    m, n = len(heights), len(heights[0])
    pac = [[False] * n for _ in range(m)]
    atl = [[False] * n for _ in range(m)]

    def dfs(r, c, visited, prev_h):
        if r < 0 or r >= m or c < 0 or c >= n or visited[r][c] or heights[r][c] < prev_h:
            return
        visited[r][c] = True
        for dr, dc in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
            dfs(r+dr, c+dc, visited, heights[r][c])

    for c in range(n): dfs(0, c, pac, 0)
    for r in range(m): dfs(r, 0, pac, 0)
    for c in range(n): dfs(m-1, c, atl, 0)
    for r in range(m): dfs(r, n-1, atl, 0)

    return [[r, c] for r in range(m) for c in range(n) if pac[r][c] and atl[r][c]]

if __name__ == "__main__":
    # 测试用例
    heights1 = [[1, 2, 2, 3, 5], [3, 2, 3, 4, 4], [2, 4, 5, 3, 1], [6, 7, 1, 4, 5], [5, 1, 1, 2, 4]]
    result1 = pacific_atlantic(heights1)
    print(result1)  # 预期: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
    heights2 = [[1]]
    result2 = pacific_atlantic(heights2)
    print(result2)  # 预期: [[0,0]]
