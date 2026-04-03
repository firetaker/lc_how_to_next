# 最长连续序列（LeetCode #128）

## 题目描述

> 给定未排序整数数组 `nums`，找最长连续序列的长度，要求 O(n) 时间。

**示例：**
- 输入：`[100, 4, 200, 1, 3, 2]`
- 输出：`4`（`[1, 2, 3, 4]`）

---

## 梯度分析

### 🔵 第一层：排序后遍历（不符合 O(n) 要求）

```cpp
sort(nums.begin(), nums.end());
int longest = 1, cur = 1;
for (int i = 1; i < nums.size(); ++i) {
    if (nums[i] == nums[i-1] + 1) cur++;
    else if (nums[i] != nums[i-1]) cur = 1;
    longest = max(longest, cur);
}
```

- 时间：O(n log n)，排序主导

---

### 🟢 第二层：哈希集合 + 起点检测（O(n)）

**核心洞察：** 只从连续序列的最小元素（`num-1` 不在 Set 中）出发扩展。

```cpp
unordered_set<int> num_set(nums.begin(), nums.end());
int longest = 0;
for (int num : num_set) {
    if (num_set.find(num - 1) == num_set.end()) { // 只从起点开始
        int cur = num, cur_len = 1;
        while (num_set.find(cur + 1) != num_set.end()) {
            ++cur; ++cur_len;
        }
        longest = max(longest, cur_len);
    }
}
```

**为什么只从「起点」扩展？**

考虑 `[1,2,3,4]`：从 1 开始统计长度 4；从 2/3/4 开始只会重复统计更短的序列。

**复杂度：**
- 时间：O(n)，每个元素最多访问常数次
- 空间：O(n)

---

## 破题总结

> **将数组全部放入 Set，从每个连续序列的最小元素（`num-1` 不在 Set 中）出发向后扩展，确保每个序列只遍历一次，达到 O(n) 时间。**
