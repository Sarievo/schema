#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rp(i, n) for (int i = 0; i < n; i++)
#define N cout << "NO" << endl;
#define Y cout << "YES" << endl;

template <typename T> void sort(vector<T> &a, bool desc = false);
template <typename T> void print(vector<T> &A);


int findDist(char a, char b) {
    int less = min(a, b);
    int more = max(a, b);
    return more - less;
}

int main() {
    int cases = 1;
    cin >> cases;
    while (cases--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> board(n, vector<int>(m, 0));
        int diaLen = n + m - 1;
        vector<int> A(diaLen, 0);
        vector<int> B(diaLen, 0);

        rp(i, n) rp(j, m) {
            int num;
            cin >> num;

            board[i][j] = num;
            A[i + j] += num;
            B[(n - 1 - i) + j] += num;
        }
        
        // cout << "\nDEBUG #" << cases << endl;
        // print(A);
        // print(B);

        ll maxRew = 0;
        rp(i, n) rp(j, m) {
            ll sum = (A[i + j] + B[(n - 1 - i) + j]) - board[i][j];
            maxRew = max(maxRew, sum);
        }
        cout << maxRew << endl;
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