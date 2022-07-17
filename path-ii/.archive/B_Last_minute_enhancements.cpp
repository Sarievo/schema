#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    int * a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    // if the first note appear in the prevous round
    // and the second note - the first note > 1, diff++ 
    // for each adj notes, log the first note
    int tmp = -1;
    for (int i = 0; i < n - 1; i++) {
        if (tmp == a[i] && (a[i] != a[i + 1]))
            a[i]++;
        tmp = a[i];
    }
    a[n - 1]++;
    
    int diff = 1;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] != a[i + 1]) diff++;
    }
    // for (int i = 0; i < n; i++) cout << a[i] << " ";
    // cout << endl;

    cout << diff << endl;
}

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        solve();
    }
    return 0;
}
