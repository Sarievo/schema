#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    int a[n][n] {0};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i % 2 == 1)
                a[j - 1][i - 1] = (i-1) * n + j;
            else
                a[n - j][i - 1] = (i-1) * n + j;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int cases = 1;
    // cin >> cases;
    while (cases--) {
        solve();
    }
    return 0;
}
