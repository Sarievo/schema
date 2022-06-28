/** 
 * Sarievo.
 * URL: https://codeforces.com/contest/416/problem/A
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
void f();
signed main() {
    IOS;
    int T=1;
    // cin >> T;
    while (T--) f();
}
//!<---------- end of preset !<----------------------------

void f() {
    int q; cin >> q;
    vi left_bounds;
    vi right_bounds;
    while (q--) {
        string a; cin >> a;
        int b; cin >> b;
        string c; cin >> c;
        if (c == "Y") {
            if (a == ">=") {
                /* inclusive bound? */
                left_bounds.push_back(b);
            } else if (a == ">") {
                /* exclusive bound? */
                left_bounds.push_back(b+1);
            } else if (a == "<=") {
                right_bounds.push_back(b);
            } else {
                right_bounds.push_back(b-1);
            }
        } else {
            if (a == ">=") {
                /* exclusive bound? */
                right_bounds.push_back(b-1);
            } else if (a == ">") {
                /* inclusive bound? */
                right_bounds.push_back(b);
            } else if (a == "<=") {
                left_bounds.push_back(b+1);
            } else {
                left_bounds.push_back(b);
            }
        }
    }

    sort(all(left_bounds));
    sort(all(right_bounds));
    
    if (left_bounds.size() && right_bounds.size()) {
        /* only the rightmost left_bound and the leftmost right_bound matter */
        if (left_bounds.back() > right_bounds[0]) {
            cout << "Impossible\n";
        } else {
            cout << left_bounds.back() << endl;
        }
    } else {
        if (left_bounds.size()) {
            cout << left_bounds.back() << endl;
        } else {
            cout << right_bounds[0] << endl;
        }
    }
}