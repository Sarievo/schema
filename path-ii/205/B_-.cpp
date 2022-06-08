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
    string s, t;
    cin >> s >> t;
    int p1 = 0;
    int p2 = 0;
    string pass = "";
    bool alt = true;
    while (p1 != s.length() && p2 != t.length()) {
        if (alt) {
            pass += s[p1++];
        } else {
            pass += t[p2++];
        }
        alt = !alt;
    }
    if (p1 != s.length()) pass += s[p1];
    if (p2 != t.length()) pass += t[p2];
    cout << pass << endl;
}

int main() {
    fast_cin;
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
