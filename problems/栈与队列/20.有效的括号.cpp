#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

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
    cout << (is_valid("()") ? "True" : "False") << endl;      // 预期: True
    cout << (is_valid("()[]{}") ? "True" : "False") << endl;  // 预期: True
    cout << (is_valid("(]") ? "True" : "False") << endl;      // 预期: False
    cout << (is_valid("([)]") ? "True" : "False") << endl;   // 预期: False

    return 0;
}
