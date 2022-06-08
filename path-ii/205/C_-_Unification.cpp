/** 
 * Sarievo.
 * URL: \contests\abc120\tasks\abc120_c
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
    string s;
    cin >> s;
    int _0s = 0;
    int _1s = 0;
    for (char ch : s) {
        if (ch == '0') _0s++;
        else _1s++;
    }
    cout << 2*min(_0s, _1s) << endl;
}

signed main() {
    IOS;
    int T=1;
    // cin >> T;
    while (T--) {
        f();
    }
}
