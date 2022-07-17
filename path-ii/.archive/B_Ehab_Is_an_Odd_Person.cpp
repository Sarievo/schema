#include <bits/stdc++.h>
using namespace std;

// #define

void solve() {
    int n;
    cin >> n;
    int * a = new int[n];
    int odds = 0;
    int evens = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0) evens++;
        else odds++;
    }
    if (evens > 0 && odds > 0) {
        sort(a, a + n);
    }
    for (int i = 0; i < n; i++) {
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
