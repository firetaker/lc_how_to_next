#include <iostream>
#include <string>
using namespace std;

string toLowerCase(string s) {
    for (char& c : s)
        if (c >= 'A' && c <= 'Z')
            c = c - 'A' + 'a';
    return s;
}

int main() {
    // 测试用例
    cout << toLowerCase("Hello") << endl;    // 预期: hello
    cout << toLowerCase("here") << endl;     // 预期: here
    cout << toLowerCase("LOVELY") << endl;   // 预期: lovely
    return 0;
}
