#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class NQueensSolver {
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        board = vector<vector<char>>(n, vector<char>(n, '.'));
        backtrack(0);
        return result;
    }
    
    void printSolutions(const vector<vector<string>>& solutions) {
        for (int s = 0; s < solutions.size(); s++) {
            cout << "Solution " << s + 1 << ":" << endl;
            for (int i = 0; i < n; i++) {
                cout << solutions[s][i] << endl;
            }
            cout << endl;
        }
    }
    
private:
    int n;
    vector<vector<string>> result;
    vector<vector<char>> board;
    unordered_set<int> cols;
    unordered_set<int> diag1;  // row + col
    unordered_set<int> diag2;  // row - col
    
    bool isValid(int row, int col) {
        if (cols.count(col)) return false;
        if (diag1.count(row + col)) return false;
        if (diag2.count(row - col)) return false;
        return true;
    }
    
    void backtrack(int row) {
        if (row == n) {
            vector<string> solution;
            for (int i = 0; i < n; i++) {
                solution.push_back(string(board[i].begin(), board[i].end()));
            }
            result.push_back(solution);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isValid(row, col)) {
                board[row][col] = 'Q';
                cols.insert(col);
                diag1.insert(row + col);
                diag2.insert(row - col);
                backtrack(row + 1);
                board[row][col] = '.';
                cols.erase(col);
                diag1.erase(row + col);
                diag2.erase(row - col);
            }
        }
    }
};

int main() {
    // 测试用例1
    NQueensSolver solver1;
    vector<vector<string>> solutions1 = solver1.solveNQueens(4);
    cout << "n=4: " << solutions1.size() << " solutions" << endl;
    solver1.printSolutions(solutions1);
    
    // 测试用例2
    NQueensSolver solver2;
    vector<vector<string>> solutions2 = solver2.solveNQueens(1);
    cout << "n=1: " << solutions2.size() << " solution" << endl;
    solver2.printSolutions(solutions2);
    
    // 测试用例3
    NQueensSolver solver3;
    vector<vector<string>> solutions3 = solver3.solveNQueens(8);
    cout << "n=8: " << solutions3.size() << " solutions" << endl;
    
    return 0;
}
