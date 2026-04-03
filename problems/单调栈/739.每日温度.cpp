#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> result(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
            result[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    return result;
}

int main() {
    // 测试用例
    vector<int> t1 = {73, 74, 75, 71, 69, 72, 76, 73};
    auto res1 = dailyTemperatures(t1);
    for (int x : res1) cout << x << " ";
    cout << endl;
    // 预期: 1 1 4 2 1 1 0 0

    vector<int> t2 = {30, 40, 50, 60};
    auto res2 = dailyTemperatures(t2);
    for (int x : res2) cout << x << " ";
    cout << endl;
    // 预期: 1 1 1 0

    vector<int> t3 = {30, 60, 90};
    auto res3 = dailyTemperatures(t3);
    for (int x : res3) cout << x << " ";
    cout << endl;
    // 预期: 1 1 0

    return 0;
}
