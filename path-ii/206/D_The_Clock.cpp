/** 
 * Sarievo.
 * URL: https://codeforces.com/contest/1692/problem/D
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
#define rep(i,b) rng(i,0,b) // i[0-b), go to range asc
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b) // i(b-0], go to range desc
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
    cin >> T;
    while (T--) f();
}
//!<---------- end of preset !<----------------------------

bool isPad(vi& t) {
    return t[0]==t[3]&&t[1]==t[2];
}

bool isPad(int t) {
    int H = t/60;
    int M = t%60;
    return H/10==M%10&&H%10==M/10;
}

int m_of_d = 24*60;
// vi gen_times(vi& t, int p) {
vi gen_times(int t, int p) {
    // cout << t << ":" << p << endl;
    set<int> seen;
    vi output;

    p%=m_of_d;
    if (!p) {
        output.push_back(t);
    } else {
        while (!seen.count(t)) {
            seen.insert(t);
            output.push_back(t);
            t = (t+p)%m_of_d;
        }
    }
    return output;
}

void f() {
    vi t;
    rep(i,5) {
        char j;
        cin >> j;
        if (i!=2) {
            t.push_back(j-'0');
        }
    }
    int p; cin >> p;

    int T = (t[0]*10+t[1])*60+(t[2]*10+t[3]);

    // find all resonable time
    vi times = gen_times(T, p);
    // cout << times << endl;
    int cnt =0;
    for (int time : times) {
        if (isPad(time)) cnt++;
    }
    cout << cnt << endl;
}