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
    MinStack ms;
    ms.push(-2);
    ms.push(0);
    ms.push(-3);
    cout << ms.getMin() << endl;  // 预期: -3
    ms.pop();
    cout << ms.top() << endl;     // 预期: 0
    cout << ms.getMin() << endl;  // 预期: -2

    return 0;
}
