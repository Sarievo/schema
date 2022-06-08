/** 
 * Sarievo.
 * URL: https://codeforces.com/problemset/problem/1657/C
 */

#include <bits/stdc++.h>
#define poly vector<int>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) // make io faster
#define rep(i, n) for(int i = 0; i < n; i++)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair<int,int>
#define fi first
#define se second
#define inf 1e18
#define int ll
#define all(a) (a).begin(), (a).end()
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++) // iterate from sequence for a given type
template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }
using namespace std;
 
void f() {
    int n; cin >> n;
    string s; cin >> s;
    int ops = 0;
    int last = 0;
    deque<char> q;
    for (int i = 0; i < n; i++) {
        // check validity
        if (s[i] == '(') {
            // open
            q.push_back('(');
        } else {
            // close
            if (q.size() && q.back() == '(') {
                q.pop_back();
                if (!q.size()) {
                    // cout << "isValid\n";
                    ops++;
                    last = i+1;
                    continue;
                }
            } else {
                // invalid
                q.push_back(')');
            }
        }

        // check is palindrome
        if ((i != last) && s[i] == s[last]) {
            bool isPalindrome = true;
            for (int j = 1; j <= (i-last)/2; j++) {
                if (s[last+j] != s[i-j]) {
                    isPalindrome = false;
                    break;
                }
            }
            if (isPalindrome) {
                // cout << "isPalindrome:" <<i << "\n";;
                ops++;
                last = i+1;
                q.clear(); // the stack is instantly deleted
                continue;
            }
        }
    }
    cout << ops << " " << (n-last) << "\n";
}

signed main() {
    IOS;
    int T=1;
    cin >> T;
    while (T--) {
        f();
    }
}
