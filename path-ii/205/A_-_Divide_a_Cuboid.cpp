/** 
 * Sarievo.
 * URL: https://atcoder.jp/contests/agc004/tasks/agc004_a
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
    int a, b, c; cin >> a >> b >> c;
    if (a % 2 == 0 || b % 2 == 0 || c % 2 == 0) {
        cout << 0 << endl;
        return; // if any of the side is of even length, we can divide it in half
    } else {
        if (c >= a && c >= b) {
            cout << a * b << endl;
            return;
        }
        if (b >= a && b >= c) {
            cout << a * c << endl;
            return;
        }
        cout << b * c << endl;
        return; // otherwise, divide from the side of the most length is always profitable
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
