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
// #define mp make_pair
#define ln "\n"
// #define mset(a, val) memset(a, val, sizeof (a))
#define sz(x) ((ll)(x).size())
// #define all(a) (a).begin(), (a).end()
// #define rall(a) (a).rbegin(), (a).rend()
// #define dbg(x) cout << #x << " = " << x << ln
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define forn(i, n)     for(int i = 0; i < int(n); i++)
#define fore(i, a, b)  for(int i = int(a); i <= int(b); i++)
#define ford(i, n)     for(int i = int(n - 1); i >= 0; i--)
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
ll MOD = 998244353;

template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }
template<typename T> inline string toStr(T x) { stringstream st; st << x; string s; st >> s; return s; }
// template<typename T> inline int hasBit(T mask, int b) { return (b >= 0 && (mask & (T(1) << b)) != 0) ? 1 : 0; }
template<typename X, typename T>inline ostream& operator<< (ostream& out, const pair<T, X>& p) { return out << '(' << p.ft << ", " << p.sc << ')'; }

inline int    nextInt()    { int    x; if (scanf("%d",    &x) != 1) throw; return x; }
inline ll     nextInt64()  { ll     x; if (scanf("%I64d", &x) != 1) throw; return x; }
inline double nextDouble() { double x; if (scanf("%lf",   &x) != 1) throw; return x; }

const int INF   = int(1e9);
// const ll  INF64 = ll(INF) * ll(INF);
// const ld  EPS   = 1e-9;
// const ld  PI    = ld(3.1415926535897932384626433832795);


const int mx = 1000000 ;
int  cnt ;
int divisor[mx+10] ;
vector<int> prime_factor[mx+10] ;

void sieve(){
    for (int i=1; i<=mx; i++) {
        for (int j=i; j<=mx; j+=i)
            divisor[j]++;
    }

    for(int i=2; i<=mx; i++) {
        if (prime_factor[i].size() == 0) {
            for(int j=i; j<=mx; j+=i) prime_factor[j].pb(i);
        }
    }
}

int main() {
    sieve();

    for (int i=1; i<=mx; i++) {
        int x = divisor[i] ;
        if (prime_factor[x].size() == 2
                && prime_factor[x][0] * prime_factor[x][1] == x) {
            cnt++;
            if (cnt%9 == 0) printf("%d\n",i);
        }
    }

    return 0;
}
