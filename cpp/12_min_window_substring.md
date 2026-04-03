# 最小覆盖子串（LeetCode #76）

## 题目描述

> 在 `s` 中找出包含 `t` 所有字符的最小子串。

**示例：**
- 输入：`s="ADOBECODEBANC", t="ABC"`
- 输出：`"BANC"`

---

## 梯度分析

### 🔵 第一层：暴力枚举个所有子串 O(n²×|t|)

枚举 s 的所有子串，检查是否覆盖 t。不可接受。

---

### 🟢 第二层：滑动窗口 + 字符计数 O(n)

**核心洞察：** 用 `need` 记录 t 中各字符的需求量，`window` 记录当前窗口中各字符的数量。维护 `less` 变量——表示**还有多少种字符的需求未满足**。

```python
need = Counter(t)
window = Counter()
less = len(need)  # 有多少种字符的需求尚未满足
for right, ch in enumerate(s):
    if ch in need:
        window[ch] += 1
        if window[ch] == need[ch]:
            less -= 1          # 这种字符的需求刚被满足
    while less == 0:           # 窗口已满足条件，收缩找最小
        更新最小答案
        left_ch = s[left]
        if left_ch in need:
            if window[left_ch] == need[left_ch]:
                less += 1      # 刚失去满足条件
            window[left_ch] -= 1
        left += 1
```

**图解 `s="ADOBECODEBANC", t="ABC"` 关键步骤：**

```
need: {A:1, B:1, C:1}  less=3

right=0 'D': 不需要 → less=3
right=1 'O': 不需要 → less=3
...
right=5 'E': 不需要 → less=3
right=9 'B': window[B]=1 == need[B] → less=2
right=10 'A': window[A]=1 == need[A] → less=1
right=11 'N': 不需要 → less=1
... 继续扩展 right 直到 less=0，然后收缩 left
最终: "BANC" 长度=4
```

**`less` 的精妙之处：**
- 初始 `less = len(set(t))`
- 当某字符的 window 量**恰好达到** need 量时，`less--`
- 当某字符的 window 量**从 need 量减为 need-1** 时，`less++`
- `less == 0` 即表示窗口完全满足条件

**复杂度：**
- 时间：O(n)
- 空间：O(1)（字符集大小固定）

---

## 破题总结

> **`need/window` 计数 + `less` 变量追踪"未满足字符种类数"——`less==0` 时收缩左端点，每次找到满足条件的最小窗口，时间 O(n)。**
