#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool detectCapitalUse(string word) {
    int n = word.size();
    bool firstUpper = isupper(word[0]);
    bool allUpper = true, allLower = true;
    for (int i = 1; i < n; i++) {
        if (isupper(word[i])) allLower = false;
        else allUpper = false;
    }
    return allUpper || allLower || (firstUpper && allLower);
}

int main() {
    // 测试用例
    cout << boolalpha << detectCapitalUse("USA") << endl;      // 预期: true
    cout << detectCapitalUse("FlaG") << endl;                    // 预期: false
    cout << detectCapitalUse("Google") << endl;                  // 预期: true
    cout << detectCapitalUse("leetcode") << endl;                // 预期: true
    return 0;
}
