/** 
 * Sarievo.
 * URL: https://codeforces.com/problemset/problem/439/D
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
void solve();
signed main() {
    IOS;
    int T=1;
    // cin >> T;
    while (T--) solve();
}
//!<---------- end of preset !<----------------------------

int n, m;
vi a, b;

ll f(ll k) {
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < k) {
            ans += (k - a[i]);
        }
    }
    for (int i = 0; i < m; i++) {
        if (b[i] > k) {
            ans += (b[i] - k);
        }
    }
    return ans;
}

void solve() {
    cin >> n >> m;
    a = vi(n); for (auto &x : a) cin >> x;
    b = vi(m); for (auto &x : b) cin >> x;
    /* 
    make the minimum value of the a at least as big as the maximum value of b
     */
    ll ans = 1e18;
    int pos = 1;
    ll lo = 1, hi = (ll) 1e9;
    for (int it = 0; it < 100; it++) {
        assert(lo <= hi);
        ll mid1 = lo + (hi - lo) / 3;
        ll mid2 = hi - (hi - lo) / 3;
        assert(mid1 >= lo && mid1 <= hi);
        assert(mid2 >= lo && mid2 <= hi);
        if (f(mid1) < ans) {
            ans = f(mid1);
            pos = mid1;
        }
        if (f(mid2) < ans) {
            ans = f(mid2);
            pos = mid2;
        }
        //cout << mid1 << " " << mid2 << " " << f(mid1) << " " << f(mid2) << endl;
        if (f(mid1) >= f(mid2)) {
            lo = mid1;
        } else {
            hi = mid2;
        }
    }
    cout << ans << endl;
}