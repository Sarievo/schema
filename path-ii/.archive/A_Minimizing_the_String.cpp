#include <bits/stdc++.h>
using namespace std;


int * readInts(int &n) {
    int * a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    return a;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    // find the first character
    // st. the second character is smaller, 
    // remove the first character
    // if no such character, remove the last character
    string output = "";
    int mark = n - 1;
    for (int i = 0; i < n - 1; i++) {
        if (s[i + 1] < s[i]) {
            mark = i;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == mark) continue;
        output += s[i];
    }
    cout << output << endl;
}

int main() {
    int cases = 1;
    // cin >> cases;
    while (cases--) {
        solve();
    }
    return 0;
}
