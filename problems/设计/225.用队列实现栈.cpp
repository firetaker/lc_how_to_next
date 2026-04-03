#include <iostream>
#include <queue>
using namespace std;

class MyStack {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        for (int i = 0; i < (int)q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    int pop() {
        int v = q.front();
        q.pop();
        return v;
    }
    int top() {
        return q.front();
    }
    bool empty() {
        return q.empty();
    }
};

int main() {
    // 测试用例
    MyStack st;
    st.push(1);
    st.push(2);
    cout << st.top() << endl;   // 预期: 2
    cout << st.pop() << endl;  // 预期: 2
    cout << boolalpha << st.empty() << endl;  // 预期: false
    st.push(3);
    cout << st.pop() << endl;  // 预期: 3
    cout << st.pop() << endl;  // 预期: 1
    cout << st.empty() << endl;  // 预期: true
    return 0;
}
