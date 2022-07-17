#include <bits/stdc++.h>
using namespace std;

int mod = 998244353;
 
int main() {
    long long n, m, a, b;
    cin >> n >> m >> a >> b;
    if (a * m <= b) {
        cout << n * a;
        return 0;
    } else {
        if (m <= n) {
            int times = n / m;
            int rem = n % m;
            int cost = times * b;

            if (b <= a * rem) {
                cost += b;
            } else {
                cost += a * rem;
            }
            
            cout << cost;
            return 0;
        } else {
            int cost;
            if (b <= a * n) {
                cost = b;
            } else {
                cost = a * n;
            }
            cout << cost;
            return 0;
        }
    }

}