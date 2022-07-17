#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define x first
#define y second
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) static_cast<int32_t>(x.size())
#define afor(i, n)     for(int i = 0; i < int(n); i++)
#define dfor(i, n)     for(int i = int(n - 1); i >= 0; i--)
#define ffor(i, a, b)  for(int i = int(a); i <= int(b); i++)
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


const int N = 1e7 + 5;
const int INF = 2e9, MOD = 1e9+7;
 

void solve(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();
    vector<int> bad;
    for (int i = 0; i < n && bad.empty(); i++) {
        vector<int> b = a[i];
        sort(all(b));
        for (int j = 0; j < m; j++) {
            if (a[i][j] != b[j]) bad.push_back(j);
        }
    }

    if ((int)bad.size() == 0) {
        cout << 1 << " " << 1 << "\n";
        return;
    }
    if ((int)bad.size() > 2) {
        cout << -1 << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        swap(a[i][bad[0]], a[i][bad[1]]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i][j] < a[i][j-1]) {
                cout << -1 << "\n";
                return;
            }
        }
    }
    cout << bad[0] + 1 << " " << bad[1] + 1 << "\n";
    return;
}

int main() {
    fast_cin();
    
    int t = 1;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        afor(i, n) {
            afor(j, m) {
                cin >> a[i][j];
            }
        }
        solve(a);
    }
}