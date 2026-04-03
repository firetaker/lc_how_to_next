# 和为 K 的子数组（LeetCode #560）

## 题目描述

> 给定一个整数数组 `nums` 和一个整数 `k`，返回**连续子数组**之和等于 `k` 的数量。

**示例：**
- 输入：`nums = [1, 2, 3], k = 3`
- 输出：`2`（`[1, 2]` 和 `[3]`）

---

## 梯度分析

### 🔵 第一层：枚举所有子数组（O(n²)）

```python
count = 0
for i in range(len(nums)):
    total = 0
    for j in range(i, len(nums)):
        total += nums[j]
        if total == k: count += 1
```

- 时间：O(n²)
- 空间：O(1)

---

### 🟢 第二层：前缀和 + 哈希表

**核心公式：** 子数组 `[j..i-1]` 的和 = `prefix_sum[i] - prefix_sum[j]`

> 如果我们想知道是否存在和为 k 的子数组结尾于 i，即：
> `prefix_sum[i] - prefix_sum[j] = k` → `prefix_sum[j] = prefix_sum[i] - k`

因此，对于当前前缀和 `prefix_sum[i]`，我们需要知道之前有多少个前缀和等于 `prefix_sum[i] - k`。

**哈希表维护「前缀和 → 出现次数」：**

```python
pre_sum = 0
pre_count = {0: 1}  # 初始：空数组前缀和为0，出现1次
count = 0
for num in nums:
    pre_sum += num
    if pre_sum - k in pre_count:
        count += pre_count[pre_sum - k]
    pre_count[pre_sum] = pre_count.get(pre_sum, 0) + 1
```

**图解 `nums=[1,1,1], k=2`：**

| 步骤 | num | pre_sum | pre_sum - k | pre_count（判断前） | 命中 | count |
|------|-----|---------|------------|-------------------|------|-------|
| 初始 | - | 0 | - | {0:1} | - | 0 |
| 1 | 1 | 1 | -1 | {0:1} | ❌ | 0 |
| 2 | 1 | 2 | 0 | {0:1,1:1} | ✅ +1 | 1 |
| 3 | 1 | 3 | 1 | {0:1,1:1,2:1} | ✅ +1 | 2 |

结果：count = 2，对应 `[1,1]` 和 `[1,1]`（两个起点不同）。

**为什么 {0:1} 初始值很重要？**
- 如果从下标 0 开始的子数组和就等于 k，需要正确计数
- `pre_count[0] = 1` 确保了当 `pre_sum == k` 时，能找到「空数组前缀和 0」这一次

**复杂度：**
- 时间：O(n)，每个元素处理一次
- 空间：O(n)，哈希表最坏存 n 个不同前缀和

---

## 破题总结

> **维护前缀和的哈希表（出现次数），当前缀和减去 k 的值存在于哈希表中时，说明存在以当前位置结尾的和为 k 的连续子数组——将 O(n²) 的双重循环优化为 O(n) 单次遍历。**
