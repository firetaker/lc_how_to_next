#include <iostream>
#include <cstdint>
using namespace std;

int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) { n &= n - 1; count++; }
    return count;
}

int main() {
    // 测试用例
    cout << hammingWeight(11) << endl;          // 预期: 3
    cout << hammingWeight(128) << endl;         // 预期: 1
    cout << hammingWeight(2147483647u) << endl; // 预期: 31
    cout << hammingWeight(0) << endl;            // 预期: 0
    return 0;
}
