#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, op;
    cin >> n >> op;
    while (op--) {
        if (n % 10 == 0) {
            n /= 10;
        } else {
            n--;
        }
    }
    cout << n;
}