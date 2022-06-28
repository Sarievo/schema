/** 
 * Sarievo.
 * URL: https://codeforces.com/contest/271/problem/B
 */

#include <bits/stdc++.h>
using namespace std;
//!<---------- start of define !<--------------------------
using ll=long long;
// #define int ll
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
template<class t,class u> bool chmax(t&a,const u&b){return a<b?a=b,1:0;}
template<class t,class u> bool chmin(t&a,const u&b){return a>b?a=b,1:0;}
template<typename X> inline X abs(const X& a) {return (a<0?-a:a);}
template<typename X> inline X sqr(const X& a) {return (a*a);}
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b) // i[0-b), go to range asc
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b) // i(b-0], go to range desc
template<class t> void asc(vc<t>& v, int inc=0) {iota(all(v),inc);}
#define acc(a) accumulate(all(a),int(0)) //...
//!<---------- end of define !<----------------------------
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
template<typename T> istream& operator>>(istream& is, vc<T>&v){for(auto&e:v)is>>e;return is;}
template<typename T> ostream& operator<<(ostream& os, const vc<T>&v){for(auto&e:v)os<<e<<" ";return os;}
template<typename T> istream& operator>>(istream& is, pair<T,T>&v){is>>v.a>>v.b;return is;}
template<typename T> ostream& operator<<(ostream& os, const pair<T,T>&v){os<<v.a<<" "<<v.b;return os;}
//!<---------- end of IO !<-----------------------------
void f();
signed main() {
    IOS;
    int T=1;
    // cin >> T;
    while (T--) f();
}
//!<---------- end of preset !<----------------------------

const int N = 1e5 + 9;
vector<int> sieve(N,0);
void precalc_sieve() {
    sieve[1] = 1; // 1 is not a prime in this problem
    for (int x = 2; x <= N; x++) {
        if (sieve[x]) continue;
        for (int u = 2*x; u <= N; u += x) {
            sieve[u] = x;
        }
    }
}

int find_nearest_prime(int i) {
    // linear search, you can only increase it by one
    int pos_cnt = 0;
    int tmp = i;
    while (sieve[tmp++]) pos_cnt++;
    return pos_cnt;
}

void f() {
    int n, m; cin >> n >> m;
    vvc<int> g(n, vi(m,0)); cin >> g;
    precalc_sieve();
    /* 
    whether any row or col of the matrix consists of only prime numbers, it's a prime matrix
    generate all primes from 1 to 1e5, 
        for every numbers in the matrix, 
            if it's not a prime, find it's nearest prime
     */

    vvc<int> cands;
    rep(i,n) {
        vi row_cands;
        bool row_valid = true;
        rep(j,m) {
            if (sieve[g[i][j]]) {
                row_valid = false;
                row_cands.push_back(g[i][j]);
            }
        }
        if (row_valid) {
            cout << "0\n";
            return;
        }
        cands.push_back(row_cands);
    }
    rep(i,m) {
        vi col_cands;
        bool col_valid = true;
        rep(j,n) {
            if (sieve[g[j][i]]) {
                col_valid = false;
                col_cands.push_back(g[j][i]);
            }
        }
        if (col_valid) {
            cout << "0\n";
            return;
        }
        cands.push_back(col_cands);
    }

// cout << cands << endl;

    int min_cost = INT_MAX;
    for (auto&cand:cands) {
        int sum_of_diff = 0;
        for (auto&e:cand) {
            sum_of_diff += find_nearest_prime(e);
        }
        chmin(min_cost, sum_of_diff);
    }
    cout << min_cost << endl;
}