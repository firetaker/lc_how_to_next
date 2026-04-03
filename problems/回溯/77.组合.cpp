#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<vector<int>>& result, vector<int>& path,
               int n, int k, int start) {
    if (path.size() == k) {
        result.push_back(path);
        return;
    }
    for (int i = start; i <= n; i++) {
        path.push_back(i);
        backtrack(result, path, n, k, i + 1);
        path.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> path;
    backtrack(result, path, n, k, 1);
    return result;
}

int main() {
    // 测试用例1
    vector<vector<int>> res1 = combine(4, 2);
    cout << "Test 1: n=4, k=2" << endl;
    for (auto& comb : res1) {
        cout << "[";
        for (int i = 0; i < comb.size(); i++) {
            cout << comb[i];
            if (i < comb.size() - 1) cout << ",";
        }
        cout << "] ";
    }
    cout << endl;
    
    // 测试用例2
    vector<vector<int>> res2 = combine(1, 1);
    cout << "Test 2: n=1, k=1" << endl;
    for (auto& comb : res2) {
        cout << "[" << comb[0] << "] ";
    }
    cout << endl;
    
    // 测试用例3
    vector<vector<int>> res3 = combine(5, 3);
    cout << "Test 3: n=5, k=3 - " << res3.size() << " combinations" << endl;
    
    return 0;
}
