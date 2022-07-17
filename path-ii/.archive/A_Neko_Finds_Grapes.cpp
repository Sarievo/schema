#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rp(i, n) for (int i = 0; i < n; i++)
#define N cout << "NO" << endl;
#define Y cout << "YES" << endl;

template <typename T> void sort(vector<T> &a, bool desc = false);
template <typename T> void print(vector<T> &A);


int solve() {
    int n, m;
    cin >> n >> m;
    // vector<int> a1(n);
    // vector<int> a2(m);
    ll odds = 0;
    ll evens = 0;
    rp(i, n) {
        int tmp;
        cin >> tmp;
        if (tmp % 2 == 1) odds++;
        else evens++;
    }


    int ans = 0;
    rp(i, m) {
        int tmp;
        cin >> tmp;
        // cin >> a2[i];
        if (tmp % 2 == 1) {
            if (evens > 0) {
                evens--;
                ans++;
            }
        } else {
            if (odds > 0) {
                odds--;
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    int cases = 1;
    // cin >> cases;
    while (cases--) {
        cout << solve() << endl;
    }
    return 0;
}

//======== ⚠ Do't Complicate the Algorithm ⚠ ========

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