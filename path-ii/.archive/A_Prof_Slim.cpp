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
    vector<int> a(n);
    int negs = 0;
    rp(i, n) {
        cin >> a[i];
        if (a[i] < 0) negs++;
    }
    // how you swap sign is determined
    // swap the sign or not and check if it's sorted
    rp(i, n) {
        if (negs > 0) {
            a[i] = -abs(a[i]);
            negs--;
        } else {
            a[i] = abs(a[i]);
        }
    }
    rp(i, n - 1) {
        if (a[i] > a[i + 1]) {
            N; return;
        }
    }
    Y;
}

int main() {
    int cases = 1;
    cin >> cases;
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