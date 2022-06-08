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


void solve() {
    int n, m;
    cin >> n >> m;
    // vector<bool> like_foods(m, false);
    set<int> liked_foods;

    int k, id;
    rep(i, n) {
        cin >> k;
        if (i == 0) {
            rep(j, k) {
                cin >> id;
                liked_foods.insert(id);
                // like_foods[id] = true;
            }
        } else {
            set<int> tmp_set;
            rep(j, k) {
                cin >> id;
                tmp_set.insert(id);
            }
            if (liked_foods.size()) {
                // you can skip the chk if there's nothing left
                set<int> even_another_set;
                for (int i : liked_foods) {
                    if (tmp_set.find(i) != tmp_set.end()) {
                        even_another_set.insert(i);
                    }
                }
                liked_foods = even_another_set;
            }
        }
    }
    cout << liked_foods.size() << endl;
}

int main() {
    fast_cin;
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
