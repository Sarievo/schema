#include <bits/stdc++.h>
using namespace std;


int * readInts(int &n) {
    int * a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    return a;
}

void solve() {
    int n;
    cin >> n;
    int * a = readInts(n);
    sort(a, a + n);
    int base = 1;
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] > a[i]) base++;
    }
    cout << base << endl;
}

int main() {
    int cases = 1;
    cin >> cases;
    while (cases--) {
        solve();
    }
    return 0;
}
