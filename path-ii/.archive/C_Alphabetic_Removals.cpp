#include <bits/stdc++.h>
using namespace std;

int mod = 998244353;
 
int main() {
    long long n, k;
    string s;
    cin >> n >> k >> s;
    // remove the least ordered key first
    // remove k times
    if (n <= k) {
        cout << "";
        return 0;
    }

    int map[26] = {0};
    for (int i = 0; i < n; i++) {
        map[s[i] - 'a']++;
    }

    int idx = 0;
    while (k >= 0) {
        k -= map[idx++];
    }

    int life = map[--idx] + k;

    // for (int i : map) cout << i;
    // cout << endl;
    // cout << "idx:" << idx << endl;
    // cout << "k:" << k << endl;
    // cout << "k to remove:" << life << endl;

    // k's .. occurrence
    for (int i = 0; i < n; i++) {
        int v = s[i] - 'a';
        if (v < idx) {
            continue; // if it has already been reducted
        }

        if (v == idx) {
            if (life) {
                life--;
                continue;
            }

            cout << s[i];
            continue;
        }

        cout << s[i];
    }
}