#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rp(i, n) for (int i = 0; i < n; i++)
#define N cout << "NO" << endl;
#define Y cout << "YES" << endl;

template <typename T> void sort(vector<T> &a, bool desc = false);
template <typename T> void print(vector<T> &A);

// bool isNotCoprime(int a, int b) {
//     if (a == 1 || b == 1) return false;

//     int less = min(a, b);
//     int more = max(a, b);
//     return (more % less == 0);
// }


int main() {
    int cases = 1;
    // cin >> cases;
    while (cases--) {
        int n;
        cin >> n;
        vector<int> v(n, 0);
        rp(i, n) cin >> v[i];
        vector<int> ans;
        
        // cout << "START\n";
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            int a = v[i];
            int b = v[i + 1];

            ans.push_back(v[i]);
            int factor = gcd(a, b);
            if (factor != 1) {
                cnt++;
                ans.push_back(1);
            }
        }
        ans.push_back(v[n - 1]);

        // cout << "END\n";
        cout << cnt << endl;
        print(ans);
    }

    return 0;
}

//======== ⚠ Don't Complicate the Problem ⚠ ========
template <typename T>
void sort(vector<T> &a, bool desc) {
    if (desc) {
        sort(a.begin(), a.end(), [](T a, T b) {return a > b;});
    } else {
        sort(a.begin(), a.end());
    }
}

template <typename T>
void print(vector<T> &A) {
    int n = A.size();
    // cout << n << endl;
    rp(i, n) cout << A[i] << " ";
    cout << endl;
}