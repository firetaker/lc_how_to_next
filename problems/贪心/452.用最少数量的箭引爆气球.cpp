#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMinArrowShots(vector<vector<int>>& points) {
    if (points.empty()) return 0;
    sort(points.begin(), points.end(),
         [](auto& a, auto& b) { return a[1] < b[1]; });
    int arrows = 1, end = points[0][1];
    for (int i = 1; i < points.size(); i++) {
        if (points[i][0] > end) {
            arrows++;
            end = points[i][1];
        }
    }
    return arrows;
}

int main() {
    // 测试用例
    vector<vector<int>> p1 = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout << findMinArrowShots(p1) << endl;  // 预期: 2

    vector<vector<int>> p2 = {{1, 2}, {3, 4}, {5, 6}};
    cout << findMinArrowShots(p2) << endl;  // 预期: 3

    vector<vector<int>> p3 = {{1, 2}, {2, 3}};
    cout << findMinArrowShots(p3) << endl;  // 预期: 1

    return 0;
}
