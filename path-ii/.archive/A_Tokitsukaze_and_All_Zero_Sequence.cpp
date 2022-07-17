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
    cin >> cases;
    while (cases--) {
        int n;
        cin >> n;
        vector<int> dictionary(101, 0); // the numbers are ranged from 0 to 100, init with 0
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            dictionary[tmp]++;
        }
        ll sumOfPos = 0;
        bool hasDup = false;
        for (int i = 1; i <= 100; i++) {
            int value = dictionary[i];
            if (value > 1) hasDup = true;
            sumOfPos += value;
        }
        if (dictionary[0] || hasDup) {
            cout << sumOfPos << endl;
        } else {
            cout << (sumOfPos + 1) << endl;
        }
        
    }
    return 0;
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