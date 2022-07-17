#include <bits/stdc++.h>
using namespace std;

// #define

int solve() {
    int n = 1;
    cin >> n;
    int * a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int problems = 0;
    for (int i = 0; i < n - 1; i += 2) {
        problems += a[i + 1] - a[i];
    }
    return problems;
}

int main() {
    int cases = 1;
    // cin >> cases;
    while (cases--) {
        cout << solve() << endl;
    }
    return 0;
}
