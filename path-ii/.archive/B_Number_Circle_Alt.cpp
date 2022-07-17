#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rp(i, n) for (int i = 0; i < n; i++)
#define hashmap unordered_map
#define hashset unordered_set
#define var auto
#define Y cout << "YES" << endl;
#define N cout << "NO" << endl;

vector<int> readInts(int &n);
vector<vector<int>> read2dInts(int &n, int &m);
void sort(vector<int> &a);

template <typename T>
void debug(vector<T> &A);
vector<int>::iterator ptr;

void solve() {
    int n;
    cin >> n;
    var a = readInts(n);
    sort(a);
    if (a[n - 1] >= a[n - 2] + a[n - 3]) {
        N return;
    }
    Y
    for (int i = n - 1; i >= 0; i -= 2) {
        cout << a[i] << " ";
    }
    for (int i = n % 2; i < n; i += 2) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int cases = 1;
    // cin >> cases;
    while (cases--) {
        solve();
    }
    return 0;
}

//======= Library Functions =======

vector<int> readInts(int &n) {
    vector<int> v(n, -1);
    rp(i, n) cin >> v[i];
    return v;
}

vector<vector<int>> read2dInts(int &n, int &m) {
    vector<vector<int>> v(n, vector<int>(m, -1));
    rp(i, n) rp(j, m) cin >> v[i][j];
    return v;
}

void sort(vector<int> &a) {
    sort(a.begin(), a.end());
}

template <typename T>
void debug(vector<T> &A) {
    typename vector<T>::iterator ptr; // shadows global iterator?
    for (ptr = A.begin(); ptr != A.end(); ptr++) {
        cout << *ptr << " ";
    }
    cout << endl;
}