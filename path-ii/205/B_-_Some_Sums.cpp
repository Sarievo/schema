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

constexpr int MAXSUM = 100 * 100 + 10;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        int tmp = i;
        int sum_of_digits = 0;
        while (tmp) {
            sum_of_digits += (tmp % 10);
            tmp /= 10;
        }

        // cout << "sod " << i << " is " << sum_of_digits;
        if (sum_of_digits >= a 
                && sum_of_digits <= b) {
            sum += i;
            // cout << "\t(valid)" << endl;
        } else {
            // cout << "\t(invalid)" << endl;
        }
    }

    cout << sum << endl;
}

int main() {
    fast_cin;
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
