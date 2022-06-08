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

constexpr int MAXSUM = 100 * 100 + 10;

void solve() {
    int n, d;
    cin >> n >> d;
    vector<vector<int>> a(n, vector<int>(d));
    rep(i, n) rep(j, d) cin >> a[i][j];

    int time_pairs = 0;
    rep(i, n) {
        for (int j = i+1; j < n; j++) {
            ll total_d = 0;
            rep(k, d) {
                total_d += sqr(a[i][k] - a[j][k]);
            }
            for (int i = 1; i*i <= total_d; i++) {
                if (i*i == total_d) {
                    time_pairs++;
                    break;
                }
            }
        }
    }
    cout << time_pairs << endl;
}

int main() {
    fast_cin;
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
