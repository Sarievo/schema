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
    string s;
    cin >> s;
    bool has_moved_N = false;
    bool has_moved_S = false;
    bool has_moved_E = false;
    bool has_moved_W = false;
    for (char c : s) {
        if (c == 'N')
            has_moved_N = true;
        else if (c == 'S') has_moved_S = true;
        else if (c == 'E') has_moved_E = true;
        else if (c == 'W') has_moved_W = true; // ...
    }

    if ((has_moved_W && !has_moved_E || has_moved_E && !has_moved_W)
            || (has_moved_N && !has_moved_S || has_moved_S && !has_moved_N)) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}

int main() {
    fast_cin;
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
