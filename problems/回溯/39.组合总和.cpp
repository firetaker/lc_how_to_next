#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<vector<int>>& result, vector<int>& path,
               vector<int>& candidates, int target, int start) {
    if (target == 0) {
        result.push_back(path);
        return;
    }
    if (target < 0) return;
    
    for (int i = start; i < candidates.size(); i++) {
        path.push_back(candidates[i]);
        backtrack(result, path, candidates, target - candidates[i], i);
        path.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> path;
    backtrack(result, path, candidates, target, 0);
    return result;
}

int main() {
    // 测试用例1
    vector<int> candidates1 = {2, 3, 6, 7};
    vector<vector<int>> res1 = combinationSum(candidates1, 7);
    cout << "Test 1: candidates=[2,3,6,7], target=7" << endl;
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
    vector<int> candidates2 = {2, 3, 5};
    vector<vector<int>> res2 = combinationSum(candidates2, 8);
    cout << "Test 2: candidates=[2,3,5], target=8" << endl;
    for (auto& comb : res2) {
        cout << "[";
        for (int i = 0; i < comb.size(); i++) {
            cout << comb[i];
            if (i < comb.size() - 1) cout << ",";
        }
        cout << "] ";
    }
    cout << endl;
    
    // 测试用例3
    vector<int> candidates3 = {2};
    vector<vector<int>> res3 = combinationSum(candidates3, 1);
    cout << "Test 3: candidates=[2], target=1 - " << res3.size() << " combinations" << endl;
    
    return 0;
}
