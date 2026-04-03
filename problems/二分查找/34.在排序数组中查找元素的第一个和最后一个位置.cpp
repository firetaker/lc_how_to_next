#include <iostream>
#include <vector>
#include <functional>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    auto find_bound = [&](bool find_first) {
        int left = 0, right = nums.size() - 1, bound = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                bound = mid;
                if (find_first) right = mid - 1;
                else left = mid + 1;
            } else if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return bound;
    };
    return {find_bound(true), find_bound(false)};
}

int main() {
    // 测试用例
    vector<int> n1 = {5, 7, 7, 8, 8, 10};
    auto r1 = searchRange(n1, 8);
    cout << r1[0] << " " << r1[1] << endl;  // 预期: 3 4

    vector<int> n2 = {5, 7, 7, 8, 8, 10};
    auto r2 = searchRange(n2, 6);
    cout << r2[0] << " " << r2[1] << endl;  // 预期: -1 -1

    vector<int> n3 = {};
    auto r3 = searchRange(n3, 0);
    cout << r3[0] << " " << r3[1] << endl;  // 预期: -1 -1

    return 0;
}
