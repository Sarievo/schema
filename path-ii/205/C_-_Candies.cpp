/** 
 * Sarievo.
 * URL: https://atcoder.jp/contests/abc087/tasks/arc090_a
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
    int n; cin >> n;
    poly a1(n); for (auto &x : a1) cin >> x;
    poly a2(n); for (auto &x : a2) cin >> x;
    poly prefix_sum_a1(n);
    poly prefix_sum_a2(n);
    prefix_sum_a1[0] = a1[0];
    reverse(all(a2)); // the order is important
    prefix_sum_a2[0] = a2[0];

    for (int i = 1; i < n; i++) {
        prefix_sum_a1[i] = prefix_sum_a1[i-1]+a1[i];
        prefix_sum_a2[i] = prefix_sum_a2[i-1]+a2[i];
    }
    reverse(all(prefix_sum_a2));
    int pre_sum = 0;
    rep(i, n) {
        int cmax = prefix_sum_a1[i]+prefix_sum_a2[i];
        if (cmax > pre_sum) {
            pre_sum = cmax;
            // cout << "found at " << i << ", the sum is " << cmax << endl; // debug
        }
    }
    cout << pre_sum << endl;
}

signed main() {
    IOS;
    int T=1;
    // cin >> T;
    while (T--) {
        f();
    }
}
