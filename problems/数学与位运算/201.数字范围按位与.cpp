#include <iostream>
using namespace std;

int rangeBitwiseAnd(int left, int right) {
    int shift = 0;
    while (left < right) {
        left >>= 1;
        right >>= 1;
        shift++;
    }
    return left << shift;
}

int main() {
    // 测试用例
    cout << rangeBitwiseAnd(5, 7) << endl;          // 预期: 4
    cout << rangeBitwiseAnd(0, 0) << endl;          // 预期: 0
    cout << rangeBitwiseAnd(1, 2147483647) << endl; // 预期: 0
    cout << rangeBitwiseAnd(16, 31) << endl;        // 预期: 16
    return 0;
}
