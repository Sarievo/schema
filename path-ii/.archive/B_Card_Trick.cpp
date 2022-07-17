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
#define afor(i, n) for(int i = 0; i < int(n); i++)
#define dfor(i, n) for(int i = int(n - 1); i >= 0; i--)
#define ffor(i, a, b) for(int i = int(a); i <= int(b); i++)
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

//======================================================

const int INF = int(1e9);
const li INF64 = li(INF) * li(INF);
const ld EPS = 1e-9;
const ld PI = ld(3.1415926535897932384626433832795);
const int N = 1e5 + 5;


// void read() {}

void solve() {
    int n, m;
    cin >> n;

    vector<int> a1(n);
    afor(i, n) {
        cin >> a1[i];
    }

    cin >> m;
    li total_shuffles = 0;
    vector<int> a2(m);
    afor(i, m) {
        cin >> a2[i];
        total_shuffles += a2[i];
    }

    li rem = total_shuffles >= n ? total_shuffles%n : total_shuffles;
    cout << a1[(rem+1)-1] << endl;
}

int main() {
    fast_cin;
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}