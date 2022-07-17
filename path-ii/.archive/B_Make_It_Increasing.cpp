#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rp(i, n) for (int i = 0; i < n; i++)
#define N cout << "NO" << endl;
#define Y cout << "YES" << endl;

template <typename T> void sort(vector<T> &a, bool desc = false);
template <typename T> void print(vector<T> &A);


void solve() {
    int n;
    cin >> n;
    vector<unsigned int> a(n);
    rp(i, n) cin >> a[i];
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    /*
    looping from n-1
    while it is not lesser than n
    if It is 0 and not i0 return -1
    make it n /= 2, operation ++
    */
//    print(a);
    int i = n-2;
    int op = 0;
    while (i > -1) {
       if (a[i + 1] == 0) {
           cout << -1 << endl;
           return;
        }
        while (a[i] >= a[i + 1] && a[i] != 0 && a[i + 1] != 0) {
           a[i] >>= 1; // uint shift-right
           op++;
        }
        i--;
    }
    cout << op << endl;
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