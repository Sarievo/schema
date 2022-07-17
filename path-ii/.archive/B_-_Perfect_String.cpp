// #include <bits/stdc++.h>
#include <iostream>
#include <set>
using namespace std;
 

bool solve() {
    string s;
    cin >> s;
    bool hasUpperCase = false;
    bool hasLowerCase = false;
    set<char> set = {};
    for (char c : s) {
        if (set.find(c) != set.end())
            return false;
        set.insert(c);
        if (c >= 'a') hasLowerCase = true;
        else if (c <= 'Z') hasUpperCase = true;
    }
    return hasUpperCase && hasLowerCase;
}

int main() {
    cout << (solve() ? "Yes" : "No") << endl;
}
