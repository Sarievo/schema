#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rp(i, n) for (int i = 0; i < n; i++)
#define N cout << "NO" << endl;
#define Y cout << "YES" << endl;

template <typename T> void sort(vector<T> &a, bool desc = false);
template <typename T> void print(vector<T> &A);


int main() {
    int cases = 1;
    // cin >> cases;
    while (cases--) {
        int n;
        cin >> n;
        // print the last digit of 1378^n
        // there's nothing to do with 1370
        // when 8 raise to its 5th power, it end with 8 and encountered a loop
        if (n == 0) {
            cout << 1 << endl;
            return 0;
        }
        vector<int> dict = {8, 4, 2, 6};
        int rem = (n - 1) % 4;
        cout << dict[rem] << endl;
    }
    return 0;
}

//======== ⚠ Don't Complicate the Problem ⚠ ========
template <typename T>
void sort(vector<T> &a, bool desc) {
    if (desc) {
        sort(a.begin(), a.end(), [](T a, T b) {return a > b;});
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