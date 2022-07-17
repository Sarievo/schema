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

int id = 0, ans = 0, mx = -1, n, ten[6] = {1, 10, 100, 1000, 10000, 100000}, len;
vector<int> canBeZero(10, 1), is(10), val(10);


inline bool read() {
    cin >> n;
    string s;
    while (n--) {
        cin >> s;
        canBeZero[s[0] - 'a'] = 0;
        reverse(all(s));
        len = s.length();
        forn(i, len) val[s[i] - 'a'] += ten[i];
    }

 	return true;
}
              
typedef long long ll;
// typedef pair<int, int> pi;
// #define all(v) v.begin(), v.end()
// #define V(a, x, n, m) vector<vector<x>> a(n, vector<x>(m))
// ------------------------------------------------------------------------------

void solve() {
    for (int i = 0; i < 10; i++)
        if (canBeZero[i] && val[i] > mx) {
            mx = val[i];
            id = i;
        }
    is[id] = 1;
    for (int i = 1; i < 10; i++) {
        id = mx = -1;
        for (int j = 0; j < 10; j++)
            if (!is[j] && mx < val[j]) {
                mx = val[j];
                id = j;
            }
        is[id] = 1;
        ans += mx * i;
    }
    cout << ans << '\n';
}

int main() {
	assert(read());
	solve();
} 