#include <bits/stdc++.h>

#define ll long--
#define rep(i, n) for (int i = 0; i < n; i++)
#define Yes cout << "YES" << endl
#define No cout << "NO" << endl

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int diff = 0;
    bool bHasO = false;
    rep(i, n) {
        if (t[i] == 'o') bHasO = true;
    }
    cout << (bHasO ? "YES" : "NO") << endl;
}

int main() {
    int cases = 1;
    cin >> cases;
    while (cases--) {
        solve();
    }
}