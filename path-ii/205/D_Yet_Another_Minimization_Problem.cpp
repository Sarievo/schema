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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;


    int sumMin = 0, sumMax = 0, sumSq = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i])
            swap(a[i], b[i]);
 
        sumSq += sqr(a[i]) + sqr(b[i]);
        sumMin += a[i];
        sumMax += b[i];
    }

    bitset<MAXSUM> dp;
    dp[0] = 1;
    for (int i = 0; i < n; i++)
        dp |= dp << (b[i] - a[i]);
 
    int ans = sqr(sumMin) + sqr(sumMax);
    for (int i = 0; i <= sumMax - sumMin; i++)
        if (dp[i])
            ans = min(ans, sqr(sumMin + i) + sqr(sumMax - i));
 
    cout << sumSq * (n - 2) + ans << '\n';
}

int main() {
    fast_cin;
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
