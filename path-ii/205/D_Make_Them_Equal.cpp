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

const int N = 1001;
vector<int> d(N, N);

void populate() {
  d[1] = 0;
  for (int i = 1; i < N; i++) {
    for (int x = 1; x <= i; x++) {
        int j = i + i / x;
        if (j < N) d[j] = min(d[j], d[i] + 1);
    }
  }
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> b(n), c(n);
    for (int &x : b) cin >> x;
    for (int &x : c) cin >> x;

    int sum = 0;
    for (int x : b) sum += d[x];
    k = min(k, sum);

    // knapsack
    vector<int> dp(k + 1, 0);
    for (int i = 0; i < n; ++i) {
      int cost = d[b[i]];
      for (int j = k - cost; j >= 0; j--) {
        dp[j + cost] = max(dp[j + cost], dp[j] + c[i]);
      }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}

int main() {
  fast_cin;
  populate();
  int cases; cin >> cases; for (int i = 1; i <= cases; i++) {solve();}
  // solve();
}

