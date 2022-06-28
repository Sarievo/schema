/** 
 * Sarievo.
 * URL: https://codeforces.com/problemset/problem/1199/C
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
   int n, I; cin >> n >> I;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    map<int, int> cnt;
    vector<int> b;
    for (int i = 1; i <= n; i++) {
        if (!cnt.count(a[i]))
            b.pb(a[i]);
        cnt[a[i]]++;
    }

    int j = 0;
    int now = 0;
    int ans = n;
    // int k = ceil(log(1) / log(2));
    // cout << "k = " << k << '\n';
    int k = 8 * I / n;
    int K = (1 << min(20, k));
    auto check = [&] (int total) {
        if (total <= K) return 1;
        return 0;
    };
    vector<int> pre(b.size() + 1);
    rep(i,b.size()) {
        if (!i) pre[i] = cnt[b[i]];
        else pre[i] = cnt[b[i]] + pre[i-1];
    }
    rep(i,b.size()) {
        while ((j+1) < b.size() && check(j+1 - i+1))
            j++;
        ans = min(ans, n - (pre[j] - (i?pre[i-1]:0)));
    }
    cout << ans << '\n';
}