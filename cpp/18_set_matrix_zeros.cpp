/**
 * LeetCode #73: 矩阵置零
 * 题目: 若元素为 0，则将整行和整列置零。要求 O(mn) 时间，O(1) 空间。
 * 解法: 两遍扫描 + 自身首行首列做标记。
 *       第一遍：matrix[i][j]==0 → matrix[i][0]=matrix[0][j]=0
 *       第二遍：利用标记置零。最后单独处理首行首列。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool row_zero = false, col_zero = false;
        for (int j = 0; j < n; ++j) if (matrix[0][j] == 0) row_zero = true;
        for (int i = 0; i < m; ++i) if (matrix[i][0] == 0) col_zero = true;
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; ++i)
            if (matrix[i][0] == 0)
                for (int j = 0; j < n; ++j) matrix[i][j] = 0;
        for (int j = 1; j < n; ++j)
            if (matrix[0][j] == 0)
                for (int i = 0; i < m; ++i) matrix[i][j] = 0;
        if (row_zero) for (int j = 0; j < n; ++j) matrix[0][j] = 0;
        if (col_zero) for (int i = 0; i < m; ++i) matrix[i][0] = 0;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> m = {{1,1,1},{1,0,1},{1,1,1}};
    sol.setZeroes(m);
    for (auto& row : m) {
        for (int v : row) cout << v << " ";
        cout << endl;
    }
    return 0;
}
