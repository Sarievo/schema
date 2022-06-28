/** 
 * Sarievo.
 * URL: https://atcoder.jp/contests/abc157/tasks/abc157_c
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
    int n,m,s,c; cin>>n>>m;
    vi num(n,-1);
    rep(i,m) {
        cin>>s>>c; s--;
        if (n>1 && s==0 && c==0) {
            cout<<-1<<endl; return;
        }
        if (num[s]<0) num[s]=c;
        else if (num[s]!=c) {
            cout<<-1<<endl; return;
        }
    }
    if(num[0]==-1) num[0]=(n==1?0:1);
    for(int i=1; i<n; i++)
        if(num[i]==-1) num[i]=0;
    for(int &i:num)
        cout<<i;
    cout<<endl;
}