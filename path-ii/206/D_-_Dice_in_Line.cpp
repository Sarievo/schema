/** 
 * Sarievo.
 * URL: https://atcoder.jp/contests/abc154/tasks/abc154_d
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
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
void f();

signed main() {
    IOS;
    int T=1;
    // cin >> T;
    while (T--) f();
}
//!<---------- end of preset !<----------------------------

void f() {
    int n, k; cin >> n >> k;
    vi a(n); for (auto &x : a) cin >> x;
    // 1,2=1.5 1,2,3,4=2.5 1,2,3,4,5=3
    // find the biggest sliding sum
    int sum = 0;
    rep(i,k) sum+=a[i];
    int max_sum = sum;
    int limit_l = 0;
    int limit_r = k; // left inclusive right exclusive
    for (int i=k; i<n; i++) {
        sum -= a[i-k];
        sum += a[i];
        if (sum > max_sum) {
            max_sum = sum;
            limit_l = i-k+1;
            limit_r = i+1;
        }
    }
    double expect_value = 0;
    for (int i = limit_l; i < limit_r; i++) {
        int dice_value = a[i];
        int dice_sum = 0;
        for (int v = 1; v <= dice_value; v++) {
            dice_sum+=v;
        }
        expect_value += (dice_sum*1.0)/dice_value;
    }
    cout << setprecision(12) << expect_value << endl;
}