#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    int * a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // how to do this??
    // what is always correct?
    bool isUnique = false;
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] != a[i]) {
            isUnique = true;
            break;
        }
    }
    cout << (isUnique ? "1" : to_string (n)) << endl;
}

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        solve();
    }
    return 0;
}
