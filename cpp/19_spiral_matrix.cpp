/**
 * LeetCode #54: 螺旋矩阵
 * 题目: 按顺时针螺旋顺序返回矩阵所有元素。
 * 解法: 方向数组 + 边界收缩 - 维护上下左右四个边界。
 *       顺序：右→下→左→上，每走完一条边收缩对应边界。
 * 时间 O(mn)，空间 O(1)。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        int i = 0, j = 0;
        int dir = 0; // 0=right, 1=down, 2=left, 3=up
        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        while (left <= right && top <= bottom) {
            result.push_back(matrix[i][j]);
            int ni = i + dirs[dir][0];
            int nj = j + dirs[dir][1];
            if (ni >= top && ni <= bottom && nj >= left && nj <= right) {
                i = ni; j = nj;
            } else {
                if (dir == 0) top++;
                else if (dir == 1) right--;
                else if (dir == 2) bottom--;
                else left++;
                dir = (dir + 1) % 4;
                i = i + dirs[dir][0];
                j = j + dirs[dir][1];
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> m = {{1,2,3},{4,5,6},{7,8,9}};
    auto res = sol.spiralOrder(m);
    for (int v : res) cout << v << " "; // 1 2 3 6 9 8 7 4 5
    cout << endl;
    return 0;
}
