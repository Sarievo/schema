/** 
 * Sarievo.
 * URL: https://codeforces.com/contest/1692/problem/C
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

void f() {
    int n=8;
    vector<vector<bool>> g(8, vector<bool>(8,false));
    rep(i,8) {
        string s; cin >> s;
        rep(j,8) {
            if (s[j]=='#') g[i][j] = true;
        }
    }
    // the bishop will not be at the four corners so the ans is not ambiguous

    vvc<int> helper = {{-1,-1},{-1,+1},{+1,+1},{+1,-1}};
    // itself is an x + UL and UR is x or UR and DR is x
    //               or DR and DL is x or DL and UL is x

    rep(i,8) {
        rep(j,8) {
            if (g[i][j]) {
                vc<bool> validity;
                for (auto& code:helper) {
                    int new_x=code[0]+i;
                    int new_y=code[1]+j;
                    if (new_x<0||new_y<0||new_x>=8||new_y>=8)
                        validity.push_back(false);
                    else validity.push_back(g[new_x][new_y]);
                }

                if (validity[0] and validity[1]
                        or validity[1] and validity[2]
                        or validity[2] and validity[3]
                        or validity[3] and validity[0]) {
                    cout << i+1 << " " << j+1 << endl;
                    return;
                }
            }
        }
    }
}