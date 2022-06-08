/** 
 * Sarievo.
 * URL: https://atcoder.jp/contests/abc075/tasks/abc075_b
 */

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
template<typename X> inline X abs(const X& a) {return (a<0?-a:a);} // std methods?
template<typename X> inline X sqr(const X& a) {return (a*a);}
using namespace std;

using ll=long long;
#define int ll
/** METHOD */
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b) // i[0-b], go to range asc
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b) // i[b-0], go to range desc
// #define foreach(it,a) for(__typeof((a).begin())it=(a).begin();it!=(a).end();it++)
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;} // if a < b, a is replaced by b
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;} // if a > b, a is replaced by b
#define SUM(a) accumulate(all(a),int(0)) //...
/** VECTOR */
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
using vi=vc<int>;
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
template<class t> ostream& operator<<(ostream& os,const vc<t>& v){os<<"{";for(auto e:v)os<<e<<",";return os<<"}";} // ease for debugging vectors
/** PAIR   */
using pi=pair<int,int>;
#define mp make_pair
#define a first
#define b second
template<class t,class u> ostream& operator<<(ostream& os,const pair<t,u>& p){return os<<"{"<<p.a<<","<<p.b<<"}";} // ease for debugging pairs
 
void f() {
    int r, c; cin >> r >> c;
    vvc<char> m(r, vc<char>(c));
    for (auto &a : m) {
        string s; cin >> s;
        rep(i, c) a[i] = s[i];
    }

    vvc<int> codes {{+1,+1},{+1,+0},{+0,+1},{+1,-1},
                    {-1,-1},{-1,+0},{+0,-1},{-1,+1}};
    vvc<int> m_tmp(r, vi(c,0));
    rep(i,r) rep(j,c) {
        if (m[i][j] == '#') continue;
        int sur_mines = 0;
        for (vi &code : codes) {
            int new_x = i+code[0];
            int new_y = j+code[1];
            if (new_x < 0 || new_y < 0 || new_x >= r || new_y >= c
                || m[new_x][new_y] != '#') continue;
            sur_mines++;
        }
        m[i][j] = sur_mines+'0';
    }

    rep(i,r) {
        rep(j,c) cout << m[i][j];
        cout << endl;
    }
}

signed main() {
    IOS;
    int T=1;
    // cin >> T;
    while (T--) {
        f();
    }
}