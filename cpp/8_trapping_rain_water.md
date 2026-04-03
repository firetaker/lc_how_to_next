# 接雨水（LeetCode #42）

## 题目描述

> 给定高度图，计算能接多少雨水。

**示例：**
- 输入：`[0,1,0,2,1,0,1,3,2,1,2,1]`
- 输出：`6`

```
     █
   █ █ █
 █ █ █ █
```

---

## 梯度分析

### 🔵 第一层：按列计算（O(n²)）

对每个位置找左右最高墙，逐列计算。

---

### 🟢 第二层：预处理前后缀 O(n)

```cpp
int n = height.size();
vector<int> left_max(n), right_max(n);
left_max[0] = height[0];
for (int i = 1; i < n; ++i) left_max[i] = max(left_max[i-1], height[i]);
right_max[n-1] = height[n-1];
for (int i = n-2; i >= 0; --i) right_max[i] = max(right_max[i+1], height[i]);
int water = 0;
for (int i = 0; i < n; ++i)
    water += max(0, min(left_max[i], right_max[i]) - height[i]);
```

**复杂度：**
- 时间：O(n)
- 空间：O(n)

---

### 🟡 第三层：相向双指针 O(1) 空间

```cpp
int left = 0, right = n - 1;
int left_max = 0, right_max = 0, water = 0;
while (left < right) {
    if (height[left] < height[right]) {
        if (height[left] >= left_max) left_max = height[left];
        else water += left_max - height[left];
        ++left;
    } else {
        if (height[right] >= right_max) right_max = height[right];
        else water += right_max - height[right];
        --right;
    }
}
```

**核心洞察：** 只需较小的那个 `max` 就能决定当前格子的蓄水量，无需同时知道两边的最大值。

**复杂度：**
- 时间：O(n)
- 空间：O(1)

---

## 破题总结

> **每个位置的水量由「左右两侧最高墙的较小值」决定——前后缀分解将左右最大值预计算；双指针更进一步，每次只处理较小侧，实现 O(1) 空间。**
