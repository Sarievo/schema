#include <bits/stdc++.h>
using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
    string s;
    cin >> s;

    int id = n-1;
    for (int i = n/2; i < n-1; i++) {
        if (s[i] != s[i+1]) {
            id = i;
            break;
        }
    }
    if (id == n-1) {
        cout << n << endl;
    } else {
        int base = 1;
        for (int i = id; i > 0; i--) {
            if (s[i] == s[i-1]) base++;
            else break;
        }
        cout << base << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}