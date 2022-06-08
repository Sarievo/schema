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
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (int &x : h) cin >> x;
    sort(all(h));

    int min_dif = abs(h[0]-h[k-1]);
    for (int i = 1; i <= n-k; i++) {
        int prev = h[i];
        int next = h[i+(k-1)];
        int cur_dif = abs(prev-next); // sliding window
        if (cur_dif < min_dif)
            min_dif = cur_dif;
    }
    cout << min_dif << endl;
}

int main() {
    fast_cin;
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}