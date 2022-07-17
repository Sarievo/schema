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
    vector<int> v(n);
    rp(i, n) cin >> v[i];
    // if the consecutive start with 0 or end with 1000, remove end/start exclusive, and start/end inclusive
    // else remove start and end exclusive
    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    bool startWith1 = v[0] == 1;
    bool endWith1k = v[n - 1] == 1000;

    int consec = 0;
    int startIndex = -1;
    int endIndex = n - 1;
    int maxCon = 0;
    rp(i, n - 1) {
        if (v[i] == v[i + 1] - 1) {
            if (startIndex == -1) {
                startIndex = i;
            }
            consec++;
        } else {
            if (consec) {
                endIndex = i;
                if (startIndex == 0 && startWith1) {
                    // cout << "path1 ";
                    // cout << consec << endl;
                    maxCon = max(maxCon, consec);
                } else {
                    // cout << "path2 ";
                    // cout << consec << endl;
                    maxCon = max(maxCon, consec - 1);
                }
                // break;
                startIndex = -1;
                consec = 0;
            }
        }
    }

    if (consec) {
        if (consec == n - 1) {
            // cout << consec << endl;
            maxCon = (consec - 1) + (startWith1 ? 1 : 0) + (endWith1k ? 1 : 0);
        } else if (endWith1k) maxCon = max(maxCon, consec);
        else maxCon = max(maxCon, consec - 1);
    }
    cout << maxCon << endl;


    // int consec = 0;
    // int ans = 0;
    // // bool hasErased = false;
    // rp(i, n - 1) {
    //     if (v[i] == v[i + 1] - 1) consec++;
    //     else {
    //         if (consec) {
    //             int startIndex = i - consec;
    //             // cout << "INDEX: " << startIndex << endl;
    //             // cout << "CONSEC:" << consec << endl;
    //             if (startIndex == 0) {
    //                 if (startWith1) ans = consec;
    //                 else ans = consec - 1;
    //                 cout << ans << endl;
    //                 return;

    //             } else if (consec > 1) {
    //                 ans = consec - 1;
    //                 cout << ans << endl;
    //                 return;
    //                 // cout << "ANS:" << ans << endl;
    //             }
    //         }
    //         consec = 0;
    //     }
    // }

    // if (consec) {
    //     if (consec == n - 1) {
    //         ans += (consec - 1) + (startWith1 ? 1 : 0) + (endWith1k ? 1 : 0);
    //     } else {
    //         ans += (consec - 1) + (endWith1k ? 1 : 0);
    //     }
    // }
    // cout << ans << endl;

    // int consecutive = 0;
    // int startIndex = -1;
    // int numbersToRemove = 0;
    // rp(i, n - 1) {
    //     if (v[i] + 1 == v[i + 1]) {
    //         if (startIndex = -1) startIndex = i;
    //         consecutive++;
    //     } else {
    //         if (consecutive) {
    //             if (startIndex == 0 && v[0] == 1) {
    //                 numbersToRemove += consecutive;
    //             } else numbersToRemove += consecutive - 1;
    //         }
    //         startIndex = -1;
    //         consecutive = 0;
    //     }
    // }

    // if (consecutive) {
    //     if (v[n - 1] == 1000) 
    //         numbersToRemove += consecutive;
    //     else {numbersToRemove += max(consecutive - 1, 0);};
    // }

    // cout << numbersToRemove << endl;
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