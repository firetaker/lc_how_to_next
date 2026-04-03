# 接雨水（LeetCode #42）

## 题目描述

> 给定 `n` 个非负整数表示的高度图，计算能接多少雨水。

**示例：**
- 输入：`[0,1,0,2,1,0,1,3,2,1,2,1]`
- 输出：`6`（6 个单位的雨水）

```
     █
   █ █ █
 █ █ █ █
```

---

## 梯度分析

### 🔵 第一层：暴力按列计算（O(n²)）

对每个位置 i，计算它上方能接多少雨水：
- 找到 i 左边最高的墙：`left_max`
- 找到 i 右边最高的墙：`right_max`
- `water[i] = max(0, min(left_max, right_max) - height[i])`

```python
water = 0
for i in range(n):
    left_max = max(height[:i+1])
    right_max = max(height[i:])
    water += max(0, min(left_max, right_max) - height[i])
```

- 时间：O(n²)（每次找 max 需 O(n)）
- 空间：O(1)

---

### 🟢 第二层：预处理前后缀最大值（O(n)）

提前把所有位置的 `left_max[i]` 和 `right_max[i]` 算出来：

```python
n = len(height)
left_max = [0] * n
right_max = [0] * n

left_max[0] = height[0]
for i in range(1, n):
    left_max[i] = max(left_max[i-1], height[i])

right_max[n-1] = height[n-1]
for i in range(n-2, -1, -1):
    right_max[i] = max(right_max[i+1], height[i])

water = sum(max(0, min(left_max[i], right_max[i]) - height[i]) for i in range(n))
```

- 时间：O(n)（遍历三遍）
- 空间：O(n)

---

### 🟡 第三层：相向双指针（O(1) 空间）

**空间优化的关键洞察：**

在双指针版本中，实际上不需要同时知道 `left_max` 和 `right_max`——只需要**两者中较小的那个**就能决定当前位置的蓄水量。

```
当前在位置 i：
- 如果 left_max < right_max：左侧最高的墙更矮
  → i 处的水量由 left_max 决定（左边不给力）
  → 移动 left 指针看能不能找到更高的
- 否则：右侧更矮，水量由 right_max 决定
  → 移动 right 指针
```

```python
left, right = 0, n - 1
left_max = right_max = 0
water = 0
while left < right:
    if height[left] < height[right]:
        if height[left] >= left_max:
            left_max = height[left]
        else:
            water += left_max - height[left]
        left += 1
    else:
        if height[right] >= right_max:
            right_max = height[right]
        else:
            water += right_max - height[right]
        right -= 1
```

**图解 `height = [0,1,0,2,1,0,1,3,2,1,2,1]` 的前几步：**

```
left=0, right=11, left_max=0, right_max=0
height[0]=0 < height[11]=1:
  height[0] >= left_max(0) → left_max=0, 不加水, left++
left=1, height[1]=1:
  height[1] >= left_max(0) → left_max=1, 不加水, left++
left=2, height[2]=0:
  height[2] < left_max(1) → water+=1, left++
...
```

**复杂度：**
- 时间：O(n)
- 空间：O(1)

---

## 破题总结

> **每个位置能接的水量由「左右两侧最高墙的较小值」决定——前后缀分解将每个位置左右最大值预计算出来；双指针优化更进一步，每次只处理较小侧，实现 O(1) 空间。**
