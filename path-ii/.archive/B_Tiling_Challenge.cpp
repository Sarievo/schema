#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rp(i, n) for (int i = 0; i < n; i++)
#define N cout << "NO" << endl
#define Y cout << "YES" << endl

template <typename T> void sort(vector<T> &a, bool desc = false);
template <typename T> void print(vector<T> &A);



int helper[4][2] = {{+1, -1}, {+1, 0}, {+1, 1}, {+2, 0}};

bool isValid() {
    int n;
    cin >> n;
    vector<vector<char>> m(n, vector<char>(n));
    rp(i, n) rp(j, n)
        cin >> m[i][j];
    
    // rp(i, n)  {
    //         rp(j, n) {
    //         cout << m[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    rp(i, n) rp(j, n) {
        if (m[i][j] == '.') {
            rp(k, 4) {
                int newI = i + helper[k][0];
                int newJ = j + helper[k][1];
                // cout << newI << ":" << newJ << endl;

                if (newI >= n || newJ >= n || newJ < 0
                        || m[newI][newJ] == '#')
                    return false;
                
                m[newI][newJ] = '#';
            }

        }
    }
    
    return true;
}

int main() {
    int cases = 1;
    // cin >> cases;
    while (cases--) {
        cout << (isValid() ? "YES" : "NO") << endl;
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