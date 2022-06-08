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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    // find the max-2 elements... so
    int max_1 = -1;
    int max_1_id = -1;
    int max_2 = -1;
    int max_2_id = -1;

    rep(i, n) {
        if (a[i] > max_1) {
            max_1 = a[i];
            max_1_id = i;
        }
    }
    rep(i, n) {
        if (a[i] > max_2 && i != max_1_id) {
            max_2 = a[i];
            max_2_id = i;
        }
    }
    rep(i, n) {
        if (i != max_1_id) {
            cout << max_1 << endl;
        } else {
            cout << max_2 << endl;
        }
    }
}

int main() {
    fast_cin;
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
