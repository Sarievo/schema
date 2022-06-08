/** 
 * Sarievo.
 * URL: https://codeforces.com/problemset/problem/1650/C
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
    // pair<weight,cordinate>
    vector<pair<int,int>> v(m); for (auto &p : v) cin >> p.second >> p.first;
    
    map<int,int> keys;
    for (int i = 1; i <= m; i++) {
        keys[v[i-1].second] = i;
    }

    sort(all(v));
    int cost = 0;

    poly pts;
    rep(i, n*2) {
        cost += v[i].first;
        pts.push_back(v[i].second);
    }

    sort(all(pts));
    cout << cost << endl;

    assert(pts.size() % 2 == 0);
    int L = 0;
    int R = pts.size()-1;
    while (L < R) {
        cout << keys[pts[L++]] << " " << keys[pts[R--]] << endl; // construct
    }
    // cout << endl;
}

signed main() {
    IOS;
    int T=1;
    cin >> T;
    while (T--) f();
}
