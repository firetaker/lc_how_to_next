#include <iostream>
#include <vector>
#include <string>
using namespace std;

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
    vector<string> t1 = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(t1) << endl;  // 预期: fl
    vector<string> t2 = {"dog", "racecar", "car"};
    cout << longestCommonPrefix(t2) << endl;  // 预期: (空)
    vector<string> t3 = {"a"};
    cout << longestCommonPrefix(t3) << endl;  // 预期: a
    return 0;
}
