/** 
 * Sarievo.
 * URL: https://codeforces.com/contest/1187/problem/B
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

bool contains(vi d, string& t) {
    for (char c : t) {
        d[c-'a']--;
        if (d[c-'a'] < 0) return false;
    }
    return true;
}

void f() {
    int n; cin >> n;
    string s; cin >> s;

    vvc<int> prefix(n,vi(26));
    rep(i, n) prefix[i][s[i]-'a']++;
    rep(i, n-1) rep(j, 26) prefix[i+1][j] += prefix[i][j];

    int m; cin >> m;
    rep(i, m) {
        string t; cin >> t;
        // closest the the right: https://codeforces.com/edu/course/2/lesson/6
        int L = -1;
        int R = n;
        while (R > L + 1) {
            int M = (L + R) / 2;
            if (!contains(prefix[M], t)) {
                L = M;
            } else {
                R = M;
            }
        }
        cout << R + 1 << endl;
    }
}