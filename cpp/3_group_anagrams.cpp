/**
 * LeetCode #49: 字母异位词分组
 * 题目: 给定一个字符串数组，将字母异位词组合在一起。
 * 解法: 哈希表 - 将每个字符串排序后作为 key，字母异位词排序后相同，
 *       因此可以加入同一组。
 * 时间 O(n * klogk)，空间 O(n*k)。k 为字符串平均长度。
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            groups[key].push_back(s);
        }
        vector<vector<string>> result;
        for (auto& kv : groups) {
            result.push_back(kv.second);
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto result = sol.groupAnagrams(strs);
    for (const auto& group : result) {
        cout << "[";
        for (int i = 0; i < group.size(); ++i) {
            cout << group[i];
            if (i < group.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}
