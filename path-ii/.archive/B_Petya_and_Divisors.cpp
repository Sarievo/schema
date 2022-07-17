#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) static_cast<int32_t>(x.size())
// #define x first
// #define y second
#define afor(i, n)     for(int i = 0; i < int(n); i++)
#define dfor(i, n)     for(int i = int(n - 1); i >= 0; i--)
#define ffor(i, a, b)  for(int i = int(a); i <= int(b); i++)
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


const int N = 1e5 + 5;
// const int INF = 2e9, MOD = 1e9+7;

int last[100005];
void test_cases() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        int ans = 0;

        for (int j = 1; j*j <= x; j++) {
            if (x%j == 0) {
                if (last[j] < i - y) ans++;
                if (last[x/j] < i - y) ans++;
                last[j] = i;
                last[x/j] = i;
            }
        }

        cout << ans << endl;
    }
}

int main() {
    fastio;   
    
    int T = 1;
    // cin >> T;
    while (T--) {
        test_cases();
    }
}