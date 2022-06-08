/** 
 * Sarievo.
 * URL: https://atcoder.jp/contests/abc135/tasks/abc135_c
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
    poly a(n+1); for (auto &x : a) cin >> x;
    poly b(n); for (auto &x : b) cin >> x;

    int total_defeated = 0;
    rep(i, n) {
        int this_monsters = a[i];
        int next_monsters = a[i+1];
        int sum_of_monsters = this_monsters+next_monsters;
        int hero_atk = b[i];
        if (hero_atk <= this_monsters) {
            a[i] -= hero_atk;
            total_defeated += hero_atk;
        } else {
            int atk_remain = hero_atk - a[i];
            int this_defeated = a[i];
            a[i] = 0;
            int next_defeated = min(next_monsters, atk_remain);
            a[i+1] -= next_defeated;
            total_defeated += this_defeated + next_defeated;
        }
    }
    cout << total_defeated << endl;
}

signed main() {
    IOS;
    int T=1;
    // cin >> T;
    while (T--) {
        f();
    }
}
