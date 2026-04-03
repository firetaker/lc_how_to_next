/**
 * LeetCode #74: 搜索二维矩阵
 * 题目: 判断目标值 target 是否存在于按上述规律排序的矩阵中。
 * 解法: 排除法（从右上角出发）- target == matrix[i][j] → 找到；
 *       target < matrix[i][j] → 排除当前列，j--；
 *       target > matrix[i][j] → 排除当前行，i++。
 * 也可二分查找（一维映射）。O(m+n) 或 O(log mn)。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            int cur = matrix[i][j];
            if (cur == target) return true;
            else if (cur < target) ++i;
            else --j;
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> m = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout << sol.searchMatrix(m, 3) << endl;  // 1 (true)
    cout << sol.searchMatrix(m, 13) << endl; // 0 (false)
    return 0;
}
