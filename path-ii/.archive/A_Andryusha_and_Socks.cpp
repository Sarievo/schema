#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

#define ll long long
#define loop(i, n) for (int i = 0; i < n; i++)
#define hashmap unordered_map
#define hashset unordered_set

int * scand(int &n);


void solve() {
    int n;
    cin >> n;
    // idea: hashset
    // if the set contains the item, remove the item
    // it the set does not contain the item, put it to the set
    // find the max size of the set during the process
    hashset<int> myset;
    hashset<int>::iterator it;
    int setmax = -1;
    int tmp = -1;
    while (n) {
        cin >> tmp;
        it = myset.find(tmp);
        if (it == myset.end()) { // item was not found
            myset.insert(tmp);
        } else { // item was found
            myset.erase(it);
            n--;
        }
        setmax = max(setmax, (int) myset.size());
    }
    cout << setmax << endl;
}

int main() {
    int cases = 1;
    // cin >> cases;
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