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
    vector<int> times(5);
    for (int &x : times) cin >> x;
    sort(all(times), [](int a, int b){
        int rem_a = a % 10;
        int rem_b = b % 10;
        int time_to_wait_a = rem_a ? 10 - rem_a : 0;
        int time_to_wait_b = rem_b ? 10 - rem_b : 0;
        return time_to_wait_a < time_to_wait_b;
    });
    int sum = 0;
    rep(i, 5) {
        int e = times[i];
        int rem = e % 10;
        if (rem && i < 4) {
            sum += e + (10-rem);
        } else {
            sum += e;
        }
    }
    cout << sum << endl;
}

int main() {
    fast_cin;
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
