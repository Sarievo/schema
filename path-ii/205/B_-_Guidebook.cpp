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
    int n;
    cin >> n;
    vector<pair<string,int>> r(n);
    for (pair<string,int> &x : r) {
        cin >> x.first >> x.second;
        // cout << x.first << " " << x.second << endl; // debug
    }

    vector<int> ids(n);
    iota(all(ids), 0); // ref: https://www.techiedelight.com/initialize-a-vector-with-sequential-range-1-to-n-in-cpp/
    // for (int &x : ids) cout << x << endl; // debug

    sort(all(ids), [&](int i, int j){
        if (r[i].first == r[j].first)
            return r[i].second > r[j].second;
        return r[i].first < r[j].first;
    });

    for (int &x : ids) cout << (x+1) << endl;
}

int main() {
    fast_cin;
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
