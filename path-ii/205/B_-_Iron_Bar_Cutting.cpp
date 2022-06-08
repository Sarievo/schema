/** 
 * Sarievo.
 * URL: https://atcoder.jp/contests/ddcc2020-qual/tasks/ddcc2020_qual_b
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
    poly a(n); for (auto &x : a) cin >> x;
    poly prefix_sum_a(n);
    poly prefix_sum_b(n);
    prefix_sum_a[0]   = a[0];
    prefix_sum_b[n-1] = a[n-1];
    rep(i, n-1)
        prefix_sum_a[i+1] = prefix_sum_a[i]+a[i+1];
    for (int i = n-1; i > 0; i--)
        prefix_sum_b[i-1] = prefix_sum_b[i]+a[i-1];
    
    // for (auto &x : prefix_sum_a) cout << x << " "; cout << endl;// debug
    // for (auto &x : prefix_sum_b) cout << x << " "; cout << endl;// debug
    int min_diff = INT_MAX;
    rep(i, n-1) {
        int diff = abs(prefix_sum_a[i] - prefix_sum_b[i+1]);
        min_diff = min(min_diff, diff);
    }
    cout << min_diff << endl;
}

signed main() {
    IOS;
    int T=1;
    // cin >> T;
    while (T--) {
        f();
    }
}
