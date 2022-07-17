#include <bits/stdc++.h>
#include <vector>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    
    while (t--) {
        // cout << "case " << t << ":\n";
        int n, m;
        cin >> n >> m;
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if ((n * 2) > m) {
            cout << "NO\n";
            continue;
        }
        sort(a.begin(), a.end(), std::greater<int>());
        int req = 0;

        if (n == 2) {
            req = a[0] * 2 + n;
        } else {
            // n is >= 2;
            long long sum = a[0] + 1 + a[0];
            long long R = 1 + a[1];
            long long L = a[2] + 1;

            // cout << "read: ";
            // for (int i : a) cout << i << " ";
            // cout << endl;
            // cout << "(init) now at " << L << ":" << sum << ":" << R << endl;

            if (n == 3) {
                int req = L + sum + R - a[2];
            } else {
                int st = 3;
                
                bool endWithR = false;
                while (st < n) {
                    sum = L + sum + R;

                    R = 1 + a[st++];
                    // cout << "sum: " << sum << endl;
                    // cout << "(R) now at " << R << endl;
                    if (st < n) {
                        L = a[st++] + 1;
                        // cout << "(L) now at " << L << endl;
                    } else {
                        endWithR = true;
                        break;
                    }
                }

                if (endWithR) {
                    req = sum + 1;
                } else {
                    req = sum + R + 1;
                }
            }
        }
        // cout << "req is " << req << endl;
        cout << (req > m ? "NO" : "YES") << endl;
    }
}