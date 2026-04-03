#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<vector<int>> result;
    if (nums1.empty() || nums2.empty()) return result;
    auto cmp = [](auto& a, auto& b) { return a[0] + a[1] > b[0] + b[1]; };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
    pq.push({nums1[0], nums2[0], 0, 0});
    while (!pq.empty() && (int)result.size() < k) {
        auto cur = pq.top(); pq.pop();
        result.push_back({cur[0], cur[1]});
        int i = cur[2], j = cur[3];
        if (i+1 < (int)nums1.size()) pq.push({nums1[i+1], nums2[j], i+1, j});
        if (j+1 < (int)nums2.size()) pq.push({nums1[i], nums2[j+1], i, j+1});
    }
    return result;
}

int main() {
    // 测试用例
    vector<int> n1a = {1, 7, 11}, n2a = {2, 4, 6};
    auto r1 = kSmallestPairs(n1a, n2a, 3);
    for (auto& p : r1) cout << "(" << p[0] << "," << p[1] << ") "; cout << endl;  // 预期: (1,2)(1,4)(1,6)
    vector<int> n1b = {1, 1, 2}, n2b = {1, 2, 3};
    auto r2 = kSmallestPairs(n1b, n2b, 2);
    for (auto& p : r2) cout << "(" << p[0] << "," << p[1] << ") "; cout << endl;  // 预期: (1,1)(1,1)
    vector<int> n1c = {1, 2}, n2c = {3};
    auto r3 = kSmallestPairs(n1c, n2c, 3);
    for (auto& p : r3) cout << "(" << p[0] << "," << p[1] << ") "; cout << endl;  // 预期: (1,3)(2,3)
    return 0;
}
