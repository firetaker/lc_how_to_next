# 找到字符串中所有字母异位词（LeetCode #438）

## 题目描述

> 在 `s` 中找出所有 `p` 的字母异位词的起始索引。

**示例：**
- `s = "cbaebabacd", p = "abc"` → `[0, 6]`

---

## 梯度分析

### 🔵 第一层：固定窗口 + 排序比较 O(n × k log k)

每个窗口排序后与 `p` 的排序比较，效率低。

---

### 🟢 第二层：滑动窗口 + 字符计数 O(n)

```cpp
vector<int> need(26, 0), window(26, 0);
for (char ch : p) need[ch - 'a']++;

int left = 0;
vector<int> result;
for (int right = 0; right < s.size(); ++right) {
    window[s[right] - 'a']++;
    if (right - left + 1 >= p.size()) {
        if (window == need) result.push_back(left);
        window[s[left] - 'a']--;
        ++left;
    }
}
```

**图解 `s="cbaebabacd", p="abc"`：**

```
need = [1,1,1,0,...]  (a=1, b=1, c=1)

right=0: c → window=[0,0,1], len=1<3
right=1: b → window=[0,1,1], len=2<3
right=2: a → window=[1,1,1], len=3 → window==need → res=[0]
         移出 c → window=[0,1,1], left=1
right=3: a → window=[1,1,1], len=3 → window==need → res=[0]
         移出 b → window=[1,0,1], left=2
...继续滑动，最终 res=[0,6]
```

**复杂度：**
- 时间：O(n)
- 空间：O(1)（固定 26 格数组）

---

## 破题总结

> **用字符频次数组（固定 26 格）替代排序，在 s 上滑动 len(p) 长的窗口——当窗口字符频次与 p 完全匹配时，该窗口即为异位词，时间 O(n)。**
