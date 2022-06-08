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

int n, k;
vector<vector<int>> mat;
vector<vector<int>> prefix_arrays;
string row;

bool read() {
    cin >> n >> k;
    mat = vector<vector<int>>(n, vector<int>(n));
    prefix_arrays = vector<vector<int>>(n+1, vector<int>(n+1, 0));

    rep(i, n) {
        cin >> row;
        rep(j, n) {
            mat[i][j] = (row[j] == 'B' ? 1 : 0);
            prefix_arrays[(i+1)][j+1] = prefix_arrays[(i+1)][j]+mat[i][j];
        }
    }

    rep(i, n) rep(j, n) {
        prefix_arrays[i+1][(j+1)] = prefix_arrays[i][(j+1)]+mat[i][j];
    }
    return true;
}

vector<int> non_empty_r;
vector<int> non_empty_c;
void solve() {
    assert(read());

    rep(i, n) {
        if (prefix_arrays[i+1][n]-prefix_arrays[i][n]) 
            non_empty_r.push_back(i);
        if (prefix_arrays[n][i+1]-prefix_arrays[n][i])
            non_empty_c.push_back(i);
    }

    int empty_r = n - non_empty_r.size();
    int empty_c = n - non_empty_c.size();
    if (empty_r == n && empty_c == n) {
        cout << n + n << endl; return;
    }

    for (int i : non_empty_r) {

    }
}

int main() {
    fast_cin;
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
