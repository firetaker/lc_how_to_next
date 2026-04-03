# 螺旋矩阵（LeetCode #54）

## 题目描述

> 按顺时针螺旋顺序返回矩阵所有元素。

**示例：**
- 输入：`[[1,2,3],[4,5,6],[7,8,9]]` → 输出：`[1,2,3,6,9,8,7,4,5]`

---

## 梯度分析

### 🔵 第一层：方向数组 + 边界判断

维护当前位置 `(i,j)` 和方向 `dir∈{0,1,2,3}`（右、下、左、上），走到边界时转向。

---

### 🟢 第二层：边界收缩法（更简洁）

**核心洞察：** 每次走完一条边后，对应边界向内收缩一个单位，防止重复访问。

```python
result = []
top, bottom, left, right = 0, m-1, 0, n-1
while left <= right and top <= bottom:
    # 右→下→左→上
    for j in range(left, right+1): result.append(matrix[top][j])
    top += 1
    for i in range(top, bottom+1): result.append(matrix[i][right])
    right -= 1
    if top <= bottom:
        for j in range(right, left-1, -1): result.append(matrix[bottom][j])
        bottom -= 1
    if left <= right:
        for i in range(bottom, top-1, -1): result.append(matrix[i][left])
        left += 1
```

**图解 3×3 矩阵的边界收缩过程：**

```
初始: top=0, bottom=2, left=0, right=2

[1,2,3]    → top=1  (右侧列→下)
[4,5,6]
[7,8,9]

[4,5] → right=1  (第5步: 从[2,1]→[2,0]  右侧列→左)
[7,8]

[7] → bottom=1  (第7步: 从[1,0]→[0,0]  下侧行→上)
```

**为什么能保证不重复？**
- 每走完一条边，对应边界内缩一个单位
- 下次访问时，该区域已被收缩排除在外

**复杂度：**
- 时间：O(mn)
- 空间：O(1)

---

## 破题总结

> **维护上下左右四个边界，按右→下→左→上的顺序遍历，每走完一条边收缩对应边界——收缩后的边界自然形成"已访问禁区"，遍历完即得到螺旋顺序。**
