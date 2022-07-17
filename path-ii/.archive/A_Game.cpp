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
    // int L = 0;
    int R = n - 1; // R on n-1 th
    bool RTurn = true;
    for (int i = 0; i < n - 1; i++) {
        if (RTurn) {
            R--;
        }
        RTurn = !RTurn; // on each alt turn R--
    }
    return a[R];
}

int main() {
    int cases = 1;
    // cin >> cases;
    while (cases--) {
        cout << solve() << endl;
    }
    return 0;
}
