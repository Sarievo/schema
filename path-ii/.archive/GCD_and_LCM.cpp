#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define x first
#define y second
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) static_cast<int32_t>(x.size())
#define afor(i, n)     for(int i = 0; i < int(n); i++)
#define dfor(i, n)     for(int i = int(n - 1); i >= 0; i--)
#define ffor(i, a, b)  for(int i = int(a); i <= int(b); i++)
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


const int N = 1e7 + 5;
const int INF = 2e9, MOD = 1e9+7;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    fast_cin();
    int t = 1;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        ll _gcd = gcd(a, b);
        ll _lcm = a / _gcd * b;
        cout << _gcd << " " << _lcm << endl;
    }
}