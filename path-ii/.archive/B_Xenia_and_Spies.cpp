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

int n, m, s, f;
unordered_map<int, pair<int, int>> watch;


inline bool read() {
	cin >> n >> m >> s >> f;
    forn(i, m) {
        int t, l, r;
        cin >> t >> l >> r;
        watch.insert({t, {l, r}});
    }

 	return true;
}
              
inline void solve() {
	// n of spies, m of watch turns, pass s to f
    bool LtoR = s < f;
    string output = "";
    int turn = 0;

    if (LtoR) {
        int L = s;
        int R = f;
        while (L != R) {
            // cout << "at turn " << turn << endl;
            ++turn;
            auto it = watch.find(turn);
            if (it != watch.end()) {
                int xwatchLeft = it->y.x;
                int xwatchRight = it->y.y;
                if (xwatchLeft <= L && L <= xwatchRight
                        || xwatchLeft <= L + 1 && L + 1 <= xwatchRight) {
                    output += 'X';
                } else {
                    output += 'R';
                    L++;
                }
            } else {
                output += 'R';
                L++;
            }
        }
    } else {
        int L = f;
        int R = s;
        while (L != R) {
            // cout << "at turn " << turn << endl;
            ++turn;
            auto it = watch.find(turn);
            if (it != watch.end()) {
                int xwatchLeft = it->y.x;
                int xwatchRight = it->y.y;
                if (xwatchLeft <= R && R <= xwatchRight
                        || xwatchLeft <= R - 1 && R - 1 <= xwatchRight) {
                    output += 'X';
                } else {
                    output += 'L';
                    R--;
                }
            } else {
                output += 'L';
                R--;
            }
        }
    }

    // if s < f, pass from L to R, only 'R' and 'X' is used
    //     while s is not f;
        //     if the turn is logged by xeria
        //         if the position is under wathch
        //             do nothing and print 'X'
        //         if the position is not under watch
        //             print 'R', move pointer to the right
        //     if the turn is not logged by xeria
        //         print 'R', move pointer to the right
    // if s > f, pass from R to L, only 'L' and 'X' is used
    //     while s is not f:
        //     if the turn is logged by xeria
        //         if the position is under watch
        //             do nothing and print 'X'
        //         if the position is not under watch
        //             print 'L', move pointer to the left
        //     if the turn is not logged by xeria
        //         print 'L', move pointer to the left
    cout << output << endl;
}

int main() {
	assert(read());
	solve();
} 