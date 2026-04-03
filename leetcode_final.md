# LeetCode Top 100 高频题解集

> 本文档包含 Top 100 高频 LeetCode 题目的完整解法，每题提供 Python 和 C++ 实现，并附算法详解。

---

## 目录

1. [哈希表](#一哈希表hash-table)
2. [双指针](#二双指针two-pointers)
3. [滑动窗口](#三滑动窗口sliding-window)
4. [链表](#四链表linked-list)
5. [栈与队列](#五栈与队列stack--queue)
6. [二分查找](#六二分查找binary-search)
7. [动态规划](#七动态规划dynamic-programming)
8. [贪心](#八贪心greedy)
9. [回溯](#九回溯backtracking)
10. [树](#十树tree)
11. [堆](#十一堆heap--priority-queue)
12. [图](#十三图graph)
13. [数学与位运算](#十四数学与位运算math--bit-manipulation)

---

## 一、哈希表（Hash Table）

### 1. 两数之和 (Two Sum)

**题目**: 给定数组 nums 和目标值 target，找出和为目标值的两个数的下标。

**Python 实现**:
```python
def two_sum(nums: list[int], target: int) -> list[int]:
    seen = {}
    for i, num in enumerate(nums):
        complement = target - num
        if complement in seen:
            return [seen[complement], i]
        seen[num] = i
    return []

if __name__ == "__main__":

    # 测试用例
    print(two_sum([2, 7, 11, 15], 9))  # 预期: [0, 1]
    print(two_sum([3, 2, 4], 6))       # 预期: [1, 2]
    print(two_sum([3, 3], 6))         # 预期: [0, 1]  # 边界: 重复元素

```

**C++ 实现**:
```cpp
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> seen;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (seen.count(complement))
            return {seen[complement], i};
        seen[nums[i]] = i;
    }
    return {};
}

int main() {
    // 测试用例
    vector<int> nums1 = {2, 7, 11, 15};
    auto r1 = twoSum(nums1, 9);
    cout << r1[0] << " " << r1[1] << endl;  // 预期: 0 1
    vector<int> nums2 = {3, 2, 4};
    auto r2 = twoSum(nums2, 6);
    cout << r2[0] << " " << r2[1] << endl;  // 预期: 1 2
    vector<int> nums3 = {3, 3};
    auto r3 = twoSum(nums3, 6);
    cout << r3[0] << " " << r3[1] << endl;  // 预期: 0 1
    return 0;
}
```

**算法详解**:
- 使用哈希表边遍历边存储
- 对于每个元素，检查 `target - num` 是否已在哈希表中
- 时间复杂度 O(n)，空间复杂度 O(n)
- 核心思想：空间换时间，一次遍历完成查找

---

### 49. 字母异位词分组 (Group Anagrams)

**Python 实现**:
```python
def group_anagrams(strs: list[str]) -> list[list[str]]:
    from collections import defaultdict
    groups = defaultdict(list)
    for s in strs:
        key = ''.join(sorted(s))
        groups[key].append(s)
    return list(groups.values())

if __name__ == "__main__":

    # 测试用例
    print(group_anagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))
    # 预期: [['eat', 'tea', 'ate'], ['tan', 'nat'], ['bat']]
    print(group_anagrams([""]))      # 预期: [['']]
    print(group_anagrams(["a"]))      # 预期: [['a']]

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;
    for (const string& s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        groups[key].push_back(s);
    }
    vector<vector<string>> result;
    for (auto& [_, v] : groups)
        result.push_back(v);
    return result;
}

int main() {
    // 测试用例
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto result = groupAnagrams(strs);
    for (auto& g : result) { for (auto& s : g) cout << s << " "; cout << endl; }
    // 预期: eat tea ate | tan nat | bat
    vector<string> strs2 = {""};
    auto r2 = groupAnagrams(strs2);
    cout << (r2.empty() ? "empty" : r2[0][0]) << endl;
    return 0;
}
```

**算法详解**:
- 排序字符串作为 key，相同 key 的词为一组
- 字母异位词排序后结果相同
- 时间复杂度 O(n * k log k)，k 为字符串平均长度

---

### 128. 最长连续序列 (Longest Consecutive Sequence)

**Python 实现**:
```python
def longest_consecutive(nums: list[int]) -> int:
    num_set = set(nums)
    longest = 0
    for num in num_set:
        if num - 1 not in num_set:
            current = num
            streak = 1
            while current + 1 in num_set:
                current += 1
                streak += 1
            longest = max(longest, streak)
    return longest

if __name__ == "__main__":

    # 测试用例
    print(longest_consecutive([100, 4, 200, 1, 3, 2]))  # 预期: 4
    print(longest_consecutive([0, 3, 7, 2, 5, 8, 4, 6, 0, 1]))  # 预期: 9
    print(longest_consecutive([]))    # 预期: 0  # 边界: 空数组

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> num_set(nums.begin(), nums.end());
    int longest = 0;
    for (int num : num_set) {
        if (!num_set.count(num - 1)) {
            int current = num;
            int streak = 1;
            while (num_set.count(current + 1)) {
                current++;
                streak++;
            }
            longest = max(longest, streak);
        }
    }
    return longest;
}
int main() {
    // 测试用例
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(nums1) << endl;  // 预期: 4
    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << longestConsecutive(nums2) << endl;  // 预期: 9
    vector<int> nums3 = {};
    cout << longestConsecutive(nums3) << endl;  // 预期: 0
    return 0;
}

```

**算法详解**:
- 使用 Set 存储所有数字
- 只从序列起点开始扩展（num-1 不存在）
- 时间复杂度 O(n)，空间复杂度 O(n)

---

## 二、双指针（Two Pointers）

### 11. 盛最多水的容器 (Container With Most Water)

**Python 实现**:
```python
def max_area(height: list[int]) -> int:
    left, right = 0, len(height) - 1
    max_water = 0
    while left < right:
        width = right - left
        h = min(height[left], height[right])
        max_water = max(max_water, width * h)
        if height[left] < height[right]:
            left += 1
        else:
            right -= 1
    return max_water

if __name__ == "__main__":

    # 测试用例
    print(max_area([1, 8, 6, 2, 5, 4, 8, 3, 7]))  # 预期: 49
    print(max_area([1, 1]))           # 预期: 1
    print(max_area([4, 3, 2, 1, 4]))  # 预期: 16

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int max_water = 0;
    while (left < right) {
        int width = right - left;
        int h = min(height[left], height[right]);
        max_water = max(max_water, width * h);
        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return max_water;
}
int main() {
    // 测试用例
    vector<int> h1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(h1) << endl;  // 预期: 49
    vector<int> h2 = {1, 1};
    cout << maxArea(h2) << endl;  // 预期: 1
    vector<int> h3 = {4, 3, 2, 1, 4};
    cout << maxArea(h3) << endl;  // 预期: 16
    return 0;
}

```

**算法详解**:
- 相向双指针从两端向中间收缩
- 每次移动较短边的指针（因为移动较长边只会减少宽度）
- 时间复杂度 O(n)，空间复杂度 O(1)

---

### 283. 移动零 (Move Zeroes)

**Python 实现**:
```python
def move_zeroes(nums: list[int]) -> None:
    left = 0
    for right in range(len(nums)):
        if nums[right] != 0:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1

if __name__ == "__main__":

    # 测试用例
    nums1 = [0, 1, 0, 3, 12]
    move_zeroes(nums1); print(nums1)  # 预期: [1, 3, 12, 0, 0]
    nums2 = [0, 0, 1]
    move_zeroes(nums2); print(nums2)  # 预期: [1, 0, 0]

```

**C++ 实现**:
```cpp
#include <iostream>
#include <vector>

void moveZeroes(vector<int>& nums) {
    int left = 0;
    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] != 0) {
            swap(nums[left], nums[right]);
            left++;
        }
    }
}
int main() {
    // 测试用例
    vector<int> nz1 = {0, 1, 0, 3, 12};
    moveZeroes(nz1);
    for (int x : nz1) cout << x << " "; cout << endl;  // 预期: 1 3 12 0 0
    vector<int> nz2 = {0, 0, 1};
    moveZeroes(nz2);
    for (int x : nz2) cout << x << " "; cout << endl;  // 预期: 1 0 0
    return 0;
}

```

---

### 42. 接雨水 (Trapping Rain Water)

**Python 实现**:
```python
def trap(height: list[int]) -> int:
    left, right = 0, len(height) - 1
    left_max, right_max = 0, 0
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
    return water

if __name__ == "__main__":

    # 测试用例
    print(trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]))  # 预期: 6
    print(trap([4, 2, 0, 3, 2, 5]))  # 预期: 9
    print(trap([]))                  # 预期: 0  # 边界: 空

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int trap(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int left_max = 0, right_max = 0;
    int water = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            left_max = max(left_max, height[left]);
            water += left_max - height[left];
            left++;
        } else {
            right_max = max(right_max, height[right]);
            water += right_max - height[right];
            right--;
        }
    }
    return water;
}
int main() {
    // 测试用例
    vector<int> ht1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(ht1) << endl;  // 预期: 6
    vector<int> ht2 = {4, 2, 0, 3, 2, 5};
    cout << trap(ht2) << endl;  // 预期: 9
    vector<int> ht3 = {};
    cout << trap(ht3) << endl;  // 预期: 0
    return 0;
}

```

**算法详解**:
- 前后缀分解：每个位置的水量 = min(左侧最高, 右侧最高) - 当前高度
- 相向双指针：从低的一端向中间推进
- 时间复杂度 O(n)，空间复杂度 O(1)

---

### 15. 三数之和 (3Sum)

**Python 实现**:
```python
def three_sum(nums: list[int]) -> list[list[int]]:
    nums.sort()
    result = []
    for i in range(len(nums) - 2):
        if i > 0 and nums[i] == nums[i-1]:
            continue
        left, right = i + 1, len(nums) - 1
        while left < right:
            s = nums[i] + nums[left] + nums[right]
            if s < 0:
                left += 1
            elif s > 0:
                right -= 1
            else:
                result.append([nums[i], nums[left], nums[right]])
                left += 1
                right -= 1
                while left < right and nums[left] == nums[left-1]:
                    left += 1
                while left < right and nums[right] == nums[right+1]:
                    right -= 1
    return result

if __name__ == "__main__":

    # 测试用例
    print(three_sum([-1, 0, 1, 2, -1, -4]))
    # 预期: [[-1, -1, 2], [-1, 0, 1]]
    print(three_sum([0, 1, 1]))       # 预期: []
    print(three_sum([0, 0, 0]))       # 预期: [[0, 0, 0]]

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    for (int i = 0; i < nums.size() - 2; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            int s = nums[i] + nums[left] + nums[right];
            if (s < 0) left++;
            else if (s > 0) right--;
            else {
                result.push_back({nums[i], nums[left], nums[right]});
                left++; right--;
                while (left < right && nums[left] == nums[left-1]) left++;
                while (left < right && nums[right] == nums[right+1]) right--;
            }
        }
    }
    return result;
}

int main() {
    // 测试用例
    vector<int> t1 = {-1, 0, 1, 2, -1, -4};
    auto r1 = threeSum(t1);
    for (auto& row : r1) { for (int x : row) cout << x << " "; cout << endl; }
    // 预期: -1 -1 2 | -1 0 1
    vector<int> t2 = {0, 0, 0};
    auto r2 = threeSum(t2);
    for (int x : r2[0]) cout << x << " "; cout << endl;  // 预期: 0 0 0
    return 0;
}
```

**算法详解**:
- 先排序，固定 i，双指针找两数之和为 -nums[i]
- 去重：跳过相同元素
- 时间复杂度 O(n²)，空间复杂度 O(1)

---

### 75. 颜色分类 (Sort Colors)

**Python 实现**:
```python
def sort_colors(nums: list[int]) -> None:
    left, cur, right = 0, 0, len(nums) - 1
    while cur <= right:
        if nums[cur] == 0:
            nums[left], nums[cur] = nums[cur], nums[left]
            left += 1
            cur += 1
        elif nums[cur] == 2:
            nums[cur], nums[right] = nums[right], nums[cur]
            right -= 1
        else:
            cur += 1

if __name__ == "__main__":

    # 测试用例
    nums1 = [2, 0, 2, 1, 1, 0]
    sort_colors(nums1); print(nums1)  # 预期: [0, 0, 1, 1, 2, 2]
    nums2 = [2, 0, 1]
    sort_colors(nums2); print(nums2)  # 预期: [0, 1, 2]

```

**C++ 实现**:
```cpp
#include <iostream>
#include <vector>

void sortColors(vector<int>& nums) {
    int left = 0, cur = 0, right = nums.size() - 1;
    while (cur <= right) {
        if (nums[cur] == 0) {
            swap(nums[left++], nums[cur++]);
        } else if (nums[cur] == 2) {
            swap(nums[cur], nums[right--]);
        } else {
            cur++;
        }
    }
}
int main() {
    // 测试用例
    vector<int> sc1 = {2, 0, 2, 1, 1, 0};
    sortColors(sc1);
    for (int x : sc1) cout << x << " "; cout << endl;  // 预期: 0 0 1 1 2 2
    vector<int> sc2 = {2, 0, 1};
    sortColors(sc2);
    for (int x : sc2) cout << x << " "; cout << endl;  // 预期: 0 1 2
    return 0;
}

```

**算法详解**:
- 荷兰国旗三路指针
- left 左侧全是 0，right 右侧全是 2
- cur 遍历，遇到 0/2 就交换

---

## 三、滑动窗口（Sliding Window）

### 3. 无重复字符的最长子串 (Longest Substring Without Repeating Characters)

**Python 实现**:
```python
def length_of_longest_substring(s: str) -> int:
    char_index = {}
    left = 0
    max_len = 0
    for right, ch in enumerate(s):
        if ch in char_index and char_index[ch] >= left:
            left = char_index[ch] + 1
        char_index[ch] = right
        max_len = max(max_len, right - left + 1)
    return max_len

if __name__ == "__main__":

    # 测试用例
    print(length_of_longest_substring("abcabcbb"))  # 预期: 3
    print(length_of_longest_substring("bbbbb"))    # 预期: 1
    print(length_of_longest_substring(""))          # 预期: 0  # 边界: 空串

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> char_index;
    int left = 0, max_len = 0;
    for (int right = 0; right < s.size(); right++) {
        if (char_index.count(s[right]) && char_index[s[right]] >= left)
            left = char_index[s[right]] + 1;
        char_index[s[right]] = right;
        max_len = max(max_len, right - left + 1);
    }
    return max_len;
}
int main() {
    // 测试用例
    cout << lengthOfLongestSubstring("abcabcbb") << endl;  // 预期: 3
    cout << lengthOfLongestSubstring("bbbbb") << endl;    // 预期: 1
    cout << lengthOfLongestSubstring("") << endl;          // 预期: 0
    return 0;
}

```

**算法详解**:
- 哈希表记录字符最近出现位置
- 当遇到重复字符时，left 收缩到上次出现位置之后
- 时间复杂度 O(n)，空间复杂度 O(min(m, n))

---

### 76. 最小覆盖子串 (Minimum Window Substring)

**Python 实现**:
```python
from collections import Counter

def min_window(s: str, t: str) -> str:
    need = Counter(t)
    window = Counter()
    left = 0
    valid = 0
    start = 0
    min_len = float('inf')
    
    for right, ch in enumerate(s):
        if ch in need:
            window[ch] += 1
            if window[ch] >= need[ch]:
                valid += 1
        
        while valid == len(need):
            if right - left + 1 < min_len:
                start = left
                min_len = right - left + 1
            if s[left] in need:
                if window[s[left]] <= need[s[left]]:
                    valid -= 1
                window[s[left]] -= 1
            left += 1
    return s[start:start+min_len] if min_len != float('inf') else ""

if __name__ == "__main__":

    # 测试用例
    result = min_window("abcabcbb", "abc")
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>

string minWindow(string s, string t) {
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;
    int left = 0, valid = 0, start = 0, min_len = INT_MAX;
    for (int right = 0; right < s.size(); right++) {
        char c = s[right];
        if (need.count(c)) {
            window[c]++;
            if (window[c] >= need[c]) valid++;
        }
        while (valid == need.size()) {
            if (right - left + 1 < min_len) {
                start = left;
                min_len = right - left + 1;
            }
            char d = s[left];
            if (need.count(d)) {
                if (window[d] <= need[d]) valid--;
                window[d]--;
            }
            left++;
        }
    }
    return min_len == INT_MAX ? "" : s.substr(start, min_len);
}
int main() {
    // 测试用例
    cout << minWindow({"abc"}, {"abc"}) << endl;
    return 0;
}

```

---

### 239. 滑动窗口最大值 (Sliding Window Maximum)

**Python 实现**:
```python
from collections import deque

def max_sliding_window(nums: list[int], k: int) -> list[int]:
    deque_indices = deque()
    result = []
    
    for i in range(len(nums)):
        while deque_indices and nums[deque_indices[-1]] <= nums[i]:
            deque_indices.pop()
        deque_indices.append(i)
        
        if deque_indices[0] <= i - k:
            deque_indices.popleft()
            
        if i >= k - 1:
            result.append(nums[deque_indices[0]])
    return result

if __name__ == "__main__":

    # 测试用例
    result = max_sliding_window([1, 2, 3], 2)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <deque>
#include <queue>
#include <vector>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();
        dq.push_back(i);
        if (dq.front() <= i - k)
            dq.pop_front();
        if (i >= k - 1)
            result.push_back(nums[dq.front()]);
    }
    return result;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 单调递减 deque，存储索引
- 队首始终是当前窗口最大值的索引
- 时间复杂度 O(n)，空间复杂度 O(k)

---

## 四、链表（Linked List）

### 2. 两数相加 (Add Two Numbers)

**Python 实现**:
```python
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def add_two_numbers(l1: ListNode, l2: ListNode) -> ListNode:
    dummy = ListNode()
    cur = dummy
    carry = 0
    while l1 or l2 or carry:
        val1 = l1.val if l1 else 0
        val2 = l2.val if l2 else 0
        total = val1 + val2 + carry
        carry = total // 10
        cur.next = ListNode(total % 10)
        cur = cur.next
        l1 = l1.next if l1 else None
        l2 = l2.next if l2 else None
    return dummy.next

if __name__ == "__main__":

    # 测试用例
    result = __init__(None, None, None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <list>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode();
    ListNode* cur = dummy;
    int carry = 0;
    while (l1 || l2 || carry) {
        int val1 = l1 ? l1->val : 0;
        int val2 = l2 ? l2->val : 0;
        int total = val1 + val2 + carry;
        carry = total / 10;
        cur->next = new ListNode(total % 10);
        cur = cur->next;
        l1 = l1 ? l1->next : nullptr;
        l2 = l2 ? l2->next : nullptr;
    }
    return dummy->next;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 迭代逐位相加，维护进位
- 创建新链表存储结果
- 时间复杂度 O(max(m, n))

---

### 21. 合并两个有序链表 (Merge Two Sorted Lists)

**Python 实现**:
```python
def merge_two_lists(l1: ListNode, l2: ListNode) -> ListNode:
    dummy = ListNode()
    cur = dummy
    while l1 and l2:
        if l1.val <= l2.val:
            cur.next = l1
            l1 = l1.next
        else:
            cur.next = l2
            l2 = l2.next
        cur = cur.next
    cur.next = l1 or l2
    return dummy.next

if __name__ == "__main__":

    # 测试用例
    result = merge_two_lists(None, None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <list>
using namespace std;
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode();
    ListNode* cur = dummy;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            cur->next = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    cur->next = l1 ? l1 : l2;
    return dummy->next;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

---

### 23. 合并K个升序链表 (Merge K Sorted Lists)

**Python 实现**:
```python
import heapq

def merge_k_lists(lists: list[ListNode]) -> ListNode:
    heap = []
    for i, l in enumerate(lists):
        if l:
            heapq.heappush(heap, (l.val, i, l))
    
    dummy = ListNode()
    cur = dummy
    while heap:
        val, i, node = heapq.heappop(heap)
        cur.next = node
        cur = cur.next
        if node.next:
            heapq.heappush(heap, (node.next.val, i, node.next))
    return dummy.next

if __name__ == "__main__":

    # 测试用例
    result = merge_k_lists(None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <deque>
#include <list>
#include <queue>
#include <vector>
using namespace std;
ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
    for (int i = 0; i < lists.size(); i++)
        if (lists[i]) pq.push({lists[i]->val, lists[i]});
    
    ListNode* dummy = new ListNode();
    ListNode* cur = dummy;
    while (!pq.empty()) {
        auto [val, node] = pq.top(); pq.pop();
        cur->next = node;
        cur = cur->next;
        if (node->next) pq.push({node->next->val, node->next});
    }
    return dummy->next;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 最小堆维护所有链表头的最小值
- 每次弹出最小节点，将其下一个节点入堆
- 时间复杂度 O(N log k)，k 为链表数

---

### 141. 环形链表 (Linked List Cycle)

**Python 实现**:
```python
def has_cycle(head: ListNode) -> bool:
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            return True
    return False

if __name__ == "__main__":

    # 测试用例
    result = has_cycle(None  # ListNode placeholder)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <list>

bool hasCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}
int main() {
    // 测试用例
    cout << hasCycle(nullptr) << endl;
    return 0;
}

```

**算法详解**:
- Floyd 判圈法：快慢指针相遇则有环
- 时间复杂度 O(n)，空间复杂度 O(1)

---

### 142. 环形链表 II (Linked List Cycle II)

**Python 实现**:
```python
def detect_cycle(head: ListNode) -> ListNode:
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            ptr = head
            while ptr != slow:
                ptr = ptr.next
                slow = slow.next
            return ptr
    return None

if __name__ == "__main__":

    # 测试用例
    result = detect_cycle(None  # ListNode placeholder)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <list>
using namespace std;
ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            ListNode *ptr = head;
            while (ptr != slow) {
                ptr = ptr->next;
                slow = slow->next;
            }
            return ptr;
        }
    }
    return nullptr;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

---

### 160. 相交链表 (Intersection of Two Linked Lists)

**Python 实现**:
```python
def get_intersection_node(headA: ListNode, headB: ListNode) -> ListNode:
    if not headA or not headB:
        return None
    pa, pb = headA, headB
    while pa != pb:
        pa = pa.next if pa else headB
        pb = pb.next if pb else headA
    return pa

if __name__ == "__main__":

    # 测试用例
    result = get_intersection_node(None, None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <list>
using namespace std;
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) return nullptr;
    ListNode *pa = headA, *pb = headB;
    while (pa != pb) {
        pa = pa ? pa->next : headB;
        pb = pb ? pb->next : headA;
    }
    return pa;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 双指针切换法：走完各自切换到另一链表必相遇
- 时间复杂度 O(m + n)，空间复杂度 O(1)

---

### 206. 反转链表 (Reverse Linked List)

**Python 实现**:
```python
def reverse_list(head: ListNode) -> ListNode:
    prev = None
    cur = head
    while cur:
        next_tmp = cur.next
        cur.next = prev
        prev = cur
        cur = next_tmp
    return prev

if __name__ == "__main__":

    # 测试用例
    result = reverse_list(None  # ListNode placeholder)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <list>
using namespace std;
ListNode* reverseList(ListNode* head) {
    ListNode *prev = nullptr, *cur = head;
    while (cur) {
        ListNode* next_tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next_tmp;
    }
    return prev;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 头插法：prev=None，逐节点头插
- 时间复杂度 O(n)，空间复杂度 O(1)

---

### 234. 回文链表 (Palindrome Linked List)

**Python 实现**:
```python
def is_palindrome(head: ListNode) -> bool:
    if not head or not head.next:
        return True
    slow = fast = head
    while fast.next and fast.next.next:
        slow = slow.next
        fast = fast.next.next
    
    prev = None
    cur = slow.next
    while cur:
        next_tmp = cur.next
        cur.next = prev
        prev = cur
        cur = next_tmp
    
    left, right = head, prev
    while right:
        if left.val != right.val:
            return False
        left = left.next
        right = right.next
    return True

if __name__ == "__main__":

    # 测试用例
    result = is_palindrome(None  # ListNode placeholder)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <list>

bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;
    ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *prev = nullptr, *cur = slow->next;
    while (cur) {
        ListNode* next_tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next_tmp;
    }
    while (prev) {
        if (head->val != prev->val) return false;
        head = head->next;
        prev = prev->next;
    }
    return true;
}
int main() {
    // 测试用例
    cout << isPalindrome(nullptr) << endl;
    return 0;
}

```

---

### 19. 删除链表的倒数第N个节点 (Remove Nth Node From End of List)

**Python 实现**:
```python
def remove_nth_from_end(head: ListNode, n: int) -> ListNode:
    dummy = ListNode()
    dummy.next = head
    fast = slow = dummy
    for _ in range(n + 1):
        fast = fast.next
    while fast:
        fast = fast.next
        slow = slow.next
    slow.next = slow.next.next
    return dummy.next

if __name__ == "__main__":

    # 测试用例
    result = remove_nth_from_end(None  # ListNode placeholder, 3)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <list>
using namespace std;
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode();
    dummy->next = head;
    ListNode *fast = dummy, *slow = dummy;
    for (int i = 0; i <= n; i++) fast = fast->next;
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return dummy->next;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

---

## 五、栈与队列（Stack & Queue）

### 20. 有效的括号 (Valid Parentheses)

**Python 实现**:
```python
def is_valid(s: str) -> bool:
    stack = []
    mapping = {')': '(', '}': '{', ']': '['}
    for ch in s:
        if ch in mapping:
            top = stack.pop() if stack else '#'
            if mapping[ch] != top:
                return False
        else:
            stack.append(ch)
    return not stack

if __name__ == "__main__":

    # 测试用例
    result = is_valid("abcabcbb")
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>

bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> mapping = {{')','('}, {'}','{'}, {']','['}};
    for (char c : s) {
        if (mapping.count(c)) {
            char top = st.empty() ? '#' : st.top();
            if (mapping[c] != top) return false;
            if (!st.empty()) st.pop();
        } else {
            st.push(c);
        }
    }
    return st.empty();
}
int main() {
    // 测试用例
    cout << isValid({"abc"}) << endl;
    return 0;
}

```

**算法详解**:
- 栈匹配：左括号入栈，右括号匹配弹出
- 时间复杂度 O(n)，空间复杂度 O(n)

---

### 155. 最小栈 (Min Stack)

**Python 实现**:
```python
class MinStack:
    def __init__(self):
        self.stack = []
        self.min_stack = []
    
    def push(self, val: int) -> None:
        self.stack.append(val)
        if not self.min_stack or val <= self.min_stack[-1]:
            self.min_stack.append(val)
    
    def pop(self) -> None:
        if self.stack.pop() == self.min_stack[-1]:
            self.min_stack.pop()
    
    def top(self) -> int:
        return self.stack[-1]
    
    def getMin(self) -> int:
        return self.min_stack[-1]

if __name__ == "__main__":

    # 测试用例
    result = __init__(None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <stack>
using namespace std;
class MinStack {
public:
    stack<int> st, minSt;
    void push(int val) {
        st.push(val);
        if (minSt.empty() || val <= minSt.top()) minSt.push(val);
    }
    void pop() {
        if (st.top() == minSt.top()) minSt.pop();
        st.pop();
    }
    int top() { return st.top(); }
    int getMin() { return minSt.top(); }
};

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

---

### 150. 逆波兰表达式求值 (Evaluate Reverse Polish Notation)

**Python 实现**:
```python
def eval_rpn(tokens: list[str]) -> int:
    stack = []
    for t in tokens:
        if t == '+':
            stack.append(stack.pop() + stack.pop())
        elif t == '-':
            b, a = stack.pop(), stack.pop()
            stack.append(a - b)
        elif t == '*':
            stack.append(stack.pop() * stack.pop())
        elif t == '/':
            b, a = stack.pop(), stack.pop()
            stack.append(int(a / b))
        else:
            stack.append(int(t))
    return stack[0]

if __name__ == "__main__":

    # 测试用例
    result = eval_rpn(None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <stack>
#include <string>
#include <vector>

int evalRPN(vector<string>& tokens) {
    stack<long long> st;
    for (string& t : tokens) {
        if (t == "+" || t == "-" || t == "*" || t == "/") {
            long long b = st.top(); st.pop();
            long long a = st.top(); st.pop();
            if (t == "+") st.push(a + b);
            else if (t == "-") st.push(a - b);
            else if (t == "*") st.push(a * b);
            else st.push(a / b);
        } else {
            st.push(stoll(t));
        }
    }
    return st.top();
}
int main() {
    // 测试用例
    cout << evalRPN(0) << endl;
    return 0;
}

```

---

### 84. 柱状图中最大的矩形 (Largest Rectangle in Histogram)

**Python 实现**:
```python
def largest_rectangle_area(heights: list[int]) -> int:
    stack = []
    max_area = 0
    for i, h in enumerate(heights + [0]):
        while stack and heights[stack[-1]] > h:
            height = heights[stack.pop()]
            width = i if not stack else i - stack[-1] - 1
            max_area = max(max_area, height * width)
        stack.append(i)
    return max_area

if __name__ == "__main__":

    # 测试用例
    result = largest_rectangle_area([1, 8, 6, 2, 5, 4, 8, 3, 7])
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int max_area = 0;
    vector<int> h = heights;
    h.push_back(0);
    for (int i = 0; i < h.size(); i++) {
        while (!st.empty() && h[st.top()] > h[i]) {
            int height = h[st.top()]; st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            max_area = max(max_area, height * width);
        }
        st.push(i);
    }
    return max_area;
}
int main() {
    // 测试用例
    cout << largestRectangleArea({1, 2, 3}) << endl;
    return 0;
}

```

**算法详解**:
- 单调递增栈，存储索引
- 遇到更小的柱子时弹出，计算以弹出高度为高的矩形
- 末尾加 0 确保所有柱子弹出
- 时间复杂度 O(n)，空间复杂度 O(n)

---

## 六、二分查找（Binary Search）

### 33. 搜索旋转排序数组 (Search in Rotated Sorted Array)

**Python 实现**:
```python
def search(nums: list[int], target: int) -> int:
    left, right = 0, len(nums) - 1
    while left <= right:
        mid = (left + right) // 2
        if nums[mid] == target:
            return mid
        if nums[left] <= nums[mid]:
            if nums[left] <= target < nums[mid]:
                right = mid - 1
            else:
                left = mid + 1
        else:
            if nums[mid] < target <= nums[right]:
                left = mid + 1
            else:
                right = mid - 1
    return -1

if __name__ == "__main__":

    # 测试用例
    result = search([1, 2, 3], 9)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <vector>

int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        } else {
            if (nums[mid] < target && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}
int main() {
    // 测试用例
    cout << search({1, 2, 3}, 9) << endl;
    return 0;
}

```

**算法详解**:
- 二分查找，先判断哪半边有序
- 根据有序的一边判断 target 是否在有序半边
- 时间复杂度 O(log n)，空间复杂度 O(1)

---

### 34. 在排序数组中查找元素的第一个和最后一个位置

**Python 实现**:
```python
def search_range(nums: list[int], target: int) -> list[int]:
    def find_bound(nums, target, find_first):
        left, right = 0, len(nums) - 1
        bound = -1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                bound = mid
                if find_first:
                    right = mid - 1
                else:
                    left = mid + 1
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return bound
    return [find_bound(nums, target, True), find_bound(nums, target, False)]

if __name__ == "__main__":

    # 测试用例
    result = search_range([1, 2, 3], 9)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <vector>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target) {
    auto find_bound = [&](bool find_first) {
        int left = 0, right = nums.size() - 1, bound = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                bound = mid;
                if (find_first) right = mid - 1;
                else left = mid + 1;
            } else if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return bound;
    };
    return {find_bound(true), find_bound(false)};
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

---

## 七、动态规划（Dynamic Programming）

### 53. 最大子数组和 (Maximum Subarray)

**Python 实现**:
```python
def max_sub_array(nums: list[int]) -> int:
    cur_sum = max_sum = nums[0]
    for num in nums[1:]:
        cur_sum = max(num, cur_sum + num)
        max_sum = max(max_sum, cur_sum)
    return max_sum

if __name__ == "__main__":

    # 测试用例
    result = max_sub_array([1, 2, 3])
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int maxSubArray(vector<int>& nums) {
    int cur_sum = nums[0], max_sum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        cur_sum = max(nums[i], cur_sum + nums[i]);
        max_sum = max(max_sum, cur_sum);
    }
    return max_sum;
}
int main() {
    // 测试用例
    cout << maxSubArray({1, 2, 3}) << endl;
    return 0;
}

```

**算法详解**:
- 贪心：cur_sum < 0 则重置
- 也可用分治法
- 时间复杂度 O(n)，空间复杂度 O(1)

---

### 70. 爬楼梯 (Climbing Stairs)

**Python 实现**:
```python
def climb_stairs(n: int) -> int:
    if n <= 2:
        return n
    dp = [0] * (n + 1)
    dp[1], dp[2] = 1, 2
    for i in range(3, n + 1):
        dp[i] = dp[i-1] + dp[i-2]
    return dp[n]

if __name__ == "__main__":

    # 测试用例
    result = climb_stairs(3)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <vector>

int climbStairs(int n) {
    if (n <= 2) return n;
    vector<int> dp(n + 1);
    dp[1] = 1; dp[2] = 2;
    for (int i = 3; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}
int main() {
    // 测试用例
    cout << climbStairs(9) << endl;
    return 0;
}

```

**算法详解**:
- 完全背包变体：每步可爬 1 或 2 格
- dp[i] = dp[i-1] + dp[i-2]
- 时间复杂度 O(n)，空间复杂度 O(n)（可优化至 O(1)）

---

### 198. 打家劫舍 (House Robber)

**Python 实现**:
```python
def rob(nums: list[int]) -> int:
    if not nums:
        return 0
    if len(nums) == 1:
        return nums[0]
    dp = [0] * len(nums)
    dp[0] = nums[0]
    dp[1] = max(nums[0], nums[1])
    for i in range(2, len(nums)):
        dp[i] = max(dp[i-1], dp[i-2] + nums[i])
    return dp[-1]

if __name__ == "__main__":

    # 测试用例
    result = rob([1, 2, 3])
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int rob(vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];
    int prev2 = nums[0], prev1 = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); i++) {
        int cur = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}
int main() {
    // 测试用例
    cout << rob({1, 2, 3}) << endl;
    return 0;
}

```

**算法详解**:
- 状态：dp[i] = 前 i 家能偷的最大金额
- 转移：dp[i] = max(dp[i-1], dp[i-2] + nums[i])
- 空间优化：只保留前两家
- 时间复杂度 O(n)，空间复杂度 O(1)

---

### 213. 打家劫舍 II (House Robber II)

**Python 实现**:
```python
def rob(nums: list[int]) -> int:
    if not nums:
        return 0
    if len(nums) == 1:
        return nums[0]
    
    def rob_range(nums: list[int]) -> int:
        prev2, prev1 = 0, 0
        for num in nums:
            cur = max(prev1, prev2 + num)
            prev2 = prev1
            prev1 = cur
        return prev1
    
    return max(rob_range(nums[:-1]), rob_range(nums[1:]))

if __name__ == "__main__":

    # 测试用例
    result = rob([1, 2, 3])
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int rob(vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];
    auto robRange = [&](int l, int r) {
        int prev2 = 0, prev1 = 0;
        for (int i = l; i <= r; i++) {
            int cur = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    };
    return max(robRange(0, nums.size()-2), robRange(1, nums.size()-1));
}
int main() {
    // 测试用例
    cout << rob({1, 2, 3}) << endl;
    return 0;
}

```

**算法详解**:
- 环形约束：首尾不能同时偷，分两种情况讨论
- 情况1：不偷最后一家 → 偷 [0, n-2]
- 情况2：不偷第一家 → 偷 [1, n-1]
- 时间复杂度 O(n)，空间复杂度 O(1)

---

### 300. 最长递增子序列 (Longest Increasing Subsequence)

**Python 实现**:
```python
import bisect

def length_of_lis(nums: list[int]) -> int:
    dp = []
    for num in nums:
        idx = bisect.bisect_left(dp, num)
        if idx == len(dp):
            dp.append(num)
        else:
            dp[idx] = num
    return len(dp)

if __name__ == "__main__":

    # 测试用例
    result = length_of_lis([1, 2, 3])
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <vector>

int lengthOfLIS(vector<int>& nums) {
    vector<int> dp;
    for (int num : nums) {
        auto it = lower_bound(dp.begin(), dp.end(), num);
        if (it == dp.end()) dp.push_back(num);
        else *it = num;
    }
    return dp.size();
}
int main() {
    // 测试用例
    cout << lengthOfLIS({1, 2, 3}) << endl;
    return 0;
}

```

**算法详解**:
- 贪心 + 二分：维护一个递增序列 dp
- 对于每个数，在 dp 中找第一个 >= num 的位置替换（lower_bound）
- 若都小于 num 则追加
- dp 长度即为 LIS 长度
- 时间复杂度 O(n log n)，空间复杂度 O(n)

---

### 1143. 最长公共子序列 (Longest Common Subsequence)

**Python 实现**:
```python
def longest_common_subsequence(text1: str, text2: str) -> int:
    m, n = len(text1), len(text2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if text1[i-1] == text2[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    return dp[m][n]

if __name__ == "__main__":

    # 测试用例
    result = longest_common_subsequence(None, None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i-1] == text2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}
int main() {
    // 测试用例
    cout << longestCommonSubsequence(0, 0) << endl;
    return 0;
}

```

**算法详解**:
- dp[i][j] = text1 前 i 个与 text2 前 j 个的 LCS 长度
- 字符相等：dp[i][j] = dp[i-1][j-1] + 1
- 不等：dp[i][j] = max(dp[i-1][j], dp[i][j-1])
- 空间可优化至 O(min(m,n))

---

### 72. 编辑距离 (Edit Distance)

**Python 实现**:
```python
def min_distance(word1: str, word2: str) -> int:
    m, n = len(word1), len(word2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    for i in range(m + 1):
        dp[i][0] = i
    for j in range(n + 1):
        dp[0][j] = j
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if word1[i-1] == word2[j-1]:
                dp[i][j] = dp[i-1][j-1]
            else:
                dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
    return dp[m][n]

if __name__ == "__main__":

    # 测试用例
    result = min_distance(None, None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
        }
    }
    return dp[m][n];
}
int main() {
    // 测试用例
    cout << minDistance(0, 0) << endl;
    return 0;
}

```

**算法详解**:
- dp[i][j] = 将 word1[0..i-1] 转为 word2[0..j-1] 的最少操作数
- 三种操作：插入、删除、替换（对应三个相邻格子 +1）
- 字符相同则直接继承
- 时间复杂度 O(mn)，空间可优化至 O(n)

---

### 322. 零钱兑换 (Coin Change)

**Python 实现**:
```python
def coin_change(coins: list[int], amount: int) -> int:
    dp = [float('inf')] * (amount + 1)
    dp[0] = 0
    for coin in coins:
        for a in range(coin, amount + 1):
            dp[a] = min(dp[a], dp[a - coin] + 1)
    return dp[amount] if dp[amount] != float('inf') else -1

if __name__ == "__main__":

    # 测试用例
    result = coin_change(None, 11)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int coin : coins) {
        for (int a = coin; a <= amount; a++) {
            if (dp[a-coin] != INT_MAX)
                dp[a] = min(dp[a], dp[a-coin] + 1);
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}
int main() {
    // 测试用例
    cout << coinChange(0, 9) << endl;
    return 0;
}

```

**算法详解**:
- 完全背包：每种硬币无限使用
- dp[a] = 凑成金额 a 的最少硬币数
- dp[a] = min(dp[a], dp[a-coin] + 1)
- 时间复杂度 O(amount * len(coins))，空间复杂度 O(amount)

---

### 416. 分割等和子集 (Partition Equal Subset Sum)

**Python 实现**:
```python
def can_partition(nums: list[int]) -> bool:
    total = sum(nums)
    if total % 2:
        return False
    target = total // 2
    dp = [False] * (target + 1)
    dp[0] = True
    for num in nums:
        for a in range(target, num - 1, -1):
            dp[a] = dp[a] or dp[a - num]
    return dp[target]

if __name__ == "__main__":

    # 测试用例
    result = can_partition([1, 2, 3])
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <vector>

bool canPartition(vector<int>& nums) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    if (total % 2) return false;
    int target = total / 2;
    vector<char> dp(target + 1, 0);
    dp[0] = 1;
    for (int num : nums) {
        for (int a = target; a >= num; a--)
            dp[a] = dp[a] || dp[a-num];
    }
    return dp[target];
}
int main() {
    // 测试用例
    cout << canPartition({1, 2, 3}) << endl;
    return 0;
}

```

**算法详解**:
- 0-1 背包：能否选取若干数使和为 target
- dp[a] = 是否能凑成金额 a
- 逆序遍历避免重复使用同一元素
- 时间复杂度 O(n * target)，空间复杂度 O(target)

---

### 139. 单词拆分 (Word Break)

**Python 实现**:
```python
def word_break(s: str, word_dict: list[str]) -> bool:
    word_set = set(word_dict)
    n = len(s)
    dp = [False] * (n + 1)
    dp[0] = True
    for i in range(1, n + 1):
        for j in range(i):
            if dp[j] and s[j:i] in word_set:
                dp[i] = True
                break
    return dp[n]

if __name__ == "__main__":

    # 测试用例
    result = word_break("abcabcbb", None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    int n = s.size();
    vector<char> dp(n+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && wordSet.count(s.substr(j, i-j))) {
                dp[i] = 1;
                break;
            }
        }
    }
    return dp[n];
}
int main() {
    // 测试用例
    cout << wordBreak({"abc"}, 0) << endl;
    return 0;
}

```

**算法详解**:
- dp[i] = s[0..i) 能否被拆分
- 枚举所有前缀 j，检查 dp[j] && s[j:i] 在字典中
- 可用 BFS/队列优化至 O(n) 平均

---

### 91. 解码方法 (Decode Ways)

**Python 实现**:
```python
def num_decodings(s: str) -> int:
    if not s or s[0] == '0':
        return 0
    n = len(s)
    dp = [0] * (n + 1)
    dp[0] = 1
    dp[1] = 1
    for i in range(2, n + 1):
        if s[i-1] != '0':
            dp[i] += dp[i-1]
        two = int(s[i-2:i])
        if 10 <= two <= 26:
            dp[i] += dp[i-2]
    return dp[n]

if __name__ == "__main__":

    # 测试用例
    result = num_decodings("abcabcbb")
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <string>
#include <vector>

int numDecodings(string s) {
    if (s.empty() || s[0] == '0') return 0;
    int n = s.size();
    vector<int> dp(n+1, 0);
    dp[0] = 1; dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (s[i-1] != '0') dp[i] += dp[i-1];
        int two = stoi(s.substr(i-2, 2));
        if (10 <= two && two <= 26) dp[i] += dp[i-2];
    }
    return dp[n];
}
int main() {
    // 测试用例
    cout << numDecodings({"abc"}) << endl;
    return 0;
}

```

**算法详解**:
- dp[i] = s[0..i) 的解码方法数
- 单独解码：s[i-1] 非 '0'
- 两位解码：s[i-2:i] 在 [10, 26] 范围内
- 注意 '0' 不能单独解码，必须与前一位组合

---

### 62. 不同路径 (Unique Paths)

**Python 实现**:
```python
def unique_paths(m: int, n: int) -> int:
    dp = [1] * n
    for _ in range(1, m):
        for j in range(1, n):
            dp[j] += dp[j-1]
    return dp[n-1]

if __name__ == "__main__":

    # 测试用例
    result = unique_paths(None, 3)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <vector>

int uniquePaths(int m, int n) {
    vector<int> dp(n, 1);
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            dp[j] += dp[j-1];
    return dp[n-1];
}
int main() {
    // 测试用例
    cout << uniquePaths(0, 9) << endl;
    return 0;
}

```

**算法详解**:
- 组合数学：C(m+n-2, m-1) 或 C(m+n-2, n-1)
- DP：dp[i][j] = dp[i-1][j] + dp[i][j-1]
- 空间优化为一维数组（逐行更新）
- 时间复杂度 O(mn)，空间 O(n)

---

### 63. 不同路径 II (Unique Paths II)

**Python 实现**:
```python
def unique_paths_with_obstacles(obstacle_grid: list[list[int]]) -> int:
    m, n = len(obstacle_grid), len(obstacle_grid[0])
    dp = [0] * n
    dp[0] = 1
    for i in range(m):
        for j in range(n):
            if obstacle_grid[i][j] == 1:
                dp[j] = 0
            elif j > 0:
                dp[j] += dp[j-1]
    return dp[n-1]

if __name__ == "__main__":

    # 测试用例
    result = unique_paths_with_obstacles(None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <vector>

int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> dp(n, 0);
    dp[0] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) dp[j] = 0;
            else if (j > 0) dp[j] += dp[j-1];
        }
    }
    return dp[n-1];
}
int main() {
    // 测试用例
    cout << uniquePathsWithObstacles({{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}) << endl;
    return 0;
}

```

**算法详解**:
- 有障碍物时，遇到障碍格 dp[j] = 0
- 其余格子：dp[j] = dp[j]（上方）+ dp[j-1]（左方）
- 空间优化为一维

---

### 64. 最小路径和 (Minimum Path Sum)

**Python 实现**:
```python
def min_path_sum(grid: list[list[int]]) -> int:
    m, n = len(grid), len(grid[0])
    for i in range(m):
        for j in range(n):
            if i == 0 and j == 0:
                continue
            grid[i][j] += min(
                grid[i-1][j] if i > 0 else float('inf'),
                grid[i][j-1] if j > 0 else float('inf')
            )
    return grid[m-1][n-1]

if __name__ == "__main__":

    # 测试用例
    result = min_path_sum([[1, 3, 1], [1, 5, 1], [4, 2, 1]])
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) { dp[j] = grid[i][j]; continue; }
            dp[j] = grid[i][j] + min(dp[j], dp[j-1]);
        }
    }
    return dp[n-1];
}
int main() {
    // 测试用例
    cout << minPathSum({{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}) << endl;
    return 0;
}

```

**算法详解**:
- dp[i][j] = 到达 (i,j) 的最小路径和
- 只能从上方或左方来
- 原地修改或空间优化
- 时间复杂度 O(mn)，空间 O(n)

---

### 152. 乘积最大子数组 (Maximum Product Subarray)

**Python 实现**:
```python
def max_product(nums: list[int]) -> int:
    max_prod = min_prod = result = nums[0]
    for num in nums[1:]:
        if num < 0:
            max_prod, min_prod = min_prod, max_prod
        max_prod = max(num, max_prod * num)
        min_prod = min(num, min_prod * num)
        result = max(result, max_prod)
    return result

if __name__ == "__main__":

    # 测试用例
    result = max_product([1, 2, 3])
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int maxProduct(vector<int>& nums) {
    int max_prod = nums[0], min_prod = nums[0], result = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0) swap(max_prod, min_prod);
        max_prod = max(nums[i], max_prod * nums[i]);
        min_prod = min(nums[i], min_prod * nums[i]);
        result = max(result, max_prod);
    }
    return result;
}
int main() {
    // 测试用例
    cout << maxProduct({1, 2, 3}) << endl;
    return 0;
}

```

**算法详解**:
- 必须同时维护最大和最小乘积（因为负数会翻转）
- 遇到负数交换 max_prod 和 min_prod
- 状态转移：max_prod = max(num, max_prod*num)
- 时间复杂度 O(n)，空间 O(1)

---

### 123. 买卖股票的最佳时机 III (Best Time to Buy and Sell Stock III)

**Python 实现**:
```python
def max_profit(prices: list[int]) -> int:
    if not prices:
        return 0
    n = len(prices)
    buy1 = sell1 = -prices[0]
    buy2 = sell2 = -prices[0]
    for i in range(1, n):
        buy1 = max(buy1, -prices[i])
        sell1 = max(sell1, buy1 + prices[i])
        buy2 = max(buy2, sell1 - prices[i])
        sell2 = max(sell2, buy2 + prices[i])
    return sell2

if __name__ == "__main__":

    # 测试用例
    result = max_profit([7, 1, 5, 3, 6, 4])
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;
    int buy1 = -prices[0], sell1 = 0;
    int buy2 = -prices[0], sell2 = 0;
    for (int i = 1; i < prices.size(); i++) {
        buy1 = max(buy1, -prices[i]);
        sell1 = max(sell1, buy1 + prices[i]);
        buy2 = max(buy2, sell1 - prices[i]);
        sell2 = max(sell2, buy2 + prices[i]);
    }
    return sell2;
}
int main() {
    // 测试用例
    cout << maxProfit({1, 2, 3}) << endl;
    return 0;
}

```

**算法详解**:
- 最多两笔交易，状态机 DP
- buy1: 第一次买入后最大现金
- sell1: 第一次卖出后最大现金
- buy2: 第二次买入后最大现金
- sell2: 第二次卖出后最大现金
- 时间复杂度 O(n)，空间 O(1)

---

### 309. 最佳买卖股票时机含冷冻期 (Best Time to Buy and Sell Stock with Cooldown)

**Python 实现**:
```python
def max_profit(prices: list[int]) -> int:
    if not prices:
        return 0
    n = len(prices)
    dp = [[0] * 3 for _ in range(n)]
    dp[0][0] = -prices[0]  # 持有
    dp[0][1] = 0           # 不持有，且不在冷冻期
    dp[0][2] = 0           # 不持有，且在冷冻期
    for i in range(1, n):
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i])
        dp[i][1] = max(dp[i-1][1], dp[i-1][2])
        dp[i][2] = dp[i-1][0] + prices[i]
    return max(dp[n-1][1], dp[n-1][2])

if __name__ == "__main__":

    # 测试用例
    result = max_profit([7, 1, 5, 3, 6, 4])
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(3, 0));
    dp[0][0] = -prices[0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][2]);
        dp[i][2] = dp[i-1][0] + prices[i];
    }
    return max(dp[n-1][1], dp[n-1][2]);
}
int main() {
    // 测试用例
    cout << maxProfit({1, 2, 3}) << endl;
    return 0;
}

```

**算法详解**:
- 三状态：持有、不持有且非冷冻、不持有且冷冻
- 冷冻期源于当天卖出后次日不能买
- 空间可优化至 O(1)

---

## 八、贪心（Greedy）

### 455. 分发饼干 (Assign Cookies)

**Python 实现**:
```python
def find_content_children(g: list[int], s: list[int]) -> int:
    g.sort()
    s.sort()
    i = j = 0
    while i < len(g) and j < len(s):
        if s[j] >= g[i]:
            i += 1
        j += 1
    return i

if __name__ == "__main__":

    # 测试用例
    result = find_content_children(None, "abcabcbb")
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = 0, j = 0;
    while (i < g.size() && j < s.size()) {
        if (s[j] >= g[i]) i++;
        j++;
    }
    return i;
}
int main() {
    // 测试用例
    cout << findContentChildren(0, {"abc"}) << endl;
    return 0;
}

```

**算法详解**:
- 胃口 g 和饼干尺寸 s 分别排序
- 双指针：用尽量小的饼干满足胃口
- 时间复杂度 O(n log n)，空间 O(1)

---

### 435. 无重叠区间 (Non-overlapping Intervals)

**Python 实现**:
```python
def erase_overlap_intervals(intervals: list[list[int]]) -> int:
    if not intervals:
        return 0
    intervals.sort(key=lambda x: x[1])
    count = 0
    end = intervals[0][1]
    for i in range(1, len(intervals)):
        if intervals[i][0] < end:
            count += 1
        else:
            end = intervals[i][1]
    return count

if __name__ == "__main__":

    # 测试用例
    result = erase_overlap_intervals([[1, 3], [2, 6], [8, 10], [15, 18]])
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;
    sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){ return a[1] < b[1]; });
    int count = 0, end = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] < end) count++;
        else end = intervals[i][1];
    }
    return count;
}
int main() {
    // 测试用例
    cout << eraseOverlapIntervals({{1, 3}, {2, 6}, {8, 10}, {15, 18}}) << endl;
    return 0;
}

```

**算法详解**:
- 按右端点排序，选择结束最早的区间
- 贪心选择与上一选中区间不重叠的
- 删除的最少区间 = 总数 - 最大不重叠数

---

### 452. 用最少数量的箭引爆气球 (Minimum Number of Arrows to Burst Balloons)

**Python 实现**:
```python
def find_min_arrow_shots(points: list[list[int]]) -> int:
    if not points:
        return 0
    points.sort(key=lambda x: x[1])
    arrows = 1
    end = points[0][1]
    for i in range(1, len(points)):
        if points[i][0] > end:
            arrows += 1
            end = points[i][1]
    return arrows

if __name__ == "__main__":

    # 测试用例
    result = find_min_arrow_shots(None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int findMinArrowShots(vector<vector<int>>& points) {
    if (points.empty()) return 0;
    sort(points.begin(), points.end(), [](auto& a, auto& b){ return a[1] < b[1]; });
    int arrows = 1, end = points[0][1];
    for (int i = 1; i < points.size(); i++) {
        if (points[i][0] > end) {
            arrows++;
            end = points[i][1];
        }
    }
    return arrows;
}
int main() {
    // 测试用例
    cout << findMinArrowShots(0) << endl;
    return 0;
}

```

**算法详解**:
- 按右端点排序，一箭射穿重叠区间
- 时间复杂度 O(n log n)

---

### 406. 根据身高重建队列 (Queue Reconstruction by Height)

**Python 实现**:
```python
def reconstruct_queue(people: list[list[int]]) -> list[list[int]]:
    people.sort(key=lambda x: (-x[0], x[1]))
    result = []
    for p in people:
        result.insert(p[1], p)
    return result

if __name__ == "__main__":

    # 测试用例
    result = reconstruct_queue(None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), [](auto& a, auto& b){
        return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
    });
    vector<vector<int>> result;
    for (auto& p : people)
        result.insert(result.begin() + p[1], p);
    return result;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 按身高降序，k（前面人数）升序排列
- 高个子先站位，k 值决定插入位置
- 低个子不影响高个子

---

### 56. 合并区间 (Merge Intervals)

**Python 实现**:
```python
def merge(intervals: list[list[int]]) -> list[list[int]]:
    if not intervals:
        return []
    intervals.sort()
    result = [intervals[0]]
    for start, end in intervals[1:]:
        if start <= result[-1][1]:
            result[-1][1] = max(result[-1][1], end)
        else:
            result.append([start, end])
    return result

if __name__ == "__main__":

    # 测试用例
    result = merge([[1, 3], [2, 6], [8, 10], [15, 18]])
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result = {intervals[0]};
    for (auto& interval : intervals) {
        if (interval[0] <= result.back()[1])
            result.back()[1] = max(result.back()[1], interval[1]);
        else
            result.push_back(interval);
    }
    return result;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 按起点排序，依次合并重叠区间
- 时间复杂度 O(n log n)，空间 O(n)

---

## 九、回溯（Backtracking）

### 78. 子集 (Subsets)

**Python 实现**:
```python
def subsets(nums: list[int]) -> list[list[int]]:
    result = []
    path = []
    def backtrack(start):
        result.append(path[:])
        for i in range(start, len(nums)):
            path.append(nums[i])
            backtrack(i + 1)
            path.pop()
    backtrack(0)
    return result

if __name__ == "__main__":

    # 测试用例
    result = subsets([1, 2, 3])
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> path;
    function<void(int)> backtrack = [&](int start) {
        result.push_back(path);
        for (int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtrack(i + 1);
            path.pop_back();
        }
    };
    backtrack(0);
    return result;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 每个元素选或不选，构成所有子集
- 时间复杂度 O(n * 2^n)，空间 O(n)

---

### 77. 组合 (Combinations)

**Python 实现**:
```python
def combine(n: int, k: int) -> list[list[int]]:
    result = []
    path = []
    def backtrack(start):
        if len(path) == k:
            result.append(path[:])
            return
        for i in range(start, n + 1):
            path.append(i)
            backtrack(i + 1)
            path.pop()
    backtrack(1)
    return result

if __name__ == "__main__":

    # 测试用例
    result = combine(3, 2)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> path;
    function<void(int)> backtrack = [&](int start) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = start; i <= n; i++) {
            path.push_back(i);
            backtrack(i + 1);
            path.pop_back();
        }
    };
    backtrack(1);
    return result;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

---

### 46. 全排列 (Permutations)

**Python 实现**:
```python
def permute(nums: list[int]) -> list[list[int]]:
    result = []
    used = [False] * len(nums)
    path = []
    def backtrack():
        if len(path) == len(nums):
            result.append(path[:])
            return
        for i in range(len(nums)):
            if not used[i]:
                used[i] = True
                path.append(nums[i])
                backtrack()
                path.pop()
                used[i] = False
    backtrack()
    return result

if __name__ == "__main__":

    # 测试用例
    result = permute([1, 2, 3])
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> path;
    vector<char> used(nums.size(), 0);
    function<void()> backtrack = [&]() {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                used[i] = 1;
                path.push_back(nums[i]);
                backtrack();
                path.pop_back();
                used[i] = 0;
            }
        }
    };
    backtrack();
    return result;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 全排列用 used 数组标记已使用
- 时间复杂度 O(n!)

---

### 47. 全排列 II (Permutations II)

**Python 实现**:
```python
def permute_unique(nums: list[int]) -> list[list[int]]:
    nums.sort()
    result = []
    used = [False] * len(nums)
    path = []
    def backtrack():
        if len(path) == len(nums):
            result.append(path[:])
            return
        for i in range(len(nums)):
            if used[i] or (i > 0 and nums[i] == nums[i-1] and not used[i-1]):
                continue
            used[i] = True
            path.append(nums[i])
            backtrack()
            path.pop()
            used[i] = False
    backtrack()
    return result

if __name__ == "__main__":

    # 测试用例
    result = permute_unique([1, 2, 3])
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> path;
    vector<char> used(nums.size(), 0);
    function<void()> backtrack = [&]() {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] || (i > 0 && nums[i] == nums[i-1] && !used[i-1])) continue;
            used[i] = 1;
            path.push_back(nums[i]);
            backtrack();
            path.pop_back();
            used[i] = 0;
        }
    };
    backtrack();
    return result;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 排序后，相邻相同元素只选第一个未使用的（避免重复排列）
- 时间复杂度 O(n!)

---

### 39. 组合总和 (Combination Sum)

**Python 实现**:
```python
def combination_sum(candidates: list[int], target: int) -> list[list[int]]:
    result = []
    path = []
    def backtrack(start, target):
        if target == 0:
            result.append(path[:])
            return
        for i in range(start, len(candidates)):
            if candidates[i] > target:
                continue
            path.append(candidates[i])
            backtrack(i, target - candidates[i])
            path.pop()
    backtrack(0, target)
    return
    return result

if __name__ == "__main__":

    # 测试用例
    result = combination_sum(None, 9)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> path;
    function<void(int, int)> backtrack = [&](int start, int target) {
        if (target == 0) {
            result.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target) continue;
            path.push_back(candidates[i]);
            backtrack(i, target - candidates[i]);
            path.pop_back();
        }
    };
    backtrack(0, target);
    return result;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 可重复选取元素（从 i 而非 i+1 开始）
- 时间复杂度 O(n * 2^n)，空间 O(n)

---

### 40. 组合总和 II (Combination Sum II)

**Python 实现**:
```python
def combination_sum2(candidates: list[int], target: int) -> list[list[int]]:
    candidates.sort()
    result = []
    path = []
    used = [False] * len(candidates)
    def backtrack(start, target):
        if target == 0:
            result.append(path[:])
            return
        for i in range(start, len(candidates)):
            if candidates[i] > target:
                continue
            if i > 0 and candidates[i] == candidates[i-1] and not used[i-1]:
                continue
            path.append(candidates[i])
            used[i] = True
            backtrack(i + 1, target - candidates[i])
            path.pop()
            used[i] = False
    backtrack(0, target)
    return result

if __name__ == "__main__":

    # 测试用例
    result = combination_sum2(None, 9)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> path;
    vector<char> used(candidates.size(), 0);
    function<void(int, int)> backtrack = [&](int start, int target) {
        if (target == 0) { result.push_back(path); return; }
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target) continue;
            if (i > 0 && candidates[i] == candidates[i-1] && !used[i-1]) continue;
            path.push_back(candidates[i]);
            used[i] = 1;
            backtrack(i + 1, target - candidates[i]);
            path.pop_back();
            used[i] = 0;
        }
    };
    backtrack(0, target);
    return result;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 元素不能重复，每个数只用一次
- 排序后跳过相同元素的重复使用

---

### 131. 分割回文串 (Palindrome Partitioning)

**Python 实现**:
```python
def partition(s: str) -> list[list[str]]:
    result = []
    path = []
    def is_palindrome(sub):
        return sub == sub[::-1]
    def backtrack(start):
        if start == len(s):
            result.append(path[:])
            return
        for i in range(start, len(s)):
            if is_palindrome(s[start:i+1]):
                path.append(s[start:i+1])
                backtrack(i + 1)
                path.pop()
    backtrack(0)
    return result

if __name__ == "__main__":

    # 测试用例
    result = partition("abcabcbb")
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> path;
    function<bool(int,int)> isPal = [&](int l, int r) {
        while (l < r) if (s[l++] != s[r--]) return false;
        return true;
    };
    function<void(int)> backtrack = [&](int start) {
        if (start == s.size()) { result.push_back(path); return; }
        for (int i = start; i < s.size(); i++) {
            if (isPal(start, i)) {
                path.push_back(s.substr(start, i-start+1));
                backtrack(i+1);
                path.pop_back();
            }
        }
    };
    backtrack(0);
    return result;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

---

### 93. 复原 IP 地址 (Restore IP Addresses)

**Python 实现**:
```python
def restore_ip_addresses(s: str) -> list[str]:
    result = []
    path = []
    def backtrack(start, parts):
        if parts == 4:
            if start == len(s):
                result.append('.'.join(path))
            return
        for i in range(start, min(start + 3, len(s))):
            if i > start and s[start] == '0':
                continue
            ip = s[start:i+1]
            if int(ip) <= 255:
                path.append(ip)
                backtrack(i + 1, parts + 1)
                path.pop()
    backtrack(0, 0)
    return result

if __name__ == "__main__":

    # 测试用例
    result = restore_ip_addresses("abcabcbb")
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    vector<string> path;
    function<void(int,int)> backtrack = [&](int start, int parts) {
        if (parts == 4) {
            if (start == s.size()) result.push_back(join(path));
            return;
        }
        for (int i = start; i < min(start+3, (int)s.size()); i++) {
            if (i > start && s[start] == '0') return;
            string ip = s.substr(start, i-start+1);
            if (stoi(ip) <= 255) {
                path.push_back(ip);
                backtrack(i+1, parts+1);
                path.pop_back();
            }
        }
    };
    backtrack(0, 0);
    return result;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 递归枚举每个段（最多3位），检查合法性
- 0-255，不能有前导零（长度>1时）

---

### 17. 电话号码的字母组合 (Letter Combinations of a Phone Number)

**Python 实现**:
```python
def letter_combinations(digits: str) -> list[str]:
    if not digits:
        return []
    mapping = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
    result = []
    path = []
    def backtrack(i):
        if i == len(digits):
            result.append(''.join(path))
            return
        for ch in mapping[int(digits[i])]:
            path.append(ch)
            backtrack(i + 1)
            path.pop()
    backtrack(0)
    return result

if __name__ == "__main__":

    # 测试用例
    result = letter_combinations(None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result;
    string path;
    function<void(int)> backtrack = [&](int i) {
        if (i == digits.size()) { result.push_back(path); return; }
        for (char ch : mapping[digits[i]-'0'])
            path.push_back(ch), backtrack(i+1), path.pop_back();
    };
    backtrack(0);
    return result;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

---

### 22. 括号生成 (Generate Parentheses)

**Python 实现**:
```python
def generate_parenthesis(n: int) -> list[str]:
    result = []
    path = []
    def backtrack(left, right):
        if len(path) == 2 * n:
            result.append(''.join(path))
            return
        if left < n:
            path.append('(')
            backtrack(left + 1, right)
            path.pop()
        if right < left:
            path.append(')')
            backtrack(left, right + 1)
            path.pop()
    backtrack(0, 0)
    return result

if __name__ == "__main__":

    # 测试用例
    result = generate_parenthesis(3)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> generateParenthesis(int n) {
    vector<string> result;
    string path;
    function<void(int,int)> backtrack = [&](int left, int right) {
        if (path.size() == 2*n) { result.push_back(path); return; }
        if (left < n) path.push_back('('), backtrack(left+1, right), path.pop_back();
        if (right < left) path.push_back(')'), backtrack(left, right+1), path.pop_back();
    };
    backtrack(0, 0);
    return result;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 左括号随时可加，右括号需与左括号匹配
- 保证序列始终有效

---

### 37. 解数独 (Sudoku Solver)

**Python 实现**:
```python
def solve_sudoku(board: list[list[str]]) -> None:
    def could_place(d, row, col):
        return d not in row[row] and d not in col[col] and d not in box[(row//3, col//3)]
    def place_number(d, row, col):
        row[row].add(d)
        col[col].add(d)
        box[(row//3, col//3)].add(d)
        board[row][col] = str(d)
    def remove_number(d, row, col):
        row[row].remove(d)
        col[col].remove(d)
        box[(row//3, col//3)].remove(d)
        board[row][col] = '.'
    def backtrack():
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    for d in '123456789':
                        if could_place(d, i, j):
                            place_number(d, i, j)
                            if backtrack():
                                return True
                            remove_number(d, i, j)
                    return False
        return True
    row = [set() for _ in range(9)]
    col = [set() for _ in range(9)]
    box = {(i, j): set() for i in range(3) for j in range(3)}
    for i in range(9):
        for j in range(9):
            if board[i][j] != '.':
                place_number(board[i][j], i, j)
    backtrack()

if __name__ == "__main__":

    # 测试用例
    result = solve_sudoku(None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <vector>

bool isValid(vector<vector<char>>& board, int row, int col, char d) {
    for (int i = 0; i < 9; i++)
        if (board[row][i] == d || board[i][col] == d) return false;
    int br = (row/3)*3, bc = (col/3)*3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[br+i][bc+j] == d) return false;
    return true;
}
bool solveSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (board[i][j] == '.')
                for (char d = '1'; d <= '9'; d++)
                    if (isValid(board, i, j, d)) {
                        board[i][j] = d;
                        if (solveSudoku(board)) return true;
                        board[i][j] = '.';
                    }
                return false;
    return true;
}
int main() {
    // 测试用例
    cout << isValid(0, 0, 0, 0) << endl;
    return 0;
}

```

**算法详解**:
- 逐格尝试，用集合记录每行/列/宫已填数字
- 约束传播加速搜索

---

### 51. N 皇后 (N-Queens)

**Python 实现**:
```python
def solve_n_queens(n: int) -> list[list[str]]:
    result = []
    cols = set()
    diag1 = set()
    diag2 = set()
    board = [['.' ] * n for _ in range(n)]
    def backtrack(row):
        if row == n:
            result.append([''.join(row) for row in board])
            return
        for col in range(n):
            if col in cols or (row - col) in diag1 or (row + col) in diag2:
                continue
            board[row][col] = 'Q'
            cols.add(col); diag1.add(row-col); diag2.add(row+col)
            backtrack(row + 1)
            board[row][col] = '.'
            cols.remove(col); diag1.remove(row-col); diag2.remove(row+col)
    backtrack(0)
    return result

if __name__ == "__main__":

    # 测试用例
    result = solve_n_queens(3)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.'));
    vector<int> cols(n, 0), diag1(2*n, 0), diag2(2*n, 0);
    function<void(int)> backtrack = [&](int row) {
        if (row == n) { result.push_back(board); return; }
        for (int col = 0; col < n; col++) {
            int d1 = row - col + n, d2 = row + col;
            if (cols[col] || diag1[d1] || diag2[d2]) continue;
            board[row][col] = 'Q';
            cols[col] = diag1[d1] = diag2[d2] = 1;
            backtrack(row + 1);
            board[row][col] = '.';
            cols[col] = diag1[d1] = diag2[d2] = 0;
        }
    };
    backtrack(0);
    return result;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 主对角线差值相同，副对角线和值相同
- 用集合/数组记录已占位置
- 时间复杂度 O(n!)

---

### 79. 单词搜索 (Word Search)

**Python 实现**:
```python
def exist(board: list[list[str]], word: str) -> bool:
    m, n = len(board), len(board[0])
    visited = [[False] * n for _ in range(m)]
    def dfs(i, j, idx):
        if idx == len(word):
            return True
        if i < 0 or i >= m or j < 0 or j >= n or visited[i][j] or board[i][j] != word[idx]:
            return False
        visited[i][j] = True
        for di, dj in [(0,1),(0,-1),(1,0),(-1,0)]:
            if dfs(i+di, j+dj, idx+1):
                return True
        visited[i][j] = False
        return False
    for i in range(m):
        for j in range(n):
            if dfs(i, j, 0):
                return True
    return False

if __name__ == "__main__":

    # 测试用例
    result = exist(None, "apple")
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <string>
#include <vector>

bool exist(vector<vector<char>>& board, string word) {
    int m = board.size(), n = board[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    function<bool(int,int,int)> dfs = [&](int i, int j, int idx) -> bool {
        if (idx == word.size()) return true;
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || board[i][j] != word[idx]) return false;
        visited[i][j] = 1;
        for (auto& d : vector<pair<int,int>>{{0,1},{0,-1},{1,0},{-1,0}})
            if (dfs(i+d.first, j+d.second, idx+1)) return true;
        visited[i][j] = 0;
        return false;
    };
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (dfs(i, j, 0)) return true;
    return false;
}
int main() {
    // 测试用例
    cout << exist(0, {"abc"}) << endl;
    return 0;
}

```

**算法详解**:
- 回溯 + DFS 搜索路径
- 每个格子可重复访问（但不能走回头路）
- 时间复杂度 O(m*n*4^L)

---

## 十、树（Tree）

### 94. 二叉树的中序遍历 (Binary Tree Inorder Traversal)

**Python 实现**:
```python
def inorder_traversal(root):
    result = []
    stack = []
    cur = root
    while cur or stack:
        while cur:
            stack.append(cur)
            cur = cur.left
        cur = stack.pop()
        result.append(cur.val)
        cur = cur.right
    return result

if __name__ == "__main__":

    # 测试用例
    result = inorder_traversal(None  # TreeNode placeholder)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur || !st.empty()) {
        while (cur) { st.push(cur); cur = cur->left; }
        cur = st.top(); st.pop();
        result.push_back(cur->val);
        cur = cur->right;
    }
    return result;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 左-根-右 顺序遍历
- 递归 O(n)，栈实现 O(n) 时间和 O(h) 空间

---

### 102. 二叉树的层序遍历 (Binary Tree Level Order Traversal)

**Python 实现**:
```python
from collections import deque
def level_order(root):
    if not root:
        return []
    result = []
    queue = deque([root])
    while queue:
        level = []
        for _ in range(len(queue)):
            node = queue.popleft()
            level.append(node.val)
            if node.left: queue.append(node.left)
            if node.right: queue.append(node.right)
        result.append(level)
    return result

if __name__ == "__main__":

    # 测试用例
    result = level_order(None  # TreeNode placeholder)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <deque>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root) return {};
    vector<vector<int>> result;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        vector<int> level;
        while (sz--) {
            TreeNode* node = q.front(); q.pop();
            level.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(level);
    }
    return result;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- BFS 层序遍历，用 size 控制每层
- 时间复杂度 O(n)，空间 O(n)

---

### 104. 二叉树的最大深度 (Maximum Depth of Binary Tree)

**Python 实现**:
```python
def max_depth(root):
    if not root:
        return 0
    return 1 + max(max_depth(root.left), max_depth(root.right))

if __name__ == "__main__":

    # 测试用例
    result = max_depth(None  # TreeNode placeholder)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>

int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
int main() {
    // 测试用例
    cout << maxDepth(nullptr) << endl;
    return 0;
}

```

**算法详解**:
- 递归求左右子树最大深度
- 时间复杂度 O(n)，空间 O(h)

---

### 111. 二叉树的最小深度 (Minimum Depth of Binary Tree)

**Python 实现**:
```python
def min_depth(root):
    if not root:
        return 0
    if not root.left:
        return 1 + min_depth(root.right)
    if not root.right:
        return 1 + min_depth(root.left)
    return 1 + min(min_depth(root.left), min_depth(root.right))

if __name__ == "__main__":

    # 测试用例
    result = min_depth(None  # TreeNode placeholder)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>

int minDepth(TreeNode* root) {
    if (!root) return 0;
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}
int main() {
    // 测试用例
    cout << minDepth(nullptr) << endl;
    return 0;
}

```

**算法详解**:
- 注意：最小深度是到最近叶子节点的距离
- 空子树直接跳过

---

### 112. 路径总和 (Path Sum)

**Python 实现**:
```python
def has_path_sum(root, target_sum):
    if not root:
        return False
    if not root.left and not root.right:
        return root.val == target_sum
    return has_path_sum(root.left, target_sum - root.val) or has_path_sum(root.right, target_sum - root.val)

if __name__ == "__main__":

    # 测试用例
    result = has_path_sum(None  # TreeNode placeholder, None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>

bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;
    if (!root->left && !root->right) return root->val == targetSum;
    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}
int main() {
    // 测试用例
    cout << hasPathSum(nullptr, 0) << endl;
    return 0;
}

```

---

### 113. 路径总和 II (Path Sum II)

**Python 实现**:
```python
def path_sum(root, target_sum):
    result = []
    path = []
    def dfs(node, remaining):
        if not node:
            return
        path.append(node.val)
        if not node.left and not node.right and remaining == node.val:
            result.append(path[:])
        dfs(node.left, remaining - node.val)
        dfs(node.right, remaining - node.val)
        path.pop()
    dfs(root, target_sum)
    return result

if __name__ == "__main__":

    # 测试用例
    result = path_sum(None  # TreeNode placeholder, None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> result;
    vector<int> path;
    function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int rem) {
        if (!node) return;
        path.push_back(node->val);
        if (!node->left && !node->right && rem == node->val) result.push_back(path);
        dfs(node->left, rem - node->val);
        dfs(node->right, rem - node->val);
        path.pop_back();
    };
    dfs(root, targetSum);
    return result;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

---

### 129. 求根节点到叶节点数字之和 (Sum Root to Leaf Numbers)

**Python 实现**:
```python
def sum_numbers(root):
    result = 0
    def dfs(node, num):
        nonlocal result
        if not node:
            return
        num = num * 10 + node.val
        if not node.left and not node.right:
            result += num
        dfs(node.left, num)
        dfs(node.right, num)
    dfs(root, 0)
    return result

if __name__ == "__main__":

    # 测试用例
    result = sum_numbers(None  # TreeNode placeholder)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>

int sumNumbers(TreeNode* root) {
    int result = 0;
    function<void(TreeNode*,int)> dfs = [&](TreeNode* node, int num) {
        if (!node) return;
        num = num * 10 + node->val;
        if (!node->left && !node->right) { result += num; return; }
        dfs(node->left, num);
        dfs(node->right, num);
    };
    dfs(root, 0);
    return result;
}
int main() {
    // 测试用例
    cout << sumNumbers(nullptr) << endl;
    return 0;
}

```

---

### 105. 从前序与中序遍历序列构造二叉树 (Construct Binary Tree from Preorder and Inorder Traversal)

**Python 实现**:
```python
def build_tree(preorder, inorder):
    if not preorder:
        return None
    root = TreeNode(preorder[0])
    idx = inorder.index(preorder[0])
    root.left = build_tree(preorder[1:idx+1], inorder[:idx])
    root.right = build_tree(preorder[idx+1:], inorder[idx+1:])
    return root

if __name__ == "__main__":

    # 测试用例
    result = build_tree(None, None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> idx;
    for (int i = 0; i < inorder.size(); i++) idx[inorder[i]] = i;
    function<TreeNode*(int,int,int)> build = [&](int pl, int pr, int il) -> TreeNode* {
        if (pl > pr) return nullptr;
        TreeNode* root = new TreeNode(preorder[pl]);
        int mid = idx[preorder[pl]];
        root->left = build(pl+1, pl+mid-il, il, mid-1);
        root->right = build(pl+mid-il+1, pr, mid+1, inorder.size()-1);
        return root;
    };
    return build(0, preorder.size()-1, 0, inorder.size()-1);
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 前序首位是根，在中序中定位，左边是左子树，右边是右子树
- 递归构建，空间 O(n) 的哈希优化

---

### 106. 从中序与后序遍历序列构造二叉树 (Construct Binary Tree from Inorder and Postorder Traversal)

**Python 实现**:
```python
def build_tree(inorder, postorder):
    if not postorder:
        return None
    root = TreeNode(postorder[-1])
    idx = inorder.index(postorder[-1])
    root.left = build_tree(inorder[:idx], postorder[:idx])
    root.right = build_tree(inorder[idx+1:], postorder[idx:-1])
    return root

if __name__ == "__main__":

    # 测试用例
    result = build_tree(None, None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
TreeNode* buildTreeInPost(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> idx;
    for (int i = 0; i < inorder.size(); i++) idx[inorder[i]] = i;
    function<TreeNode*(int,int,int)> build = [&](int il, int ir, int pl) -> TreeNode* {
        if (il > ir) return nullptr;
        TreeNode* root = new TreeNode(postorder[pl]);
        int mid = idx[postorder[pl]];
        root->left = build(il, mid-1, pl-(ir-mid)-1);
        root->right = build(mid+1, ir, pl-1);
        return root;
    };
    return build(0, inorder.size()-1, postorder.size()-1);
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 后序末位是根，中序定位后左右递归
- 哈希映射加速查找

---

### 116. 填充每个节点的下一个右侧节点指针 (Populating Next Right Pointers in Each Node)

**Python 实现**:
```python
def connect(root):
    if not root:
        return root
    if root.left:
        root.left.next = root.right
    if root.next and root.right:
        root.right.next = root.next.left
    connect(root.left)
    connect(root.right)
    return root

if __name__ == "__main__":

    # 测试用例
    result = connect(None  # TreeNode placeholder)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
using namespace std;
Node* connect(Node* root) {
    if (!root) return root;
    if (root->left) root->left->next = root->right;
    if (root->next && root->right) root->right->next = root->next->left;
    connect(root->left);
    connect(root->right);
    return root;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 完全二叉树，利用 next 指针层序连接
- 递归连接同父节点和跨父节点

---

### 117. 填充每个节点的下一个右侧节点指针 II (Populating Next Right Pointers in Each Node II)

**Python 实现**:
```python
def connect(root):
    if not root:
        return root
    dummy = Node(0)
    cur = dummy
    while root:
        if root.left:
            cur.next = root.left
            cur = cur.next
        if root.right:
            cur.next = root.right
            cur = cur.next
        root = root.next
        if not root:
            cur = dummy
            root = dummy.next
            dummy.next = None
    return dummy

if __name__ == "__main__":

    # 测试用例
    result = connect(None  # TreeNode placeholder)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
using namespace std;
Node* connect(Node* root) {
    Node* dummy = new Node(0);
    Node* cur = dummy;
    while (root) {
        if (root->left) { cur->next = root->left; cur = cur->next; }
        if (root->right) { cur->next = root->right; cur = cur->next; }
        root = root->next;
        if (!root) { cur = dummy; root = dummy->next; dummy->next = nullptr; }
    }
    return dummy;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 层序遍历思想，用 dummy 头节点连接每层
- dummy 简化首节点处理

---

### 236. 二叉树的最近公共祖先 (Lowest Common Ancestor of a Binary Tree)

**Python 实现**:
```python
def lowest_common_ancestor(root, p, q):
    if not root or root == p or root == q:
        return root
    left = lowest_common_ancestor(root.left, p, q)
    right = lowest_common_ancestor(root.right, p, q)
    if left and right:
        return root
    return left or right

if __name__ == "__main__":

    # 测试用例
    result = lowest_common_ancestor(None  # TreeNode placeholder, "abc", None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
using namespace std;
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left && right) return root;
    return left ? left : right;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 后序遍历：左子树和右子树各找到一个节点，则当前是 LCA
- 时间复杂度 O(n)，空间 O(h)

---

### 235. 二叉搜索树的最近公共祖先 (Lowest Common Ancestor of a Binary Search Tree)

**Python 实现**:
```python
def lowest_common_ancestor(root, p, q):
    while root:
        if p.val < root.val and q.val < root.val:
            root = root.left
        elif p.val > root.val and q.val > root.val:
            root = root.right
        else:
            return root
    return root

if __name__ == "__main__":

    # 测试用例
    result = lowest_common_ancestor(None  # TreeNode placeholder, "abc", None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
using namespace std;
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root) {
        if (p->val < root->val && q->val < root->val) root = root->left;
        else if (p->val > root->val && q->val > root->val) root = root->right;
        else return root;
    }
    return root;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- BST 有序性：p、q 在同侧则在对应子树找，否则当前即 LCA

---

### 108. 将有序数组转换为二叉搜索树 (Convert Sorted Array to Binary Search Tree)

**Python 实现**:
```python
def sorted_array_to_bst(nums):
    if not nums:
        return None
    mid = len(nums) // 2
    root = TreeNode(nums[mid])
    root.left = sorted_array_to_bst(nums[:mid])
    root.right = sorted_array_to_bst(nums[mid+1:])
    return root

if __name__ == "__main__":

    # 测试用例
    result = sorted_array_to_bst([1, 2, 3])
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <vector>
using namespace std;
TreeNode* sortedArrayToBST(vector<int>& nums) {
    function<TreeNode*(int,int)> build = [&](int l, int r) -> TreeNode* {
        if (l > r) return nullptr;
        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(l, mid-1);
        root->right = build(mid+1, r);
        return root;
    };
    return build(0, nums.size()-1);
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 中间元素作为根，保证平衡
- 时间复杂度 O(n)

---

### 109. 有序链表转换二叉搜索树 (Convert Sorted List to Binary Search Tree)

**Python 实现**:
```python
def sorted_list_to_bst(head):
    if not head:
        return None
    if not head.next:
        return TreeNode(head.val)
    slow = fast = head
    prev = None
    while fast and fast.next:
        prev = slow
        slow = slow.next
        fast = fast.next.next
    root = TreeNode(slow.val)
    if prev:
        prev.next = None
        root.left = sorted_list_to_bst(head)
    root.right = sorted_list_to_bst(slow.next)
    return root

if __name__ == "__main__":

    # 测试用例
    result = sorted_list_to_bst(None  # ListNode placeholder)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <list>
using namespace std;
TreeNode* sortedListToBST(ListNode* head) {
    if (!head) return nullptr;
    if (!head->next) return new TreeNode(head->val);
    ListNode *slow = head, *fast = head, *prev = nullptr;
    while (fast && fast->next) {
        prev = slow; slow = slow->next; fast = fast->next->next;
    }
    TreeNode* root = new TreeNode(slow->val);
    if (prev) { prev->next = nullptr; root->left = sortedListToBST(head); }
    root->right = sortedListToBST(slow->next);
    return root;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 快慢指针找中点作为根
- 链表分割后递归建树

---

### 110. 平衡二叉树 (Balanced Binary Tree)

**Python 实现**:
```python
def is_balanced(root):
    def dfs(node):
        if not node:
            return 0
        left = dfs(node.left)
        if left == -1:
            return -1
        right = dfs(node.right)
        if right == -1 or abs(left - right) > 1:
            return -1
        return max(left, right) + 1
    return dfs(root) != -1

if __name__ == "__main__":

    # 测试用例
    result = is_balanced(None  # TreeNode placeholder)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>

int height(TreeNode* node) {
    if (!node) return 0;
    int l = height(node->left);
    if (l == -1) return -1;
    int r = height(node->right);
    if (r == -1 || abs(l-r) > 1) return -1;
    return max(l, r) + 1;
}
bool isBalanced(TreeNode* root) { return height(root) != -1; }
int main() {
    // 测试用例
    cout << height(0) << endl;
    return 0;
}

```

**算法详解**:
- 自底向上 O(n)：子树高度差 > 1 返回 -1
- 提前剪枝

---

### 124. 二叉树中的最大路径和 (Binary Tree Maximum Path Sum)

**Python 实现**:
```python
def max_path_sum(root):
    result = float('-inf')
    def dfs(node):
        nonlocal result
        if not node:
            return 0
        left = max(0, dfs(node.left))
        right = max(0, dfs(node.right))
        result = max(result, left + right + node.val)
        return max(left, right) + node.val
    dfs(root)
    return result

if __name__ == "__main__":

    # 测试用例
    result = max_path_sum(None  # TreeNode placeholder)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>

int maxPathSum(TreeNode* root) {
    int result = INT_MIN;
    function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
        if (!node) return 0;
        int l = max(0, dfs(node->left));
        int r = max(0, dfs(node->right));
        result = max(result, l + r + node->val);
        return max(l, r) + node->val;
    };
    dfs(root);
    return result;
}
int main() {
    // 测试用例
    cout << maxPathSum(nullptr) << endl;
    return 0;
}

```

**算法详解**:
- 每个节点返回从该节点向下走的最大路径
- 路径可以在任意节点"拐弯"
- 时间复杂度 O(n)

---

### 103. 二叉树的锯齿形层序遍历 (Binary Tree Zigzag Level Order Traversal)

**Python 实现**:
```python
def zigzag_level_order(root):
    if not root:
        return []
    result = []
    queue = deque([root])
    reverse = False
    while queue:
        level = []
        for _ in range(len(queue)):
            node = queue.popleft()
            level.append(node.val)
            if node.left: queue.append(node.left)
            if node.right: queue.append(node.right)
        if reverse:
            level.reverse()
        result.append(level)
        reverse = not reverse
    return result

if __name__ == "__main__":

    # 测试用例
    result = zigzag_level_order(None  # TreeNode placeholder)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <deque>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (!root) return {};
    vector<vector<int>> result;
    queue<TreeNode*> q;
    q.push(root);
    bool reverse = false;
    while (!q.empty()) {
        int sz = q.size();
        vector<int> level;
        while (sz--) {
            TreeNode* node = q.front(); q.pop();
            level.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        if (reverse) reverse(level.begin(), level.end());
        result.push_back(level);
        reverse = !reverse;
    }
    return result;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

---

### 144. 二叉树的前序遍历 (Binary Tree Preorder Traversal)

**Python 实现**:
```python
def preorder_traversal(root):
    result = []
    stack = [root]
    while stack:
        node = stack.pop()
        if node:
            result.append(node.val)
            stack.append(node.right)
            stack.append(node.left)
    return result

    return result

if __name__ == "__main__":

    # 测试用例
    result = preorder_traversal(None  # TreeNode placeholder)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    if (root) st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top(); st.pop();
        result.push_back(node->val);
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
    return result;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 根-左-右 顺序，栈模拟递归
- 时间复杂度 O(n)，空间 O(h)

---

### 145. 二叉树的后序遍历 (Binary Tree Postorder Traversal)

**Python 实现**:
```python
def postorder_traversal(root):
    result = []
    stack = []
    cur = root
    while cur or stack:
        while cur:
            stack.append((cur, False))
            cur = cur.left
        node, visited = stack.pop()
        if visited:
            result.append(node.val)
        else:
            stack.append((node, True))
            cur = node.right
    return result

if __name__ == "__main__":

    # 测试用例
    result = postorder_traversal(None  # TreeNode placeholder)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<pair<TreeNode*, bool>> st;
    if (root) st.push({root, false});
    while (!st.empty()) {
        auto [node, visited] = st.top(); st.pop();
        if (visited) {
            result.push_back(node->val);
        } else {
            st.push({node, true});
            if (node->right) st.push({node->right, false});
            if (node->left) st.push({node->left, false});
        }
    }
    return result;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 用栈模拟：节点先标记为未访问，压入右左子树
- 第二次弹出时加入结果（左右根）
- 时间复杂度 O(n)，空间 O(h)

---

### 199. 二叉树的右视图 (Binary Tree Right Side View)

**Python 实现**:
```python
from collections import deque

def right_side_view(root):
    if not root:
        return []
    result = []
    queue = deque([root])
    while queue:
        size = len(queue)
        for i in range(size):
            node = queue.popleft()
            if i == size - 1:
                result.append(node.val)
            if node.left: queue.append(node.left)
            if node.right: queue.append(node.right)
    return result

if __name__ == "__main__":

    # 测试用例
    result = right_side_view(None  # TreeNode placeholder)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <deque>
#include <queue>
#include <vector>
using namespace std;
vector<int> rightSideView(TreeNode* root) {
    if (!root) return {};
    vector<int> result;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            TreeNode* node = q.front(); q.pop();
            if (i == sz - 1) result.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return result;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

---

### 222. 完全二叉树的节点个数 (Count Complete Tree Nodes)

**Python 实现**:
```python
def count_nodes(root):
    if not root:
        return 0
    left_depth = right_depth = 0
    left_node = root
    while left_node:
        left_depth += 1
        left_node = left_node.left
    right_node = root
    while right_node:
        right_depth += 1
        right_node = right_node.right
    if left_depth == right_depth:
        return (1 << left_depth) - 1
    return 1 + count_nodes(root.left) + count_nodes(root.right)

if __name__ == "__main__":

    # 测试用例
    result = count_nodes(None  # TreeNode placeholder)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>

int countNodes(TreeNode* root) {
    if (!root) return 0;
    TreeNode *l = root, *r = root;
    int hl = 0, hr = 0;
    while (l) { hl++; l = l->left; }
    while (r) { hr++; r = r->right; }
    if (hl == hr) return (1 << hl) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
int main() {
    // 测试用例
    cout << countNodes(nullptr) << endl;
    return 0;
}

```

**算法详解**:
- 完全二叉树：若左右深度相同则为满二叉树，节点数 = 2^h - 1
- 否则递归计数左右子树
- 时间复杂度 O(h^2) ~ O(log n * log n)

---

### 226. 翻转二叉树 (Invert Binary Tree)

**Python 实现**:
```python
def invert_tree(root):
    if not root:
        return root
    root.left, root.right = root.right, root.left
    invert_tree(root.left)
    invert_tree(root.right)
    return root

if __name__ == "__main__":

    # 测试用例
    result = invert_tree(None  # TreeNode placeholder)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
using namespace std;
TreeNode* invertTree(TreeNode* root) {
    if (!root) return root;
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 递归交换每个节点的左右子树
- 时间复杂度 O(n)

---

### 617. 合并二叉树 (Merge Two Binary Trees)

**Python 实现**:
```python
def merge_trees(t1, t2):
    if not t1:
        return t2
    if not t2:
        return t1
    t1.val += t2.val
    t1.left = merge_trees(t1.left, t2.left)
    t1.right = merge_trees(t1.right, t2.right)
    return t1

if __name__ == "__main__":

    # 测试用例
    result = merge_trees(None, None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
using namespace std;
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (!t1) return t2;
    if (!t2) return t1;
    t1->val += t2->val;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);
    return t1;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 递归合并两棵树的对应节点
- 时间复杂度 O(min(n,m))

---

### 572. 另一棵树的子树 (Subtree of Another Tree)

**Python 实现**:
```python
def is_subtree(root, sub_root):
    if not root:
        return False
    def is_same(t1, t2):
        if not t1 and not t2:
            return True
        if not t1 or not t2:
            return False
        return t1.val == t2.val and is_same(t1.left, t2.left) and is_same(t1.right, t2.right)
    if is_same(root, sub_root):
        return True
    return is_subtree(root.left, sub_root) or is_subtree(root.right, sub_root)

if __name__ == "__main__":

    # 测试用例
    result = is_subtree(None  # TreeNode placeholder, None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>

bool isSameTree(TreeNode* a, TreeNode* b) {
    if (!a && !b) return true;
    if (!a || !b) return false;
    return a->val == b->val && isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
}
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root) return false;
    if (isSameTree(root, subRoot)) return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
int main() {
    // 测试用例
    cout << isSameTree(0, 0) << endl;
    return 0;
}

```

---

### 404. 左叶子之和 (Sum of Left Leaves)

**Python 实现**:
```python
def sum_of_left_leaves(root):
    if not root:
        return 0
    total = 0
    if root.left and not root.left.left and not root.left.right:
        total += root.left.val
    else:
        total += sum_of_left_leaves(root.left)
    total += sum_of_left_leaves(root.right)
    return total

if __name__ == "__main__":

    # 测试用例
    result = sum_of_left_leaves(None  # TreeNode placeholder)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>

int sumOfLeftLeaves(TreeNode* root) {
    if (!root) return 0;
    int total = 0;
    if (root->left && !root->left->left && !root->left->right) total += root->left->val;
    else total += sumOfLeftLeaves(root->left);
    total += sumOfLeftLeaves(root->right);
    return total;
}
int main() {
    // 测试用例
    cout << sumOfLeftLeaves(nullptr) << endl;
    return 0;
}

```

**算法详解**:
- 左叶子：左子节点且该节点没有子节点
- 递归累加

---

### 513. 找树左下角的值 (Find Bottom Left Tree Value)

**Python 实现**:
```python
from collections import deque

def find_bottom_left_value(root):
    queue = deque([root])
    leftmost = root.val
    while queue:
        node = queue.popleft()
        leftmost = node.val
        if node.right: queue.append(node.right)
        if node.left: queue.append(node.left)
    return leftmost

if __name__ == "__main__":

    # 测试用例
    result = find_bottom_left_value(None  # TreeNode placeholder)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <queue>

int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int leftmost;
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        leftmost = node->val;
        if (node->right) q.push(node->right);
        if (node->left) q.push(node->left);
    }
    return leftmost;
}
int main() {
    // 测试用例
    cout << findBottomLeftValue(nullptr) << endl;
    return 0;
}

```

**算法详解**:
- BFS 层序遍历，每层最后一个就是该层最左
- 或从右往左遍历，每层最后一个就是左下角

---

## 十一、堆（Heap & Priority Queue）

### 215. 数组中的第K个最大元素 (Kth Largest Element in an Array)

**Python 实现**:
```python
import heapq

def find_kth_largest(nums: list[int], k: int) -> int:
    return heapq.nlargest(k, nums)[-1]

if __name__ == "__main__":

    # 测试用例
    result = find_kth_largest([1, 2, 3], 2)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <queue>
#include <vector>

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq(nums.begin(), nums.end());
    for (int i = 0; i < k - 1; i++) pq.pop();
    return pq.top();
}
int main() {
    // 测试用例
    cout << findKthLargest({1, 2, 3}, 9) << endl;
    return 0;
}

```

**算法详解**:
- 维护大小为 k 的最小堆，或者直接用最大堆 pop k 次
- 时间复杂度 O(n + k log n)

---

### 347. 前 K 个高频元素 (Top K Frequent Elements)

**Python 实现**:
```python
import heapq
from collections import Counter

def top_k_frequent(nums: list[int], k: int) -> list[int]:
    count = Counter(nums)
    return [item[0] for item in heapq.nlargest(k, count.items(), key=lambda x: x[1])]

if __name__ == "__main__":

    # 测试用例
    result = top_k_frequent([1, 2, 3], 2)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <deque>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int num : nums) freq[num]++;
    priority_queue<pair<int,int>> pq;
    for (auto& kv : freq) pq.push({kv.second, kv.first});
    vector<int> result;
    while (k-- > 0) { result.push_back(pq.top().second); pq.pop(); }
    return result;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 统计频率，用堆取 Top K
- 时间复杂度 O(n log n)，空间 O(n)

---

### 295. 数据流的中位数 (Find Median from Data Stream)

**Python 实现**:
```python
import heapq

class MedianFinder:
    def __init__(self):
        self.small = []
        self.large = []
    def add_num(self, num: int) -> None:
        heapq.heappush(self.small, -num)
        heapq.heappush(self.large, -heapq.heappop(self.small))
        if len(self.small) < len(self.large):
            heapq.heappush(self.small, -heapq.heappop(self.large))
    def find_median(self) -> float:
        if len(self.small) > len(self.large):
            return -self.small[0]
        return (-self.small[0] + self.large[0]) / 2.0

if __name__ == "__main__":

    # 测试用例
    result = __init__(None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <queue>
#include <vector>

class MedianFinder {
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
public:
    void addNum(int num) {
        small.push(num);
        large.push(small.top()); small.pop();
        if (small.size() < large.size()) {
            small.push(large.top()); large.pop();
        }
    }
    double findMedian() {
        return small.size() > large.size() ? small.top() : (small.top() + large.top()) / 2.0;
    }
};
int main() {
    // 测试用例
    addNum(0, 0);
    return 0;
}

```

**算法详解**:
- small 为最大堆（大元素），large 为最小堆（小元素）
- 保持两堆大小平衡，中位数即堆顶
- 时间复杂度 O(log n)，空间 O(n)

---

### 23. 合并K个升序链表 (Merge K Sorted Lists)

（已在第四章链表给出，见第 23 题）

---

### 373. 查找和最小的K对数字 (Find K Pairs with Smallest Sums)

**Python 实现**:
```python
import heapq

def k_smallest_pairs(nums1: list[int], nums2: list[int], k: int) -> list[list[int]]:
    if not nums1 or not nums2:
        return []
    heap = [(nums1[0] + nums2[0], 0, 0)]
    visited = set()
    result = []
    while heap and len(result) < k:
        _, i, j = heapq.heappop(heap)
        result.append([nums1[i], nums2[j]])
        if i + 1 < len(nums1) and (i+1, j) not in visited:
            heapq.heappush(heap, (nums1[i+1] + nums2[j], i+1, j))
            visited.add((i+1, j))
        if j + 1 < len(nums2) and (i, j+1) not in visited:
            heapq.heappush(heap, (nums1[i] + nums2[j+1], i, j+1))
            visited.add((i, j+1))
    return result

if __name__ == "__main__":

    # 测试用例
    result = k_smallest_pairs([1, 2, 3], [1, 2, 3], 2)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <deque>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<vector<int>> result;
    if (nums1.empty() || nums2.empty()) return result;
    auto cmp = [](auto& a, auto& b) { return a[0] + a[1] > b[0] + b[1]; };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
    pq.push({nums1[0], nums2[0], 0, 0});
    while (!pq.empty() && result.size() < k) {
        auto cur = pq.top(); pq.pop();
        result.push_back({cur[0], cur[1]});
        int i = cur[2], j = cur[3];
        if (i+1 < nums1.size()) pq.push({nums1[i+1], nums2[j], i+1, j});
        if (j+1 < nums2.size()) pq.push({nums1[i], nums2[j+1], i, j+1});
    }
    return result;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 小根堆从 (0,0) 开始扩展
- 每对元素扩展到右侧和下方邻居
- 时间复杂度 O(k log k)

---

## 十二、分治（Divide and Conquer）

### 53. 最大子数组和（分治法）(Maximum Subarray - Divide & Conquer)

**Python 实现**:
```python
def max_sub_array_dc(nums: list[int]) -> int:
    def divide_conquer(nums, left, right):
        if left == right:
            return nums[left], nums[left], nums[left]
        mid = (left + right) // 2
        left_max, left_presum, left_sufsum = divide_conquer(nums, left, mid)
        right_max, right_presum, right_sufsum = divide_conquer(nums, mid+1, right)
        cross_max = left_sufsum + right_presum
        max_part = max(left_max, right_max)
        return max(max_part, cross_max), max(left_presum, left_sufsum + right_presum), max(right_sufsum, left_sufsum + right_sufsum)
    return divide_conquer(nums, 0, len(nums)-1)[0]

if __name__ == "__main__":

    # 测试用例
    result = max_sub_array_dc([1, 2, 3])
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>
#include <vector>

struct Status { int sum, pref, suff, best; };
Status combine(Status l, Status r) {
    Status res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.best = max({l.best, r.best, l.suff + r.pref});
    return res;
}
Status divideConquer(vector<int>& nums, int left, int right) {
    if (left == right) return {nums[left], nums[left], nums[left], nums[left]};
    int mid = (left + right) / 2;
    Status leftStatus = divideConquer(nums, left, mid);
    Status rightStatus = divideConquer(nums, mid+1, right);
    return combine(leftStatus, rightStatus);
}
int maxSubArrayDC(vector<int>& nums) {
    return divideConquer(nums, 0, nums.size()-1).best;
}
int main() {
    // 测试用例
    cout << combine(0, 9) << endl;
    return 0;
}

```

**算法详解**:
- 分：从中点分割为左右子数组
- 治：递归求左右子数组的最大子数组和
- 合：求跨越中点的最大子数组和
- 时间复杂度 O(n log n)

---

### 169. 多数元素 (Majority Element)

**Python 实现**:
```python
def majority_element(nums: list[int]) -> int:
    count = 0
    candidate = None
    for num in nums:
        if count == 0:
            candidate = num
        count += (1 if num == candidate else -1)
    return candidate

if __name__ == "__main__":

    # 测试用例
    result = majority_element([1, 2, 3])
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <vector>

int majorityElement(vector<int>& nums) {
    int count = 0, candidate = 0;
    for (int num : nums) {
        if (count == 0) candidate = num;
        count += (num == candidate ? 1 : -1);
    }
    return candidate;
}
int main() {
    // 测试用例
    cout << majorityElement({1, 2, 3}) << endl;
    return 0;
}

```

**算法详解**:
- Boyer-Moore 投票法：candidate 相同则 count++，不同则 count--
- count 为 0 时更换 candidate
- 众数最终票数 > n/2，必胜出
- 时间复杂度 O(n)，空间 O(1)

---

### 240. 搜索二维矩阵 II (Search a 2D Matrix II)

**Python 实现**:
```python
def search_matrix(matrix: list[list[int]], target: int) -> bool:
    if not matrix:
        return False
    row, col = 0, len(matrix[0]) - 1
    while row < len(matrix) and col >= 0:
        if matrix[row][col] == target:
            return True
        elif matrix[row][col] > target:
            col -= 1
        else:
            row += 1
    return False

if __name__ == "__main__":

    # 测试用例
    result = search_matrix([[1, 2, 3], [4, 5, 6], [7, 8, 9]], 9)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <vector>

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = 0, col = matrix[0].size() - 1;
    while (row < matrix.size() && col >= 0) {
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] > target) col--;
        else row++;
    }
    return false;
}
int main() {
    // 测试用例
    cout << searchMatrix({{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}, 9) << endl;
    return 0;
}

```

**算法详解**:
- 从右上角开始，左边更小，下边更大
- 每次排除一行或一列
- 时间复杂度 O(m + n)

---

### 241. 为运算表达式设计优先级 (Different Ways to Add Parentheses)

**Python 实现**:
```python
def diff_ways_to_compute(expression: str) -> list[int]:
    if expression.isdigit():
        return [int(expression)]
    result = []
    for i, ch in enumerate(expression):
        if ch in '+-*':
            left = diff_ways_to_compute(expression[:i])
            right = diff_ways_to_compute(expression[i+1:])
            for l in left:
                for r in right:
                    if ch == '+': result.append(l + r)
                    elif ch == '-': result.append(l - r)
                    else: result.append(l * r)
    return result

if __name__ == "__main__":

    # 测试用例
    result = diff_ways_to_compute(None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> diffWaysToCompute(string expression) {
    if (expression.find('+') == string::npos && expression.find('-') == string::npos && expression.find('*') == string::npos)
        return {stoi(expression)};
    vector<int> result;
    for (int i = 0; i < expression.size(); i++) {
        char op = expression[i];
        if (op == '+' || op == '-' || op == '*') {
            auto left = diffWaysToCompute(expression.substr(0, i));
            auto right = diffWaysToCompute(expression.substr(i+1));
            for (int l : left)
                for (int r : right)
                    result.push_back(op == '+' ? l+r : op == '-' ? l-r : l*r);
        }
    }
    return result;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 按运算符分割，递归计算左右两部分，再合并
- 利用分治思想枚举所有括号方式

---

## 十三、图（Graph）

### 133. 克隆图 (Clone Graph)

**Python 实现**:
```python
def clone_graph(node):
    if not node:
        return None
    visited = {}
    def dfs(n):
        if n in visited:
            return visited[n]
        clone = Node(n.val)
        visited[n] = clone
        for neighbor in n.neighbors:
            clone.neighbors.append(dfs(neighbor))
        return clone
    return dfs(node)

if __name__ == "__main__":

    # 测试用例
    result = clone_graph(None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
unordered_map<Node*, Node*> mp;
Node* cloneGraph(Node* node) {
    if (!node) return nullptr;
    if (mp.count(node)) return mp[node];
    Node* clone = new Node(node->val);
    mp[node] = clone;
    for (Node* n : node->neighbors)
        clone->neighbors.push_back(cloneGraph(n));
    return clone;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- DFS + 哈希表记录已克隆节点
- 时间复杂度 O(n)，空间 O(n)

---

### 417. 太平洋大西洋水流问题 (Pacific Atlantic Water Flow)

**Python 实现**:
```python
def pacific_atlantic(heights: list[list[int]]) -> list[list[int]]:
    if not heights:
        return []
    m, n = len(heights), len(heights[0])
    pac = [[False] * n for _ in range(m)]
    atl = [[False] * n for _ in range(m)]
    def dfs(r, c, visited, prev_h):
        if r < 0 or r >= m or c < 0 or c >= n or visited[r][c] or heights[r][c] < prev_h:
            return
        visited[r][c] = True
        for dr, dc in [(0,1),(0,-1),(1,0),(-1,0)]:
            dfs(r+dr, c+dc, visited, heights[r][c])
    for c in range(n): dfs(0, c, pac, 0)
    for r in range(m): dfs(r, 0, pac, 0)
    for c in range(n): dfs(m-1, c, atl, 0)
    for r in range(m): dfs(r, n-1, atl, 0)
    return [[r, c] for r in range(m) for c in range(n) if pac[r][c] and atl[r][c]]

if __name__ == "__main__":

    # 测试用例
    result = pacific_atlantic([1, 8, 6, 2, 5, 4, 8, 3, 7])
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
    int m = h.size(), n = h[0].size();
    vector<vector<char>> pac(m, vector<char>(n, 0)), atl(m, vector<char>(n, 0));
    function<void(int,int,vector<vector<char>>&,int)> dfs = [&](int r,int c,vector<vector<char>>& v,int h0){
        if (r<0||r>=m||c<0||c>=n||v[r][c]||h[r][c]<h0) return;
        v[r][c] = 1;
        for (auto& d : vector<pair<int,int>>{{0,1},{0,-1},{1,0},{-1,0}}) dfs(r+d.first,c+d.second,v,h[r][c]);
    };
    for (int c=0;c<n;c++) dfs(0,c,pac,0);
    for (int r=0;r<m;r++) dfs(r,0,pac,0);
    for (int c=0;c<n;c++) dfs(m-1,c,atl,0);
    for (int r=0;r<m;r++) dfs(r,n-1,atl,0);
    vector<vector<int>> result;
    for (int r=0;r<m;r++) for (int c=0;c<n;c++) if (pac[r][c] && atl[r][c]) result.push_back({r,c});
    return result;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

---

### 130. 被围绕的区域 (Surrounded Regions)

**Python 实现**:
```python
def solve(board: list[list[str]]) -> None:
    if not board:
        return
    m, n = len(board), len(board[0])
    def dfs(r, c):
        if r < 0 or r >= m or c < 0 or c >= n or board[r][c] != 'O':
            return
        board[r][c] = '#'
        for dr, dc in [(0,1),(0,-1),(1,0),(-1,0)]:
            dfs(r+dr, c+dc)
    for c in range(n): dfs(0, c); dfs(m-1, c)
    for r in range(m): dfs(r, 0); dfs(r, n-1)
    for r in range(m):
        for c in range(n):
            if board[r][c] == '#': board[r][c] = 'O'
            elif board[r][c] == 'O': board[r][c] = 'X'

if __name__ == "__main__":

    # 测试用例
    result = solve(None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <vector>

void solve(vector<vector<char>>& board) {
    if (board.empty()) return;
    int m = board.size(), n = board[0].size();
    function<void(int,int)> dfs = [&](int r, int c){
        if (r<0||r>=m||c<0||c>=n||board[r][c]!='O') return;
        board[r][c] = '#';
        for (auto& d : vector<pair<int,int>>{{0,1},{0,-1},{1,0},{-1,0}}) dfs(r+d.first,c+d.second);
    };
    for (int c=0;c<n;c++) { dfs(0,c); dfs(m-1,c); }
    for (int r=0;r<m;r++) { dfs(r,0); dfs(r,n-1); }
    for (int r=0;r<m;r++) for (int c=0;c<n;c++) {
        if (board[r][c]=='#') board[r][c]='O';
        else if (board[r][c]=='O') board[r][c]='X';
    }
}
int main() {
    // 测试用例
    solve(0);
    return 0;
}

```

**算法详解**:
- 从四边 O 开始 DFS，将所有与边界相连的 O 标记为 #
- 其余 O 被 X 包围，转换为 X
- 时间复杂度 O(mn)

---

### 695. 岛屿的最大面积 (Max Area of Island)

**Python 实现**:
```python
def max_area_of_island(grid: list[list[int]]) -> int:
    m, n = len(grid), len(grid[0])
    def dfs(r, c):
        if r < 0 or r >= m or c < 0 or c >= n or grid[r][c] == 0:
            return 0
        grid[r][c] = 0
        return 1 + dfs(r+1,c) + dfs(r-1,c) + dfs(r,c+1) + dfs(r,c-1)
    max_area = 0
    for r in range(m):
        for c in range(n):
            if grid[r][c] == 1:
                max_area = max(max_area, dfs(r, c))
    return max_area

if __name__ == "__main__":

    # 测试用例
    result = max_area_of_island([[1, 3, 1], [1, 5, 1], [4, 2, 1]])
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), area = 0;
    function<int(int,int)> dfs = [&](int r, int c) -> int {
        if (r<0||r>=m||c<0||c>=n||grid[r][c]==0) return 0;
        grid[r][c] = 0;
        return 1 + dfs(r+1,c) + dfs(r-1,c) + dfs(r,c+1) + dfs(r,c-1);
    };
    for (int r=0;r<m;r++) for (int c=0;c<n;c++) if (grid[r][c]) area = max(area, dfs(r,c));
    return area;
}
int main() {
    // 测试用例
    cout << maxAreaOfIsland({{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}) << endl;
    return 0;
}

```

**算法详解**:
- DFS 遍历岛屿面积
- 时间复杂度 O(mn)

---

### 200. 岛屿数量 (Number of Islands)

**Python 实现**:
```python
def num_islands(grid: list[list[str]]) -> int:
    if not grid:
        return 0
    m, n = len(grid), len(grid[0])
    count = 0
    def dfs(r, c):
        if r < 0 or r >= m or c < 0 or c >= n or grid[r][c] == '0':
            return
        grid[r][c] = '0'
        for dr, dc in [(0,1),(0,-1),(1,0),(-1,0)]:
            dfs(r+dr, c+dc)
    for r in range(m):
        for c in range(n):
            if grid[r][c] == '1':
                count += 1
                dfs(r, c)
    return count

if __name__ == "__main__":

    # 测试用例
    result = num_islands([[1, 3, 1], [1, 5, 1], [4, 2, 1]])
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <vector>

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size(), count = 0;
    function<void(int,int)> dfs = [&](int r, int c){
        if (r<0||r>=m||c<0||c>=n||grid[r][c]=='0') return;
        grid[r][c] = '0';
        for (auto& d : vector<pair<int,int>>{{0,1},{0,-1},{1,0},{-1,0}}) dfs(r+d.first,c+d.second);
    };
    for (int r=0;r<m;r++) for (int c=0;c<n;c++) if (grid[r][c]=='1'){ count++; dfs(r,c); }
    return count;
}
int main() {
    // 测试用例
    cout << numIslands({{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}) << endl;
    return 0;
}

```

**算法详解**:
- DFS/BFS 遍历所有相连的 1，每找到一个新的岛屿起点 count++
- 时间复杂度 O(mn)

---

### 463. 岛屿的周长 (Island Perimeter)

**Python 实现**:
```python
def island_perimeter(grid: list[list[int]]) -> int:
    m, n = len(grid), len(grid[0])
    perimeter = 0
    for r in range(m):
        for c in range(n):
            if grid[r][c] == 1:
                if r == 0 or grid[r-1][c] == 0: perimeter += 1
                if r == m-1 or grid[r+1][c] == 0: perimeter += 1
                if c == 0 or grid[r][c-1] == 0: perimeter += 1
                if c == n-1 or grid[r][c+1] == 0: perimeter += 1
    return perimeter

if __name__ == "__main__":

    # 测试用例
    result = island_perimeter([[1, 3, 1], [1, 5, 1], [4, 2, 1]])
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <vector>

int islandPerimeter(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), perimeter = 0;
    for (int r=0;r<m;r++) for (int c=0;c<n;c++) if (grid[r][c]==1){
        if (r==0||grid[r-1][c]==0) perimeter++;
        if (r==m-1||grid[r+1][c]==0) perimeter++;
        if (c==0||grid[r][c-1]==0) perimeter++;
        if (c==n-1||grid[r][c+1]==0) perimeter++;
    }
    return perimeter;
}
int main() {
    // 测试用例
    cout << islandPerimeter({{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}) << endl;
    return 0;
}

```

---

## 十四、数学与位运算（Math & Bit Manipulation）

### 136. 只出现一次的数字 (Single Number)

**Python 实现**:
```python
def single_number(nums: list[int]) -> int:
    result = 0
    for num in nums:
        result ^= num
    return result

if __name__ == "__main__":

    # 测试用例
    result = single_number([1, 2, 3])
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <vector>

int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) result ^= num;
    return result;
}
int main() {
    // 测试用例
    cout << singleNumber({1, 2, 3}) << endl;
    return 0;
}

```

**算法详解**:
- 异或：a^a=0，a^0=a，满足交换律
- 所有出现两次的数字异或后为 0，唯一出现一次的就是结果
- 时间复杂度 O(n)，空间 O(1)

---

### 137. 只出现一次的数字 II (Single Number II)

**Python 实现**:
```python
def single_number_ii(nums: list[int]) -> int:
    seen_once = seen_twice = 0
    for num in nums:
        seen_once = (seen_once ^ num) & ~seen_twice
        seen_twice = (seen_twice ^ num) & ~seen_once
    return seen_once

if __name__ == "__main__":

    # 测试用例
    result = single_number_ii([1, 2, 3])
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <vector>

int singleNumberII(vector<int>& nums) {
    int seen_once = 0, seen_twice = 0;
    for (int num : nums) {
        seen_once = (seen_once ^ num) & ~seen_twice;
        seen_twice = (seen_twice ^ num) & ~seen_once;
    }
    return seen_once;
}
int main() {
    // 测试用例
    cout << singleNumberII({1, 2, 3}) << endl;
    return 0;
}

```

**算法详解**:
- 有限状态机：每一位 bit 出现 1 次、2 次、3 次分别对应状态
- 三次后回到 0
- 时间复杂度 O(n)，空间 O(1)

---

### 268. 丢失的数字 (Missing Number)

**Python 实现**:
```python
def missing_number(nums: list[int]) -> int:
    result = len(nums)
    for i, num in enumerate(nums):
        result ^= i ^ num
    return result

if __name__ == "__main__":

    # 测试用例
    result = missing_number([1, 2, 3])
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <vector>

int missingNumber(vector<int>& nums) {
    int res = nums.size();
    for (int i = 0; i < nums.size(); i++) res ^= i ^ nums[i];
    return res;
}
int main() {
    // 测试用例
    cout << missingNumber({1, 2, 3}) << endl;
    return 0;
}

```

**算法详解**:
- 异或：0..n 与数组所有元素异或，缺失的数字只出现一次

---

### 190. 颠倒二进制位 (Reverse Bits)

**Python 实现**:
```python
def reverse_bits(n: int) -> int:
    result = 0
    for i in range(32):
        result = (result << 1) | (n & 1)
        n >>= 1
    return result

if __name__ == "__main__":

    # 测试用例
    result = reverse_bits(3)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; i++)
        result = (result << 1) | (n >> i & 1);
    return result;
}
int main() {
    // 测试用例
    cout << reverseBits(9) << endl;
    return 0;
}

```

---

### 191. 位1的个数 (Number of 1 Bits)

**Python 实现**:
```python
def hamming_weight(n: int) -> int:
    count = 0    while n:
        n &= n - 1
        count += 1
    return count

if __name__ == "__main__":

    # 测试用例
    result = hamming_weight(3)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>

int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) { n &= n - 1; count++; }
    return count;
}
int main() {
    // 测试用例
    cout << hammingWeight(9) << endl;
    return 0;
}

```

**算法详解**:
- n & (n-1) 消除最低位的 1

---

### 201. 数字范围的按位与 (Bitwise AND of Numbers Range)

**Python 实现**:
```python
def range_bitwise_and(left: int, right: int) -> int:
    shift = 0
    while left < right:
        left >>= 1
        right >>= 1
        shift += 1
    return left << shift

if __name__ == "__main__":

    # 测试用例
    result = range_bitwise_and(None, None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>

int rangeBitwiseAnd(int left, int right) {
    int shift = 0;
    while (left < right) {
        left >>= 1;
        right >>= 1;
        shift++;
    }
    return left << shift;
}
int main() {
    // 测试用例
    cout << rangeBitwiseAnd(0, 0) << endl;
    return 0;
}

```

**算法详解**:
- 找公共前缀：left 和 right 右移直到相等
- 剩余公共前缀左移回来

---

### 338. 比特位计数 (Counting Bits)

**Python 实现**:
```python
def count_bits(n: int) -> list[int]:
    dp = [0] * (n + 1)
    for i in range(1, n + 1):
        dp[i] = dp[i >> 1] + (i & 1)
    return dp

if __name__ == "__main__":

    # 测试用例
    result = count_bits(3)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <vector>
using namespace std;
vector<int> countBits(int n) {
    vector<int> dp(n+1, 0);
    for (int i = 1; i <= n; i++)
        dp[i] = dp[i>>1] + (i & 1);
    return dp;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- dp[i] = dp[i/2] + (i%2)，利用前一个数的结果
- 时间复杂度 O(n)

---

### 172. 阶乘后的零 (Factorial Trailing Zeroes)

**Python 实现**:
```python
def trailing_zeroes(n: int) -> int:
    count = 0
    while n:
        n //= 5
        count += n
    return count

if __name__ == "__main__":

    # 测试用例
    result = trailing_zeroes(3)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>

int trailingZeroes(int n) {
    int count = 0;
    while (n) {
        n /= 5;
        count += n;
    }
    return count;
}
int main() {
    // 测试用例
    cout << trailingZeroes(9) << endl;
    return 0;
}

```

**算法详解**:
- 末尾 0 的数量 = min(2,5) 的因子个数，只需求 5 的因子数

---

### 50. Pow(x, n) (Pow(x, n))

**Python 实现**:
```python
def my_pow(x: float, n: int) -> float:
    if n < 0:
        x = 1 / x
        n = -n
    result = 1.0
    cur = x
    while n:
        if n % 2 == 1:
            result *= cur
        cur *= cur
        n //= 2
    return result

if __name__ == "__main__":

    # 测试用例
    result = my_pow(None, 3)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>

double myPow(double x, long long n) {
    if (n < 0) { x = 1/x; n = -n; }
    double result = 1.0, cur = x;
    while (n) {
        if (n % 2 == 1) result *= cur;
        cur *= cur;
        n /= 2;
    }
    return result;
}
int main() {
    // 测试用例
    cout << myPow(0, 9) << endl;
    return 0;
}

```

**算法详解**:
- 快速幂（binary exponentiation）
- n 折半，底数平方
- 时间复杂度 O(log n)

---

### 149. 直线上最多的点数 (Max Points on a Line)

**Python 实现**:
```python
import math
from collections import defaultdict

def max_points(points: list[list[int]]) -> int:
    n = len(points)
    if n <= 2:
        return n
    max_count = 0
    for i in range(n):
        slopes = defaultdict(int)
        same = 1
        for j in range(i+1, n):
            dx = points[j][0] - points[i][0]
            dy = points[j][1] - points[i][1]
            if dx == 0 and dy == 0:
                same += 1
            else:
                g = math.gcd(dx, dy)
                slope = (dx // g, dy // g)
                slopes[slope] += 1
        max_count = max(max_count, same + (max(slopes.values()) if slopes else 0))
    return max_count

if __name__ == "__main__":

    # 测试用例
    result = max_points(None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

int maxPoints(vector<vector<int>>& points) {
    int n = points.size();
    if (n <= 2) return n;
    int result = 0;
    for (int i = 0; i < n; i++) {
        unordered_map<long long, int> mp;
        int same = 1;
        for (int j = i+1; j < n; j++) {
            long long dx = points[j][0] - points[i][0];
            long long dy = points[j][1] - points[i][1];
            if (dx == 0 && dy == 0) { same++; continue; }
            long long g = std::gcd(dx, dy);
            dx /= g; dy /= g;
            long long key = dx * 2000 + dy;
            mp[key]++;
        }
        int local_max = same;
        for (auto& kv : mp) local_max = max(local_max, same + kv.second);
        result = max(result, local_max);
    }
    return result;
}
int main() {
    // 测试用例
    cout << maxPoints(0) << endl;
    return 0;
}

```

**算法详解**:
- 以每个点为基准，计算与其他点的斜率
- 约化分数避免精度问题
- 时间复杂度 O(n^2)

---

### 223. 矩形面积 (Rectangle Area)

**Python 实现**:
```python
def compute_area(ax1: int, ay1: int, ax2: int, ay2: int,
                 bx1: int, by1: int, bx2: int, by2: int) -> int:
    area1 = (ax2 - ax1) * (ay2 - ay1)
    area2 = (bx2 - bx1) * (by2 - by1)
    overlap = max(0, min(ax2, bx2) - max(ax1, bx1)) * max(0, min(ay2, by2) - max(ay1, by1))
    return area1 + area2 - overlap

if __name__ == "__main__":

    # 测试用例
    result = compute_area(None, None, None, None, None, None, None, None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>

int computeArea(int ax1, int ay1, int ax2, int ay2,
               int bx1, int by1, int bx2, int by2) {
    long long area1 = 1LL*(ax2-ax1)*(ay2-ay1);
    long long area2 = 1LL*(bx2-bx1)*(by2-by1);
    long long overlap = max(0, min(ax2,bx2)-max(ax1,bx1)) * max(0, min(ay2,by2)-max(ay1,by1));
    return area1 + area2 - overlap;
}
int main() {
    // 测试用例
    cout << computeArea(0, 0, 0, 0, 0, 0, 0, 0) << endl;
    return 0;
}

```

**算法详解**:
- 两矩形面积和减去重叠面积

---

### 1269. 停在原地的方案数 (Number of Ways to Stay in the Same Place)

**Python 实现**:
```python
def num_ways(steps: int, arr_len: int) -> int:
    MOD = 10**9 + 7
    max_pos = min(steps // 2, arr_len - 1)
    dp = [0] * (max_pos + 1)
    dp[0] = 1
    for _ in range(1, steps + 1):
        new_dp = [0] * (max_pos + 1)
        for pos in range(max_pos + 1):
            new_dp[pos] = (new_dp[pos] + dp[pos]) % MOD
            if pos > 0: new_dp[pos] = (new_dp[pos] + dp[pos-1]) % MOD
            if pos < max_pos: new_dp[pos] = (new_dp[pos] + dp[pos+1]) % MOD
        dp = new_dp
    return dp[0]

if __name__ == "__main__":

    # 测试用例
    result = num_ways(None, None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int numWays(int steps, int arrLen) {
    int maxPos = min(steps/2, arrLen-1);
    vector<int> dp(maxPos+1, 0), ndp(maxPos+1, 0);
    dp[0] = 1;
    const int MOD = 1e9+7;
    for (int s = 1; s <= steps; s++) {
        fill(ndp.begin(), ndp.end(), 0);
        for (int p = 0; p <= maxPos; p++) {
            ndp[p] = (ndp[p] + dp[p]) % MOD;
            if (p > 0) ndp[p] = (ndp[p] + dp[p-1]) % MOD;
            if (p < maxPos) ndp[p] = (ndp[p] + dp[p+1]) % MOD;
        }
        dp.swap(ndp);
    }
    return dp[0];
}
int main() {
    // 测试用例
    cout << numWays(0, 0) << endl;
    return 0;
}

```

**算法详解**:
- DP[i][p] = 第 i 步走到位置 p 的方案数
- 位置不能超过 maxPos = min(steps/2, arr_len-1)
- 时间复杂度 O(steps * maxPos)

---

## 十五、字符串（String）

### 28. 找出字符串中第一个匹配项的下标 (Find the Index of the First Occurrence in a String)

**Python 实现**:
```python
def str_str(haystack: str, needle: str) -> int:
    return haystack.find(needle)

if __name__ == "__main__":

    # 测试用例
    result = str_str(None, None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <stack>
#include <string>

int strStr(string haystack, string needle) {
    return haystack.find(needle);
}
int main() {
    // 测试用例
    cout << strStr(0, 0) << endl;
    return 0;
}

```

---

### 14. 最长公共前缀 (Longest Common Prefix)

**Python 实现**:
```python
def longest_common_prefix(strs: list[str]) -> str:
    if not strs:
        return ''
    for i in range(len(strs[0])):
        for j in range(1, len(strs)):
            if i >= len(strs[j]) or strs[j][i] != strs[0][i]:
                return strs[0][:i]
    return strs[0]

if __name__ == "__main__":

    # 测试用例
    result = longest_common_prefix(None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <string>
#include <vector>

string longestCommonPrefix(vector<string>& strs) {
    for (int i = 0; i < strs[0].size(); i++) {
        for (int j = 1; j < strs.size(); j++)
            if (i >= strs[j].size() || strs[j][i] != strs[0][i])
                return strs[0].substr(0, i);
    }
    return strs[0];
}
int main() {
    // 测试用例
    cout << longestCommonPrefix({"abc"}) << endl;
    return 0;
}

```

**算法详解**:
- 纵向扫描：逐字符比较所有字符串
- 时间复杂度 O(n * L)

---

### 68. 文本左右对齐 (Text Justification)

**Python 实现**:
```python
def full_justify(words: list[str], max_width: int) -> list[str]:
    result = []
    i = 0
    while i < len(words):
        line_words = [words[i]]
        line_len = len(words[i])
        j = i + 1
        while j < len(words) and line_len + 1 + len(words[j]) <= max_width:
            line_len += 1 + len(words[j])
            line_words.append(words[j])
            j += 1
        if j - i == 1:
            result.append(line_words[0] + ' ' * (max_width - len(line_words[0])))
        else:
            spaces = max_width - line_len + (j - i - 1)
            extra = spaces % (j - i - 1)
            base = spaces // (j - i - 1)
            line = line_words[0]
            for k in range(1, j - i):
                line += ' ' * (base + (1 if k <= extra else 0)) + line_words[k]
            result.append(line)
        i = j
    return result

if __name__ == "__main__":

    # 测试用例
    result = full_justify(None, None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    int i = 0;
    while (i < words.size()) {
        int j = i + 1, lineLen = words[i].size();
        while (j < words.size() && lineLen + 1 + words[j].size() <= maxWidth)
            lineLen += 1 + words[j++].size();
        int spaces = maxWidth - lineLen, cnt = j - i - 1;
        string line = words[i];
        for (int k = 1; k < j - i; k++) {
            int sp = cnt > 0 ? spaces / cnt : spaces;
            line += string(sp + 1, ' ') + words[i + k];
            spaces -= sp; cnt--;
        }
        if (cnt == 0) line += string(maxWidth - line.size(), ' ');
        result.push_back(line);
        i = j;
    }
    return result;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

---

### 58. 最后一个单词的长度 (Length of Last Word)

**Python 实现**:
```python
def length_of_last_word(s: str) -> int:
    words = s.strip().split()
    return len(words[-1]) if words else 0

if __name__ == "__main__":

    # 测试用例
    result = length_of_last_word("abcabcbb")
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <string>

int lengthOfLastWord(string s) {
    int n = s.size(), len = 0;
    for (int i = n-1; i >= 0; i--) {
        if (s[i] != ' ') len++;
        else if (len > 0) break;
    }
    return len;
}
int main() {
    // 测试用例
    cout << lengthOfLastWord({"abc"}) << endl;
    return 0;
}

```

---

### 434. 字符串中的单词数 (Number of Segments in a String)

**Python 实现**:
```python
def count_segments(s: str) -> int:
    return len([w for w in s.split() if w])

if __name__ == "__main__":

    # 测试用例
    result = count_segments("abcabcbb")
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <string>

int countSegments(string s) {
    int count = 0;
    stringstream ss(s);
    string word;
    while (ss >> word) count++;
    return count;
}
int main() {
    // 测试用例
    cout << countSegments({"abc"}) << endl;
    return 0;
}

```

---

### 151. 反转字符串中的单词 (Reverse Words in a String)

**Python 实现**:
```python
def reverse_words(s: str) -> str:
    return ' '.join(s.strip().split()[::-1])

if __name__ == "__main__":

    # 测试用例
    result = reverse_words("abcabcbb")
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <string>

string reverseWords(string s) {
    istringstream iss(s);
    string word, result;
    while (iss >> word) {
        if (!result.empty()) result += ' ';
        result = word + (result.empty() ? "" : " " + result);
    }
    return result;
}
int main() {
    // 测试用例
    cout << reverseWords({"abc"}) << endl;
    return 0;
}

```

**算法详解**:
- split + reverse + join

---

### 186. 翻转字符串里的单词 II (Reverse Words in a String II)

**Python 实现**:
```python
def reverse_words(s: list[str]) -> None:
    s.reverse()
    i = 0
    for j in range(len(s) + 1):
        if j == len(s) or s[j] == ' ':
            l, r = i, j - 1
            while l < r:
                s[l], s[r] = s[r], s[l]
                l += 1
                r -= 1
            i = j + 1

if __name__ == "__main__":

    # 测试用例
    result = reverse_words("abcabcbb")
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <vector>

void reverseWords(vector<char>& s) {
    reverse(s.begin(), s.end());
    int i = 0;
    for (int j = 0; j <= s.size(); j++) {
        if (j == s.size() || s[j] == ' ') {
            reverse(s.begin()+i, s.begin()+j);
            i = j + 1;
        }
    }
}
int main() {
    // 测试用例
    reverseWords({"abc"});
    return 0;
}

```

---

### 709. 转换成小写字母 (To Lower Case)

**Python 实现**:
```python
def to_lower_case(s: str) -> str:
    return s.lower()

if __name__ == "__main__":

    # 测试用例
    result = to_lower_case("abcabcbb")
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <string>

string toLowerCase(string s) {
    for (char& c : s) if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
    return s;
}
int main() {
    // 测试用例
    cout << toLowerCase({"abc"}) << endl;
    return 0;
}

```

---

### 520. 检测大写字母 (Detect Capital)

**Python 实现**:
```python
def detect_capital_use(word: str) -> bool:
    return word.isupper() or word.islower() or (word[0].isupper() and word[1:].islower())

if __name__ == "__main__":

    # 测试用例
    result = detect_capital_use("apple")
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <string>

bool detectCapitalUse(string word) {
    int n = word.size();
    bool firstUpper = isupper(word[0]);
    bool allUpper = true, allLower = true;
    for (int i = 1; i < n; i++) {
        if (isupper(word[i])) allLower = false;
        else allUpper = false;
    }
    return allUpper || allLower || (firstUpper && allLower);
}
int main() {
    // 测试用例
    cout << detectCapitalUse({"abc"}) << endl;
    return 0;
}

```

---

## 十六、设计（Design）

### 146. LRU 缓存 (LRU Cache)

**Python 实现**:
```python
from collections import OrderedDict

class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = OrderedDict()
    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        self.cache.move_to_end(key)
        return self.cache[key]
    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.cache.move_to_end(key)
        self.cache[key] = value
        if len(self.cache) > self.capacity:
            self.cache.popitem(last=False)

if __name__ == "__main__":

    # 测试用例
    result = __init__(None, 2)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class LRUCache {
    int capacity;
    list<pair<int,int>> lst;
    unordered_map<int, list<pair<int,int>>::iterator> mp;
public:
    LRUCache(int c): capacity(c) {}
    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) return -1;
        lst.splice(lst.begin(), lst, it->second);
        return it->second->second;
    }
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key]->second = value;
            lst.splice(lst.begin(), lst, mp[key]);
        } else {
            lst.push_front({key, value});
            mp[key] = lst.begin();
            if (lst.size() > capacity) {
                mp.erase(lst.back().first);
                lst.pop_back();
            }
        }
    }
};

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 哈希表 + 双向链表：O(1) get 和 put
- Python 可用 OrderedDict

---

### 225. 用队列实现栈 (Implement Stack using Queues)

**Python 实现**:
```python
from collections import deque

class MyStack:
    def __init__(self):
        self.q = deque()
    def push(self, x: int) -> None:
        self.q.append(x)
        for _ in range(len(self.q) - 1):
            self.q.append(self.q.popleft())
    def pop(self) -> int:
        return self.q.popleft()
    def top(self) -> int:
        return self.q[0]
    def empty(self) -> bool:
        return not self.q

if __name__ == "__main__":

    # 测试用例
    result = __init__(None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <queue>
#include <stack>

class MyStack {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        for (int i = 0; i < (int)q.size()-1; i++) { q.push(q.front()); q.pop(); }
    }
    int pop() { int v = q.front(); q.pop(); return v; }
    int top() { return q.front(); }
    bool empty() { return q.empty(); }
};
int main() {
    // 测试用例
    push(0, 0);
    return 0;
}

```

---

### 232. 用栈实现队列 (Implement Queue using Stacks)

**Python 实现**:
```python
class MyQueue:
    def __init__(self):
        self.s1 = []
        self.s2 = []
    def push(self, x: int) -> None:
        self.s1.append(x)
    def pop(self) -> int:
        if not self.s2:
            while self.s1:
                self.s2.append(self.s1.pop())
        return self.s2.pop()
    def peek(self) -> int:
        if not self.s2:
            while self.s1:
                self.s2.append(self.s1.pop())
        return self.s2[-1]
    def empty(self) -> bool:
        return not self.s1 and not self.s2

if __name__ == "__main__":

    # 测试用例
    result = __init__(None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <queue>
#include <stack>

class MyQueue {
    stack<int> s1, s2;
public:
    void push(int x) { s1.push(x); }
    int pop() {
        if (s2.empty()) while(!s1.empty()){ s2.push(s1.top()); s1.pop(); }
        int v = s2.top(); s2.pop(); return v;
    }
    int peek() {
        if (s2.empty()) while(!s1.empty()){ s2.push(s1.top()); s1.pop(); }
        return s2.top();
    }
    bool empty() { return s1.empty() && s2.empty(); }
};
int main() {
    // 测试用例
    push(0, 0);
    return 0;
}

```

---

### 380. O(1) 时间插入、删除和获取随机元素 (Insert Delete GetRandom O(1))

**Python 实现**:
```python
import random

class RandomizedSet:
    def __init__(self):
        self.val = []
        self.pos = {}
    def insert(self, val: int) -> bool:
        if val in self.pos:
            return False
        self.pos[val] = len(self.val)
        self.val.append(val)
        return True
    def remove(self, val: int) -> bool:
        if val not in self.pos:
            return False
        idx = self.pos[val]
        last = self.val[-1]
        self.val[idx] = last
        self.pos[last] = idx
        self.val.pop()
        del self.pos[val]
        return True
    def get_random(self) -> int:
        return random.choice(self.val)

if __name__ == "__main__":

    # 测试用例
    result = __init__(None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class RandomizedSet {
    vector<int> vals;
    unordered_map<int, int> pos;
public:
    bool insert(int val) {
        if (pos.count(val)) return false;
        pos[val] = vals.size();
        vals.push_back(val);
        return true;
    }
    bool remove(int val) {
        if (!pos.count(val)) return false;
        int idx = pos[val], last = vals.back();
        vals[idx] = last; pos[last] = idx;
        vals.pop_back(); pos.erase(val);
        return true;
    }
    int getRandom() { return vals[rand() % vals.size()]; }
};
int main() {
    // 测试用例
    cout << insert(0, 0) << endl;
    return 0;
}

```

**算法详解**:
- 数组存储值，哈希表存值到索引的映射
- 删除时用末尾元素覆盖，然后 pop
- 时间复杂度 O(1)，空间 O(n)

---

### 381. O(1) 时间插入、删除和获取随机元素 - 允许重复 (Insert Delete GetRandom O(1) - Duplicates allowed)

**Python 实现**:
```python
import random

class RandomizedCollection:
    def __init__(self):
        self.vals = []
        self.pos = {}
    def insert(self, val: int) -> bool:
        if val not in self.pos:
            self.pos[val] = set()
        first = len(self.pos[val]) == 0
        self.pos[val].add(len(self.vals))
        self.vals.append(val)
        return first
    def remove(self, val: int) -> bool:
        if not self.pos.get(val):
            return False
        idx = next(iter(self.pos[val]))
        last = self.vals[-1]
        self.vals[idx] = last
        self.pos[val].remove(idx)
        if idx != len(self.vals) - 1:
            self.pos[last].add(idx)
            self.pos[last].remove(len(self.vals) - 1)
        self.vals.pop()
        return True
    def get_random(self) -> int:
        return random.choice(self.vals)

if __name__ == "__main__":

    # 测试用例
    result = __init__(None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class RandomizedCollection {
    vector<int> vals;
    unordered_map<int, unordered_set<int>> pos;
public:
    bool insert(int val) {
        bool first = !pos.count(val) || pos[val].empty();
        pos[val].insert(vals.size());
        vals.push_back(val);
        return first;
    }
    bool remove(int val) {
        if (!pos.count(val) || pos[val].empty()) return false;
        int idx = *pos[val].begin();
        int last = vals.back();
        vals[idx] = last;
        pos[val].erase(idx);
        if (idx != vals.size()-1) {
            pos[last].insert(idx);
            pos[last].erase(vals.size()-1);
        }
        vals.pop_back();
        return true;
    }
    int getRandom() { return vals[rand() % vals.size()]; }
};
int main() {
    // 测试用例
    cout << insert(0, 0) << endl;
    return 0;
}

```

---

## 十七、拓扑排序（Topological Sort）

### 207. 课程表 (Course Schedule)

**Python 实现**:
```python
from collections import deque, defaultdict

def can_finish(num_courses: int, prerequisites: list[list[int]]) -> bool:
    graph = defaultdict(list)
    indegree = [0] * num_courses
    for u, v in prerequisites:
        graph[v].append(u)
        indegree[u] += 1
    queue = deque([i for i in range(num_courses) if indegree[i] == 0])
    count = 0
    while queue:
        course = queue.popleft()
        count += 1
        for neighbor in graph[course]:
            indegree[neighbor] -= 1
            if indegree[neighbor] == 0:
                queue.append(neighbor)
    return count == num_courses

if __name__ == "__main__":

    # 测试用例
    result = can_finish(None, [[1, 0]])
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <queue>
#include <vector>

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> indegree(numCourses, 0);
    for (auto& p : prerequisites) {
        graph[p[1]].push_back(p[0]);
        indegree[p[0]]++;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++) if (indegree[i] == 0) q.push(i);
    int count = 0;
    while (!q.empty()) {
        int course = q.front(); q.pop();
        count++;
        for (int neighbor : graph[course])
            if (--indegree[neighbor] == 0) q.push(neighbor);
    }
    return count == numCourses;
}
int main() {
    // 测试用例
    cout << canFinish(9, 0) << endl;
    return 0;
}

```

**算法详解**:
- BFS + Kahn 算法：统计入度，队列 BFS 拓扑排序
- 时间复杂度 O(V+E)，空间 O(V+E)

---

### 210. 课程表 II (Course Schedule II)

**Python 实现**:
```python
from collections import deque, defaultdict

def find_order(num_courses: int, prerequisites: list[list[int]]) -> list[int]:
    graph = defaultdict(list)
    indegree = [0] * num_courses
    for u, v in prerequisites:
        graph[v].append(u)
        indegree[u] += 1
    queue = deque([i for i in range(num_courses) if indegree[i] == 0])
    order = []
    while queue:
        course = queue.popleft()
        order.append(course)
        for neighbor in graph[course]:
            indegree[neighbor] -= 1
            if indegree[neighbor] == 0:
                queue.append(neighbor)
    return order if len(order) == num_courses else []

if __name__ == "__main__":

    # 测试用例
    result = find_order(None, [[1, 0]])
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <deque>
#include <queue>
#include <vector>
using namespace std;
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> indegree(numCourses, 0);
    for (auto& p : prerequisites) {
        graph[p[1]].push_back(p[0]);
        indegree[p[0]]++;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++) if (indegree[i] == 0) q.push(i);
    vector<int> order;
    while (!q.empty()) {
        int course = q.front(); q.pop();
        order.push_back(course);
        for (int neighbor : graph[course])
            if (--indegree[neighbor] == 0) q.push(neighbor);
    }
    return order.size() == numCourses ? order : vector<int>();
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

---

## 十八、扫描线（Line Sweep）

### 218. 天际线问题 (The Skyline Problem)

**Python 实现**:
```python
import heapq

def get_skyline(buildings: list[list[int]]) -> list[list[int]]:
    events = []
    for l, r, h in buildings:
        events.append((l, -h, r))
        events.append((r, h, 0))
    events.sort()
    result = []
    heap = [(0, float('inf'))]
    for x, neg_h, r in events:
        h = -neg_h
        if neg_h < 0:
            if h > -heap[0][0]:
                result.append([x, h])
            heapq.heappush(heap, (-h, r))
        else:
            while heap and heap[0][1] <= r:
                heapq.heappop(heap)
            if -heap[0][0] != (result[-1][1] if result else 0):
                result.append([x, -heap[0][0]])
    return result

if __name__ == "__main__":

    # 测试用例
    result = get_skyline(None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<array<long,3>> events;
    for (auto& b : buildings) {
        events.push_back({b[0], -b[2], b[1]});
        events.push_back({b[1], b[2], 0});
    }
    sort(events.begin(), events.end());
    vector<vector<int>> result;
    priority_queue<pair<int,int>> pq;
    pq.push({0, INT_MAX});
    for (auto& e : events) {
        long x = e[0], h = -e[1], r = e[2];
        if (h > 0) {
            if (h > pq.top().first) result.push_back({(int)x, (int)h});
            pq.push({(int)h, (int)r});
        } else {
            while (!pq.empty() && pq.top().second <= r) pq.pop();
            int currH = pq.top().first;
            if (result.empty() || currH != result.back()[1])
                result.push_back({(int)x, currH});
        }
    }
    return result;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 事件点：建筑左侧（负高，入堆），右侧（正高，出堆）
- 堆维护当前最高建筑
- 时间复杂度 O(n log n)

---

## 十九、前缀和（Prefix Sum）

### 560. 和为 K 的子数组 (Subarray Sum Equals K)

**Python 实现**:
```python
def subarray_sum(nums: list[int], k: int) -> int:
    count = 0
    prefix = 0
    prefix_count = {0: 1}
    for num in nums:
        prefix += num
        count += prefix_count.get(prefix - k, 0)
        prefix_count[prefix] = prefix_count.get(prefix, 0) + 1
    return count

if __name__ == "__main__":

    # 测试用例
    result = subarray_sum([1, 2, 3], 2)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;
    int prefix = 0, count = 0;
    for (int num : nums) {
        prefix += num;
        count += prefixCount[prefix - k];
        prefixCount[prefix]++;
    }
    return count;
}
int main() {
    // 测试用例
    cout << subarraySum({1, 2, 3}, 9) << endl;
    return 0;
}

```

**算法详解**:
- 前缀和哈希表：prefix - k 出现过多少次
- 时间复杂度 O(n)，空间 O(n)

---

### 1248. 统计「优美子数组」(Count Number of Nice Subarrays)

**Python 实现**:
```python
def number_of_subarrays(nums: list[int], k: int) -> int:
    prefix = 0
    prefix_count = {0: 1}
    count = 0
    for num in nums:
        prefix += num % 2
        count += prefix_count.get(prefix - k, 0)
        prefix_count[prefix] = prefix_count.get(prefix, 0) + 1
    return count

if __name__ == "__main__":

    # 测试用例
    result = number_of_subarrays([1, 2, 3], 2)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

int numberOfSubarrays(vector<int>& nums, int k) {
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;
    int prefix = 0, count = 0;
    for (int num : nums) {
        prefix += num & 1;
        count += prefixCount[prefix - k];
        prefixCount[prefix]++;
    }
    return count;
}
int main() {
    // 测试用例
    cout << numberOfSubarrays({1, 2, 3}, 9) << endl;
    return 0;
}

```

**算法详解**:
- 奇数映射为 1，偶数为 0
- 前缀和为奇数个数，转化为子数组和为 k 的问题

---

### 974. 和可被 K 整除的子数组 (Subarray Sums Divisible by K)

**Python 实现**:
```python
def subarrays_div_by_k(nums: list[int], k: int) -> int:
    prefix_mod = 0
    mod_count = [0] * k
    mod_count[0] = 1
    count = 0
    for num in nums:
        prefix_mod = (prefix_mod + num) % k
        if prefix_mod < 0:
            prefix_mod += k
        count += mod_count[prefix_mod]
        mod_count[prefix_mod] += 1
    return count

if __name__ == "__main__":

    # 测试用例
    result = subarrays_div_by_k([1, 2, 3], 2)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <vector>

int subarraysDivByK(vector<int>& nums, int k) {
    vector<int> modCount(k, 0);
    modCount[0] = 1;
    int prefixMod = 0, count = 0;
    for (int num : nums) {
        prefixMod = (prefixMod + num) % k;
        if (prefixMod < 0) prefixMod += k;
        count += modCount[prefixMod];
        modCount[prefixMod]++;
    }
    return count;
}
int main() {
    // 测试用例
    cout << subarraysDivByK({1, 2, 3}, 9) << endl;
    return 0;
}

```

**算法详解**:
- 若 prefix[i] % k == prefix[j] % k，则子数组 [i+1..j] 可被 K 整除

---

### 523. 连续的子数组和 (Continuous Subarray Sum)

**Python 实现**:
```python
def check_subarray_sum(nums: list[int], k: int) -> bool:
    prefix = 0
    prefix_index = {0: -1}
    for i, num in enumerate(nums):
        prefix = (prefix + num) % k
        if prefix in prefix_index:
            if i - prefix_index[prefix] > 1:
                return True
        else:
            prefix_index[prefix] = i
    return False

if __name__ == "__main__":

    # 测试用例
    result = check_subarray_sum([1, 2, 3], 2)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixIndex;
    prefixIndex[0] = -1;
    int prefix = 0;
    for (int i = 0; i < nums.size(); i++) {
        prefix = (prefix + nums[i]) % k;
        if (prefixIndex.count(prefix)) {
            if (i - prefixIndex[prefix] > 1) return true;
        } else {
            prefixIndex[prefix] = i;
        }
    }
    return false;
}
int main() {
    // 测试用例
    cout << checkSubarraySum({1, 2, 3}, 9) << endl;
    return 0;
}

```

**算法详解**:
- 前缀和 % k，若之前出现过相同余数则子数组和 % k == 0
- 子数组长度至少为 2

---

### 528. 按权重随机选择 (Random Pick with Weight)

**Python 实现**:
```python
import random

class Solution:
    def __init__(self, w: list[int]):
        self.prefix = []
        total = 0
        for weight in w:
            total += weight
            self.prefix.append(total)
        self.total = total
    def pick_index(self) -> int:
        target = random.randint(1, self.total)
        left, right = 0, len(self.prefix) - 1
        while left < right:
            mid = (left + right) // 2
            mid = (left + right) // 2
            if self.prefix[mid] >= target:
                right = mid
            else:
                left = mid + 1
        return left

if __name__ == "__main__":

    # 测试用例
    result = __init__(None, None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <vector>

class Solution {
    vector<int> prefix;
public:
    Solution(vector<int>& w) {
        for (int x : w) prefix.push_back((prefix.empty()?0:prefix.back()) + x);
    }
    int pickIndex() {
        int target = rand() % prefix.back() + 1;
        int left = 0, right = prefix.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (prefix[mid] >= target) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
int main() {
    // 测试用例
    cout << Solution(0) << endl;
    return 0;
}

```

**算法详解**:
- 前缀和 + 二分查找
- target 落在哪个区间就选哪个索引
- 时间复杂度 O(n) 初始化，O(log n) 查询

---

## 二十、单调栈（Monotonic Stack）

### 84. 柱状图中最大的矩形 (Largest Rectangle in Histogram)

（已在第五章栈与队列给出，见第 84 题）

---

### 85. 最大矩形 (Maximal Rectangle)

**Python 实现**:
```python
def maximal_rectangle(matrix: list[list[str]]) -> int:
    if not matrix:
        return 0
    heights = [0] * len(matrix[0])
    max_area = 0
    for row in matrix:
        for j, val in enumerate(row):
            heights[j] = heights[j] + 1 if val == '1' else 0
        stack = []
        for j, h in enumerate(heights + [0]):
            while stack and heights[stack[-1]] > h:
                height = heights[stack.pop()]
                width = j if not stack else j - stack[-1] - 1
                max_area = max(max_area, height * width)
            stack.append(j)
    return max_area

if __name__ == "__main__":

    # 测试用例
    result = maximal_rectangle([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int n = matrix[0].size(), max_area = 0;
    vector<int> heights(n, 0);
    for (auto& row : matrix) {
        for (int j = 0; j < n; j++)
            heights[j] = (row[j] == '1') ? heights[j] + 1 : 0;
        stack<int> st;
        for (int j = 0; j <= n; j++) {
            int h = j == n ? 0 : heights[j];
            while (!st.empty() && heights[st.top()] > h) {
                int height = heights[st.top()]; st.pop();
                int width = st.empty() ? j : j - st.top() - 1;
                max_area = max(max_area, height * width);
            }
            st.push(j);
        }
    }
    return max_area;
}
int main() {
    // 测试用例
    cout << maximalRectangle({{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}) << endl;
    return 0;
}

```

**算法详解**:
- 将每行视作直方图的底部，递推计算高度
- 转换为柱状图最大矩形问题
- 时间复杂度 O(mn)，空间 O(n)

---

### 739. 每日温度 (Daily Temperatures)

**Python 实现**:
```python
def daily_temperatures(temperatures: list[int]) -> list[int]:
    n = len(temperatures)
    result = [0] * n
    stack = []
    for i, temp in enumerate(temperatures):
        while stack and temperatures[stack[-1]] < temp:
            prev = stack.pop()
            result[prev] = i - prev
        stack.append(i)
    return result

if __name__ == "__main__":

    # 测试用例
    result = daily_temperatures(None)
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> result(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
            result[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    return result;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 单调递减栈，存索引
- 遇到更高温度时弹出并计算距离
- 时间复杂度 O(n)，空间 O(n)

---

### 503. 下一个更大元素 II (Next Greater Element II)

**Python 实现**:
```python
def next_greater_elements(nums: list[int]) -> list[int]:
    n = len(nums)
    result = [-1] * n
    stack = []
    for i in range(2 * n):
        while stack and nums[stack[-1]] < nums[i % n]:
            result[stack.pop()] = nums[i % n]
        if i < n:
            stack.append(i)
    return result

if __name__ == "__main__":

    # 测试用例
    result = next_greater_elements([1, 2, 3])
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;
    for (int i = 0; i < 2 * n; i++) {
        while (!st.empty() && nums[st.top()] < nums[i % n]) {
            result[st.top()] = nums[i % n];
            st.pop();
        }
        if (i < n) st.push(i);
    }
    return result;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 环形的数组展成两倍遍历
- 单调递减栈

---

### 42. 接雨水 (Trapping Rain Water)

（已在第二章双指针给出，见第 42 题）

---

### 496. 下一个更大元素 I (Next Greater Element I)

**Python 实现**:
```python
def next_greater_element(nums1: list[int], nums2: list[int]) -> list[int]:
    stack = []
    next_greater = {}
    for num in nums2:
        while stack and stack[-1] < num:
            next_greater[stack.pop()] = num
        stack.append(num)
    return [next_greater.get(num, -1) for num in nums1]

if __name__ == "__main__":

    # 测试用例
    result = next_greater_element([1, 2, 3], [1, 2, 3])
    print(f"Result: {result}")

```

**C++ 实现**:
```cpp
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> st;
    unordered_map<int, int> ng;
    for (int num : nums2) {
        while (!st.empty() && st.top() < num) {
            ng[st.top()] = num;
            st.pop();
        }
        st.push(num);
    }
    vector<int> result;
    for (int num : nums1) result.push_back(ng.count(num) ? ng[num] : -1);
    return result;
}

int main() {
    // 测试用例
    // (请根据具体函数签名补充测试)
    return 0;
}
```

**算法详解**:
- 单调递减栈构建哈希表
- 时间复杂度 O(n)

---
