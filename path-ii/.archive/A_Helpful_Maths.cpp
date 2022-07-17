#include <bits/stdc++.h>
using namespace std;

// #define

void solve() {
    string s;
    cin >> s;
    if (s.length() == 1) {
        cout << s << endl;
        return;
    }
    int numbers = s.length() / 2 + 1;
    int ones = 0;
    int twos = 0;
    int threes = 0;
    for (int i = 0; i < numbers; i++) {
        char n = s[i * 2];
        if (n == '1') ones++;
        else if (n == '2') twos++;
        else if (n == '3') threes++;
    }

    while (ones + twos + threes > 1) {
        if (ones > 0) {
            ones--;
            cout << "1+";
        } else if (twos > 0) {
            twos--;
            cout << "2+";
        } else {
            threes--;
            cout << "3+";
        }
    }
    if (ones > 0) {
        cout << "1";
    } else if (twos > 0) {
        cout << "2";
    } else {
        cout << "3";
    }
    cout << endl;
}

int main() {
    int cases = 1;
    // cin >> cases;
    while (cases--) {
        // cout << solve() << endl;
        solve();
    }
    return 0;
}
