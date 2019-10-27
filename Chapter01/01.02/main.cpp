#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

bool isPermutation(string s1, string s2) {
    if (s1.length() != s2.length()) {
        return false;
    }
    map<char, int> m;
    for (auto &c : s1) {
        if (m.find(c) == m.end()) {
            m[c] = 0;
        } else {
            m[c] += 1;
        }
    }
    for (auto &c : s2) {
        if (m.find(c) == m.end()) {
            return false;
        } else {
            m[c] -= 1;
            if (m[c] < 0) return false;
        }
    }
    for (auto it : m) {
        if (it.second != 0) return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    vector<bool> tests {
        isPermutation("arst", "tsra") == true,
        isPermutation("arst", "tsrx") == false,
        isPermutation("fuck", "") == false
    };
    bool result = true;
    for (bool b : tests) result = result && b;
    result ? (cout << "fail\n") : (cout << "good\n");
    return 0;
}