# 找到字符串中所有字母异位词（LeetCode #438）

## 题目描述

> 给定字符串 `s` 和 `p`，找出 `s` 中所有 `p` 的**字母异位词**的起始索引。

**示例：**
- 输入：`s = "cbaebabacd", p = "abc"`
- 输出：`[0, 6]`（`s[0:3]="cba"`，`s[6:9]="cab"`，都是 "abc" 的异位词）

---

## 梯度分析

### 🔵 第一层：固定窗口 + 排序比较（O(n × k log k)）

枚举所有长度为 `len(p)` 的窗口，对每个窗口排序后与 `p` 的排序比较：

```python
k = len(p)
p_sorted = ''.join(sorted(p))
result = []
for i in range(len(s) - k + 1):
    if ''.join(sorted(s[i:i+k])) == p_sorted:
        result.append(i)
```

- 时间：O(n × k log k)，k 为 p 的长度
- 问题：每次窗口都要排序，效率低

---

### 🟢 第二层：不定长滑动窗口 + 字符计数（O(n)）

**与第 9 题「无重复字符最长子串」类似的思路：**

用两个数组记录字符频次：
- `need`：p 中各字符的需求量
- `window`：当前窗口中各字符的数量

窗口在 s 上滑动，每当 `window` 完全匹配 `need` 时，说明当前窗口是异位词。

```python
need = [0] * 26
window = [0] * 26
for ch in p: need[ord(ch) - ord('a')] += 1

left = 0
for right in range(len(s)):
    window[ord(s[right]) - ord('a')] += 1
    # 当窗口长度 >= len(p) 时，收缩到恰好 len(p)
    if right - left + 1 >= len(p):
        if window == need:  # 频次完全相同 → 异位词
            result.append(left)
        window[ord(s[left]) - ord('a')] -= 1
        left += 1
```

**图解 `s="cbaebabacd", p="abc"`：**

```
need = [1,1,1,0,...]  (a=1, b=1, c=1)

right=0: window[c]=1 → [0,0,1,...], len=1<3 → 不判断
right=1: window[b]=1 → [0,1,1,...], len=2<3 → 不判断
right=2: window[a]=1 → [1,1,1,...], len=3 → 判断: match! → res=[0]
         移出 s[0]=c → window[c]=0, left=1

right=3: window[b]=2 → [1,2,1,...], len=3 → 判断: a=1≠2 → 不匹配
         移出 s[1]=b → window[b]=1, left=2
right=4: window[a]=2 → [2,1,1,...], len=3 → 判断: a=2≠1 → 不匹配
         移出 s[2]=a → window[a]=1, left=3
...
right=6: (从 s[3] 开始新窗口扩展) → 最终找到 res=[0,6]
```

**为什么叫「不定长」滑窗？**
- 本题窗口长度**固定**为 `len(p)`
- 但代码实现上，窗口先扩展到足够长，再收缩——这是一种更通用的「滑动窗口模板」

**复杂度：**
- 时间：O(n × 1) = O(n)，每个字符最多进入和移出窗口各一次
- 空间：O(1)，26 个固定大小的数组

---

## 破题总结

> **用字符频次数组（固定 26 格）替代排序，在 s 上滑动一个 len(p) 长的窗口——当窗口字符频次与 p 完全匹配时，该窗口即为异位词，时间 O(n)。**
