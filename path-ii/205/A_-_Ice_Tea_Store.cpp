/** 
 * Sarievo.
 * URL: https://atcoder.jp/contests/agc019/tasks/agc019_a
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
    int q, h, s, d, n; cin >> q >> h >> s >> d >> n;
    // choose only between .5, .25, and 1, then choose only between prev and .2 greedy
    int price_25 = q*4;
    int price_50 = h*2;
    int one_liter_choice = min(s, min(price_25, price_50));
    int two_liter_choice = min(d, one_liter_choice*2);
    int two_liter_fill = n/2;
    int one_liter_fill = n-two_liter_fill*2;
    if (!two_liter_fill) {
        cout << one_liter_choice << endl;
    } else {
        int ans = one_liter_choice * one_liter_fill;
        ans += two_liter_fill * two_liter_choice;
        cout << ans << endl;
    }
}

signed main() {
    IOS;
    int T=1;
    // cin >> T;
    while (T--) {
        f();
    }
}
