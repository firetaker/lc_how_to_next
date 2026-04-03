# 三数之和（LeetCode #15）

## 题目描述

> 给定一个数组 `nums`，找出所有和为 0 的**不重复**三元组。

**示例：**
- 输入：`[-1, 0, 1, 2, -1, -4]`
- 输出：`[[-1, -1, 2], [-1, 0, 1]]`

---

## 梯度分析

### 🔵 第一层：哈希集合去重（容易出错）

三层循环枚举所有三元组，用集合去重：

- 时间：O(n³)，不可接受
- 去重逻辑复杂，容易出错

---

### 🟢 第二层：排序 + 双指针（标准解法）

**排序的威力：**
1. 排序后，相同元素相邻 → 容易跳过重复
2. 排序后，可以用双指针收缩搜索空间

**核心思路：**
1. 固定一个数 `nums[i]`，问题转化为「在 i+1..n-1 范围内找两数之和等于 -nums[i]」
2. 使用双指针 `left=i+1`, `right=n-1`，向中间收缩

```python
nums.sort()
result = []
for i in range(n - 2):
    if nums[i] > 0: break              # 三数之和为0，最小值都>0，无解
    if i > 0 and nums[i] == nums[i-1]: continue  # 跳过重复的 i
    left, right = i + 1, n - 1
    while left < right:
        total = nums[i] + nums[left] + nums[right]
        if total == 0:
            result.append([nums[i], nums[left], nums[right]])
            left += 1; right -= 1
            while left < right and nums[left] == nums[left-1]: left += 1
            while left < right and nums[right] == nums[right+1]: right -= 1
        elif total < 0: left += 1
        else: right -= 1
```

**去重技巧图解：**

对于 `[-1, -1, -1, 0, 1]`，固定 i=0（第一个 -1）：
- 若不跳过第二个 -1，会重复产生相同的三元组
- `if i > 0 and nums[i] == nums[i-1]: continue` 保证了 i 不重复

对于 `nums = [-2, 0, 0, 2, 2]`，当找到 `[0, 0, 2]` 后：
- `left++` 和 `right--` 后，需要跳过重复的 0 和 2

**为什么先排序再处理 i>0 的情况是合理的？**

排序后相同的元素聚集，固定 i 时只需要保证 i 不取到重复值区间中的第二个起始位置。

**复杂度：**
- 时间：排序 O(n log n) + 双指针 O(n²) = O(n²)
- 空间：O(1)（不计结果空间）

---

## 破题总结

> **排序后枚举最小数，用双指针在已排序的剩余数组中找两数之和为零——排序使去重和双指针收缩都变得简洁，将 O(n³) 降为 O(n²)。**
