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
    vector<int> P(n);
    vector<int> Q(n);
    for (int &x : P) cin >> x;
    for (int &x : Q) cin >> x;
    ll occ_permutation = 0;

    rep(i, n) {
        if (P[i] != Q[i]) {
            if (P[i] > Q[i]) {
                while (Q[i] != P[i]) {
                    next_permutation(all(Q));
                    occ_permutation++;
                }
            } else {
                while (Q[i] != P[i]) {
                    next_permutation(all(P));
                    occ_permutation++;
                }
            }
        }
    }

    cout << occ_permutation << endl;
}

int main() {
    fast_cin;
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
