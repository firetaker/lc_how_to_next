/**
 * LeetCode #48: 旋转图像
 * 题目: 顺时针旋转 n×n 矩阵 90 度。原地修改。
 * 解法: 两次翻转 - 先沿主对角线翻转（转置），再沿水平中线翻转。
 * 等价于：先转置，再每行 reverse。时间 O(n²)，空间 O(1)。
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                swap(matrix[i][j], matrix[j][i]);
        for (int i = 0; i < n; ++i)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};

int main() {
    Solution sol;
    vector<vector<int>> m = {{1,2,3},{4,5,6},{7,8,9}};
    sol.rotate(m);
    for (auto& row : m) {
        for (int v : row) cout << v << " ";
        cout << endl;
    }
    return 0;
}
