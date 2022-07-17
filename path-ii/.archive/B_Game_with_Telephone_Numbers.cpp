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
    // cin >> cases;
    while (cases--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int extra = s.length() - 11;
        int eights = 0;
        rp(i, extra) {
            if (s[i] == '8') eights++;
        }
        int others = extra - eights;
        if (others > eights) {
            cout << "NO" << endl;
        } else if (others == eights) {
            cout << (s[extra] == '8' ? "YES" : "NO") << endl;
        } else {
            cout << "YES" << endl;
            // int diff = eights - others;
            // if (diff > (extra - extra % 2) / 2) {
            //     cout << "YES" << endl;
            //     continue;
            // }
            // // cout << "CUR DIF" << diff << endl;
            // for (int i = extra; i < n; i++) {
            //     if (s[i] == '8' || diff < 0) break;
            //     diff--;
            //     // cout << "CUR DIF" << diff << endl;
            // }
            // cout << (diff < 0 ? "NO" : "YES") << endl;
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