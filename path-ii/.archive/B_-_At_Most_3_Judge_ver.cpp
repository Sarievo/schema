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


int n, w;
vector<int> A;

inline bool read() {
 	cin >> n >> w;
    forn(i, n) {
        int number;
        cin >> number;
        if (number <= w) {
            A.push_back(number);
        }
    }
    return true;
}

unordered_set<int> results;

void solve() {
    int size = A.size();
    for (int i = 0; i < size; i++) {
        int s1 = A[i];
        results.insert(s1);
        int e1 = w - s1;

        if (e1 > 0) {
            for (int j = 0; j < size; j++) {
                if (i == j) continue;

                int s2 = s1 + A[j];
                int e2 = w - s2;
                
                if (e2 >= 0) {
                    results.insert(s2);

                    if (e2 == 0) {
                        continue;
                    } else if (e2 > 0) {
                        for (int k = 0; k < size; k++) {
                            if (i == k || j == k) continue;

                            int s3 = s2 + A[k];
                            int e3 = w - s3;
                            if (e3 >= 0) {
                                results.insert(s3);
                            }
                        }
                    }
                }
            }
        }
    }
    cout << results.size() << endl;
    // how many number is lesser or equal than n
    // how many 2 sum of number is lesser or equal than n
    // how many 3 sum of number is lesser or equal than n
}

int main() {
    assert(read());
    solve();
} 