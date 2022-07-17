#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rp(i, n) for (int i = 0; i < n; i++)
#define N cout << "NO" << endl
#define Y cout << "YES" << endl

template <typename T> void sort(vector<T> &a, bool desc = false);
template <typename T> void print(vector<T> &A);


int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> A(n, 1);
// if a is 0 and b is 0, just decrease from n to 1
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (b == 0) {
        if (a >= n - 1) {
            cout << -1 << endl;
        } else {
            // cout << "IM" << endl;
            int start = 2;
            int end = 1 + a;

            for (int i = start; i <= end; i++) {
                int prev = A[i - 1];
                A[i] = prev + 1;
            }

            start += a;
            end = n;
            for (int i = start; i < end; i++) {
                int prev = A[i - 1];
                A[i] = prev;
            }
            for (int i = 0; i < n; i++) {
                cout << A[i] << " ";
            }
            cout << endl;
        }
    } else {
        // cout << "IM" << endl;
        int start = 1;
        int end = b;
        for (int i = start; i <= end; i++) {
            int prev = A[i - 1];
            A[i] = prev * 2;
        }

        start += b;
        end += a;
        for (int i = start; i <= end; i++) {
            int prev = A[i - 1];
            A[i] = prev + 1;
        }

        start += a;
        end = n;
        for (int i = start; i < end; i++) {
            int prev = A[i - 1];
            A[i] = prev;
        }

        for (int i = 0; i < n; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
// if (2^b + a > n)
    // if there's b, from 1, to it like 1 2 4 8 16 ..
    // get prev and multiply it, 
    // for all a, increase 1 prev each, 
    // than decrease for the remaining of n

// make it increasing using a, then 

    // b will supersede a, so keep b minimized
    // say: 1 2 4
}


//======== ⚠ Don't Complicate the Problem ⚠ ========

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