#include <bits/stdc++.h>
using namespace std;

// #define

string solve() {
    int n = 1;
    cin >> n;
    int * a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] - a[i] > 1) return "NO";
    }
    return "YES";
}

int main() {
    int cases = 1;
    cin >> cases;
    while (cases--) {
        cout << solve() << endl;
    }
    return 0;
}
