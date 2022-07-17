#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    bool hasOddLength = false;
    int ones = 0;
    for (int i = 0; i < n; i++) {
        string num;
        cin >> num;
        hasOddLength = hasOddLength || num.length() % 2 == 1;
        for (char i : num) {
            if (i == '1') ones++;
        }
    }

    if (hasOddLength) {
        cout << n << endl;
    } else {
        if (ones % 2 == 0) {
            cout << n << endl;
        } else {
            cout << (n - 1) << endl;
        }
    }
}

int main() {
    int cases = 1;
    cin >> cases;
    while (cases--) {
        solve();
    }
    return 0;
}
