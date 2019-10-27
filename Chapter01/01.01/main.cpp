#include <map>
#include <string>
#include <iostream>
using namespace std;

bool isUnique(string s) {
    map<char, int> m;
    for (auto &c : s) {
        if (m[c]) {
            return false;
        } else {
            m[c] = 1;
        }
    }
    return true;
}

bool aux(string s1, string s2) {
    if (s2.empty()) {
        return true;
    } else {
        for (auto &c : s1) {
            if (s2[0] == c) {
                return false;
            }
        }
        return aux(s1 += s2[0], s2.substr(1));
    }
}

bool isUniqueHardcore(string s) {
    return aux(s.substr(0, 1), s.substr(1));
}

int main(int argc, char const *argv[])
{
    bool ex1 = isUnique("arst") == true;
    bool ex2 = isUnique("xx") == false;
    bool ex3 = isUniqueHardcore("arst") == true;
    bool ex4 = isUniqueHardcore("xx") == false;
    if (ex1 && ex2 && ex3 && ex4) {
        cout << "good" << "\n";
    } else {
        cout << "fail" << "\n";
    }
    return 0;
}