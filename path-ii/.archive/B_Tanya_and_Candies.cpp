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
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define afor(i, n) for(int i = 0; i < int(n); i++)
#define dfor(i, n) for(int i = int(n - 1); i >= 0; i--)
#define ffor(i, a, b) for(int i = int(a); i <= int(b); i++)
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define fast_cin ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }
//======================================================

int n;
vector<int> a;
vector<ll> S1(1, 0); // odd seq prefix array
vector<ll> S2(1, 0);

bool read() {
    cin >> n;
    a = vector<int>(n);

    bool turn = true;
    afor(i, n) {
        cin >> a[i];
        if (turn) {
            S1.push_back(S1[S1.size()-1]+a[i]);
        } else {
            S2.push_back(S2[S2.size()-1]+a[i]);
        }
        turn = !turn;
    }
    return true;
}

void solve() {
    assert(read());

    int total_candies = 0;
    bool turn = true;
    afor(i, n) {
        int num = a[i];
        int p = i/2+1;
        if (turn) {
            // int p = (i)/2; // cmp 0->0, 2->1,...
            // int v1 = S1[i-1] + S2[S2.size()-1]-S2[i-1];
            // int v2 = S2[i-1] + S1[S1.size()-1]-S1[i];
            int v1 = S1[p-1] + S2[S2.size()-1]-S2[p-1];
            int v2 = S2[p-1] + S1[S1.size()-1]-S1[p];
            // cout << "cmp " << v1 << " against " << v2 << endl;
            if (v1 == v2) total_candies++;
        } else {
            // int p = (i-1)/2; // cmp 1->0, 3->2,...
            // int v1 = S1[i]   + S2[S2.size()-1]-S2[i];
            // int v2 = S2[i-1] + S1[S1.size()-1]-S1[i];
            int v1 = S1[p]   + S2[S2.size()-1]-S2[p];
            int v2 = S2[p-1] + S1[S1.size()-1]-S1[p];
            // cout << "cmp " << v1 << " against " << v2 << endl;
            if (v1 == v2) total_candies++;
        }
        turn = !turn;
    }
    cout << total_candies << endl;
}

int main() {
    fast_cin;
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
