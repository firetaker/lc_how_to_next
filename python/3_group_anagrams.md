# 字母异位词分组（LeetCode #49）

## 题目描述

> 给定一个字符串数组 `strs`，将字母异位词（即包含相同字母但排列不同的字符串，如 "eat" 和 "tea"）组合在一起。

**示例：**
- 输入：`["eat", "tea", "tan", "ate", "nat", "bat"]`
- 输出：`[["eat", "tea", "ate"], ["tan", "nat"], ["bat"]]`

---

## 梯度分析

### 🔵 第一层：排序字符串作为 key

**核心观察：** 字母异位词的共同特征是——将字符串内部排序后，得到的字符串完全相同。

- "eat" → 排序 → "aet"
- "tea" → 排序 → "aet"
- "tan" → 排序 → "ant"

因此，将**排序后的字符串**作为哈希表的 key，字母异位词就会自动聚到同一组。

```python
groups = {}
for s in strs:
    key = ''.join(sorted(s))
    if key not in groups:
        groups[key] = []
    groups[key].append(s)
```

**复杂度：**
- 时间：O(n × k log k)，n 为字符串数量，k 为字符串平均长度（排序耗时）
- 空间：O(n × k)

---

### 🟢 第二层：用 `defaultdict` 简化代码

Python 的 `defaultdict` 可以让代码更简洁，无需每次检查 key 是否存在：

```python
from collections import defaultdict
groups = defaultdict(list)
for s in strs:
    key = ''.join(sorted(s))
    groups[key].append(s)
return list(groups.values())
```

**实质与第一层完全相同**，只是写法更 Pythonic。

---

### 🟡 第三层：字符计数（不排序）

有没有不需要排序的方法？可以用**固定长度的数组（26个字母）**做字符计数：

```python
def count_key(s):
    count = [0] * 26
    for ch in s:
        count[ord(ch) - ord('a')] += 1
    return tuple(count)  # 列表不可哈希，转为元组

groups = defaultdict(list)
for s in strs:
    groups[count_key(s)].append(s)
```

**对比：**
- 排序法：O(k log k) 时间，字符比较排序
- 计数法：O(k) 时间，但需额外 26 个整数的空间
- 两者时间复杂度同量级，**排序法实现更简洁，面试中更常见**

---

## 破题总结

> **字母异位词的「身份证」是排序后的字符串——将每个字符串排序，相同 key 的即为异位词，天然归为一组。**
