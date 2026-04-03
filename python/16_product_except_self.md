# 除自身以外的数组乘积（LeetCode #238）

## 题目描述

> 返回 `answer[i] = 除 nums[i] 以外所有元素的乘积`。不能用除法。

**示例：**
- 输入：`[1,2,3,4]` → 输出：`[24,12,8,6]`
- 1 的左边乘积=1，右边乘积=2×3×4=24 → 1×24=24

---

## 梯度分析

### 🔵 第一层：前缀积 × 后缀积 O(n²)

对每个 i，分别计算前后所有数的乘积。重复计算，O(n²)。

---

### 🟢 第二层：前后缀分解 O(n)

**核心公式：**
- `prefix[i]` = `nums[0] × nums[1] × ... × nums[i-1]`（不含 i）
- `suffix[i]` = `nums[i+1] × ... × nums[n-1]`（不含 i）
- `answer[i]` = `prefix[i] × suffix[i]`

**两次遍历：**

```python
n = len(nums)
answer = [1] * n

# 第一遍：计算前缀积（存在 answer 中）
prefix = 1
for i in range(n):
    answer[i] = prefix    # nums[i] 左边的所有乘积
    prefix *= nums[i]

# 第二遍：从右向左乘入后缀积
suffix = 1
for i in range(n - 1, -1, -1):
    answer[i] *= suffix   # 乘以 nums[i] 右边的所有乘积
    suffix *= nums[i]
```

**图解 `[1, 2, 3, 4]`：**

```
第一遍（prefix）:
i=0: answer[0]=1, prefix=1
i=1: answer[1]=1, prefix=2
i=2: answer[2]=2, prefix=6
i=3: answer[3]=6, prefix=24

第二遍（suffix，从右向左）:
i=3: answer[3]*=1=6, suffix=4
i=2: answer[2]*=4=8, suffix=12
i=1: answer[1]*=12=12, suffix=24
i=0: answer[0]*=24=24

结果: [24, 12, 8, 6] ✅
```

**复杂度：**
- 时间：O(n)
- 空间：O(1)（输出数组外只用两个变量）

---

## 破题总结

> **answer[i] = 左边所有数的乘积 × 右边所有数的乘积。两次遍历分别累计前缀积和后缀积，在结果数组上一次合并。**
