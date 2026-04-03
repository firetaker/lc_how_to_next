#!/usr/bin/env python3
"""
373. 查找和最小的K对数字
"""
import heapq

def k_smallest_pairs(nums1: list[int], nums2: list[int], k: int) -> list[list[int]]:
    if not nums1 or not nums2:
        return []
    heap = [(nums1[0] + nums2[0], 0, 0)]
    visited = set()
    result = []
    while heap and len(result) < k:
        _, i, j = heapq.heappop(heap)
        result.append([nums1[i], nums2[j]])
        if i + 1 < len(nums1) and (i+1, j) not in visited:
            heapq.heappush(heap, (nums1[i+1] + nums2[j], i+1, j))
            visited.add((i+1, j))
        if j + 1 < len(nums2) and (i, j+1) not in visited:
            heapq.heappush(heap, (nums1[i] + nums2[j+1], i, j+1))
            visited.add((i, j+1))
    return result

if __name__ == "__main__":
    # 测试用例
    print(k_smallest_pairs([1, 7, 11], [2, 4, 6], 3))  # 预期: [[1,2],[1,4],[1,6]]
    print(k_smallest_pairs([1, 1, 2], [1, 2, 3], 2))  # 预期: [[1,1],[1,1]]
    print(k_smallest_pairs([1, 2], [3], 3))  # 预期: [[1,3],[2,3]]
