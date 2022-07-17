#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
// typedef pair<int, int> p32;
// typedef pair<ll, ll> p64;
// typedef pair<double, double> pdd;
// typedef vector<int> v32;
// typedef vector<ll> v64;
// typedef vector<vector<int>> vv32;
// typedef vector<vector<ll>> vv64;
// typedef vector<vector<p64>> vvp64;
// typedef vector<p32> vp32;
// typedef vector<p64> vp64;

#define x first
#define y second
#define pb push_back
#define ln "\n"
#define sz(x) ((ll)(x).size())
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define forn(i, n)     for(int i = 0; i < int(n); i++)
#define fore(i, a, b)  for(int i = int(a); i <= int(b); i++)
#define ford(i, n)     for(int i = int(n - 1); i >= 0; i--)
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
// #define mp make_pair
// #define all(a) (a).begin(), (a).end()
// #define rall(a) (a).rbegin(), (a).rend()
// #define mset(a, val) memset(a, val, sizeof (a))
// #define dbg(x) cout << #x << " = " << x << ln


template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }
template<typename T> inline string toStr(T x) { stringstream st; st << x; string s; st >> s; return s; }
template<typename X, typename T>inline ostream& operator<< (ostream& out, const pair<T, X>& p) { return out << '(' << p.ft << ", " << p.sc << ')'; }
// template<typename T> inline int hasBit(T mask, int b) { return (b >= 0 && (mask & (T(1) << b)) != 0) ? 1 : 0; }

inline int    nextInt()    { int    x; if (scanf("%d",    &x) != 1) throw; return x; }
inline ll     nextInt64()  { ll     x; if (scanf("%I64d", &x) != 1) throw; return x; }
inline double nextDouble() { double x; if (scanf("%lf",   &x) != 1) throw; return x; }

const int INF   = int(1e9);
const ll  INF64 = ll(INF) * ll(INF);
// const ld  EPS   = 1e-9;
// const ld  PI    = ld(3.1415926535897932384626433832795);

bool is_prime(int n) {
    if (n == 1) {
        return false;
    }

    int i = 2;
    while (i*i <= n) {
        if (n % i == 0) {
            return false;
        }
        i += 1;
    }
    return true;
}

int main () {
    int k;
    scanf("%d", &k);
    if (is_prime(k)) {
        printf("1\n");
        printf("%d\n", k);
        return 0;
    }

    if (is_prime(k - 2)) {
        printf("2\n");
        printf("%d %d\n", 2, k-2);
        return 0;
    }

    for (int i = 3; i <= k/3; i++) {
        if (is_prime(i)) {
            int k2 = k - i;
            for (int j = 3; j <= k2/2; j++) {
                if (j == i || is_prime(j)) {
                    int k3 = k2 - j;
                    if (k3 == j || is_prime(k3)) {
                        printf("3\n");
                        printf("%d %d %d\n", i, j, k3);
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}
