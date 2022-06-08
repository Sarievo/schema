#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
#define x  first
#define y  second
#define mp make_pair
#define len(a) int((a).size())
#define rep(i, n) for(int i = 0; i < int(n); i++)
#define all(a) (a).begin(), (a).end()
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define fast_cin ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }
//======================================================

void solve() {
    string x; cin >> x;
    int nine_cnt = 0;
    for (char &c : x) {
        if (c == '9') nine_cnt++;
    }

    int sum = 0;
    if (nine_cnt == x.length()
            || nine_cnt == x.length()-1 && x[0] != '9') {
        for (char &c : x) {
            sum += (c - '0');
        }
        cout << sum << endl;
    } else {
        int sum = x[0]-'1';
        cout << sum + (x.length()-1) * 9 << endl;
    }
}

int main() {
    fast_cin;
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}