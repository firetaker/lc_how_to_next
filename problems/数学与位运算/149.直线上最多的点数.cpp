#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
using namespace std;

int maxPoints(vector<vector<int>>& points) {
    int n = points.size();
    if (n <= 2) return n;
    int result = 0;
    for (int i = 0; i < n; i++) {
        unordered_map<long long, int> mp;
        int same = 1;
        for (int j = i+1; j < n; j++) {
            long long dx = points[j][0] - points[i][0];
            long long dy = points[j][1] - points[i][1];
            if (dx == 0 && dy == 0) { same++; continue; }
            long long g = std::gcd(dx, dy);
            dx /= g; dy /= g;
            long long key = dx * 2000 + dy;
            mp[key]++;
        }
        int local_max = same;
        for (auto& kv : mp) local_max = max(local_max, same + kv.second);
        result = max(result, local_max);
    }
    return result;
}

int main() {
    // 测试用例
    vector<vector<int>> p1 = {{1,1},{2,2},{3,3}};
    cout << maxPoints(p1) << endl;  // 预期: 3
    vector<vector<int>> p2 = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    cout << maxPoints(p2) << endl;  // 预期: 4
    vector<vector<int>> p3 = {{0,0}};
    cout << maxPoints(p3) << endl;  // 预期: 1
    return 0;
}
