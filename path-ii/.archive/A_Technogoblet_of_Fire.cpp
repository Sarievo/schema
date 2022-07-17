#include <bits/stdc++.h>
// #include <cstdio>
using namespace std;

#define ll long long
#define rp(i, n) for (int i = 0; i < n; i++)
#define hashmap unordered_map
#define hashset unordered_set
#define var auto

vector<int> readInts(int &n);
vector<vector<int>> read2dInts(int &n, int &m);

template <typename T>
void debug(vector<T> &A);
vector<int>::iterator ptr;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    var a = readInts(n);
    var b = readInts(n);
    var c = readInts(k);
    // debug(a);

    // if i in c is already the strongest, 
    // nothing to be made up about
    // if not, a new school has to be made up 
    // hashmap<int, int> mmap;
    int ans = 0;
    // int * dict = new int[128];
    vector<int> dict(128, -1);
    rp(i, n)
        // higherest score in b[i] is the highest score
        // in a[i] where b[i] == b[i_n]
        dict[b[i]] = max(dict[b[i]], a[i]);

    rp(i, k) {
        int key = c[i] - 1; // 1 index
        int score = a[key];
        int school = b[key];
        int school_highest = dict[school];
        // cout << "comparing " << score << ":" << school_highest << endl;
        if (score != school_highest) ans++;
    }

    cout << ans << endl;
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

template <typename T>
void debug(vector<T> &A) {
    typename vector<T>::iterator ptr; // shadows global iterator?
    for (ptr = A.begin(); ptr != A.end(); ptr++) {
        cout << *ptr << " ";
    }
    cout << endl;
}
