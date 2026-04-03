#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = 0, j = 0;
    while (i < g.size() && j < s.size()) {
        if (s[j] >= g[i]) i++;
        j++;
    }
    return i;
}

int main() {
    // 测试用例
    vector<int> g1 = {1, 2, 3}, s1 = {1, 1};
    cout << findContentChildren(g1, s1) << endl;  // 预期: 1

    vector<int> g2 = {1, 2}, s2 = {1, 2, 3};
    cout << findContentChildren(g2, s2) << endl;  // 预期: 2

    vector<int> g3 = {10, 9, 8, 7}, s3 = {5, 6, 7, 8};
    cout << findContentChildren(g3, s3) << endl;  // 预期: 2

    return 0;
}
