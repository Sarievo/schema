#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rp(i, n) for (int i = 0; i < n; i++)
#define N cout << "NO" << endl
#define Y cout << "YES" << endl

template <typename T> void sort(vector<T> &a, bool desc = false);
template <typename T> void print(vector<T> &A);


void solve() {
    int n;
    cin >> n;
    // if it contains 5 or 7, it's guaranteed to be failed
    vector<int> map(8, 0);
    rp(i, n) {
        int tmp;
        cin >> tmp;
        map[tmp]++;
    }
    if (map[5] || map[7] || map[3] > map[6]) {
        cout << -1 << endl;
        return;
    }
    int type1 = 0;
    int type2 = 0;
    int type3 = 0;
    while (map[6]--) {
        if (map[3]) {
            map[3]--;
            type1++;
        } else {
            if (map[2]) {
                map[2]--;
                type2++;
            } else {
                cout << -1 << endl;
                return;
            }
        }
        if (map[1]) {
            map[1]--;
        } else {
            cout << -1 << endl;
            return;
        }
    }
    if (map[1] != map[2] || map[2] != map[4]) {
        cout << -1 << endl;
        return;
    }

    type3 = map[1];
    while (type1--) {
        cout << "1 3 6" << endl;
    }
    while (type3--) {
        cout << "1 2 4" << endl;
    }
    while (type2--) {
        cout << "1 2 6" << endl;
    }
}

int main() {
    int cases = 1;
    // cin >> cases;
    while (cases--) {
        solve();
    }
    return 0;
}

//======== ⚠ Don't Complicate the Algorithm ⚠ ========

template <typename T>
void sort(vector<T> &a, bool desc) {
    if (desc) {
        sort(a.begin(), a.end(), [](T a, T b) {return a > b;}); // sort by anonymous comparator
    } else {
        sort(a.begin(), a.end());
    }
}

template <typename T>
void print(vector<T> &A) {
    int n = A.size();
    cout << n << endl;
    rp(i, n) cout << A[i] << " ";
    cout << endl;
}