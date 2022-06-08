/** 
 * Sarievo.
 * URL: \contests\abc145\tasks\abc145_c
 */

#include <bits/stdc++.h>
#define poly vector<int>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) // make io faster
#define rep(i, n) for(int i = 0; i < n; i++)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair<int,int>
#define fi first
#define se second
#define inf 1e18
#define int ll
#define all(a) (a).begin(), (a).end()
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++) // iterate from sequence for a given type
template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }
using namespace std;

int N;
int x[10], y[10];

double dist(int i, int j) {
    double dx = x[i] - x[j];
    double dy = y[i] - y[j];
    return pow(dx * dx + dy * dy, 0.5);
}

void f() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> x[i] >> y[i];
    vector<int> v(N);
    iota(all(v), 1);
    double sum = 0.0;
    do {
        for (int i = 0; i < N-1; i++) sum += dist(v[i], v[i+1]);
    } while (next_permutation(all(v)));
    int Factorial = 1;
    for (int i = 2; i <= N; i++) Factorial *= i;
    cout << fixed << setprecision(10) << sum / Factorial << endl;
    return;
}

signed main() {
    IOS;
    int T=1;
    // cin >> T;
    while (T--) {
        f();
    }
}
