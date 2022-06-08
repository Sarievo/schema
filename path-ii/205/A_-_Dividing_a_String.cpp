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
    vector<int> g(s.length()+1);
    g[1] = 1;
    if (s.length() == 1) {
        cout << g[1] << endl;
        return;
    }
    g[2] = (s[0] == s[1] ? 1 : 2);
    if (s.length() == 2) {
        cout << g[2] << endl;
        return;
    }
    for (int i = 3; i <= s.length(); i++) {
        if (s[i-1] != s[i-2]) {
            g[i] = g[i-1] + 1;
        } else {
            g[i] = g[i-3] + 2;
        }
    }
    cout << g[s.length()] << endl;
}

int main() {
    fast_cin;
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
