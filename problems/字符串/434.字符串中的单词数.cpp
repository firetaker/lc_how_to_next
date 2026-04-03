#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int countSegments(string s) {
    int count = 0;
    string word;
    istringstream iss(s);
    while (iss >> word) count++;
    return count;
}

int main() {
    // 测试用例
    cout << countSegments("Hello, my name is John") << endl;  // 预期: 5
    cout << countSegments("") << endl;                        // 预期: 0
    cout << countSegments("    ") << endl;                   // 预期: 0
    cout << countSegments("a") << endl;                      // 预期: 1
    return 0;
}
