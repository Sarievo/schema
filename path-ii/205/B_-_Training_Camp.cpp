/** 
 * Sarievo.
 * URL: \contests\abc055\tasks\abc055_b
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

int mod = 1e9+7;

void f() {
    int n; cin >> n;
    int init = 1;
    for (int i = 1; i <= n; i++) {
        init = (init * i) % mod;
    }
    cout << init << endl;
}

signed main() {
    IOS;
    int T=1;
    // cin >> T;
    while (T--) {
        f();
    }
}
