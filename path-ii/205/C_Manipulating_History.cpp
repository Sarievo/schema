/** 
 * Sarievo.
 * URL: https://codeforces.com/contest/1688/problem/C
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
    map<char,int> m;
    string s;
    rep(i, n*2+1) {
        cin >> s;
        // cout << "read: " << s << endl;
        for (char ch : s) m[ch]++; // ??
    }

    for (auto &p : m) {
        if (p.second % 2 == 1) {
            cout << p.first << endl;
            return;
        }
    }
}

signed main() {
    IOS;
    int T=1;
    cin >> T;
    while (T--) {
        f();
    }
}
