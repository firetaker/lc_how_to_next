#include <iostream>
#include <cstdint>
using namespace std;

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; i++)
        result = (result << 1) | (n >> i & 1);
    return result;
}

int main() {
    // 测试用例
    cout << reverseBits(43261596) << endl;  // 预期: 964176192
    cout << reverseBits(4294967293u) << endl;  // 预期: 3221225472
    cout << reverseBits(0) << endl;  // 预期: 0
    cout << reverseBits(1) << endl;  // 预期: 2147483648
    return 0;
}
