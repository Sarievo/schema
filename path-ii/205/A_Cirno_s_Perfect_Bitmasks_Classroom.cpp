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
    ull x;
    cin >> x;
    bitset<64> bits(x);

    int _1st_on_id = -1;
    int _1st_off_id = -1;
    int num_of_ons = 0;

    for (int i = 0; i < bits.size(); i++) {

        if (bits[i]) {
            num_of_ons++;
            if (_1st_on_id == -1) {
                // cout << " i" << i << endl; //db
                _1st_on_id = i;
            }
        } else {
            if (_1st_off_id == -1) {
                _1st_off_id = i;
            }
        }
    }

    if (num_of_ons == 1) {
        for (int i = 0; i < bits.size(); i++) {
            if (i == _1st_on_id || i == _1st_off_id) {
                bits[i] = 1;
            } else {
                bits[i] = 0;
            }
        }
    } else {
        for (int i = 0; i < bits.size(); i++) {
            // cout << bits[i];
            if (i != _1st_on_id) {
                bits[i] = 0;
            }
        }
    }

    ull ans = bits.to_ullong();
    cout << ans << endl;
}

int main() {
    fast_cin;
    int t; cin >> t; for (int i = 1; i <= t; i++) {solve();}
    // solve();
}