/** 
 * Sarievo.
 * URL: https://codeforces.com/problemset/problem/1635/C
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
// template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;} // if a < b, a is replaced by b
// template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;} // if a > b, a is replaced by b
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
    int n; cin >> n;
    vi v(n); for (int &x : v) cin >> x;
    if (v[n-2] > v[n-1]) {
        cout << -1 << endl;
    } else {
        vvc<int> seq;
        per(i, n-2) {
            int R = n-1;
            int L = i+1;
            int LL = i;
            assert(v[L] <= v[R]);

            if (v[LL] > v[L]) {
                v[LL] = min(v[LL], v[L]-v[R]);
                seq.pb({LL, L, R});
            }
            if (v[LL] > v[L]) {
                cout << -1 << endl;
                return;
            }
        }
        // cout << v << endl;
        cout << seq.size() << endl;
        for (vi v : seq) {
            for (int &x : v) cout << (x+1) << " ";
            cout << endl;
        }
    }
}

signed main() {
    IOS;
    int T=1;
    cin >> T;
    while (T--) {
        f();
    }
}