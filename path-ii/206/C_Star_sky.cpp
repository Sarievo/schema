/** 
 * Sarievo.
 * URL: https://codeforces.com/contest/835/problem/C
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

const int N = 1e5 + 123;
const int C = 101;
const int P = 11;
int n, q, c;
int cnt[P][C][C];

void f() {
    int n, q, c; cin >> n >> q >> c;
    rep(i, n) {
        int x, y, s; cin >> x >> y >> s;
        cnt[s][x][y]++;
    }

    rep(p, c+1)
        for (int i = 1; i < C; i++)
            for (int j = 1; j < C; j++)
                cnt[p][i][j] += cnt[p][i - 1][j] + cnt[p][i][j - 1] - cnt[p][i - 1][j - 1];

    rep(i, q) {
        int t, x1, y1, x2, y2; cin >> t >> x1 >> y1 >> x2 >> y2;
        int ans = 0;
        rep(p, c+1) {
            int brightness = (p + t) % (c + 1);
            int amount = cnt[p][x2][y2] - cnt[p][x1 - 1][y2] - cnt[p][x2][y1 - 1] + cnt[p][x1 - 1][y1 - 1];
            ans += brightness * amount;
        }
        cout << ans << endl;
    }

}