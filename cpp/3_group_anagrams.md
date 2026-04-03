# 字母异位词分组（LeetCode #49）

## 题目描述

> 给定一个字符串数组 `strs`，将字母异位词组合在一起。

**示例：**
- 输入：`["eat", "tea", "tan", "ate", "nat", "bat"]`
- 输出：`[["eat", "tea", "ate"], ["tan", "nat"], ["bat"]]`

---

## 梯度分析

### 🔵 第一层：排序字符串作为 key

**核心观察：** 字母异位词排序后得到的字符串完全相同。

- "eat" → 排序 → "aet"
- "tea" → 排序 → "aet"
- "tan" → 排序 → "ant"

```cpp
unordered_map<string, vector<string>> groups;
for (const string& s : strs) {
    string key = s;
    sort(key.begin(), key.end());
    groups[key].push_back(s);
}
```

**复杂度：**
- 时间：O(n × k log k)，k 为字符串平均长度
- 空间：O(n × k)

---

### 🟢 第二层：字符计数（不排序）

用固定 26 字符的数组做频次统计，元组作为 key：

```cpp
string count_key(const string& s) {
    vector<int> cnt(26, 0);
    for (char ch : s) cnt[ch - 'a']++;
    string key;
    for (int c : cnt) key += to_string(c) + '#';  // # 分隔避免混淆
    return key;
}
```

两者时间同量级，**排序法实现更简洁，面试更常见**。

---

## 破题总结

> **字母异位词的「身份证」是排序后的字符串——将每个字符串排序，相同 key 的即为异位词，天然归为一组。**
