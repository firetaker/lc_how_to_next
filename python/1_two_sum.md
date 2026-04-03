# 两数之和（LeetCode #1）

## 题目描述

> 给定一个整数数组 `nums` 和一个目标值 `target`，请你在数组中找出和为目标值的两个整数，返回它们的索引。

**示例：**
- 输入：`nums = [2, 7, 11, 15], target = 9`
- 输出：`[0, 1]`（因为 `nums[0] + nums[1] = 2 + 7 = 9`）

---

## 梯度分析

### 🔵 第一层：暴力解法（Brute Force）

拿到这道题，最直觉的想法是——枚举所有可能的两个数的组合，检查它们的和是否等于 `target`。

```python
for i in range(n):
    for j in range(i+1, n):
        if nums[i] + nums[j] == target:
            return [i, j]
```

**分析：**
- 时间复杂度：O(n²)，需遍历所有两两组合
- 空间复杂度：O(1)
- 问题：对于 `n = 10⁵` 的数组，O(n²) 意味着 10¹⁰ 次操作，会超时

**这是面试官最不想看到的解法**，但它是我们思考优化的起点。

---

### 🟢 第二层：排序 + 双指针（Sort + Two Pointers）

注意到题目只要求返回索引，不要求保持原顺序。如果我们愿意牺牲原始顺序，可以先排序，再用双指针：

```python
sorted_nums = sorted(enumerate(nums), key=lambda x: x[1])  # 按值排序
left, right = 0, len(sorted_nums) - 1
while left < right:
    s = sorted_nums[left][1] + sorted_nums[right][1]
    if s == target:
        return [sorted_nums[left][0], sorted_nums[right][0]]
    elif s < target: left += 1
    else: right -= 1
```

**分析：**
- 时间复杂度：O(n log n)（排序）
- 空间复杂度：O(n)
- 问题：需要额外空间存储排序后的索引，且代码复杂度增加

---

### 🟡 第三层：哈希表（Hash Map）—— 最优解

**核心观察：** 对于每个元素 `nums[i]`，我们要找的是 `target - nums[i]` 是否存在于数组中。

> 这就像查字典——我们一边遍历，一边把已经遍历过的数字"登记"到哈希表中。需要查询时 O(1) 时间内完成。

**算法流程：**
1. 创建一个空字典 `index_map`（存放「数值 → 索引」）
2. 遍历数组，对每个元素 `nums[i]`：
   - 计算差值 `complement = target - nums[i]`
   - 如果 `complement` 已在字典中 → 找到答案，返回 `[index_map[complement], i]`
   - 否则，将 `nums[i]` 及其索引存入字典

**图解过程（nums = [2, 7, 11, 15], target = 9）：**

| 步骤 | i | nums[i] | complement | index_map（此时） | 动作 |
|------|---|---------|------------|-------------------|------|
| 1 | 0 | 2 | 7 | {} | 7 不在，存入 {2:0} |
| 2 | 1 | 7 | 2 | {2:0} | **2 在！返回 [0, 1]** ✅ |

**复杂度：**
- 时间复杂度：O(n)，每个元素只遍历一次
- 空间复杂度：O(n)，最坏情况下需存入 n-1 个元素

---

## 破题总结

> **遍历数组时，将每个数存入哈希表，同时查找差值是否已存在——「边存边查」，将两数之和的查询从 O(n²) 降为 O(n)。**
