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
    // init string is length-1
    ll n;
    cin >> n;

    ll min_dist = 1e12+5;
    for (ll i = 1; i*i <= n; i++) {
        ll a = i;
        if (n % a != 0) continue;

        ll b = n/a;
        ll dist = a+b-2;
        min_dist = min(min_dist, dist);
    }
    cout << min_dist << endl;
}

int main() {
    fast_cin;
    // int t; cin >> t; for (int i = 1; i <= t; i++) {solve();}
    solve();
}