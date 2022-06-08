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

    vector<vector<int>> m(3);
    for (vector<int> &a : m) {
        a = vector<int>(3);
        for (int &x : a) cin >> x;
    }

    int n, x;
    set<int> es;

    cin >> n;
    rep(i, n) {
        cin >> x;
        es.insert(x);
    }

    // cout << "COMPLETE" << endl;
    // for (int i : es) cout << i << " ";
    // cout << endl;
    // for (vector<int> a : m) for (int i : a) cout << i << " ";

    bool r1 = true;
    bool r2 = true;
    bool r3 = true;

    rep(i, 3) {
        if (r1 && (es.find(m[0][i]) == es.end()))
            r1 = false;
        if (r2 && (es.find(m[1][i]) == es.end()))
            r2 = false;
        if (r3 && (es.find(m[2][i]) == es.end()))
            r3 = false;
    }
    if (r1 || r2 || r3) {
        cout << "Yes" << endl; return;
    }

    bool c1 = true;
    bool c2 = true;
    bool c3 = true;

    rep(i, 3) {
        if (c1 && (es.find(m[i][0]) == es.end()))
            c1 = false;
        if (c2 && (es.find(m[i][1]) == es.end()))
            c2 = false;
        if (c3 && (es.find(m[i][2]) == es.end()))
            c3 = false;
    }
    if (c1 || c2 || c3) {
        cout << "Yes" << endl; return;
    }
    
    bool d1 = true;
    bool d2 = true;

    rep(i, 3) {
        if (d1 && (es.find(m[i][i]) == es.end()))
            d1 = false;
        if (d2 && (es.find(m[(2-i)][i]) == es.end()))
            d2 = false;
    }

    if (d1 || d2) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    fast_cin;
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
