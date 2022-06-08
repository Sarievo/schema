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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    vector<int> tmp(n);
    iota(all(tmp), 0);
    sort(all(tmp), [&](int i, int j){
        return mp(a[i], b[i]) < mp(a[j], b[j]); // ??
    });
    rep(i, n-1) {
        if (a[tmp[i]] > a[tmp[i+1]] || b[tmp[i]] > b[tmp[i+1]]) {
            cout << "-1" << endl;
            return;
        }
    }

    vector<pair<int,int>> ans;
    rep(i, n-1) {
        rep(j, n-1) {
            if (a[j] > a[j+1] || b[j] > b[j+1]) {
                swap(a[j], a[j+1]); // bubble sort with 2 arrays
                swap(b[j], b[j+1]);
                ans.push_back({j+1, j+2});
            }
        }
    }
    cout << ans.size() << endl;
    foreach(e, ans)
        cout << e->first << " " << e->second << endl;
}

int main() {
    fast_cin;
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
