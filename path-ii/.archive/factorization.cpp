#include <bits/stdc++.h>
using namespace std;

int main() {
    // print the factorization list
    int n;
    cin >> n;

    for (int i = 2; i*i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            cout << i << ", ";
        }
    }
    if (n > 1) cout << n;
    cout << endl;
}