/** 
 * Sarievo.
 * URL: https://atcoder.jp/contests/abc129/tasks/abc129_c
 */

#include <bits/stdc++.h>
using namespace std;

struct custom_hash {
    // https://codeforces.com/blog/entry/62393
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template<class t> using hashset=unordered_set<t,custom_hash>;
template<class t,class u> using hashmap=unordered_map<t,u,custom_hash>;
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
#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)    // [a,b)
#define rep(i,b) FOR(i,0,b)
#define DWN(i,a,b) for(int i=int(b)-1;i>=int(a);i--) // (b,a]
#define per(i,b) DWN(i,0,b)
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

const int mod = 1e9+7;
void f() {
    int n, m; cin >> n >> m;
    hashset<int> broken_threads;
    int x;
    rep(i,m) {
        cin >> x;
        broken_threads.insert(x);
    }

    vi dp(n+1);
    dp[1] = !broken_threads.count(1);
    dp[2] = !broken_threads.count(2) ? dp[1]+1 : 0;
    for (int i = 3; i <= n; ++i) {
        for(int j : {i-1, i-2})
            if (!broken_threads.count(j))
                dp[i] = (dp[i] + dp[j]) % mod;
    }
    cout << dp.back() << endl;
}