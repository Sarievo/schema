#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    int * a1 = new int[n];
    int * a2 = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a2[i];
    }
    // for i in a1, there need to be at least 1 
    // is solvable by a1, and not by a2
    int aEx = 0;
    // for i in a2, count the number of i that is
    // solvable by a2, but not by a1
    int bEx = 0;
    for (int i = 0; i < n; i++) {
        if (a1[i] == 1 && a2[i] == 0)
            aEx++;
        else if (a1[i] == 0 && a2[i] == 1)
            bEx++;
    }
    if (aEx == 0) {
        cout << "-1" << endl;
        return;
    }
    if (aEx == 1) {
        cout << (bEx + 1) << endl;
        return;
    }
    int limit = bEx / aEx;
    // if (bEx % aEx != 0) limit++;
    cout << limit + 1 << endl;
    // the points can be divided by questions solvable
}

int main() {
    int cases = 1;
    // cin >> cases;
    while (cases--) {
        solve();
    }
    return 0;
}
