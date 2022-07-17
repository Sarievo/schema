#include <bits/stdc++.h>
using namespace std;


void solve() {
    string n;
    cin >> n;

    for (int i = 0; i < n.length(); i++) {
        if (i == 0) {
            if (n[i] == '9')
                continue;
            if (n[i] == '0') {
                n[i] = '9';
                continue;
            }
        }

        if (n[i] > '4')
            n[i] = '0' + ('9' - n[i]);
    }

    cout << n << endl;
}

int main() {
    int cases = 1;
    // cin >> cases;
    while (cases--) {
        solve();
    }
    return 0;
}
