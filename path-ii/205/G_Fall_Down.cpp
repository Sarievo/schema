/** 
 * Sarievo.
 * URL: \problemset\problem\1669\G
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
    vector<vector<char>> g(r, vector<char>(c, '.'));
    rep(i, r) {
        string s;
        cin >> s;
        rep(j, c) {
            if (s[j] == '*')
                g[i][j] = '*';
            else if (s[j] == 'o')
                g[i][j] = 'o';
        }
    }

    rep(i, c) {
        int last_seen_rock = r;
        for (int j = r-1; j>= 0; j--) {
            if (g[j][i] == 'o') {
                last_seen_rock = j;
            } else if (g[j][i] == '*'){
                swap(g[j][i], g[last_seen_rock-1][i]);
                last_seen_rock--;
            }
        }
    }

    rep(i, r) {
        rep(j, c) cout << g[i][j];
        cout << '\n';
    }
    // cout << '\n';
}

signed main() {
    IOS;
    int T=1;
    cin >> T;
    while (T--) {
        f();
    }
}
