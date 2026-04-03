# 两数之和（LeetCode #1）

## 题目描述

> 给定一个整数数组 `nums` 和一个目标值 `target`，请你在数组中找出和为目标值的两个整数，返回它们的索引。

**示例：**
- 输入：`nums = [2, 7, 11, 15], target = 9`
- 输出：`[0, 1]`（因为 `nums[0] + nums[1] = 2 + 7 = 9`）

---

## 梯度分析

### 🔵 第一层：暴力解法（Brute Force）

枚举所有两两组合，检查和是否等于 `target`：

```cpp
for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
        if (nums[i] + nums[j] == target)
            return {i, j};
```

**分析：**
- 时间复杂度：O(n²)，两两枚举
- 空间复杂度：O(1)
- **问题：** n = 10⁵ 时，10¹⁰ 次操作会超时

---

### 🟢 第二层：哈希表（Hash Map）—— 最优解

**核心观察：** 对于每个元素 `nums[i]`，要找的是 `target - nums[i]` 是否存在。

> 一边遍历，一边将已遍历的数"登记"到哈希表，查询 O(1)。

```cpp
unordered_map<int, int> index_map; // val -> index
for (int i = 0; i < nums.size(); ++i) {
    int complement = target - nums[i];
    if (index_map.count(complement))
        return {index_map[complement], i};
    index_map[nums[i]] = i;
}
```

**图解过程（nums = [2, 7, 11, 15], target = 9）：**

| 步骤 | i | nums[i] | complement | index_map（此时） | 动作 |
|------|---|---------|------------|-------------------|------|
| 1 | 0 | 2 | 7 | {} | 7 不在，存入 {2:0} |
| 2 | 1 | 7 | 2 | {2:0} | **2 在！返回 [0, 1]** ✅ |

**复杂度：**
- 时间：O(n)，每个元素只遍历一次
- 空间：O(n)

---

## 破题总结

> **遍历数组时，将每个数存入哈希表，同时查找差值是否已存在——「边存边查」，将两数之和的查询从 O(n²) 降为 O(n)。**
