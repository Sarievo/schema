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

bool isPalindrome(string s) {
    int L = 0;
    int R = s.size()-1;
    while (L <= R) {
        if (s[L] != s[R]) return false;
        L++; R--;
    }
    return true;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k == 0) {
        cout << 1 << endl; return;
    }

    cout << (isPalindrome(s) ? "1" : "2") << endl;
}

int main() {
  fast_cin;
//   populate();
  int cases; cin >> cases; for (int i = 1; i <= cases; i++) {solve();}
  // solve();
}

