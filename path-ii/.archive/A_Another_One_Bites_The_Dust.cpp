#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    int diff = max(n, m) - min(n, m);
    long long ava = n + m - diff;
    if (k > 0) {
        ava += 2 * k;
        if (diff > 0) ava++;
    }

    cout << ava << endl;
}

int main() {
    int cases = 1;
    // cin >> cases;
    while (cases--) {
        solve();
    }
    return 0;
}
