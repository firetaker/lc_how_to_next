# 三数之和（LeetCode #15）

## 题目描述

> 在数组中找出所有不重复的三数之和为 0 的组合。

**示例：**
- 输入：`[-1, 0, 1, 2, -1, -4]`
- 输出：`[[-1, -1, 2], [-1, 0, 1]]`

---

## 梯度分析

### 🔵 第一层：三层枚举 + 集合去重

- 时间：O(n³)
- 去重逻辑复杂，容易出错

---

### 🟢 第二层：排序 + 双指针（标准解）

```cpp
sort(nums.begin(), nums.end());
vector<vector<int>> result;
for (int i = 0; i < n - 2; ++i) {
    if (nums[i] > 0) break;                           // 最小值>0，无解
    if (i > 0 && nums[i] == nums[i-1]) continue;      // i 去重
    int left = i + 1, right = n - 1;
    while (left < right) {
        int total = nums[i] + nums[left] + nums[right];
        if (total == 0) {
            result.push_back({nums[i], nums[left], nums[right]});
            ++left; --right;
            while (left < right && nums[left] == nums[left-1]) ++left;
            while (left < right && nums[right] == nums[right+1]) --right;
        } else if (total < 0) {
            ++left;
        } else {
            --right;
        }
    }
}
```

**去重关键：**
- `i > 0 && nums[i] == nums[i-1]`：跳过重复的 i
- 找到解后跳过重复的 left/right

**复杂度：**
- 时间：O(n²)
- 空间：O(1)（不计结果）

---

## 破题总结

> **排序后枚举最小数，用双指针在已排序的剩余数组中找两数之和为零——排序使去重和双指针收缩都变得简洁，将 O(n³) 降为 O(n²)。**
