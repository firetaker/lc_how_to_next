#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), [](auto& a, auto& b) {
        return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
    });
    vector<vector<int>> result;
    for (auto& p : people)
        result.insert(result.begin() + p[1], p);
    return result;
}

int main() {
    // 测试用例
    vector<vector<int>> p1 = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    auto r1 = reconstructQueue(p1);
    for (auto& row : r1) {
        cout << "[" << row[0] << "," << row[1] << "] ";
    }
    cout << endl;
    // 预期: [5,0] [7,0] [5,2] [6,1] [4,4] [7,1]

    vector<vector<int>> p2 = {{6, 0}, {5, 0}, {4, 0}, {3, 2}, {2, 2}, {1, 4}};
    auto r2 = reconstructQueue(p2);
    for (auto& row : r2) {
        cout << "[" << row[0] << "," << row[1] << "] ";
    }
    cout << endl;
    // 预期: [4,0] [5,0] [2,2] [3,2] [1,4] [6,0]

    return 0;
}
