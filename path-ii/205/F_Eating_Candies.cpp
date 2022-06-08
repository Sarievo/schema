/** 
 * Sarievo.
 * URL: https://codeforces.com/problemset/problem/1669/F
 */

#include <bits/stdc++.h>
#define poly vector<int>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) // make io faster
#define rep(i, n) for(int i = 0; i < n; i++)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair<int,int>
#define fi first
#define se second
#define inf 1e18
#define int ll
#define all(a) (a).begin(), (a).end()
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++) // iterate from sequence for a given type
template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }
using namespace std;

int binarySearch(poly &a, int L, int R, int target) {
    // for (int i = L; i < R; i++) {
    //     if (a[i] == target) { // linear search
    //         cout << "i:" << i << endl;
    //         return i;
    //     }
    // }
    // return -1;

    int l = L;
    int r = R-1;
    int i = -1;
    while (l <= r) {
        int m = l + (r-l)/2;
        if (a[m] == target) {
            i = m;
            break;
        }
        // cout << a[m] << " is not " << target << ".\n"; // db
        if (a[m] > target) { // <- in reverse
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    while ((i-1 > L) && a[i-1] == target) i--;
    // cout << "i:" << i << endl;
    return i;
}
 
void f() {
    int n; cin >> n;
    poly a(n); for (int &x : a) cin >> x;

    poly prefix_sum_a(n);
    prefix_sum_a[0] = a[0];
    rep(i, n-1) prefix_sum_a[i+1] = prefix_sum_a[i] + a[i+1];
    
    set<int> validation_set {a[n-1]};
    poly prefix_sum_b(n);
    prefix_sum_b[n-1] = a[n-1];
    for(int i = n-2; i >= 0; --i) {
        prefix_sum_b[i] = prefix_sum_b[i+1] + a[i];
        validation_set.insert(prefix_sum_b[i]);
    }
    // for (int &x : prefix_sum_a) cout << x << " "; cout << endl; // db
    // for (int &x : prefix_sum_b) cout << x << " "; cout << endl; // db

    int max_sum = 0;
    rep(posA, n-1) {
        int target = prefix_sum_a[posA];
        if (validation_set.find(target) != validation_set.end()) {
            int posB = binarySearch(prefix_sum_b, (posA+1), n, target);
            if (posB != -1) {
                // cout << "found " << posA << ":" << posB << endl;
                int sum = n - ((posB-posA)-1); // n-interval-1?
                max_sum = max(max_sum, sum);
            }
        }
    }
    cout << max_sum << endl;
}

signed main() {
    IOS;
    int T=1;
    cin >> T;
    while (T--) {
        f();
    }
}
