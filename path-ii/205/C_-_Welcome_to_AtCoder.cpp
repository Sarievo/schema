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
    int n, m;
    cin >> n >> m;
    set<int> ACs;
    map<int,int> WAs;
    int id;
    string type;
    rep(i, m) {
        cin >> id >> type;
        if (type == "AC") {
            ACs.insert(id);
        } else {
            if (ACs.find(id) == ACs.end()) // only the peneties before the AC submissions is logged 
                WAs[id]++;
        }
    }

    int peneties = 0;
    for (int i : ACs) {
        auto it = WAs.find(i);
        if (it != WAs.end()) {
            peneties += it->second;
        }
    }
    cout << ACs.size() << " " << peneties << endl;
}

int main() {
    fast_cin;
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}