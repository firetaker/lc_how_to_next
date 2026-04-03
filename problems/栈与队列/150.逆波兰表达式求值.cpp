#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cstdlib>
using namespace std;

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
    return (int)st.top();
}

int main() {
    // 测试用例
    vector<string> t1 = {"2", "1", "+", "3", "*"};
    cout << evalRPN(t1) << endl;  // 预期: 9

    vector<string> t2 = {"4", "13", "5", "/", "+"};
    cout << evalRPN(t2) << endl;  // 预期: 6

    vector<string> t3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << evalRPN(t3) << endl;  // 预期: 22

    return 0;
}
