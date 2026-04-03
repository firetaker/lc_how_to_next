#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

/**
 * 49. 字母异位词分组 (Group Anagrams)
 * 题目: 给定字符串数组，将字母异位词分组返回。
 * 
 * 算法: 排序字符串作为 key，相同 key 的词为一组
 * 时间复杂度: O(n * k log k)，k 为字符串平均长度
 * 空间复杂度: O(n * k)
 */
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;
    for (const string& s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        groups[key].push_back(s);
    }
    vector<vector<string>> result;
    for (auto& [_, v] : groups) {
        result.push_back(v);
    }
    return result;
}

int main() {
    // 测试用例
    vector<string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto result1 = groupAnagrams(strs1);
    cout << "输入: [\"eat\", \"tea\", \"tan\", \"ate\", \"nat\", \"bat\"] -> 输出:" << endl;
    for (const auto& group : result1) {
        cout << "  [";
        for (size_t i = 0; i < group.size(); i++) {
            cout << "\"" << group[i] << "\"";
            if (i < group.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    // 预期: [['eat', 'tea', 'ate'], ['tan', 'nat'], ['bat']] 或类似分组
    
    vector<string> strs2 = {""};
    auto result2 = groupAnagrams(strs2);
    cout << "输入: [\"\"] -> 输出: " << result2.size() << " 组" << endl;  // 预期: 1 组
    
    vector<string> strs3 = {"a"};
    auto result3 = groupAnagrams(strs3);
    cout << "输入: [\"a\"] -> 输出: " << result3.size() << " 组" << endl;  // 预期: 1 组
    
    return 0;
}
