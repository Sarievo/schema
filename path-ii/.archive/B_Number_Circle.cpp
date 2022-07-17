#include <bits/stdc++.h>
using namespace std;

// #define

void solve() {
    int n = 1;
    cin >> n;
    int * a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    if (a[n - 1] >= a[n - 2] + a[n - 3]) {
    // for (int i = 2; i < n; i++) {
        // if (a[i] >= a[i - 1] + a[i - 2]) {
            cout << "NO" << endl;
            return;
        // }
        // return "NO";
    }
    // return "YES";
    cout << "YES" << endl;
    for (int i = n - 1; i > -1; i -= 2) {
        cout << a[i] << " ";
    }
    for (int i = n % 2; i < n; i += 2) {
        cout << a[i] << " ";
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
