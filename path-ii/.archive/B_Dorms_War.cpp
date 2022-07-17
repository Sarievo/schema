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
        string s;
        cin >> n >> s;

        int k;
        cin >> k;


        char tmp;
        // unordered_set<char> a;
        vector<int> a (27, 0);
        while (k--) {
            cin >> tmp;
            // a.insert(tmp);
            a[tmp - 'a']++;
        }

        if (n == 1) {
            cout << 0 << endl;
            continue;
        }

        s[0] = 'z' + 1;

        int irr = 0;
        int maxC = 0;
        int curC = 0;
        for (int i = 0; i < n; i++) {
            if (a[s[i] - 'a'] == 0) curC++;
            else {
                if (maxC != 0 && curC >= maxC) irr = 1;
                maxC = max(maxC, curC);
                curC = 0;
            }
        }
        if (irr) maxC++;
        cout << maxC << endl;
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