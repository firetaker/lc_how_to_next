#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int max_area = 0;
    vector<int> h = heights;
    h.push_back(0);
    for (int i = 0; i < h.size(); i++) {
        while (!st.empty() && h[st.top()] > h[i]) {
            int height = h[st.top()]; st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            max_area = max(max_area, height * width);
        }
        st.push(i);
    }
    return max_area;
}

int main() {
    // 测试用例
    vector<int> h1 = {2, 1, 5, 6, 2, 3};
    cout << largestRectangleArea(h1) << endl;  // 预期: 10

    vector<int> h2 = {2, 4};
    cout << largestRectangleArea(h2) << endl;  // 预期: 4

    vector<int> h3 = {1};
    cout << largestRectangleArea(h3) << endl;  // 预期: 1

    return 0;
}
