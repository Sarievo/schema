#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define x first
#define y second
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) static_cast<int32_t>(x.size())
#define forn(i, n)     for(int i = 0; i < int(n); i++)
#define rforn(i, n)     for(int i = int(n - 1); i >= 0; i--)
#define ffor(i, a, b)  for(int i = int(a); i <= int(b); i++)
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 1000;

map<int, int> cnt;
int ans[N];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    fast_cin();
    int t = 1;
    // cin >> t;
    while (t--) {
        int n;
        cin >> n;

        forn(i, n*n) {
            int e;
            cin >> e;
            cnt[-e]++;
        }

        int pos = n-1;
        foreach(it, cnt) {
            int x = -it->first;
            while (it->second) {
                ans[pos] = x;
                --it->second;

                for (int i = pos+1; i < n; ++i)
                    cnt[-gcd(ans[pos], ans[i])] -= 2;
                
                pos--;
            }
        }

        forn(i, n)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}