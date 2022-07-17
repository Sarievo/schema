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

template <typename T> void debug(vector<T> &A);
template <typename T> hashmap<T, int> getftable(vector<T> &A);

//======== ✨ Start of Solver ✨ ========

void solve() {
    int n;
    cin >> n;
    var a = readInts(n);

    hashmap<int, int> ftable = getftable(a);
    vector<int> frequencies;
    hashset<int>::iterator it;
    for (auto e : ftable) {
        frequencies.push_back(e.second);
    }
    hashset<int> seen;
    sort(frequencies, true);
    ll answer = 0;
    int limit = min(frequencies[0], (int) frequencies.size());
    rp(i, limit) {
        while (seen.find(frequencies[i]) != seen.end()
            && frequencies[i] > 0) frequencies[i]--;
        answer += frequencies[i];
        seen.insert(frequencies[i]);
    }
    cout << answer << endl;
}

int main() {
    int cases = 1;
    cin >> cases;
    while (cases--) {
        solve();
    }
    return 0;
}

//======= ✨ Library Functions ✨ =======

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
    int n = A.size();
    cout << n << endl;
    rp(i, n) cout << A[i] << " ";
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