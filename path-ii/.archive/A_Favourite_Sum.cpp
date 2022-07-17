#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pt;

#define x  first
#define y  second
#define pb emplace_back
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define afor(i, n) for(int i = 0; i < int(n); i++)
#define dfor(i, n) for(int i = int(n - 1); i >= 0; i--)
#define ffor(i, a, b) for(int i = int(a); i <= int(b); i++)
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define fast_cin ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
//======================================================

void solve() {
    ll n, k;
    cin >> n >> k;

    vector<int> fav(n, 0);
    ll pre_sum = 0;
    afor(i, n) {
        cin >> fav[i];
        if (fav[i] <= k)
            pre_sum -= fav[i];
    }
    pre_sum *= 2;

    /* 
    1..5 6 6 3, 5/2 2+1;
    1..6 7 7 7, (1+6)*(6/2) if even, (1+5)*(5/2)+(5/2+1)
     */
    ll sum = -1;
    if (k == 1) {
        sum = 1;
    } else {
        if (k % 2 == 0) {
            sum = (k+1)*(k/2);
        } else {
            sum = (k+1)*(k/2)+(k/2+1);
        }
    }
    cout << (sum+pre_sum) << endl;
}

int main() {
    fast_cin;
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}