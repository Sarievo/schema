#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// #define pb emplace_back
// #define all(x) x.begin(), x.end()
// #define sz(x) static_cast<int32_t>(x.size())
// #define x first
// #define y second
// #define afor(i, n)     for(int i = 0; i < int(n); i++)
// #define dfor(i, n)     for(int i = int(n - 1); i >= 0; i--)
// #define ffor(i, a, b)  for(int i = int(a); i <= int(b); i++)
// #define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
int main() {
    fast_cin();
    string a, b;
    cin >> a >> b;
    cout << (a == b ? a : "1") << endl;
}