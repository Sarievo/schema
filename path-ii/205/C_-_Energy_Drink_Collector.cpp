/** 
 * Sarievo.
 * URL: https://atcoder.jp/contests/abc121/tasks/abc121_c
 */

#include <bits/stdc++.h>
#define poly vector<int>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) // make io faster
#define rep(i, n) for(int i = 0; i < n; i++)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair<int,int>
#define fi first
#define se second
#define inf 1e18
#define int ll
#define all(a) (a).begin(), (a).end()
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++) // iterate from sequence for a given type
template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }
using namespace std;
 
void f() {
    int n, m; cin >> n >> m;
    vector<pair<int,int>> a(n);
    for (auto &x : a) cin >> x.first >> x.second; // for easier sort
    
    int sum = 0;
    sort(all(a));
    for (auto &x : a) {
        int price = x.first;
        int amount = x.second;
        int to_buy = min(amount, m);
        m -= to_buy;
        sum += to_buy * price;

        if (!m) break; // brought all needed
    }
    cout << sum << endl;
}

signed main() {
    IOS;
    int T=1;
    // cin >> T;
    while (T--) {
        f();
    }
}
