#include <bits/stdc++.h>
using namespace std;

int main() {
    string a;
    string b;
    cin >> a >> b;
    for (int i = 0; i < a.length(); i++) {
        int vA = 0;
        int vB = 0;

        if (a[i] > 'Z')
            vA = a[i] - 'a';
        else vA = a[i] - 'A';

        if (b[i] > 'Z')
            vB = b[i] - 'a';
        else vB += b[i] - 'A';

        int cmp = vA - vB;
        if (cmp > 0) {
            cout << 1;
            return 0;
        }
        if (cmp < 0) {
            cout << -1;
            return 0;
        }
    }

    cout << 0; //
}