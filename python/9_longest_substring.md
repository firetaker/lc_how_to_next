# 无重复字符的最长子串（LeetCode #3）

## 题目描述

> 给定一个字符串 `s`，找出**不含重复字符**的最长子串长度。

**示例：**
- 输入：`"abcabcbb"` → 输出：`3`（"abc"）
- 输入：`"bbbbb"` → 输出：`1`（"b"）
- 输入：`"pwwkew"` → 输出：`3`（"wke"）

---

## 梯度分析

### 🔵 第一层：暴力滑动窗口（O(n³)）

枚举所有子串，检查是否有重复字符：

```python
for i in range(len(s)):
    for j in range(i+1, len(s)+1):
        if len(set(s[i:j])) == j - i:  # 无重复
            max_len = max(max_len, j - i)
```

- 时间：O(n³)，枚举子串 O(n²)，检查重复 O(n)

---

### 🟢 第二层：维护字符最新位置（O(n)）

**标准滑动窗口：** 右指针扩展，遇到重复字符时收缩左指针。

```python
char_index = {}  # char -> latest index
left = 0
max_len = 0
for right, ch in enumerate(s):
    if ch in char_index and char_index[ch] >= left:
        left = char_index[ch] + 1  # 收缩到重复字符之后
    char_index[ch] = right
    max_len = max(max_len, right - left + 1)
```

**图解 `"abcabcbb"`：**

| 步骤 | right | ch | char_index | left | max_len | 说明 |
|------|-------|----|-----------|------|---------|------|
| 1 | 0 | a | {a:0} | 0 | 1 | |
| 2 | 1 | b | {a:0,b:1} | 0 | 2 | |
| 3 | 2 | c | {a:0,b:1,c:2} | 0 | 3 | |
| 4 | 3 | a | {a:3,b:1,c:2} | 1 | 3 | a 重复，a 上次在0，收缩 left=0+1=1 |
| 5 | 4 | b | {a:3,b:4,c:2} | 2 | 3 | b 重复，收缩 left=1+1=2 |
| 6 | 5 | c | {a:3,b:4,c:5} | 3 | 3 | c 重复，收缩 left=2+1=3 |
| 7 | 6 | b | {a:3,b:6,c:5} | 4 | 3 | b 重复，收缩 left=4+1=5 |
| 8 | 7 | b | {a:3,b:7,c:5} | 6 | 3 | b 重复，收缩 left=6+1=7 |

最长 = 3（"abc" 或 "bca" 或 "cab"）

**核心洞察：**
- `char_index[ch] >= left` 判断字符是否在当前窗口内
- 如果在，就将 left 跳到「重复字符的下一个位置」
- 这样始终保证窗口内无重复字符

**复杂度：**
- 时间：O(n)，每个字符最多被左右指针各访问一次
- 空间：O(min(n, sigma))，sigma 为字符集大小

---

## 破题总结

> **滑动窗口右指针不断扩展，遇到重复字符时将左指针收缩到重复字符上次出现位置的右侧，确保窗口始终无重复——每个字符仅进出一 次，时间 O(n)。**
