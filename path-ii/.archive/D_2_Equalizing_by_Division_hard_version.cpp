#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
#define hashmap unordered_map
#define hashset unordered_set
#define Y cout << "YES" << endl;
#define N cout << "NO" << endl;
#define let auto

vector<int> readInts(int &n);
void sort(vector<int> &a, bool desc = false);
vector<vector<int>> read2dInts(int &n, int &m);

template <typename T> void debug(vector<T> &A);
template <typename T> hashmap<T, int> getftable(vector<T> &A);


void solve() {
    int n, k;
    cin >> n >> k;
    let a = readInts(n);
    
    vector<vector<int>> vals(200 * 1000 + 1);
    f(i, n) {
        int x = a[i];
        int cur = 0;
        while (x > 0) {
            vals[x].push_back(cur);
            x /= 2;
            cur++;
        }
    }

    int ans = 1e9;
    f(i, 200 * 1000 + 1) {
        sort(vals[i]);
        if (int(vals[i].size()) < k) continue;
        ans = min(ans, accumulate(vals[i].begin(), vals[i].begin() + k, 0));
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

//==================== Keep Calm and ====================
//======== ✨ Do Not Complicate the Algorithm ✨ ========

vector<int> readInts(int &n) {
    vector<int> v(n, -1);
    f(i, n) cin >> v[i];
    return v;
}

vector<vector<int>> read2dInts(int &n, int &m) {
    vector<vector<int>> v(n, vector<int>(m, -1));
    f(i, n) f(j, m) cin >> v[i][j];
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
    int n = A.size();
    cout << n << endl;
    f(i, n) cout << A[i] << " ";
    cout << endl;
}

template <typename T>
hashmap<T, int> getftable(vector<T> &A) {
    typename vector<T>::iterator itr;
    hashmap<int, int> ftable;
    for (itr = A.begin(); itr != A.end(); itr++)
        ftable[*itr]++;
    return ftable;
}