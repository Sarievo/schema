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
        int n, sx, sy;
        cin >> n >> sx >> sy;

        int L = 0, R = 1e9;
        vector<int> cand (4, -1);
        vector<vector<int>> helper {{-1, 0}, {0, -1}, {0, +1}, {+1, 0}};
        rp(i, 4) {
            int newX = sx + helper[i][0];
            int newY = sy + helper[i][1];
            if ((newX >= L && newX <= R) && (newY >= L && newY <= R)) {
                cand[i] = 0;
                helper[i] = {newX, newY};
            } else {
                helper[i] = {-1, -1};
            }
        }

        rp(i, n) {
            int x, y;
            cin >> x >> y;
            rp(j, 4) {
                if (cand[j] != -1
                        && (min(sx, x) <= helper[j][0] && helper[j][0] <= max(sx, x))
                        && (min(sy, y) <= helper[j][1] && helper[j][1] <= max(sy, y)))
                    cand[j]++;
            }
        }

        int maxOverlap = -1;
        vector<int> ans;
        rp(i, 4) {
            if (cand[i] > maxOverlap) {
                maxOverlap = cand[i];
                ans = helper[i];
            }
        }

        cout << maxOverlap << endl;
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

//======== ⚠ Do't Complicate the Problem ⚠ ========

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