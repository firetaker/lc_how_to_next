#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
    stack<int> s1, s2;
public:
    void push(int x) {
        s1.push(x);
    }
    int pop() {
        if (s2.empty())
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        int v = s2.top();
        s2.pop();
        return v;
    }
    int peek() {
        if (s2.empty())
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        return s2.top();
    }
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    // 测试用例
    MyQueue q;
    q.push(1);
    q.push(2);
    cout << q.peek() << endl;   // 预期: 1
    cout << q.pop() << endl;   // 预期: 1
    cout << boolalpha << q.empty() << endl;  // 预期: false
    q.push(3);
    cout << q.pop() << endl;   // 预期: 2
    cout << q.pop() << endl;   // 预期: 3
    cout << q.empty() << endl;  // 预期: true
    return 0;
}
