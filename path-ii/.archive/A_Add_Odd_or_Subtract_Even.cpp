#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rp(i, n) for (int i = 0; i < n; i++)
#define N cout << "NO" << endl
#define Y cout << "YES" << endl

template <typename T> void sort(vector<T> &a, bool desc = false);
template <typename T> void print(vector<T> &A);

int main() {
    int cases = 1;
    cin >> cases;
    while (cases--) {
        int a, b;
        cin >> a >> b;
        bool isAOdd = a % 2 == 1;
        bool isBOdd = b % 2 == 1;
        if (a == b) {
            cout << 0 << endl;
        } else if (a > b) {
            if (isAOdd == isBOdd) {
                cout << 1 << endl;
            } else {
                cout << 2 << endl;
            }
        } else {
            if (isAOdd != isBOdd) {
                cout << 1 << endl;
            } else {
                cout << 2 << endl;
            }
        }
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