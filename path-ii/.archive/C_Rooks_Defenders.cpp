#include <bits/stdc++.h>
using namespace std;
 
typedef long long li;
typedef long double ld;
typedef pair<int,int> pt;
typedef pair<ld, ld> ptd;
typedef unsigned long long uli;
 
#define x  first
#define ft first
#define y  second
#define sc second
#define pb push_back
#define mp make_pair
#define sz(a) int((a).size())
#define mset(a, val) memset(a, val, sizeof (a))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define ford(i, n) for(int i = int(n - 1); i >= 0; i--)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i++)
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define fast_cin ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }
template<typename T> inline string toStr(T x) { stringstream st; st << x; string s; st >> s; return s; }
template<typename T> inline int hasBit(T mask, int b) { return (b >= 0 && (mask & (T(1) << b)) != 0) ? 1 : 0; }
template<typename X, typename T>inline ostream& operator<< (ostream& out, const pair<T, X>& p) { return out << '(' << p.ft << ", " << p.sc << ')'; }
 
inline int nextInt() { int x; if (scanf("%d", &x) != 1) throw; return x; }
inline li nextInt64() { li x; if (scanf("%I64d", &x) != 1) throw; return x; }
inline double nextDouble() { double x; if (scanf("%lf", &x) != 1) throw; return x; }
 
const int INF = int(1e9);
const li INF64 = li(INF) * li(INF);
const ld EPS = 1e-9;
const ld PI = ld(3.1415926535897932384626433832795);
const int N = 1e5 + 5;
 

int n, q;
int freqRows[N], freqCols[N];

void update(int t[], int x, int y) {
    while (x <= n) {
        t[x] += y;
        x += (x & (-x));
    }
}

int query(int t[], int l, int r) {
    int ans = 0;
    while (r) {
        ans += t[r];
        r -= (r & (-r));
    }
 
    l--;
    while (l) {
        ans -= t[l];
        l -= (l & (-l));
    }
 
    return ans;
}
 
int rows[N], cols[N];
void solve() {
    cin >> n >> q;
 
    while (q--) {
        int type;
        cin >> type;
 
        if (type == 1) {
            int x, y;
            cin >> x >> y;
 
            ++cols[x];
            ++rows[y];
 
            if (cols[x] == 1)
                update(freqCols, x, 1);
            if (rows[y] == 1)
                update(freqRows, y, 1);

        } else if (type == 2) {
            int x, y;
            cin >> x >> y;
 
            --cols[x];
            --rows[y];
 
            if (cols[x] == 0)
                update(freqCols, x, -1);
            if (rows[y] == 0)
                update(freqRows, y, -1);

        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
 
            if (query(freqCols, x1, x2) == (x2 - x1)+1
                    || query(freqRows, y1, y2) == (y2 - y1)+1) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
}

int main() {
    fast_cin;
    int t = 1;
    // cin >> t;
    while (t--) {
        // assert(read());
        solve();
    }
} 