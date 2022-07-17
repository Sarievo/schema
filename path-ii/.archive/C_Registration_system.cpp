#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    string st;
    map<string, int> mp;
    map<string, int>::iterator it;
    cin >> n;
    while (n--) {
        cin >> st;
        it = mp.find(st);
        if (it == mp.end()) {
            mp.insert({st, 1});
            cout << "OK" << endl;
        } else {
            cout << st << it->second++ << endl;
        }
    }
}

int main() {
    int cases = 1;
    // cin >> cases;
    while (cases--)
    {
        solve();
    }
    return 0;
}
