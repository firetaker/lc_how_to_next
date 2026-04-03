#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = 0, col = (int)matrix[0].size() - 1;
    while (row < (int)matrix.size() && col >= 0) {
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] > target) col--;
        else row++;
    }
    return false;
}

int main() {
    // 测试用例
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    cout << (searchMatrix(matrix, 5) ? "True" : "False") << endl;   // 预期: True
    cout << (searchMatrix(matrix, 20) ? "True" : "False") << endl;  // 预期: False
    vector<vector<int>> matrix2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << (searchMatrix(matrix2, 9) ? "True" : "False") << endl;  // 预期: True
    return 0;
}
