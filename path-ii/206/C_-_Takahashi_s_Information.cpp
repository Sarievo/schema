/** 
 * Sarievo.
 * URL: https://atcoder.jp/contests/abc088/tasks/abc088_c
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
    vvc<int> m(3,vi(3));
    for (auto &a : m) for (auto &x : a) cin >> x;
    int diff_b12 = m[0][1]-m[0][0]; // assume the diff from the first row
    int diff_b23 = m[0][2]-m[0][1];
    int diff_a12 = m[1][0]-m[0][0]; // assume the diff from the first col
    int diff_a23 = m[2][0]-m[1][0];
    for (int i=1;i<=2;i++) {
        if (m[i][1]-m[i][0] != diff_b12 || m[i][2]-m[i][1] != diff_b23) {
            cout << "No" << endl;
            return;
        }
        if (m[1][i]-m[0][i] != diff_a12 || m[2][i]-m[1][i] != diff_a23) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}