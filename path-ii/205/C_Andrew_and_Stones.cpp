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

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (ll &x : a) {
        cin >> x;
    }
    // the stones aside does not matter at all
    // if there exists odd piles, there must be at least one even pile as well, or it's impossible
    // or if there's at least 2 odd piles and one of them is at least 3, they can remove from each other
    // order does not matter because odd piles are removed sequencially
    ll odd_piles = 0;
    ll even_piles = 0;
    // one can move the sum of even piles by sum/2 times
    ll sum_of_even_piles = 0;
    // 1 3 5 7 -> 1 3 5 8(1) -> 2 4 6(5) -> 2 4(8)
    // 1 3 5 7 -> 1 3 6 7(1) -> 2 4 8(4) -> 4 8(5) -> 8(7) -> (11) // the order does not matter at all
    // 1 3 5 7 -> 2 3 5 7(1) -> 4 5 7(2) -> 6 7(4) -> 8(7) -> (11) (1+2+3+4+1)
    // the array of odd piles can be removed in SUM:(ai+1)/2 +1 times
    ll sum_of_odd_piles_addition = 0;
    ll at_least1_odd_at_least3 = false;
    for (int i = 1; i < n-1; i++) {
        if (a[i] % 2 == 0) {
            even_piles++;
            sum_of_even_piles += a[i];
        } else {
            odd_piles++;
            if (a[i] >= 3) at_least1_odd_at_least3 = true;
            sum_of_odd_piles_addition += (a[i]+1);
        }
    }

    ll even_piles_to_remove = sum_of_even_piles / 2;
    if (odd_piles) {
        if (!even_piles) {
            if (odd_piles > 1 && at_least1_odd_at_least3) {
                ll to_remove = sum_of_odd_piles_addition / 2;
                cout << to_remove << endl;
            } else
                cout << -1 << endl; return; // impossible
        } else {
            ll to_remove = even_piles_to_remove + sum_of_odd_piles_addition/2;
            cout << to_remove << endl;
        }
    } else {
        // no odd piles
        cout << even_piles_to_remove << endl;
    }
}

int main() {
    fast_cin;
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
