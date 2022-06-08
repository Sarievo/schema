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

    double sum = 0;
    for (int &x : a) {
        cin >> x;
        sum += x;
    }

    bool all_equal = true;
    rep(i, n-1) {
        if (a[i+1] != a[i]) {
            all_equal = false;
            break;
        }
    }
    if (all_equal) {
        cout << "YES" << endl;
        return;
    }

    for (int &x : a) {
        double avg = (sum - x) * 1.0 / (n-1);
        if (avg == x) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    fast_cin;
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
