#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long a, b, k;
    cin >> a >> b >> k;
    if (a >= b) {
        cout << 0;
        return 0;
    }

    int times = 0;
    while (a < b) {
        a *= k;
        times++;
    }
    cout << times;
}