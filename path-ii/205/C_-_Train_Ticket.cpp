/** 
 * Sarievo.
 * URL: https://atcoder.jp/contests/abc079/tasks/abc079_c
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
    string s; cin >> s;
    deque<pair<int, vector<char>>> q;
    q.push_back({s[0]-'0', {}});
    int layer = 0;
    while(q.size()) {
        layer++;
        int sz = q.size();
        rep(i, sz) {
            if (layer != s.size()) {
                auto p = q.front(); q.pop_front();
                auto v1 = p.second; v1.push_back({'+'});
                auto v2 = p.second; v2.push_back({'-'});
                q.push_back({p.first + (s[layer]-'0'), v1});
                q.push_back({p.first - (s[layer]-'0'), v2});
            } else {
                auto p = q.front(); q.pop_front();
                int sum = p.first;
                if (sum == 7) {
                    string ans = "";
                    ans.push_back(s[0]);
                    rep(i, 3) {
                        ans.push_back(p.second[i]);
                        ans.push_back(s[i+1]);
                    }
                    ans.append("=7");
                    cout << ans << endl;
                    return;
                }
            }
        }
    }
    // cout << "???" << 
}

signed main() {
    IOS;
    int T=1;
    // cin >> T;
    while (T--) {
        f();
    }
}
