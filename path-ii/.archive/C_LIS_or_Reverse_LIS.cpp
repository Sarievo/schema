#include <bits/stdc++.h>
using namespace std;
// #define fast_cin ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve() {
	int n;
	cin >> n;
    vector<int> a(n);
    map<int, int> fmap;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        fmap[a[i]]++;
    }

    int d_once = 0;
    int d_twice = 0;
    for (auto [k, v] : fmap) {
        if (v > 1) d_twice++;
        else d_once++;
    }

    cout << d_twice + (d_once + 1) / 2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}