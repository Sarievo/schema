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


int main() {
    fast_cin();
    int n, k;
    cin >> n >> k;

    vector<int> foods(n);
    int greatest = -1;
    afor(i, n) {
        cin >> foods[i];
        if (foods[i] > greatest)
            greatest = foods[i];
    }

    unordered_set<int> codes;
    afor(i, k) {
        int tmp;
        cin >> tmp;
        codes.insert(tmp);
    }
    bool ans = false;

    afor(i, n) {
        if (greatest == foods[i]) {
            if (codes.find(i+1) != codes.end()) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
}