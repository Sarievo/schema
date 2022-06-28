/** 
 * Sarievo.
 * URL: https://codeforces.com/contest/1332/problem/B
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
const int N = 1e5 + 9;
vector<int> spf(N);
void get_spf() {
    spf[1] = 1;
    for (int i=2; i<N; i++)
        spf[i] = i;
 
    for (int i=4; i<N; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<N; i++) {
        if (spf[i] == i) for (int j=i*i; j<N; j+=i)
            if (spf[j]==j) spf[j]=i;
    }
}

void f();
signed main() {
    IOS;
    get_spf();
    int T=1;
    cin >> T;
    while (T--) f();
}
//!<---------- end of preset !<----------------------------

void f() {
    int n; cin >> n;
    vi a(n); cin >> a;
    int color = 1;
    map<int,int> colors;
    map<int,int> int_colors;
    for (int i = 0; i < n; i++) {
        int factor = spf[a[i]];
        if (colors.find(factor)==colors.end()) {
            colors[factor] = color++;
        }
        int_colors[i] = colors[factor];
    }

    cout << (color - 1) << endl;
    for (int i = 0; i < n; i++) cout << int_colors[i] << " ";
    cout << endl;
}