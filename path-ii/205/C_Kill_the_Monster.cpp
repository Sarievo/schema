#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
#define x  first
#define y  second
#define pb push_back
#define mp make_pair
#define len(a) int((a).size())
// #define mset(a, val) memset(a, val, sizeof (a))              // ??
// #define dfor(i, n) for(int i = int(n - 1); i >= 0; i--)      // ??
// #define ffor(i, a, b) for(int i = int(a); i <= int(b); i++)  // ??
#define rep(i, n) for(int i = 0; i < int(n); i++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define fast_cin ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }
//======================================================

ll hc, dc;
ll hm, dm;
ll k, w, a;

bool read() {
    cin >> hc >> dc >> hm >> dm >> k >> w >> a;
    return true;
}

void solve() {
    assert(read());
    rep(i, k+1) {
        ll spent_on_weapon = i;
        ll spent_on_armour = k-i;

        ll _hc = hc + (spent_on_armour * a);
        ll _dc = dc + (spent_on_weapon * w);

        ll moster_hits = (hm / _dc) + (hm % _dc ? 1 : 0);
        ll monocarp_hits = (_hc / dm) + (_hc % dm ? 1 : 0);

        if (monocarp_hits >= moster_hits) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    fast_cin;
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
