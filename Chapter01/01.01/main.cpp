#include <map>
#include <string>
#include <iostream>
using namespace std;

int is_unique(string s) {
    map<char, int> m;
    for (auto &c : s) {
        if (m[c]) {
            return 0;
        } else {
            m[c] = 1;
        }
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    if (is_unique("fuckmeintheass")) {
        cout << "fail" << "\n";
    } else {
        cout << "good" << "\n";
    }
    return 0;
}