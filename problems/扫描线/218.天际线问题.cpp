#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<array<long, 3>> events;
    for (auto& b : buildings) {
        events.push_back({b[0], -b[2], b[1]});
        events.push_back({b[1], b[2], 0});
    }
    sort(events.begin(), events.end());
    vector<vector<int>> result;
    priority_queue<pair<int, int>> pq;
    pq.push({0, INT_MAX});
    for (auto& e : events) {
        long x = e[0], h = -e[1], r = e[2];
        if (h > 0) {
            if (h > pq.top().first) result.push_back({(int)x, (int)h});
            pq.push({(int)h, (int)r});
        } else {
            while (!pq.empty() && pq.top().second <= r) pq.pop();
            int currH = pq.top().first;
            if (result.empty() || currH != result.back()[1])
                result.push_back({(int)x, currH});
        }
    }
    return result;
}

int main() {
    // 测试用例
    vector<vector<int>> buildings1 = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    auto res1 = getSkyline(buildings1);
    for (auto& p : res1) cout << "[" << p[0] << "," << p[1] << "] ";
    cout << endl;
    // 预期: [2,10] [3,15] [7,12] [12,0] [15,10] [20,8] [24,0]

    vector<vector<int>> buildings2 = {{0,2,3},{2,5,3}};
    auto res2 = getSkyline(buildings2);
    for (auto& p : res2) cout << "[" << p[0] << "," << p[1] << "] ";
    cout << endl;
    // 预期: [0,3] [5,0]

    vector<vector<int>> buildings3 = {{1,2,1},{1,2,2},{1,2,3}};
    auto res3 = getSkyline(buildings3);
    for (auto& p : res3) cout << "[" << p[0] << "," << p[1] << "] ";
    cout << endl;
    // 预期: [1,3] [2,0]

    return 0;
}
