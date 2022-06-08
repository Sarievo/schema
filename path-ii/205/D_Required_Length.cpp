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
    ll n, v;
    cin >> n >> v;
    // BFS
    queue<ll> q;
    map<ll, int> dist;
    dist[v] = 0;
    q.push(v);
    while (!q.empty()) {
        ll k = q.front();
        q.pop();
        string s = to_string(k);
        if (s.size() == n) {
            cout << dist[k] << endl;
            return;
        }

        for (auto x : s) {
            if(x == '0') continue;
            ll w = k * int(x-'0');
            if (!dist.count(w)) {
                dist[w] = dist[k]+1;
                q.push(w);
            }
        }
    }
    cout << -1 << endl;
}

int main() {
    fast_cin;
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
