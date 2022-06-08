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
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    ll sum_of_a = 0;
    for (ll &x : a) {
        cin >> x;
        sum_of_a += x;
    }

    bool is_sum_odd = sum_of_a % 2 == 1;
    // if sum is odd, it'll change the parity, else it won't
    bool parity_of_alice = x % 2 == 1;
    bool parity_of_answer = y % 2 == 1;
    if (is_sum_odd) {
        if (parity_of_alice != parity_of_answer) {
            cout << "Alice" << endl;
        } else {
            cout << "Bob" << endl;
        }
    } else {
        if (parity_of_alice == parity_of_answer) {
            cout << "Alice" << endl;
        } else {
            cout << "Bob" << endl;
        }
    }
}

int main() {
  fast_cin;
  int cases; cin >> cases; for (int i = 1; i <= cases; i++) {solve();}
  // solve();
}

