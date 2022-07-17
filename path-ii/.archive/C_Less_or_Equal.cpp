#include <bits/stdc++.h>
using namespace std;

// #define

void solve() {
    int n, k;
    cin >> n >> k;
    int * a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    // int x = 0;
    // int last = INT_MIN;
    // for (int i = 0; i < n - 1; i++) {
    //     if (x )
    // }
    if (k == 0) {
        if (a[0] > 1) {
            cout << 1 << endl;
        } else {
            cout << -1 << endl;
        }
        return;
    }
    if (k < n && a[k - 1] == a[k]) {
        cout << -1 << endl;
    } else {
        cout << a[k - 1] << endl;
    }
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
