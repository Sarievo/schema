#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) static_cast<int32_t>(x.size())
#define x first
#define y second
#define afor(i, n)     for(int i = 0; i < int(n); i++)
#define dfor(i, n)     for(int i = int(n - 1); i >= 0; i--)
#define ffor(i, a, b)  for(int i = int(a); i <= int(b); i++)
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


const int N = 1e7 + 5;
const int INF = 2e9, MOD = 1e9+7;
 
int main() {
    fast_cin();
    int n;
    // spf is the smallest prime factor
    // precompute spf for all n using prime sieve (O(n loglogn))
    array<int, N> spf; iota(all(spf), 0);
    for(int i = 4; i < N; i += 2) spf[i] = 2;
    for(int i = 3; i*i < N; i += 2)
        if(spf[i] == i) for(int j = i*i; j < N; j+=i*2) // 9..(12)..15..(18)..21
            if(spf[j] == j) spf[j] = i;
 
    // Answer queries in O(log n) per query.
    // Log n because the maximum number of prime factors is log2 n.
    while(cin >> n) {
        cout << 1;
        while(n > 1) {
            cout << " x " << spf[n];
            n /= spf[n];
        } cout << '\n';
    }
    
} // ~W 