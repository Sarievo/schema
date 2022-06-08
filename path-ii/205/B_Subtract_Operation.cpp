/** 
 * Sarievo.
 * URL: https://codeforces.com/problemset/problem/1656/B
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
    poly v(n); for (auto &x : v) cin >> x;
    sort(all(v));
    bool ans = false;
    if (n==1) ans = (v[0] == k);
    else {
        int i = 0;
        int j = 1;
        while (i < n && j < n) {
            if (v[i] + abs(k) == v[j]) {
                ans = true; break;
            } else if (v[i] + abs(k) < v[j]) {
                i++;
            } else {
                j++;
            }
        }
    }
    cout << (ans ? "YES" : "NO") << "\n";
}

signed main() {
    IOS;
    int T=1;
    cin >> T;
    while (T--) f();
}
