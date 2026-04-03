#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int n = matrix[0].size(), max_area = 0;
    vector<int> heights(n, 0);
    for (auto& row : matrix) {
        for (int j = 0; j < n; j++)
            heights[j] = (row[j] == '1') ? heights[j] + 1 : 0;
        stack<int> st;
        for (int j = 0; j <= n; j++) {
            int h = j == n ? 0 : heights[j];
            while (!st.empty() && heights[st.top()] > h) {
                int height = heights[st.top()]; st.pop();
                int width = st.empty() ? j : j - st.top() - 1;
                max_area = max(max_area, height * width);
            }
            st.push(j);
        }
    }
    return max_area;
}

int main() {
    // 测试用例
    vector<vector<char>> matrix1 = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    cout << maximalRectangle(matrix1) << endl;
    // 预期: 6

    vector<vector<char>> matrix2 = {{'0'}};
    cout << maximalRectangle(matrix2) << endl;
    // 预期: 0

    vector<vector<char>> matrix3 = {{'1'}};
    cout << maximalRectangle(matrix3) << endl;
    // 预期: 1

    return 0;
}
