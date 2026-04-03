#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/**
 * 139. 单词拆分 (Word Break)
 *
 * 判断字符串 s 是否可以由 wordDict 中的单词拼接而成。
 *
 * 动态规划思路：
 * - dp[i] 表示 s[0:i] 是否可以由 wordDict 拼接而成
 * - dp[i] = True if exists j in [0,i) such that dp[j] and s[j:i] in wordDict
 */
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    int n = s.size();

    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}

int main() {
    // 测试用例1: "leetcode", ["leet", "code"]
    vector<string> dict1 = {"leet", "code"};
    assert(wordBreak("leetcode", dict1) == true);
    cout << "测试1通过: leetcode -> true" << endl;

    // 测试用例2: "applepenapple", ["apple", "pen"]
    vector<string> dict2 = {"apple", "pen"};
    assert(wordBreak("applepenapple", dict2) == true);
    cout << "测试2通过: applepenapple -> true" << endl;

    // 测试用例3: 无法拆分
    vector<string> dict3 = {"cats", "dog", "sand", "and", "cat"};
    assert(wordBreak("catsandog", dict3) == false);
    cout << "测试3通过: catsandog -> false" << endl;

    cout << "所有测试用例通过!" << endl;
    return 0;
}
