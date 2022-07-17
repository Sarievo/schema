#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
#define x  first
#define y  second
#define pb push_back
#define mp make_pair
#define len(a) int((a).size())
// #define mset(a, val) memset(a, val, sizeof (a)) // ??
#define rep(i, n) for(int i = 0; i < int(n); i++)
// #define rrep(i, n) for(int i = int(n - 1); i >= 0; i--)
// #define frep(i, a, b) for(int i = int(a); i <= int(b); i++) // ??
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define fast_cin ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }
//======================================================

int n;
vector<int> A;

bool read() {
    cin >> n;
    A = vector<int>(n);

    rep(i, n) cin >> A[i];
    return true;
}

void solve() {
    assert(read());
    int L = A[0], R = A[0];
    rep(i, n) {
        L = min(L, A[i]);
        R = max(R, A[i]);
    }
    int ans = INT_MAX;
    for (int i = L; i <= R; i++) {
        int cost = 0;
        rep(j, n) cost += (A[j] - i) * (A[j] - i);
        ans = min(ans, cost);
    }

    cout << ans << endl;
}

int main() {
    fast_cin;
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
