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
    string s;
    cin >> s;
    int first_pos_of_a = -1;
    int last_pos_of_z = -1;
    for (int i = 0; i < int(s.length()); i++) {
        char ch = s[i];
        if (ch == 'A') {
            if (first_pos_of_a == -1)
                first_pos_of_a = i;
        } // ...
        if (ch == 'Z') {
            last_pos_of_z = i;
        } // ...
    }
    cout << last_pos_of_z - first_pos_of_a + 1 << endl;
}

int main() {
    fast_cin;
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
