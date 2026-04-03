#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(const string& s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

void backtrack(vector<vector<string>>& result, vector<string>& path,
               const string& s, int start) {
    if (start == s.size()) {
        result.push_back(path);
        return;
    }
    for (int i = start; i < s.size(); i++) {
        if (isPalindrome(s, start, i)) {
            path.push_back(s.substr(start, i - start + 1));
            backtrack(result, path, s, i + 1);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(const string& s) {
    vector<vector<string>> result;
    vector<string> path;
    backtrack(result, path, s, 0);
    return result;
}

int main() {
    // 测试用例1
    vector<vector<string>> res1 = partition("aab");
    cout << "Test 1: s=\"aab\"" << endl;
    for (auto& partition : res1) {
        cout << "[";
        for (int i = 0; i < partition.size(); i++) {
            cout << "\"" << partition[i] << "\"";
            if (i < partition.size() - 1) cout << ",";
        }
        cout << "] ";
    }
    cout << endl;
    
    // 测试用例2
    vector<vector<string>> res2 = partition("a");
    cout << "Test 2: s=\"a\"" << endl;
    for (auto& partition : res2) {
        cout << "[";
        for (int i = 0; i < partition.size(); i++) {
            cout << "\"" << partition[i] << "\"";
            if (i < partition.size() - 1) cout << ",";
        }
        cout << "] ";
    }
    cout << endl;
    
    // 测试用例3
    vector<vector<string>> res3 = partition("abcba");
    cout << "Test 3: s=\"abcba\" - " << res3.size() << " partitions" << endl;
    
    return 0;
}
