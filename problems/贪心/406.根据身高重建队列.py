#!/usr/bin/env python3
"""
406. 根据身高重建队列
算法: 贪心（身高降序，k升序，插入）
时间复杂度: O(n^2)
空间复杂度: O(n)
"""
def reconstruct_queue(people: list[list[int]]) -> list[list[int]]:
    people.sort(key=lambda x: (-x[0], x[1]))
    result = []
    for p in people:
        result.insert(p[1], p)
    return result


if __name__ == "__main__":
    print(reconstruct_queue([[7, 0], [4, 4], [7, 1], [5, 0], [6, 1], [5, 2]]))
    # 预期: [[5, 0], [7, 0], [5, 2], [6, 1], [4, 4], [7, 1]]
    print(reconstruct_queue([[6, 0], [5, 0], [4, 0], [3, 2], [2, 2], [1, 4]]))
    # 预期: [[4, 0], [5, 0], [2, 2], [3, 2], [1, 4], [6, 0]]
