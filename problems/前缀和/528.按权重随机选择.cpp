#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
    vector<int> prefix;
public:
    Solution(vector<int>& w) {
        for (int x : w) prefix.push_back((prefix.empty() ? 0 : prefix.back()) + x);
    }
    int pickIndex() {
        int target = rand() % prefix.back() + 1;
        int left = 0, right = prefix.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (prefix[mid] >= target) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};

int main() {
    // 测试用例
    srand(42);
    Solution sol1({1});
    cout << sol1.pickIndex() << endl;
    // 预期: 0

    Solution sol2({1, 3});
    cout << sol2.pickIndex() << endl;
    // 预期: 0 或 1

    Solution sol3({2, 5, 3, 4});
    cout << sol3.pickIndex() << endl;
    // 预期: 0, 1, 2, 或 3

    return 0;
}
