#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rp(i, n) for (int i = 0; i < n; i++)
#define N cout << "NO" << endl;
#define Y cout << "YES" << endl;

template <typename T> void sort(vector<T> &a, bool desc = false);
template <typename T> void print(vector<T> &A);

// #define hashmap unordered_map
// template <typename T> hashmap<T, int> getftable(vector<T> &A);


int findDist(char a, char b) {
    int less = min(a, b);
    int more = max(a, b);
    return more - less;
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        // vector<int> A(n, 0);
        map<int, int> freq;
        rp(i, n) {
            int tmp = 0;
            cin >> tmp;
            freq[tmp]++;
        }
        vector<pair<int, int>> vec;
        copy(freq.begin(), freq.end(), 
            back_inserter<vector<pair<int, int>>>(vec));
        sort(vec);



        int target = k;
        int maxcnt = 0;
        int curcnt = 0;
        int endnum = -99;
        bool started = false;

        rp(i, int(vec.size())) {
            // cout << vec[i].first << ":" << vec[i].second << endl;
            int key = vec[i].first;
            int val = vec[i].second;
// 1 check if the occurrence bigger than target
            if (val >= target && !started || val >= target && (vec[i - 1].first + 1 != key)) {
// if it is bigger than target, and not started consecutive counting
// start the counter, 
                started = true;
                curcnt = 1;
            } else if (val >= target) {
// else if it is bigger than target, and the diff of key from previous one is incremented by 1
// make counter ++ 
                curcnt++;
            } else {
// else (it is not bigger than target and the diff of key from previous one is different) -> case 1
// else reset every thing
                started = false;
                curcnt = 0;
// if the counter is bigger than any logged counter, log the ending number and the update the maxcounter
            }
            if (curcnt > maxcnt) {
                maxcnt = curcnt;
                endnum = key;
            }
        }
        if (endnum == -99) cout << -1 << endl;
        else cout << endnum - maxcnt + 1 << " " << endnum << endl;
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

// template <typename T>
// hashmap<T, int> getftable(vector<T> &A) {
//     typename vector<T>::iterator itr;
//     hashmap<int, int> ftable;
//     for (itr = A.begin(); itr != A.end(); itr++)
//         ftable[*itr]++;
//     return ftable;
// }