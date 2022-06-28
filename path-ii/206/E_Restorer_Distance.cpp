/** 
 * Sarievo.
 * URL: https://codeforces.com/problemset/problem/1355/e
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
    // cin >> T;
    while (T--) f();
}
//!<---------- end of preset !<----------------------------

int n, A, R, M;
int binarySearch(vi& a, int h, vi& pref) {
    int pos = lower_bound(all(a), h) - a.begin();
    int res = 0;
    int k1 = h * pos - pref[pos];
    int k2 = pref[n] - pref[pos] - h * (n - pos);
    res = min(k1, k2);
    k1 -= res;
    k2 -= res;
    res *= M;
    res += k1 * A;
    res += k2 * R;
    return res;
}

void f() {
    cin >> n >> A >> R >> M; // cost of add, remove, move
    M = min(M, A + R);
    
    vi a(n); for (auto &x : a) cin >> x;
    sort(all(a));

    vi pref(n+1, 0);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + a[i-1];
    }

    int ans = LONG_LONG_MAX;
    ans = min(ans, binarySearch(a, pref[n] / n,   pref));
    ans = min(ans, binarySearch(a, pref[n] / n+1, pref));
    for (int i = 0; i < n; i++)
        ans = min(ans, binarySearch(a, a[i], pref));
    cout << ans << endl;
}