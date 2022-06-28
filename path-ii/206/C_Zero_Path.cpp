/** 
 * Sarievo.
 * URL: https://codeforces.com/contest/1695/problem/C
 */

#include <bits/stdc++.h>
using namespace std;
//!<---------- start of define !<--------------------------
using ll=long long;
#define int ll
using ull=unsigned long long;
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
using pi=pair<int,int>;
#define mp make_pair
#define a first
#define b second
using vi=vc<int>;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)x.size()
#define pb push_back
#define eb emplace_back
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;} // if a < b, a is replaced by b
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;} // if a > b, a is replaced by b
template<typename X> inline X abs(const X& a) {return (a<0?-a:a);}
template<typename X> inline X sqr(const X& a) {return (a*a);}
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b) // i[0-b), go to range asc
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b) // i(b-0], go to range desc
template<class t> void fill(vc<t>& v, int inc=0) {iota(all(v),inc);}
#define acc(a) accumulate(all(a),int(0)) //...
//!<---------- end of define !<----------------------------
template<class t> ostream& operator<<(ostream& os,const vc<t>& v){os<<"{";for(auto e:v)os<<e<<":";return os<<"}";}
template<class t,class u> ostream& operator<<(ostream& os,const pair<t,u>& p){return os<<"{"<<p.a<<":"<<p.b<<"}";}
//!<---------- end of debug !<-----------------------------
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void f();
signed main() {
    IOS;
    int T=1;
    cin >> T;
    while (T--) f();
}
//!<---------- end of preset !<----------------------------

#define N 1010

int n, m;
vvc<int> g;
int mn[N][N], mx[N][N];

void f() {
    cin >> n >> m;
    g = vvc<int>(n, vi(m, 0));
    rep(i, n) rep(j, m) cin >> g[i][j];
    if ((n * m) % 2 == 1) {
        cout << "NO" << endl;
        return;
    }

// calculate the prefix sum of row 0 and col 0
    mn[0][0] = mx[0][0] = g[0][0];
    for (int i = 1; i < n; ++i)
        mx[i][0] = mn[i][0] = mx[i - 1][0] + g[i][0];
    for (int j = 1; j < m; ++j)
        mx[0][j] = mn[0][j] = mx[0][j - 1] + g[0][j];
// calculate the minimal path sum and maximum path sum
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j) {
            mx[i][j] = max(mx[i - 1][j], mx[i][j - 1]) + g[i][j];
            mn[i][j] = min(mn[i - 1][j], mn[i][j - 1]) + g[i][j];
        }
// if the minimum sum is even, the maximum sum got to be even too
    if (mn[n - 1][m - 1] % 2 || mn[n - 1][m - 1] > 0 || mx[n - 1][m - 1] < 0)
        cout << "NO\n";
    else
        cout << "YES\n";
}