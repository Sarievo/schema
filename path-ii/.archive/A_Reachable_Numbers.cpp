#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    
    int ans = 0;
    while (n > 9) {
        // if it's bigger than 9,
        // we get it's rightmost number
        // apply it to the sum by (10 - that_number)
        // make it shift right
        int nAtd0 = n % 10;
        ans += (10 - nAtd0);
        n /= 10;
        n++;
        while (n % 10 == 0) n /= 10; // ??
    }
    ans += 9;
    cout << ans;
}