#include <iostream>
#include <string>
using namespace std;

int lengthOfLastWord(string s) {
    int n = s.size(), len = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] != ' ')
            len++;
        else if (len > 0)
            break;
    }
    return len;
}

int main() {
    // 测试用例
    cout << lengthOfLastWord("Hello World") << endl;                    // 预期: 5
    cout << lengthOfLastWord("   fly me   to   the moon  ") << endl;  // 预期: 4
    cout << lengthOfLastWord("a") << endl;                             // 预期: 1
    return 0;
}
