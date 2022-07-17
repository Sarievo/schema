/** 
 * Sarievo.
 * URL: 
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
void riev();
signed main() {
    IOS;
    int T=1;
    // cin >> T;
    while (T--) riev();
}
//!<---------- end of preset !<----------------------------

const int N = 2e5+53, M = 2e5+1;
typedef array<long long, 3> vec;
typedef array<vec, 3> mat;

vec operator+(const vec& a, const vec& b){
    vec c;
    rep(i,3) c[i] = a[i] + b[i];
    return c;
}

vec operator-(const vec& a, const vec& b){
    vec c;
    rep(i,3) c[i] = a[i] - b[i];
    return c;
}

vec operator*(const mat& a, const vec& b){
    vec c;
    rep(i,3) c[i] = 0;
    rep(i,3) rep(j,3)
        c[i] += a[i][j] * b[j];
    return c;
}

mat operator*(const mat& a, const mat& b){
    mat c;
    rep(i,3) rep(j,3) c[i][j] = 0;
    rep(i,3) rep(j,3) rep(k,3)
        c[i][k] += a[i][j] * b[j][k];
    return c;
}

mat F = {vec({1, 0, 0}), vec({+1, 1, 0}), vec({1, +2, 1})};
mat B = {vec({1, 0, 0}), vec({-1, 1, 0}), vec({1, -2, 1})};
mat E = {vec({1, 0, 0}), vec({+0, 1, 0}), vec({0, +0, 1})};

vec S = {1, 0, 0};
vec Z = {0, 0, 0};

vec t[4 * N];
mat f[4 * N];
bool active[4 * N];
bool has[N];
int q, d;

vec getVal(int v){
    if(!active[v]) return Z;
    return f[v] * t[v];
}

void recalc(int v){
    t[v] = getVal(v * 2 + 1) + getVal(v * 2 + 2);    
}

void build(int v, int l, int r){
    if(l == r - 1){
        f[v] = E;
        t[v] = S;
        active[v] = false;           
    }else{
        int m = (l + r) / 2;
        build(v * 2 + 1, l, m);
        build(v * 2 + 2, m, r);
        f[v] = E;
        recalc(v);
        active[v] = true;               
    }
}

void push(int v){
    if(f[v] == E) return;
    t[v] = f[v] * t[v];
    f[v * 2 + 1] = f[v] * f[v * 2 + 1];
    f[v * 2 + 2] = f[v] * f[v * 2 + 2];
    f[v] = E;
}

void updSegment(int v, int l, int r, int L, int R, bool adv){
    if(L >= R) return;
    if(l == L && r == R){
        if(adv) f[v] = F * f[v];
        else f[v] = B * f[v];
        return;
    }
    push(v);
    int m = (l + r) / 2;
    updSegment(v * 2 + 1, l, m, L, min(m, R), adv);
    updSegment(v * 2 + 2, m, r, max(m, L), R, adv);
    recalc(v);
}

void setState(int v, int l, int r, int pos, bool val){
    if(l == r - 1){   
        active[v] = val;
        return;
    }
    push(v);
    int m = (l + r) / 2;
    if(pos < m)
        setState(v * 2 + 1, l, m, pos, val);
    else
        setState(v * 2 + 2, m, r, pos, val);
    recalc(v);
}

void addPoint(int x){
    int lf = max(0, x - d);
    int rg = x;
    if(lf < rg)
        updSegment(0, 0, M, lf, rg, true);
    setState(0, 0, M, x, true);        
}

void delPoint(int x){
    int lf = max(0, x - d);
    int rg = x;
    if(lf < rg)
        updSegment(0, 0, M, lf, rg, false);
    setState(0, 0, M, x, false);        
}

void query(int x){
    if(has[x]){
        has[x] = false;
        delPoint(x);
    }else{
        has[x] = true;
        addPoint(x);
    }
    vec res = getVal(0);
    printf("%lld\n", (res[2] - res[1]) / 2);
}

void riev() {
    cin >> q >> d;
    build(0,0,M);
    while(q--)  {
        int x; cin >> x;
        query(x);
    }
}