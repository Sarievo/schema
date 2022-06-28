/** 
 * Sarievo.
 * URL: https://codeforces.com/contest/1200/problem/D
 */

#include <bits/stdc++.h>
using namespace std;
//!<---------- start of define !<--------------------------
using ll=long long;
// #define int ll <-- if you could look at this
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
#define rep(i,b) rng(i,0,b) // i[0-b], go to range asc
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b) // i[b-0], go to range desc
template<class t> void fill(vc<t>& v, int inc=0) {iota(all(v),inc);}
#define acc(a) accumulate(all(a),int(0)) //...
//!<---------- end of define !<----------------------------
template<class t> ostream& operator<<(ostream& os,const vc<t>& v){os<<"{";for(auto e:v)os<<e<<":";return os<<"}";} // ease for debugging vectors
template<class t,class u> ostream& operator<<(ostream& os,const pair<t,u>& p){return os<<"{"<<p.a<<":"<<p.b<<"}";} // ease for debugging pairs
//!<---------- end of debug !<-----------------------------
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void f();
signed main() {
    IOS;
    int T=1;
    // cin >> T;
    while (T--) f();
}
//!<---------- end of preset !<----------------------------

void f() {
    int n,k; cin >> n >> k;
    vector<vector<bool>> g(n,vector<bool>(n));
    rep(i,n) rep(j,n) {
        char c; cin >> c;
        g[i][j]= c=='W';
    }
    vvc<int> pre_rows(n,vi(n+1,0));
    vvc<int> pre_cols(n,vi(n+1,0));
    rep(j,n) rng(i,1,n+1) {
        pre_rows[j][i]=pre_rows[j][i-1]+g[j][i-1];
        pre_cols[j][i]=pre_cols[j][i-1]+g[i-1][j];
    }
    vi pre_row(n+1,0),pre_col(n+1,0);
    rng(i,1,n+1) {
        pre_row[i]=pre_row[i-1]+(pre_rows[i-1][n]==n);
        pre_col[i]=pre_col[i-1]+(pre_cols[i-1][n]==n);
    }
    vvc<int> dp_row(n,vi(n,0));
    vvc<int> dp_col(n,vi(n,0));
    rep(i,n) rep(j,n) {
        dp_row[i][j]=j+k-1>=n?
            0:pre_rows[i][n]-pre_rows[i][j+k]+pre_rows[i][j]==n-k;
        dp_col[i][j]=i+k-1>=n?
            0:pre_cols[j][n]-pre_cols[j][i+k]+pre_cols[j][i]==n-k;
    }
    vvc<int> pre_dp_rows(n,vi(n+1,0));
    vvc<int> pre_dp_cols(n,vi(n+1,0));
    rep(j,n) rng(i,1,n+1) {
        pre_dp_rows[j][i]=pre_dp_rows[j][i-1]+dp_row[i-1][j];
        pre_dp_cols[j][i]=pre_dp_cols[j][i-1]+dp_col[j][i-1];
    }
    int ans=0;
    rep(i,n) rep(j,n) {
        if (i+k-1<n and j+k-1<n) {
            int tmp=(pre_row[i]+pre_row[n]-pre_row[i+k])
                   +(pre_col[j]+pre_col[n]-pre_col[j+k]);
            tmp+=(pre_dp_cols[i][j+k]-pre_dp_cols[i][j]);
            tmp+=(pre_dp_rows[j][i+k]-pre_dp_rows[j][i]);
            chmax(ans,tmp);
        }
    }
    cout << ans << endl;
}