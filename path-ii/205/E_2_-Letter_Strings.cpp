/** 
 * Sarievo.
 * URL: https://codeforces.com/problemset/problem/1669/E
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
// #define int ll
#define all(a) (a).begin(), (a).end()
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++) // iterate from sequence for a given type
template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }
using namespace std;

void f() {
    int n; cin >> n;
    map<char, int> L,R;
    map<string,int> S;
    string ch;
    long long sum = 0;
    rep(i, n) {
        cin >> ch;
        sum += L[ch[0]]+R[ch[1]];
        if (S[ch] != 0)
            sum -= 2*S[ch];
        L[ch[0]]++;
        R[ch[1]]++;
        S[ch]++;
    }
    cout << sum << endl;
}

signed main() {
    IOS;
    int T=1;
    cin >> T;
    while (T--) {
        f();
    }
}
