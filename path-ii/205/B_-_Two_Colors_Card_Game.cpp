/** 
 * Sarievo.
 * URL: \contests\abc091\tasks\abc091_b
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
 
map<string,int> fmap1;
map<string,int> fmap2;
void f() {
    int n; cin >> n;
    vector<string> s(n); for (auto &x : s) {
        cin >> x; fmap1[x]++;
    }
    int m; cin >> m;
    vector<string> t(m); for (auto &x : t) {
        cin >> x; fmap2[x]++;
    }
    int max_occ = 0;
    for (auto p : fmap1) {
        auto it = fmap2.find(p.first);
        if (it == fmap2.end()) { // the type card does not occur in fmap2
            max_occ = max(max_occ, p.second);
        } else {
            max_occ = max(max_occ, p.second - it->second);
        }
    }
    cout << max_occ << endl;
}

signed main() {
    IOS;
    int T=1;
    // cin >> T;
    while (T--) {
        f();
    }
}
