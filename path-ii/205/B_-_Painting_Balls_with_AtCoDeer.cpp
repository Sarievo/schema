/** 
 * Sarievo.
 * URL: 
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
    int n, k; cin >> n >> k;
    if (n == 1) {
        cout << k << endl;
    } else {
        // only adj balls need to be different
        // k choice at ball 1, k-1 choice at ball 2, k-1 choice at ball 3 ...
        int base = k;
        for (int i = 1; i < n; i++) {
            base *= k-1;
        }
        cout << base << endl;
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
