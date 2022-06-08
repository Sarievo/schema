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
    vector<ll> a(n);
    int odds = 0;
    int evens = 0;
    vector<ll> even_nums;
    // ll smallest_even = INT_MAX;
    for (ll &x : a) {
        cin >> x;
        if (x % 2 == 0) {
            evens++;
            // if (x < smallest_even) smallest_even = x;
            even_nums.push_back(x);
        }
    }

    odds = n - evens;
    if (odds) {
        cout << evens << endl;
    } else {
        // the mininum cost of obtaining an odd number
        int ops = evens-1;
        int min_ops = INT_MAX;
        for (ll &x : even_nums) {
            int cur_ops = 0;
            while (x % 2 == 0) {
                x /= 2;
                cur_ops++;
            }
            min_ops = min(min_ops, cur_ops);
        }
        cout << ops + min_ops << endl;
    }

}

int main() {
    fast_cin;
    int t; cin >> t; for (int i = 1; i <= t; i++) {solve();}
    // solve();
}