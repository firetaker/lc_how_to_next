#include <iostream>
#include <vector>
#include <string>
using namespace std;

void backtrack(vector<string>& result, string& path, int n, int open, int close) {
    if (path.size() == 2 * n) {
        result.push_back(path);
        return;
    }
    if (open < n) {
        path.push_back('(');
        backtrack(result, path, n, open + 1, close);
        path.pop_back();
    }
    if (close < open) {
        path.push_back(')');
        backtrack(result, path, n, open, close + 1);
        path.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    string path;
    backtrack(result, path, n, 0, 0);
    return result;
}

int main() {
    // 测试用例1
    vector<string> res1 = generateParenthesis(3);
    cout << "Test 1: n=3 - " << res1.size() << " combinations" << endl;
    for (auto& comb : res1) {
        cout << comb << " ";
    }
    cout << endl;
    
    // 测试用例2
    vector<string> res2 = generateParenthesis(1);
    cout << "Test 2: n=1" << endl;
    for (auto& comb : res2) {
        cout << comb << " ";
    }
    cout << endl;
    
    // 测试用例3
    vector<string> res3 = generateParenthesis(4);
    cout << "Test 3: n=4 - " << res3.size() << " combinations" << endl;
    
    return 0;
}
