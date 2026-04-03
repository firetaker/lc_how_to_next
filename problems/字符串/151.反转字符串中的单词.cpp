#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string reverseWords(string s) {
    istringstream iss(s);
    string word, result;
    while (iss >> word) {
        if (!result.empty()) result += ' ';
        result = word + (result.empty() ? "" : " " + result);
    }
    return result;
}

int main() {
    // 测试用例
    cout << reverseWords("the sky is blue") << endl;      // 预期: blue is sky the
    cout << reverseWords("  hello world  ") << endl;     // 预期: world hello
    cout << reverseWords("a good   example") << endl;    // 预期: example good a
    return 0;
}
