#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
#define x  first
#define y  second
#define mp make_pair
#define len(a) int((a).size())
#define rep(i, n) for(int i = 0; i < int(n); i++)
#define all(a) (a).begin(), (a).end()
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define fast_cin ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }
//======================================================

void solve() {
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    
    ll money_needed = 0;
    ll price_ab = c*2;
    if (a + b >= price_ab) {
        ll cmb = min(x, y);
        x -= cmb; y -= cmb;
        money_needed = price_ab * cmb;
    } else {
        cout << (a * x + b * y) << endl;
        return;
    }

    if (x) {
        ll price_a = x * a;
        ll price_b = x * price_ab;
        money_needed += min(price_a, price_b);
    }
    if (y) {
        ll price_a = y * b;
        ll price_b = y * price_ab;
        money_needed += min(price_a, price_b);
    }
    cout << money_needed << endl;
}

int main() {
    fast_cin;
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}