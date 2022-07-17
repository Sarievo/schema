#include <bits/stdc++.h>
using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int,int> pt;
typedef pair<ld, ld> ptd;
typedef unsigned long long uli;

#define pb push_back
#define mp make_pair
#define mset(a, val) memset(a, val, sizeof (a))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ft first
#define sc second
#define sz(a) int((a).size())
#define x first
#define y second

template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }
template<typename T> inline string toStr(T x) { stringstream st; st << x; string s; st >> s; return s; }
template<typename T> inline int hasBit(T mask, int b) { return (b >= 0 && (mask & (T(1) << b)) != 0) ? 1 : 0; }
template<typename X, typename T>inline ostream& operator<< (ostream& out, const pair<T, X>& p) { return out << '(' << p.ft << ", " << p.sc << ')'; }

inline int nextInt() { int x; if (scanf("%d", &x) != 1) throw; return x; }
inline li nextInt64() { li x; if (scanf("%I64d", &x) != 1) throw; return x; }
inline double nextDouble() { double x; if (scanf("%lf", &x) != 1) throw; return x; }

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i++)
#define ford(i, n) for(int i = int(n - 1); i >= 0; i--)
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)

const int INF = int(1e9);
const li INF64 = li(INF) * li(INF);
const ld EPS = 1e-9;
const ld PI = ld(3.1415926535897932384626433832795);


uli n;

inline bool read() {
 	cin >> n;
    return true;
}

void solve() {
    if (n == 4 || n == 6) {
        cout << "1 1" << endl;
        return;
    } else if (n % 2 == 1 || n < 8) {
        cout << "-1" << endl;
        return;
    }

    uli div6 = n / 6;
    uli rem6 = n % 6;
    uli minCars, maxCars;
    if (rem6 == 2 || rem6 == 4) {
        minCars = div6 + 1;
    } else if (rem6 == 0) {
        minCars = div6;
    }

    uli div4 = n / 4;
    // int rem4 = n % 4;
    maxCars = div4;
    cout << minCars << " " << maxCars << endl;
    // if n is odd return false
    // if n lesser than 8 and not 4 or 6 return false
    // find n divied by 6 and its remainder
    // if remainder is 0, log min
    // if remainder is 4, log min + 1
    // if remainder is 2, log min + 1
    // find n divied by 4 and its remainder
    // if remainder is 0, log max
    // if remainder is 2, log max
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        assert(read());
        solve();
    }
} 