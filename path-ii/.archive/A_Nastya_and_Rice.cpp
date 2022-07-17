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

int t, n, a, b, c, d;
vector<vector<int>> inputs;

inline bool read() {
    cin >> t;
    forn(i, t) {
        cin >> n >> a >> b >> c >> d;
        inputs.push_back({n, a, b, c, d});
    }

 	return true;
}
              

void solve() {
    for (int i = 0; i < t; i++) {
        vector<int> input = inputs[i];
        n = input[0], a = input[1], b = input[2], c = input[3], d = input[4];
        int LBound = (a - b) * n, 
            RBound = (a + b) * n;
        int gLBound = c - d, 
            gRBound = c + d;
        cout << ((gRBound <= RBound && gRBound >= LBound)
            || (gLBound <= RBound && gLBound >= LBound
            || (gRBound > RBound && gLBound < LBound)) ? "Yes" : "No") << endl;
    }
}

int main() {
	assert(read());
	solve();
} 