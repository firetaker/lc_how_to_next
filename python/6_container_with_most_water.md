# 盛最多水的容器（LeetCode #11）

## 题目描述

> 给定一个数组 `height`，每条垂线宽度为 1，两条线 `i` 和 `j` 之间能盛的水量为：
> `min(height[i], height[j]) × (j - i)`
> 求最大水量。

**示例：**
- 输入：`[1, 8, 6, 2, 5, 4, 8, 3, 7]`
- 输出：`49`（对应 1 和 7 两条线）

---

## 梯度分析

### 🔵 第一层：暴力枚举（O(n²)）

枚举所有两两组合，计算面积：

```python
max_water = 0
for i in range(n):
    for j in range(i+1, n):
        max_water = max(max_water, min(height[i], height[j]) * (j - i))
```

- 时间：O(n²)，对于大数据集会超时

---

### 🟢 第二层：相向双指针（O(n)）

**核心洞察：** 面积由「较短的木板」决定。

初始时，左右指针分别在最左和最右：
```
height = [1, 8, 6, 2, 5, 4, 8, 3, 7]
 i=0                              j=8
```

此时面积 = `min(1, 7) × 8 = 7`

**关键问题：应该移动哪一侧的指针？**

- 如果移动左侧的矮木板（height[0]=1）：
  - 高度不可能增加（因为新的矮木板 ≤ 1 = 原来的矮木板）
  - 宽度会减小
  - **面积一定不会增加**

- 如果移动右侧的木板：
  - 新高度可能增加
  - **有可能获得更大面积**

因此，**每次移动较短的那条边**，保留较高的边，期待后续能找到更高的木板。

```python
left, right = 0, len(height) - 1
max_water = 0
while left < right:
    h = min(height[left], height[right])
    w = right - left
    max_water = max(max_water, h * w)
    if height[left] < height[right]:
        left += 1
    else:
        right -= 1
```

**图解关键步骤：**

```
初始: left=0(1), right=8(7), area=min(1,7)*8=7, 1<7 → left++
left=1(8), right=8(7), area=min(8,7)*7=49, 8>7 → right--
left=1(8), right=7(3), area=min(8,3)*6=18, 8>3 → right--
...
```

**为什么 O(n) ？** 每次循环要么 `left++`，要么 `right--`，指针最多移动 n 次。

**复杂度：**
- 时间：O(n)
- 空间：O(1)

---

## 破题总结

> **相向双指针中，每次移动较短边的指针——因为面积由短板决定，固定长板后只有找到更高的短板才可能增大面积，指针移动次数被严格限制在 O(n)。**
