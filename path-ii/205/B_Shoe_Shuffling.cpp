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

    vector<int> a(n);
    map<int, deque<int>> fmap; // deque with x's indices

    int x;
    rep(i, n) {
        cin >> x;
        a[i] = x;
        auto it = fmap.find(x);
        if (it == fmap.end()) {
            deque<int> q;
            q.push_back(1 + i); // create a new deque or update the existing one
            fmap[x] = q;
        } else {
            it->second.push_back(1 + i);
        }
    }

    if (n == 1) {
        cout << -1 << endl; // cannot shuffle with itself
        return;
    }

    for (pair<int, deque<int>> p : fmap) {
        if (p.second.size() < 2) { // no valid lists of 2 or more pairs
            cout << -1 << endl;
            return;
        }
    }
    
    set<int> inited;

    // into fmap, for each occ, pop last
    vector<int> output(n);
    rep(i, n) {
        auto it = fmap.find(a[i]); // guarantee a valid list
        if (inited.find(it->first) == inited.end()) {
            inited.insert(it->first);
            output[i] = it->second.back();
            it->second.pop_back();
        } else {
            output[i] = it->second.front();
            it->second.pop_front();
        }
    }

    for (int &x : output) cout << x << " ";
    cout << endl;
}

int main() {
    fast_cin;
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
