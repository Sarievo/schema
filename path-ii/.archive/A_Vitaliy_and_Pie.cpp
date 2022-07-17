#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, c = 0, d = 0;
    cin >> n;
    string s;
    cin >> s;
    ll a[30] {0};
    for (int i = 0; i < 2 * n - 2; i++) {
        if (i % 2 == 0) {
            a[s[i] - 'a']++;
        } else {
            if (a[tolower(s[i]) - 'a'] > 0) {
                a[tolower(s[i]) - 'a']--;
            } else {
                c++;
            }
        }
    }
    cout << c << endl;
    return 0;
}
