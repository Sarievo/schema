/** 
 * Sarievo.
 * URL: https://codeforces.com/contest/1702/problem/G1
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
int n, sz;
vvc<int> sl, up;
vi d;

void precalc(int v, int p){
    d[v] = d[p] + 1;
    up[v][0] = p;
    for (int i = 1; i <= sz; ++i)
        up[v][i] = up[up[v][i - 1]][i - 1];
    for (int u: sl[v])
        if (u == p) continue;
        else precalc(u, v);
}

int lca(int u, int v){
    if (d[u] < d[v]) swap(u, v);
    for (int cur = sz; cur >= 0; --cur)
        if (d[u] - (1 << cur) >= d[v])
            u = up[u][cur];
    for (int cur = sz; cur >= 0; --cur)
        if (up[u][cur] != up[v][cur]) {
            u = up[u][cur];
            v = up[v][cur];
        }
    return u == v ? u : up[u][0];
}

void f() {
    cin >> n;
    sz = 0;
    while ((1 << sz) < n) sz++;
    d.assign(n, -1);
    up.assign(n, vi(sz+1));
    sl.assign(n, vi(0));
    for(int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        sl[--a].push_back(--b);
        sl[b].push_back(a);
    }

    precalc(0, 0);
    int q;
    cin >> q;
    while(q--) {
        int k;
        cin >> k;
        vi p(k);
        for (auto&e:p) {
            cin >> e;
            --e;
        }
        
        sort(all(p), [](int a, int b){return d[a] > d[b];});

        vc<bool> used(k);
        rep(i, k)
            if (lca(p[0], p[i]) == p[i]) used[i] = true;

        int f = 0;
        while (f < k && used[f]) f++;
        if (f == k){
            cout << "YES\n";
            continue;
        }

        bool ans = true;
        for (int i = f; i < k; ++i)
            if(lca(p[f], p[i]) == p[i]) used[i] = true;
        for (bool e: used) ans &= e;
        ans &= d[lca(p[0], p[f])] <= d[p.back()];

        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }
}