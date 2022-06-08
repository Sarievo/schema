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


void solve() {
    int a, b, m;
    cin >> a >> b >> m;

    int min_of_a = INT_MAX;
    int min_of_b = INT_MAX;

    vector<int> A(a);
    for(int &x : A) {
        cin >> x;
        if (x < min_of_a) min_of_a = x;
    }
    vector<int> B(b);
    for(int &x : B) {
        cin >> x;
        if (x < min_of_b) min_of_b = x;
    }
    
    int min_price = min_of_a + min_of_b;
    rep(i, m) {
        int x, y, discount;
        cin >> x >> y >> discount;
        int price = (A[x-1] + B[y-1]) - discount;
        min_price = min(min_price, price); 
    }

    cout << min_price << endl;
}

int main() {
    fast_cin;
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
