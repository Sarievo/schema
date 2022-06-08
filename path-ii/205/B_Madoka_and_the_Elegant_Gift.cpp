/** 
 * Sarievo.
 * URL: https://codeforces.com/problemset/problem/1647/B
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
    int r, c; cin >> r >> c;
    vector<vector<int>> a(r, vector<int> (c));
    rep(i, r) {
        string s; cin >> s;
        rep(j, c) a[i][j] = s[j]-'0';
    }
    rep(i, r-1) {
        rep(j, c-1) { // if any 2x2 block contains 3 coloured block, there are at least 2 intersections
            int sum = a[i][j] + a[i][j+1] + a[i+1][j] + a[i+1][j+1];
            if (sum == 3) {
                cout << "NO\n"; return;
            }
        }
    }
    cout << "YES\n";
}

signed main() {
    IOS;
    int T=1;
    cin >> T;
    while (T--) {
        f();
    }
}
