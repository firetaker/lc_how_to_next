#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backtrack(vector<vector<int>>& result, vector<int>& path,
               vector<int>& candidates, int target, int start) {
    if (target == 0) {
        result.push_back(path);
        return;
    }
    if (target < 0) return;
    
    for (int i = start; i < candidates.size(); i++) {
        // 剪枝：相同元素跳过
        if (i > start && candidates[i] == candidates[i - 1]) continue;
        
        path.push_back(candidates[i]);
        backtrack(result, path, candidates, target - candidates[i], i + 1);
        path.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> path;
    sort(candidates.begin(), candidates.end());
    backtrack(result, path, candidates, target, 0);
    return result;
}

int main() {
    // 测试用例1
    vector<int> candidates1 = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> res1 = combinationSum2(candidates1, 8);
    cout << "Test 1: candidates=[10,1,2,7,6,1,5], target=8" << endl;
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
    vector<int> candidates2 = {2, 5, 2, 1, 2};
    vector<vector<int>> res2 = combinationSum2(candidates2, 5);
    cout << "Test 2: candidates=[2,5,2,1,2], target=5" << endl;
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
    vector<int> candidates3 = {1, 1, 1, 1, 1};
    vector<vector<int>> res3 = combinationSum2(candidates3, 3);
    cout << "Test 3: candidates=[1,1,1,1,1], target=3 - " << res3.size() << " combinations" << endl;
    
    return 0;
}
