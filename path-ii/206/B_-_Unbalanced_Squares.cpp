/** 
 * Sarievo.
 * URL: https://atcoder.jp/contests/arc142/tasks/arc142_b
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

void f() {
    int n; cin >> n;
    /* 
    for every X X X the number of squares those are bigger than O (a)
              X O X and the number of squares those are smaller than 0 (b) are not equal
              X X X
        output the grid
        for side and corner it will always satisfy, because the number of the adjacent cells are odd
      x  x  x  x  x  x  x  x  x  x
      x mx mn mx mn  x mx mn mx  x
      x mx mn mx mn  x mn mx mn  x wrong?
      x mx mn mx mn  x mx mn mx  x
      x  x  x  x  x  x  x  x  x  x

             5   6   7   8   9
25          10  25   1  24' 11
            12   2  23   3  13
            14  22   4  21  15
            16  17  18  19  20
     */
    if (n == 1) {
        cout << 1 << endl;
    } else if (n == 2) {
        cout << "1 2\n3 4\n";
    } else {
        int mn = 1;
        int mx = n*n;
        vvc<int> g(n, vi(n));
        bool turn = true;
        for (int i = 1; i < n-1; i++) {
            for (int j = 1; j < n-1; j++) {
                if (turn) {
                    g[i][j] = mx--;
                } else {
                    g[i][j] = mn++;
                }
                turn = !turn;
            }
        }
        for (int i = 0; i < n; i++) {
            g[0][i] = mn++;
        }
        for (int i = 1; i < n-1; i++) {
            g[i][0] = mn++;
            g[i][n-1] = mn++;
        }
        for (int i = 0; i < n; i++) {
            g[n-1][i] = mn++;
        }

        rep(i,n) {
            rep(j,n) cout << g[i][j] << " ";
            cout << endl;
        }

    }
}