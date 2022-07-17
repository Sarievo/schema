#include <bits/stdc++.h>
using namespace std;


int * readInts(int &n) {
    int * a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    return a;
}

void solve() {
    int n;
    cin >> n;
    int * a = readInts(n);
    // if there's isolated zeros (not at start or end)
    // it will be disturbed
    // find the minimum i to be set to 0,
    // so nobody will be disturbed

    // if there is zero and before it is 1
    // if the next is 1, set it to zero, cnt++
    // before is zero
    int before = a[0];
    int count = 0;
    for (int i = 1; i < n - 1; i++) {
        if (a[i] == 0 && before == 1) {
            if (a[i + 1] == 1) {
                a[i + 1] = 0;
                count++;
            }
        }
        before = a[i];
    }
    cout << count << endl;
}

int main() {
    int cases = 1;
    // cin >> cases;
    while (cases--) {
        solve();
    }
    return 0;
}
