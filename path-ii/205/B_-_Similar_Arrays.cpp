/** 
 * Sarievo.
 * URL: https://atcoder.jp/contests/code-festival-2017-qualc/tasks/code_festival_2017_qualc_b
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
    deque<poly> q;
    poly ini0(1, a[0]-1);
    poly ini1(1, a[0]);
    poly ini2(1, a[0]+1);
    q.push_back(ini0);
    q.push_back(ini1);
    q.push_back(ini2);
    int layer = 0;
    while (q.size()) {
        ++layer;
        if (layer == n) {
            int eligible_v = 0;
            while (q.size()) {
                poly v = q.front(); q.pop_front();
                for (auto &x : v) {
                    if (x % 2 == 0) {
                        eligible_v++;
                        break;
                    }
                }
            }
            cout << eligible_v << endl;
            return;
        } else {
            int sz = q.size();
            while (sz--) {
                poly v0 = q.front(); q.pop_front();
                poly v1 = v0;
                poly v2 = v0;
                v0.push_back(a[layer]-1);
                v1.push_back(a[layer]);
                v2.push_back(a[layer]+1);
                q.push_back(v0);
                q.push_back(v1);
                q.push_back(v2);
            }
        }
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
