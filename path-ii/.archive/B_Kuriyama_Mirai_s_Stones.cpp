#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
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



int n;
vector<ll> a;
// bool read() {
//     return true;
// }

void solve() {
    // assert(read());
    cin >> n;
    a = vector<ll>(n);
    afor(i, n) {
        cin >> a[i];
    }
    
    vector<ll> prefix_sums(n);
    vector<ll> prefix_sums2(n);
    
    prefix_sums[0] = a[0];
    for (int i = 1; i < n; i++) {
        prefix_sums[i] = prefix_sums[i-1] + a[i];
    }
    sort(all(a)); // sort asc
    prefix_sums2[0] = a[0];
    for (int i = 1; i < n; i++) {
        prefix_sums2[i] = prefix_sums2[i-1] + a[i];
    }

    int queries = 0;
    cin >> queries;

    ll t, l, r;
    ll l_max, r_max;
    ll sum;
    afor(i, queries) {
        cin >> t >> l >> r;
        if (t == 1) { // calc norm sum
            if (l == 1) {
                l_max = 0;
            } else {
                l_max = prefix_sums[l-2];
            }
            r_max = prefix_sums[r-1];

        } else { // calc sorted sum
            if (l == 1) {
                l_max = 0;
            } else {
                l_max = prefix_sums2[l-2];
            }
            r_max = prefix_sums2[r-1];
        }
        sum = (r_max-l_max);
        cout << sum << endl;
    }
}

int main() {
    fast_cin;
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}