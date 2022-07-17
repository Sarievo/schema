#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    int luckies = 0;
    while (n > 0) {
        int tmp = n % 10;
        if (tmp == 4 || tmp == 7)
            luckies++;
        n /= 10;
    }
    if (luckies == 7 || luckies == 4)
        cout << "YES";
    else cout << "NO";
}