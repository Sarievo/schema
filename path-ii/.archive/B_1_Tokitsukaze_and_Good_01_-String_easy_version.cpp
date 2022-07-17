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
        string s;
        cin >> s;
        
        vector<int> A; // seg occ
        
        // getting the seg
        char curr = s[0];
        int seglen = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] != curr) {
                curr = s[i];
                A.push_back(seglen);
                seglen = 0;
            }
            seglen++;
        }
        if (seglen) A.push_back(seglen);
        // finished getting the seg

        ll answer = 0;
        int prevOddIdx = -1;
        for (int i = 0; i < (int) A.size(); i++) {
            if (A[i] % 2 == 1) {
                if (prevOddIdx != -1) {
                    answer += i - prevOddIdx;
                    prevOddIdx = -1;
                } else {
                    prevOddIdx = i;
                }
            }
        }

        cout << answer << endl;
        // print(A);
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