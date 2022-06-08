/** 
 * Sarievo.
 * URL: https://codeforces.com/problemset/problem/1685/A
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
    
    poly a(n);
    for (int &x : a) cin >> x;

    if (n % 2 == 1) {
        cout << "NO\n";
        return;
    }

    int m = n/2;
    sort(all(a));
    poly b(a.begin(), a.begin() + m);
    poly c(a.begin() + m, a.end());

    bool bad = false;
    rep(i, m) {
        if (b[i] >= c[i % m] or b[i] >= c[(i-1+m) % m]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    rep(i, m) {
        cout << a[i] << " ";
        cout << a[i+m] << " ";
    }
    cout << endl;
}

signed main() {
    IOS;
    int T=1;
    cin >> T;
    while (T--) {
        f();
    }
}
//🦴