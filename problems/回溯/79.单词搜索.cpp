#include <iostream>
#include <vector>
#include <string>
using namespace std;

class WordSearch {
public:
    bool exist(vector<vector<char>>& board, const string& word) {
        if (board.empty() || board[0].empty()) return false;
        m = board.size();
        n = board[0].size();
        this->board = board;
        this->word = word;
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, 0)) return true;
                }
            }
        }
        return false;
    }
    
private:
    int m, n;
    vector<vector<char>> board;
    string word;
    vector<vector<bool>> visited;
    
    bool dfs(int r, int c, int index) {
        if (index == word.size()) return true;
        if (r < 0 || r >= m || c < 0 || c >= n) return false;
        if (visited[r][c] || board[r][c] != word[index]) return false;
        
        visited[r][c] = true;
        bool found = dfs(r + 1, c, index + 1) ||
                     dfs(r - 1, c, index + 1) ||
                     dfs(r, c + 1, index + 1) ||
                     dfs(r, c - 1, index + 1);
        visited[r][c] = false;
        return found;
    }
};

int main() {
    WordSearch solver;
    
    // 测试用例1
    vector<vector<char>> board1 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    cout << "Test 1:" << endl;
    cout << "ABCCED: " << (solver.exist(board1, "ABCCED") ? "true" : "false") << endl;
    cout << "SEE: " << (solver.exist(board1, "SEE") ? "true" : "false") << endl;
    cout << "ABCB: " << (solver.exist(board1, "ABCB") ? "true" : "false") << endl;
    
    // 测试用例2
    vector<vector<char>> board2 = {{'a'}};
    cout << "\nTest 2:" << endl;
    cout << "a: " << (solver.exist(board2, "a") ? "true" : "false") << endl;
    cout << "b: " << (solver.exist(board2, "b") ? "true" : "false") << endl;
    
    // 测试用例3
    vector<vector<char>> board3 = {
        {'A', 'A', 'A'},
        {'A', 'A', 'A'},
        {'A', 'A', 'A'}
    };
    cout << "\nTest 3:" << endl;
    cout << "AAAAA: " << (solver.exist(board3, "AAAAA") ? "true" : "false") << endl;
    cout << "AAAAAAA: " << (solver.exist(board3, "AAAAAAA") ? "true" : "false") << endl;
    
    return 0;
}
