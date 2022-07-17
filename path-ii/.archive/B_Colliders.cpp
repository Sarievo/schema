// Level 1400
#include <bits/stdc++.h>
#include <complex>
#include <list>
#include <chrono>
#include <random>
#include <algorithm>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define inf 1000000007
// vector<bool> prime(1e5 + 1, true);
// vector<int> spf(1e5 + 1, -1);
// void seive()
// {
//     int n = 1e5;
//     for (int i = 2; i * i <= n; i++)
//     {
//         if (prime[i])
//         {
//             for (int j = i * i; j <= n; j += i)
//             {
//                 if (spf[j] == -1)
//                     spf[j] = i;
//                 prime[j] = 0;
//             }
//         }
//     }
// }
int main() {
    fast_cin();
    ll n, m;
    cin >> n >> m;
    vector<bool> prime(n + 1, true);
    vector<int> spf(n + 1, -1);
    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                if (spf[j] == -1)
                    spf[j] = i;
                prime[j] = 0;
            }
        }
    }
    vector<int> vec(n + 1, 0);
    for (int i = 0; i < m; i++) {
        char c;
        ll e;
        cin >> c;
        cin >> e;
        if (c == '+') {
            int d = spf[e] == -1 ? e : spf[e];
            if (vec[d]) {
                if (vec[d] == e)
                    cout << "Already on" << ln;
                else
                    cout << "Conflict with " << vec[d] << ln;
            } else {
                if (e != 1) {
                    ll t = e;
                    bool flag = 0;
                    while (spf[e] != -1) {
                        if (vec[spf[e]] != 0) {
                            cout << "Conflict with " << vec[spf[e]] << ln;
                            flag = 1;
                            break;
                        }
                        else
                            e /= spf[e];
                    }
                    if (flag)
                        continue;
                    if (e != 1 and vec[e] != 0) {
                        cout << "Conflict with " << vec[e] << ln;
                        continue;
                    }
                    e = t;
                    while (spf[e] != -1) {
                        vec[spf[e]] = t;
                        e /= spf[e];
                    }
                    if (e != 1)
                        vec[e] = t;
                }
                else
                    vec[e] = e;
                cout << "Success" << ln;
            }
        } else {
            int d = spf[e] == -1 ? e : spf[e];
            if (vec[d] == e) {
                cout << "Success" << ln;
                if (e != 1) {
                    while (spf[e] != -1) {
                        vec[spf[e]] = 0;
                        e /= spf[e];
                    }
                    if (e != 1)
                        vec[e] = 0;
                }
                else
                    vec[e] = 0;
            } else {
                cout << "Already off" << ln;
            }
        }
    }
    return 0;
}