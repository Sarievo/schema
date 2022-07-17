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
    cin >> cases;
    while (cases--) {
        // int n;
        string s;
        cin >> s;
        int sumfirst3 = s[0] + s[1] + s[2] - ('0' * 3);
        int sumlast3  = s[3] + s[4] + s[5] - ('0' * 3);
        // cout << sumfirst3 << ":" << sumlast3 << "\n";
        if (sumfirst3 == sumlast3) {
            Y;
        } else {
            N;
        }
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
    // cout << n << endl;
    rp(i, n) cout << A[i] << " ";
    cout << endl;
}