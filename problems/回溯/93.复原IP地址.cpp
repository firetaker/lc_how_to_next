#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isValid(const string& s, int start, int end) {
    if (end - start + 1 > 3) return false;
    if (end - start + 1 > 1 && s[start] == '0') return false;
    int num = 0;
    for (int i = start; i <= end; i++) {
        num = num * 10 + (s[i] - '0');
        if (num > 255) return false;
    }
    return true;
}

void backtrack(vector<string>& result, string& path,
               const string& s, int start, int parts) {
    if (parts == 4) {
        if (start == s.size()) {
            result.push_back(path);
        }
        return;
    }
    for (int i = start; i < s.size() && i < start + 3; i++) {
        if (isValid(s, start, i)) {
            string segment = s.substr(start, i - start + 1);
            string newPath = path.empty() ? segment : path + "." + segment;
            backtrack(result, newPath, s, i + 1, parts + 1);
        }
    }
}

vector<string> restoreIpAddresses(const string& s) {
    vector<string> result;
    string path;
    if (s.size() >= 4 && s.size() <= 12) {
        backtrack(result, path, s, 0, 1);
    }
    return result;
}

int main() {
    // 测试用例1
    vector<string> res1 = restoreIpAddresses("25525511135");
    cout << "Test 1: \"25525511135\"" << endl;
    for (auto& ip : res1) {
        cout << ip << " ";
    }
    cout << endl;
    
    // 测试用例2
    vector<string> res2 = restoreIpAddresses("0000");
    cout << "Test 2: \"0000\"" << endl;
    for (auto& ip : res2) {
        cout << ip << " ";
    }
    cout << endl;
    
    // 测试用例3
    vector<string> res3 = restoreIpAddresses("101023");
    cout << "Test 3: \"101023\" - " << res3.size() << " addresses" << endl;
    for (auto& ip : res3) {
        cout << ip << " ";
    }
    cout << endl;
    
    return 0;
}
