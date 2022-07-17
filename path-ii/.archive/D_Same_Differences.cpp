#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

#define ll long long
#define itr(i, n) for (int i = 0; i < n; i++)

int * scand(int &n);


void solve() {
    int n;
    cin >> n;
    // int * a = readInts(n);
    // vector<int> a(n);
    unordered_map<int, int> mmap;
    unordered_map<int, int>::iterator it;
    ll pairs = 0;
    int tmp;
    itr(i, n) {
        cin >> tmp;
        tmp -= i; // normalize
        it = mmap.find(tmp);
        if (it == mmap.end()) {
            mmap.insert({tmp, 1});
        } else {
            pairs += it->second;
            it->second++;
        }
    }

    // count the number of pairs st
    // their differance of indices is their differance of value
    
    // log the position and the value of the number
    // iteratively look forward
    // int pairs = 0;
    // loop(i, n) {
    //     // int value = a[i];
    //     for (int j = i + 1; j < n; j++) {
    //         if (a[j] - a[i] == j - i) pairs++;
    //     }
    // }
    // idea: normalize them
    // then make a map, at each occasion, add occurance + 1
    
    cout << pairs << endl;
}

int main() {
    int cases = 1;
    cin >> cases;
    while (cases--) {
        solve();
    }
    return 0;
}

//======= Library Functions =======

int * scand(int &n) {
    int * a = new int[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    return a;
}