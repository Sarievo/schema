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
    vector<string> a(n);
    map<string,int> fmap;
    int max_occ = -1;
    for (string &x : a) {
        cin >> x;
        fmap[x]++;
        max_occ = max(max_occ, fmap[x]);
    };

    vector<string> outputs;
    for (pair<string,int> p : fmap) {
        if (p.second == max_occ)
            outputs.push_back(p.first);
    }
    
    sort(all(outputs));
    for (string &x : outputs) cout << x << endl;
}

int main() {
    fast_cin;
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
