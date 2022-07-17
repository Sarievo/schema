#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = n;
    int cmp = a[--k];
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] && a[i] >= cmp) break;
        ans--;
    }

    cout << ans << endl;

    return 0;
}