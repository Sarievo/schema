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
void sort(vector<int> &a, bool desc = false);

template <typename T>
void debug(vector<T> &A);

void solve() {
    int n;
    cin >> n;
    var a = readInts(n);

    hashmap<int, int> mmap;
    vector<int> a1;
    vector<int> a2;

    rp(i, n) {
        auto ptr = mmap.find(a[i]);
        if (ptr == mmap.end()) {
            mmap.insert({a[i], 1});
            a1.push_back(a[i]);
        } else {
            if (ptr->second > 1) {
                N return;
            } else {
                a2.push_back(a[i]);
                ptr->second++;
            }
        }
    }
    Y
    sort(a2); // ??
    debug(a2);
    sort(a1, true);
    debug(a1);
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

void sort(vector<int> &a, bool desc) {
    if (desc) {
        sort(a.begin(), a.end(), [](int a, int b) {return a > b;}); // sort by anonymous comparator
    } else {
        sort(a.begin(), a.end());
    }
}

template <typename T>
void debug(vector<T> &A) {
    // typename vector<T>::iterator ptr; // shadows global iterator?
    // for (ptr = A.begin(); ptr != A.end(); ptr++) {
    //     cout << *ptr << " ";
    // }
    int n = A.size();
    cout << n << endl;
    rp(i, n) cout << A[i] << " ";
    cout << endl;
}