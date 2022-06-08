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
    int x;
    cin >> x;
    vector<bool> validity(1e5 + 5, false);
    validity[100] = true;
    validity[101] = true;
    validity[102] = true;
    validity[103] = true;
    validity[104] = true;
    validity[105] = true;
    for (int i = 200; i < 1e5 + 5; i++) {
        if (validity[i - 100]
                || validity[i - 101]
                || validity[i - 102]
                || validity[i - 103]
                || validity[i - 104]
                || validity[i - 105])
            validity[i] = true;
    }
    cout << validity[x] << endl;
}

int main() {
    fast_cin;
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
