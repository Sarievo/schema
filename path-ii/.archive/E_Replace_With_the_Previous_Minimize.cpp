#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rp(i, n) for (int i = 0; i < n; i++)
#define N cout << "NO" << endl;
#define Y cout << "YES" << endl;

template <typename T> void sort(vector<T> &a, bool desc = false);
template <typename T> void print(vector<T> &A);


string solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k == 0) return s;
    
    char tmp = s[0];
    if (k <= s[0] - 'a') {
        s[0] -= k;
        for (int i = 1; i < n; i++) {
            if (s[i] > s[0] && s[i] <= tmp)
                s[i] = s[0];
        }
    } else {
        int krem = k - (s[0] - 'a');
        s[0] = 'a';
        char specTmp = 'N';
        char specRep = 'N';
        for (int i = 1; i < n; i++) {
            char e = s[i];
            if (e <= tmp) {
                if (e > s[0]) s[i] = s[0];
            } else {
                // if (krem == 0) continue;
                int diff = (e - tmp);
                if (diff <= krem) {
                    tmp = e;
                    krem -= diff;
                    // cout << "diff " << diff << endl;
                    s[i] = s[0];
                } else if (specTmp == 'N') {
                    // cout << "krem:diff " << krem << ":" << diff << "\n";
                    specTmp = e;
                    s[i] = e - krem;
                    specRep = s[i];
                    krem = 0;
                } else {
                    if (e <= specTmp && e > specRep) {
                        s[i] = specRep;
                    }
                }
            }
        }
    }
    return s;
}

int main() {
    int cases = 1;
    cin >> cases;
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