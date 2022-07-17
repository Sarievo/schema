#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
#define hashmap unordered_map
#define hashset unordered_set
#define Y cout << "YES" << endl;
#define N cout << "NO" << endl;
#define let auto // funny JS syntax

vector<int> readInts(int &n);
void sort(vector<int> &a, bool desc = false);
// vector<vector<int>> read2dInts(int &n, int &m);

// template <typename T> void debug(vector<T> &A);
// template <typename T> hashmap<T, int> getftable(vector<T> &A);


void solve() {
    string a, b;
    cin >> a >> b;
    if (b == "a") {
        cout << "1" << endl;
        return;
    }
    for (char c : b) {
        if (c == 'a') {
            cout << "-1" << endl;
            return;
        }
    }
    ll ans = 1;
    f(i, a.length()) {
        ans *= 2;
    }
    cout << ans << endl;
}

int main() {
    int cases = 1;
    cin >> cases;
    while (cases--) {
        solve();
    }
    return 0;
}

//======== ⚠ Do't Complicate the Algorithm ⚠ ========

vector<int> readInts(int &n) {
    vector<int> v(n, -1);
    f(i, n) cin >> v[i];
    return v;
}

// vector<vector<int>> read2dInts(int &n, int &m) {
//     vector<vector<int>> v(n, vector<int>(m, -1));
//     f(i, n) f(j, m) cin >> v[i][j];
//     return v;
// }

void sort(vector<int> &a, bool desc) {
    if (desc) {
        sort(a.begin(), a.end(), [](int a, int b) {return a > b;}); // sort by anonymous comparator
    } else {
        sort(a.begin(), a.end());
    }
}

// template <typename T>
// void debug(vector<T> &A) {
//     int n = A.size();
//     cout << n << endl;
//     f(i, n) cout << A[i] << " ";
//     cout << endl;
// }

// template <typename T>
// hashmap<T, int> getftable(vector<T> &A) {
//     typename vector<T>::iterator itr;
//     hashmap<int, int> ftable;
//     for (itr = A.begin(); itr != A.end(); itr++)
//         ftable[*itr]++;
//     return ftable;
// }