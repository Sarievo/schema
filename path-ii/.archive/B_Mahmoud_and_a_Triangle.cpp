#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    int * a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);
    for (int i = 0; i < n - 2; i++) {
        int l1 = a[i];
        int l2 = a[i + 1];
        int l3 = a[i + 2];
        if (l1 < l2 + l3 && l2 < l1 + l3
                && l3 < l1 + l2) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main() {
    int cases = 1;
    // cin >> cases;
    while (cases--) {
        solve();
    }
    return 0;
}
