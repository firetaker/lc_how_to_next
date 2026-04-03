# 无重复字符的最长子串（LeetCode #3）

## 题目描述

> 找不含重复字符的最长子串长度。

**示例：**
- `"abcabcbb"` → `3`（"abc"）
- `"bbbbb"` → `1`（"b"）

---

## 梯度分析

### 🔵 第一层：暴力枚举所有子串 O(n³)

枚举子串 + 检查重复 → 不可接受。

---

### 🟢 第二层：滑动窗口 + 哈希表 O(n)

```cpp
unordered_map<char, int> char_index;
int left = 0, max_len = 0;
for (int right = 0; right < s.size(); ++right) {
    char ch = s[right];
    if (char_index.count(ch) && char_index[ch] >= left)
        left = char_index[ch] + 1;
    char_index[ch] = right;
    max_len = max(max_len, right - left + 1);
}
```

**图解 `"abcabcbb"` 关键步骤：**

| right | ch | char_index | left | max_len | 说明 |
|-------|----|-----------|------|---------|------|
| 0 | a | {a:0} | 0 | 1 | |
| 1 | b | {a:0,b:1} | 0 | 2 | |
| 2 | c | {a:0,b:1,c:2} | 0 | 3 | |
| 3 | a | {a:3,b:1,c:2} | 1 | 3 | a 重复，收缩 left→1 |
| 4 | b | {a:3,b:4,c:2} | 2 | 3 | b 重复，收缩 left→2 |
| 5 | c | {a:3,b:4,c:5} | 3 | 3 | c 重复，收缩 left→3 |

**复杂度：**
- 时间：O(n)
- 空间：O(min(n, sigma))

---

## 破题总结

> **滑动窗口右指针不断扩展，遇到重复字符时将左指针收缩到重复字符上次出现位置之后，确保窗口始终无重复——每个字符仅进出一 次，时间 O(n)。**
