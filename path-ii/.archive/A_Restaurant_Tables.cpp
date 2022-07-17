#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rp(i, n) for (int i = 0; i < n; i++)
#define in  cin
#define out cout
#define N out << "NO"  << endl
#define Y out << "YES" << endl

template <typename T> void sort(vector<T> &a, bool desc = false);
template <typename T> void print(vector<T> &A);
template <typename T1, typename T2> void print_pairs(vector<pair<T1, T2>> &A);


int main() {
    int cases = 1;
    // cin >> cases;
    while (cases--) {
        int n, a, b, c = 0;
        in >> n >> a >> b;
        // vector<int> people(n, 0);
        int denied = 0;
        rp(i, n) {
            int num;
            in >> num;
            if (num == 1) {
                if (a > 0) {
                    a--;
                } else if (b > 0) {
                    b--;
                    c++;
                } else if (c > 0) {
                    c--;
                } else {
                    denied++;
                }
            } else if (num == 2) {
                if (b > 0) {
                    b--;
                } else {
                    denied += 2;
                }
            }
        }
        out << denied << endl;
        
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

template <typename T1, typename T2>
void print_pairs(vector<pair<T1, T2>> &A) {
    int n = A.size();
    cout << n << endl;
    rp(i, n)
        cout << A[i].first << " " \
            << A[i].second << endl;
}