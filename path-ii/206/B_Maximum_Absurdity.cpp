/** 
 * Sarievo.
 * URL: https://codeforces.com/contest/332/problem/B
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

int get_sum(const vi&a, int l, int r) {
    return l ? (a[r]-a[l-1]) : a[r];
}

void f() {
    int n, k; cin >> n >> k;
    vi a(n); cin >> a;
    /* 
    find 2 segments of k length, st. they have the maximum sum
     */

    for (int i = 1; i < n; i++) a[i] = a[i-1] + a[i];
    pi ans = mp(n-2*k, n-k);
    int ans_sum = get_sum(a, n-2*k, n-k-1) + get_sum(a, n-k, n-1);
    pi suf_max = mp(n-k, get_sum(a, n-k, n-1));
    for (int i = n-2*k-1; i >= 0; --i) {
        int cur = get_sum(a, i+k, i+2*k-1);
        if (cur >= suf_max.b)
            suf_max = mp(i+k, cur);
        cur = get_sum(a, i, i+k-1) + suf_max.b;
        if (cur >= ans_sum) {
            ans_sum = cur;
            ans = mp(i, suf_max.a);
        }
    }
    cout << ans.a+1 << " " << ans.b+1 << endl;
}