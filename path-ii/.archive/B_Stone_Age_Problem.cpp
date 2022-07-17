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


int n, q;
vector<li> A;
li sumA = 0;

inline bool read() {
 	cin >> n >> q;
    A = vector<li>(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        sumA += A[i];
    }
    return true;
}

void solve() {
    unordered_set<li> record;
    bool replaced = false;
    li replacedValue = -1;
    // cout << "DEBUG, sum is: " << sumA << endl;

    for (int i = 0; i < q; i++) {
        int choice;
        cin >> choice;

        if (choice == 1) { // replace A[x] with y
            li x, y;
            cin >> x >> y;
            x--;
            if (!replaced) {
                li diff = y - A[x];
                sumA += diff;
                A[x] = y;
            } else {
                if (record.find(x) != record.end()) {
                    li diff = y - A[x];
                    sumA += diff;
                    A[x] = y;
                } else {
                    assert(replacedValue != -1);
                    li diff = y - replacedValue;
                    sumA += diff;
                    record.insert(x);
                    A[x] = y;
                }
            }
        } else { // replace each A[i] with y
            li y;
            cin >> y;
            sumA = y * n;
            record.clear();
            replacedValue = y;
            replaced = true;
        }

        cout << sumA << endl;
    }

    // if replacing, 
        // if not A replaced
            // than new sum is prev sum + diff at indice (new - ori)
            // replace the array[x] with y
        // if A replaced
            // if x in set
                // than new sum is prev sum + diff at indice (new - ori)
                // replace the array[x] with y
            // if x not in set 
                // than new sum is prev sum + diff (new - y)
                // push x to the set so mark it as replaced
                // replace the array[x] with y
    // if replacing every e
    // empty the set
    // new sum is y * n, mark the array is replaced, log y
}

int main() {
    // int t;
    // cin >> t;
    // while (t--) {
        assert(read());
        solve();
    // }
} 