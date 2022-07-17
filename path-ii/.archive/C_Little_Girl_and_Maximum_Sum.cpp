#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pt;
typedef pair<ld, ld> ptd;
typedef unsigned long long uli;
 
#define x  first
#define y  second
#define pb push_back
#define ft first
#define sc second
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
inline ll nextInt64() { ll x; if (scanf("%I64d", &x) != 1) throw; return x; }
inline double nextDouble() { double x; if (scanf("%lf", &x) != 1) throw; return x; }

const int INF = int(1e9);
const ll INF64 = ll(INF) * ll(INF);
const ld EPS = 1e-9;
const ld PI = ld(3.1415926535897932384626433832795);
//======================================================



int n, k;
vector<ull> a;

void solve() {
    // assert(read());
    cin >> n >> k;
    a = vector<ull>(n);
    afor(i, n) cin >> a[i];

    int L, R;
    vector<int> inc(n, 0);
    vector<int> dec(n, 0);
    vector<ull> freq(n, 0);
    
    afor(i, k) {
        cin >> L >> R;
        inc[L-1]++;
        if (R < n) dec[R]++;
    }

    int acc = 0;
    for (int i = 0; i < n; i++) {
        acc += (inc[i] - dec[i]);
        freq[i] = acc;
    }
    
    sort(all(a));
    reverse(all(a)); // for easier retrieve
    sort(all(freq));
    reverse(all(freq));

    ull ans = 0;
    for (int i = 0; i < n; i++) {
        int counter = freq[i];
        if (!counter) break;
        
        ans += freq[i] * a[i];
    }
    cout << ans << endl;
}

int main() {
    fast_cin;
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}