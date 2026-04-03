#include <iostream>
using namespace std;

int trailingZeroes(int n) {
    int count = 0;
    while (n) {
        n /= 5;
        count += n;
    }
    return count;
}

int main() {
    // 测试用例
    cout << trailingZeroes(3) << endl;  // 预期: 0
    cout << trailingZeroes(5) << endl;  // 预期: 1
    cout << trailingZeroes(30) << endl; // 预期: 7
    cout << trailingZeroes(0) << endl;  // 预期: 0
    return 0;
}
