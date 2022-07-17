#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    // case >= 4
    // case <  4
    string ans = "";
    while (n > 3) {
        n -= 2;
        ans += "1";
    }

    if (n == 3) ans = "7" + ans;
    else ans += "1";

    cout << ans << endl;
}

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        solve();
    }
    return 0;
}
