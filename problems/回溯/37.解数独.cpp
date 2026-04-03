#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SudokuSolver {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
    
    void printBoard(const vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j];
                if (j == 2 || j == 5) cout << " ";
                if (j == 8) cout << endl;
            }
            if (i == 2 || i == 5) cout << endl;
        }
    }
    
private:
    bool isValid(const vector<vector<char>>& board, int row, int col, char num) {
        // 检查行
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num) return false;
        }
        // 检查列
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == num) return false;
        }
        // 检查 3x3 宫格
        int startRow = 3 * (row / 3);
        int startCol = 3 * (col / 3);
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == num) return false;
            }
        }
        return true;
    }
    
    bool backtrack(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char num = '1'; num <= '9'; num++) {
                        if (isValid(board, i, j, num)) {
                            board[i][j] = num;
                            if (backtrack()) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    // 测试用例
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    
    SudokuSolver solver;
    cout << "Before solving:" << endl;
    solver.printBoard(board);
    
    solver.solveSudoku(board);
    
    cout << "\nAfter solving:" << endl;
    solver.printBoard(board);
    
    return 0;
}
