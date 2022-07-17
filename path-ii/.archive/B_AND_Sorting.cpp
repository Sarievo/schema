#include <bits/stdc++.h>
using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> sorted = a;
    sort(sorted.begin(), sorted.end());
    vector<int> cands;
    for (int i = 0; i < n; i++) {
        int v1 = sorted[i];
        int v2 = a[i];
        if (v1 != v2) {
            cands.emplace_back(v1);
        }
    }

    assert(cands.size() >= 2);
    int ans = cands[0];
    for (int i = 1; i < cands.size(); i++) {
        ans &= cands[i];
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}