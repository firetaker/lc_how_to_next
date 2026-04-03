#!/usr/bin/env python3
"""
295. 数据流的中位数
"""
import heapq

class MedianFinder:
    def __init__(self):
        self.small = []
        self.large = []

    def add_num(self, num: int) -> None:
        heapq.heappush(self.small, -num)
        heapq.heappush(self.large, -heapq.heappop(self.small))
        if len(self.small) < len(self.large):
            heapq.heappush(self.small, -heapq.heappop(self.large))

    def find_median(self) -> float:
        if len(self.small) > len(self.large):
            return -self.small[0]
        return (-self.small[0] + self.large[0]) / 2.0

if __name__ == "__main__":
    # 测试用例
    mf = MedianFinder()
    mf.add_num(1)
    mf.add_num(2)
    print(mf.find_median())  # 预期: 1.5
    mf.add_num(3)
    print(mf.find_median())  # 预期: 2.0
    mf2 = MedianFinder()
    mf2.add_num(2)
    mf2.add_num(3)
    mf2.add_num(4)
    print(mf2.find_median())  # 预期: 3.0
