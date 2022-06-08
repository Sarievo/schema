#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
#define x  first
#define y  second
#define pb push_back
#define mp make_pair
#define len(a) int((a).size())
// #define mset(a, val) memset(a, val, sizeof (a)) // ??
#define rep(i, n) for(int i = 0; i < int(n); i++)
// #define dfor(i, n) for(int i = int(n - 1); i >= 0; i--) // ??
// #define ffor(i, a, b) for(int i = int(a); i <= int(b); i++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define fast_cin ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }
//======================================================

int n;
vector<int> a;

bool read() {
    cin >> n;
    a = vector<int>(n);
    rep(i, n) cin >> a[i];

    return true;
}

void solve() {
    assert(read());
    int L = 0, R = n-1;
    int score_sereja = 0;
    int score_dima = 0;
    if (L == R) {
        cout << a[0] << " " << 0 << endl; return;
    }

    bool turn_sereja = true;
    while (L <= R) {

        if (a[L] < a[R]) {
            if (turn_sereja) {
                score_sereja += a[R];
            } else {
                score_dima += a[R];
            }
            R--;
        } else {
            if (turn_sereja) {
                score_sereja += a[L];
            } else {
                score_dima += a[L];
            }
            L++;
        }

        turn_sereja = !turn_sereja;
    }

    cout << score_sereja << " " << score_dima << endl;
}

int main() {
    fast_cin;
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
