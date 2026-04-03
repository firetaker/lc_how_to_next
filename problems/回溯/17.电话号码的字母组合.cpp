#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

void backtrack(vector<string>& result, string& path,
               const string& digits, int index,
               const unordered_map<char, string>& phone) {
    if (index == digits.size()) {
        result.push_back(path);
        return;
    }
    string letters = phone.at(digits[index]);
    for (char letter : letters) {
        path.push_back(letter);
        backtrack(result, path, digits, index + 1, phone);
        path.pop_back();
    }
}

vector<string> letterCombinations(const string& digits) {
    vector<string> result;
    if (digits.empty()) return result;
    
    unordered_map<char, string> phone = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    
    string path;
    backtrack(result, path, digits, 0, phone);
    return result;
}

int main() {
    // 测试用例1
    vector<string> res1 = letterCombinations("23");
    cout << "Test 1: \"23\" - " << res1.size() << " combinations" << endl;
    for (auto& comb : res1) {
        cout << comb << " ";
    }
    cout << endl;
    
    // 测试用例2
    vector<string> res2 = letterCombinations("");
    cout << "Test 2: \"\" - " << res2.size() << " combinations" << endl;
    
    // 测试用例3
    vector<string> res3 = letterCombinations("2");
    cout << "Test 3: \"2\"" << endl;
    for (auto& comb : res3) {
        cout << comb << " ";
    }
    cout << endl;
    
    // 测试用例4
    vector<string> res4 = letterCombinations("79");
    cout << "Test 4: \"79\" - " << res4.size() << " combinations" << endl;
    
    return 0;
}
