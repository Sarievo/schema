#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
#define x  first
#define y  second
#define pb push_back
#define mp make_pair
#define len(a) int((a).size())
// #define mset(a, val) memset(a, val, sizeof (a))              // ??
// #define dfor(i, n) for(int i = int(n - 1); i >= 0; i--)      // ??
// #define ffor(i, a, b) for(int i = int(a); i <= int(b); i++)  // ??
#define rep(i, n) for(int i = 0; i < int(n); i++)
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
    if (n == 1) {
        cout << "1 0" << endl; return;
    }

    int L = 0;
    int R = n-1;
    int vL = a[L];
    int vR = a[R];
    int cntL = 0;
    int cntR = 0;

    while (L < R) {
        int elapsed_time = min(vL, vR);
        vL -= elapsed_time, vR -= elapsed_time;
        // cout<< "cmp " << vL << " against " << vR << endl;
        if (!vL && !vR) {
            L++;
            R--;
            cntL++;
            cntR++;
            if (L == R) {
                cntL++;
                break;
            }
            vL = a[L];
            vR = a[R];
        } else if (!vL) {
        // L finished first
            L++; // move pointer L++
            cntL++;
            if (L != R) vL = a[L]; // assign L to a new chocolate
            else cntR++;
        } else if (!vR) {
        // R finished first
            R--; // move pointer R--
            cntR++;
            if (R != L) vR = a[R];
            else cntL++;
        }
    }

    cout << cntL << " " << cntR;
}

int main() {
    fast_cin;
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
