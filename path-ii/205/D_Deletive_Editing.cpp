/** 
 * Sarievo.
 * URL: https://codeforces.com/problemset/problem/1666/D
 */

#include <bits/stdc++.h>
#define poly vector<int>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) // make io faster
#define rep(i, n) for(int i = 0; i < n; i++)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair<int,int>
#define fi first
#define se second
#define inf 1e18
#define int ll
#define all(a) (a).begin(), (a).end()
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++) // iterate from sequence for a given type
template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }
using namespace std;
 
void f() {
    string s, t; cin >> s >> t;
    reverse(all(s));
    reverse(all(t));
    set<char> keys;
    map<char, int> validation;
    for (char &ch : t) {
        keys.insert(ch);
        validation[ch]++;
    }
    int pos = 0;
    int cmp = t[pos];
    for (char ch : s) {
        if (keys.find(ch) != keys.end()) {
            if (ch != cmp) {
                cout << "NO" << endl; return;
            }
            validation[ch]--;
            if (validation[ch] == 0) {
                keys.erase(ch);
                validation.erase(validation.find(ch));
            }
            cmp = t[++pos];
        }
    }
    if (keys.size()) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

signed main() {
    IOS;
    int T=1;
    cin >> T;
    while (T--) {
        f();
    }
}
