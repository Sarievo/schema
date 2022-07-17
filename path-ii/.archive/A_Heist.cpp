#include <bits/stdc++.h>
using namespace std;

// #define

void solve() {
    int n;
    cin >> n;
    // int * a = new int[n];
    int min = INT_MAX;
    int max = INT_MIN;
    int tmp = -1;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp > max) max = tmp;
        if (tmp < min) min = tmp;
    }
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    int interval = (max - min) + 1 - n;
    cout << interval << endl;
}

int main() {
    int cases = 1;
    // cin >> cases;
    while (cases--) {
        solve();
    }
    return 0;
}
